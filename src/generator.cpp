#include "bracketsched/generator.hpp"

#include <algorithm>
#include <set>
#include <stdexcept>

#include "bracketsched/seeding.hpp"

namespace bracketsched {

namespace {

bool isByeSeed(int seed, int participantCount) { return seed > participantCount; }

// A pending reference into the bracket. Unlike an earlier version of this
// file, `Bye` is a first-class case here, not just "a participant seed
// that happens to exceed participantCount": once a bye has propagated
// forward (there was no opponent to play), it must keep propagating as an
// *empty* slot through however many further rounds it takes for a real
// competitor to reach that position -- see README "Design decisions" for
// the concrete example (a losers-bracket position fed by two round-one
// byes has nobody in it at all until a real loser is eventually injected).
enum class SourceKind { Participant, Bye, MatchRef };

struct Source {
    SourceKind kind = SourceKind::Bye;
    int seed = 0;
    MatchId matchId{};
    bool asLoser = false;

    static Source participant(int seed) { return Source{SourceKind::Participant, seed, {}, false}; }
    static Source bye() { return Source{SourceKind::Bye, 0, {}, false}; }
    static Source matchWinner(MatchId id) { return Source{SourceKind::MatchRef, 0, id, false}; }
    static Source matchLoser(MatchId id) { return Source{SourceKind::MatchRef, 0, id, true}; }
};

Slot slotFromSource(const Source& s) {
    if (s.kind == SourceKind::Participant) return Slot::fromParticipant(s.seed);
    if (s.kind == SourceKind::Bye) return Slot::bye();
    return s.asLoser ? Slot::fromMatchLoser(s.matchId) : Slot::fromMatchWinner(s.matchId);
}

struct PairResult {
    Source winner;
    Source loser;  // Source::bye() if no real match was played at this pairing
    bool matchCreated;
};

// The one place bye-propagation logic lives, used for every kind of
// pairing in both brackets (winners rounds, losers first-wave self-pairs,
// losers injection, losers consolidation): a bye against a bye stays an
// (empty) bye; a bye against anything else lets the other side through
// untouched, with no match and no loser; two real sides play a real match.
PairResult resolvePair(const Source& a, const Source& b, BracketKind kind, int round, int matchIndex,
                        std::vector<Match>& matches) {
    bool aBye = a.kind == SourceKind::Bye;
    bool bBye = b.kind == SourceKind::Bye;

    if (aBye && bBye) return {Source::bye(), Source::bye(), false};
    if (aBye) return {b, Source::bye(), false};
    if (bBye) return {a, Source::bye(), false};

    MatchId id{kind, round, matchIndex};
    matches.push_back(Match{id, slotFromSource(a), slotFromSource(b), false});
    return {Source::matchWinner(id), Source::matchLoser(id), true};
}

// Sequentially pairs neighbors in `sources` (length must be even), used
// for winners-bracket rounds and for losers-bracket self-pairing rounds.
struct RoundResult {
    std::vector<Source> winners;
    std::vector<Source> losers;  // only meaningful for winners-bracket rounds
};

RoundResult resolveSequentialRound(const std::vector<Source>& sources, BracketKind kind, int round,
                                    std::vector<Match>& matches) {
    RoundResult result;
    int matchIndex = 1;
    for (std::size_t i = 0; i < sources.size(); i += 2) {
        PairResult pr = resolvePair(sources[i], sources[i + 1], kind, round, matchIndex, matches);
        if (pr.matchCreated) ++matchIndex;
        result.winners.push_back(pr.winner);
        result.losers.push_back(pr.loser);
    }
    return result;
}

struct WinnersResult {
    Source champion;
    // losersByRound[r] has exactly bracketSize/2^(r+1) entries, one per
    // winners-bracket round-(r+1) pairing -- Source::bye() wherever that
    // pairing was decided by a bye (no real loser to report), matching
    // the corresponding winners-round entry one-for-one.
    std::vector<std::vector<Source>> losersByRound;
};

WinnersResult buildWinnersBracket(int participantCount, std::size_t bracketSize, std::vector<Match>& matches) {
    std::vector<int> seedOrder = innerOuterSeedOrder(bracketSize);
    std::vector<Source> current;
    current.reserve(seedOrder.size());
    for (int seed : seedOrder) {
        current.push_back(isByeSeed(seed, participantCount) ? Source::bye() : Source::participant(seed));
    }

    WinnersResult result;
    int round = 1;
    while (current.size() > 1) {
        RoundResult rr = resolveSequentialRound(current, BracketKind::Winners, round, matches);
        result.losersByRound.push_back(std::move(rr.losers));
        current = std::move(rr.winners);
        ++round;
    }

    result.champion = current[0];
    return result;
}

// Builds the losers bracket per the "alternating" cross-bracket policy.
// See README "Design decisions" for the derivation: the first wave of
// winners-bracket losers plays itself, then every subsequent wave is
// injected against current survivors (alternating natural/reversed order
// to avoid an immediate rematch), followed by a consolidation round to
// halve survivors back down to meet the next wave -- except after the
// last (winners-final) wave, which produces the losers-bracket champion
// directly. Every pairing (including self-pairing and consolidation
// rounds) goes through the same bye-aware resolvePair/resolveSequentialRound
// helpers as the winners bracket, so a losers-bracket position with no
// real occupant yet correctly keeps propagating as a bye instead of
// desynchronizing the population size from the next incoming wave (a real
// bug caught by this project's own test suite -- see PROJECT_NOTES.md).
Source buildLosersBracket(WinnersResult& wb, std::vector<Match>& matches) {
    std::vector<Source> lbPopulation;
    int lbRound = 1;
    int injectionCount = 0;
    std::size_t totalWaves = wb.losersByRound.size();

    for (std::size_t r = 0; r < totalWaves; ++r) {
        std::vector<Source>& arrivals = wb.losersByRound[r];
        if (arrivals.empty()) continue;

        if (lbPopulation.empty()) {
            if (arrivals.size() == 1) {
                lbPopulation = arrivals;
            } else {
                RoundResult rr = resolveSequentialRound(arrivals, BracketKind::Losers, lbRound, matches);
                lbPopulation = std::move(rr.winners);
                ++lbRound;
            }
            continue;
        }

        std::vector<Source> orderedArrivals = arrivals;
        if (injectionCount % 2 == 1) std::reverse(orderedArrivals.begin(), orderedArrivals.end());
        ++injectionCount;

        std::vector<Source> injected;
        int matchIndex = 1;
        for (std::size_t i = 0; i < lbPopulation.size(); ++i) {
            PairResult pr = resolvePair(lbPopulation[i], orderedArrivals[i], BracketKind::Losers, lbRound,
                                         matchIndex, matches);
            if (pr.matchCreated) ++matchIndex;
            injected.push_back(pr.winner);
        }
        lbPopulation = std::move(injected);
        ++lbRound;

        bool isLastWave = (r == totalWaves - 1);
        if (!isLastWave && lbPopulation.size() > 1) {
            RoundResult rr = resolveSequentialRound(lbPopulation, BracketKind::Losers, lbRound, matches);
            lbPopulation = std::move(rr.winners);
            ++lbRound;
        }
    }

    return lbPopulation.empty() ? Source::bye() : lbPopulation[0];
}

void validateParticipants(const std::vector<Participant>& participants) {
    if (participants.size() < 2) {
        throw std::invalid_argument("generateBracket: at least 2 participants are required");
    }
    std::set<int> seeds;
    for (const Participant& p : participants) {
        if (p.seed < 1 || p.seed > static_cast<int>(participants.size())) {
            throw std::invalid_argument("generateBracket: seeds must be a contiguous range 1..N");
        }
        if (!seeds.insert(p.seed).second) {
            throw std::invalid_argument("generateBracket: duplicate seed " + std::to_string(p.seed));
        }
    }
}

}  // namespace

BracketGraph generateBracket(const std::vector<Participant>& participants, const BracketConfig& config) {
    validateParticipants(participants);

    int n = static_cast<int>(participants.size());
    std::size_t bracketSize = bitCeil(static_cast<std::size_t>(n));

    BracketGraph graph;
    graph.participantCount = n;
    graph.bracketSize = static_cast<int>(bracketSize);
    graph.format = config.format;
    graph.config = config;

    WinnersResult wb = buildWinnersBracket(n, bracketSize, graph.matches);

    if (config.format == Format::Single) {
        return graph;
    }

    Source lbChampion = buildLosersBracket(wb, graph.matches);

    MatchId gf1{BracketKind::GrandFinal, 1, 1};
    graph.matches.push_back(Match{gf1, slotFromSource(wb.champion), slotFromSource(lbChampion), false});

    if (config.grandFinal == GrandFinalPolicy::ResetIfNecessary) {
        MatchId gf2{BracketKind::GrandFinal, 2, 1};
        graph.matches.push_back(Match{gf2, slotFromSource(wb.champion), slotFromSource(lbChampion), true});
    }

    return graph;
}

}  // namespace bracketsched
