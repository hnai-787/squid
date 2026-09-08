#include "bracketsched/serialize.hpp"

#include <nlohmann/json.hpp>

namespace bracketsched {

using nlohmann::json;

namespace {

std::string bracketKindName(BracketKind k) {
    switch (k) {
        case BracketKind::Winners: return "winners";
        case BracketKind::Losers: return "losers";
        case BracketKind::GrandFinal: return "grand_final";
    }
    return "unknown";
}

json slotJson(const Slot& s) {
    switch (s.kind) {
        case SlotKind::Participant:
            return json{{"type", "participant"}, {"seed", s.participantSeed}};
        case SlotKind::FromMatch:
            return json{{"type", "from_match"},
                        {"match", toString(s.sourceMatch)},
                        {"result", s.sourceIsWinner ? "winner" : "loser"}};
        case SlotKind::Bye:
            return json{{"type", "bye"}};
        default:
            return json{{"type", "unknown"}};
    }
}

}  // namespace

std::string toCanonicalJson(const BracketGraph& graph, bool pretty) {
    json root;
    root["participant_count"] = graph.participantCount;
    root["bracket_size"] = graph.bracketSize;
    root["format"] = graph.format == Format::Single ? "single" : "double";
    root["algorithm_version"] = graph.config.algorithmVersion;
    root["seed_policy"] = "inner_outer";
    root["cross_bracket_policy"] = "alternating";
    root["grand_final_policy"] =
        graph.config.grandFinal == GrandFinalPolicy::ResetIfNecessary ? "reset_if_necessary" : "single_match";

    json matches = json::array();
    for (const Match& m : graph.matches) {
        matches.push_back({
            {"id", toString(m.id)},
            {"bracket", bracketKindName(m.id.bracket)},
            {"round", m.id.round},
            {"index", m.id.index},
            {"first", slotJson(m.first)},
            {"second", slotJson(m.second)},
            {"conditional", m.conditional},
        });
    }
    root["matches"] = matches;

    return pretty ? root.dump(2) : root.dump();
}

ParsedRequest parseRequestJson(const std::string& source) {
    ParsedRequest result;
    json root;
    try {
        root = json::parse(source);
    } catch (const json::parse_error& e) {
        result.error = std::string("JSON syntax error: ") + e.what();
        return result;
    }

    if (!root.contains("participants") || !root["participants"].is_array()) {
        result.error = "request must contain a \"participants\" array";
        return result;
    }

    for (const json& p : root["participants"]) {
        if (!p.contains("seed") || !p["seed"].is_number_integer()) {
            result.error = "every participant needs an integer \"seed\"";
            return result;
        }
        Participant participant;
        participant.seed = p["seed"].get<int>();
        participant.name = p.value("name", "Seed " + std::to_string(participant.seed));
        result.participants.push_back(participant);
    }

    if (root.contains("format")) {
        std::string fmt = root["format"].get<std::string>();
        if (fmt == "double") result.config.format = Format::Double;
        else if (fmt == "single") result.config.format = Format::Single;
        else {
            result.error = "\"format\" must be \"single\" or \"double\"";
            return result;
        }
    }

    if (root.contains("grand_final")) {
        std::string gf = root["grand_final"].get<std::string>();
        if (gf == "single") result.config.grandFinal = GrandFinalPolicy::SingleMatch;
        else if (gf == "reset") result.config.grandFinal = GrandFinalPolicy::ResetIfNecessary;
        else {
            result.error = "\"grand_final\" must be \"single\" or \"reset\"";
            return result;
        }
    }

    result.ok = true;
    return result;
}

}  // namespace bracketsched
