#ifndef BRACKETSCHED_TYPES_HPP
#define BRACKETSCHED_TYPES_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace bracketsched {

struct Participant {
    int seed;  // 1-based competitive rank/seed, NOT a random-number-generator seed
    std::string name;
};

enum class Format { Single, Double };

// See README "Design decisions": named, citable policies rather than an
// implied "the" algorithm, because (per the research this was built
// against) there is no single universal standard for several of these.
enum class SeedPolicy { InnerOuter };
enum class CrossBracketPolicy { Alternating };
enum class GrandFinalPolicy { ResetIfNecessary, SingleMatch };

struct BracketConfig {
    Format format = Format::Single;
    SeedPolicy seedPolicy = SeedPolicy::InnerOuter;
    CrossBracketPolicy crossBracket = CrossBracketPolicy::Alternating;
    GrandFinalPolicy grandFinal = GrandFinalPolicy::ResetIfNecessary;
    std::uint32_t algorithmVersion = 1;
};

enum class BracketKind { Winners, Losers, GrandFinal };

struct MatchId {
    BracketKind bracket;
    int round;  // 1-based
    int index;  // 1-based, within the round

    bool operator==(const MatchId& other) const {
        return bracket == other.bracket && round == other.round && index == other.index;
    }
};

std::string toString(const MatchId& id);

enum class SlotKind { Participant, FromMatch, Bye, Unknown };

struct Slot {
    SlotKind kind = SlotKind::Unknown;
    int participantSeed = 0;  // valid when kind == Participant
    MatchId sourceMatch{};    // valid when kind == FromMatch
    bool sourceIsWinner = true;

    static Slot fromParticipant(int seed) { return Slot{SlotKind::Participant, seed, {}, true}; }
    static Slot bye() { return Slot{SlotKind::Bye, 0, {}, true}; }
    static Slot fromMatchWinner(MatchId id) { return Slot{SlotKind::FromMatch, 0, id, true}; }
    static Slot fromMatchLoser(MatchId id) { return Slot{SlotKind::FromMatch, 0, id, false}; }
};

struct Match {
    MatchId id;
    Slot first;
    Slot second;
    // Only meaningful for the second Grand Final match under
    // GrandFinalPolicy::ResetIfNecessary: this match is only played if the
    // lower-bracket entrant wins the first Grand Final match. It has the
    // same two source slots as the first Grand Final match, not "winner of
    // GF1" -- see README "Design decisions" for why.
    bool conditional = false;
};

struct BracketGraph {
    int participantCount = 0;
    int bracketSize = 0;  // next power of two >= participantCount
    Format format = Format::Single;
    BracketConfig config{};
    std::vector<Match> matches;  // deterministic order: WB rounds, then LB rounds, then GF
};

}  // namespace bracketsched

#endif
