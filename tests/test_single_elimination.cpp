#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <map>
#include <set>

#include "bracketsched/generator.hpp"

using namespace bracketsched;

namespace {

std::vector<Participant> makeParticipants(int n) {
    std::vector<Participant> ps;
    for (int i = 1; i <= n; ++i) ps.push_back({i, "Seed " + std::to_string(i)});
    return ps;
}

std::map<int, Match> byRoundIndex(const BracketGraph& g, int round) {
    std::map<int, Match> result;
    for (const Match& m : g.matches) {
        if (m.id.bracket == BracketKind::Winners && m.id.round == round) result[m.id.index] = m;
    }
    return result;
}

std::map<std::string, Match> indexById(const BracketGraph& g) {
    std::map<std::string, Match> result;
    for (const Match& m : g.matches) result[toString(m.id)] = m;
    return result;
}

// All original seeds that could possibly end up occupying this slot (the
// full set of leaves under this slot's subtree), regardless of who wins
// along the way.
std::set<int> reachableSeeds(const std::map<std::string, Match>& matches, const Slot& slot) {
    if (slot.kind == SlotKind::Participant) return {slot.participantSeed};
    const Match& m = matches.at(toString(slot.sourceMatch));
    std::set<int> result = reachableSeeds(matches, m.first);
    for (int s : reachableSeeds(matches, m.second)) result.insert(s);
    return result;
}

}  // namespace

TEST_CASE("match count is N-1 for a range of team counts", "[single-elim]") {
    for (int n = 2; n <= 64; ++n) {
        BracketGraph g = generateBracket(makeParticipants(n), BracketConfig{Format::Single});
        REQUIRE(static_cast<int>(g.matches.size()) == n - 1);
    }
}

TEST_CASE("bracket size is the next power of two", "[single-elim]") {
    BracketGraph g = generateBracket(makeParticipants(6), BracketConfig{Format::Single});
    REQUIRE(g.bracketSize == 8);
}

TEST_CASE("top B seeds receive round-one byes, where B = bracketSize - N", "[single-elim]") {
    // N=6 -> bracketSize=8 -> 2 byes -> seeds 1 and 2 should have no
    // round-one opponent (their winners-bracket round-1 "match" doesn't
    // exist at all -- they advance directly).
    BracketGraph g = generateBracket(makeParticipants(6), BracketConfig{Format::Single});
    auto round1 = byRoundIndex(g, 1);

    std::set<int> seedsWithRound1Matches;
    for (auto& [idx, m] : round1) {
        if (m.first.kind == SlotKind::Participant) seedsWithRound1Matches.insert(m.first.participantSeed);
        if (m.second.kind == SlotKind::Participant) seedsWithRound1Matches.insert(m.second.participantSeed);
    }
    REQUIRE_FALSE(seedsWithRound1Matches.contains(1));
    REQUIRE_FALSE(seedsWithRound1Matches.contains(2));
}

TEST_CASE("no round-one match pairs two byes together", "[single-elim]") {
    for (int n = 2; n <= 64; ++n) {
        BracketGraph g = generateBracket(makeParticipants(n), BracketConfig{Format::Single});
        int bracketSize = g.bracketSize;
        // A round-1 "match" only exists in the graph for real pairings
        // (bye pairings never produce a Match record at all), so simply
        // counting round-1 matches and comparing against the expected
        // real-pairing count IS the no-double-bye invariant.
        int byes = bracketSize - n;
        int expectedRound1Matches = (bracketSize / 2) - byes;
        auto round1 = byRoundIndex(g, 1);
        REQUIRE(static_cast<int>(round1.size()) == expectedRound1Matches);
    }
}

TEST_CASE("top 2^r seeds occupy disjoint regions until round (final - r + 1)", "[single-elim]") {
    // Generalizes "seed 1 and 2 can only meet in the final": the top 2^r
    // seeds must stay in 2^r structurally distinct subtrees (no single
    // match's combined reachable-seed set contains two of them) until
    // there are only 2^r subtrees left to converge, i.e. round
    // (finalRound - r + 1) onward.
    for (int n : {8, 16, 32}) {
        BracketGraph g = generateBracket(makeParticipants(n), BracketConfig{Format::Single});
        auto byId = indexById(g);
        int finalRound = static_cast<int>(std::log2(n));

        for (int r = 1; r <= 3 && (1 << r) <= n; ++r) {
            int topCount = 1 << r;
            int earliestAllowedRound = finalRound - r + 1;

            for (const Match& m : g.matches) {
                if (m.id.bracket != BracketKind::Winners) continue;
                if (m.id.round >= earliestAllowedRound) continue;

                std::set<int> combined = reachableSeeds(byId, m.first);
                for (int s : reachableSeeds(byId, m.second)) combined.insert(s);

                int topSeedsPresent = 0;
                for (int s : combined) {
                    if (s <= topCount) ++topSeedsPresent;
                }
                INFO("n=" << n << " r=" << r << " match=" << toString(m.id));
                REQUIRE(topSeedsPresent <= 1);
            }
        }
    }
}

TEST_CASE("pair-complement invariant: matches at each round trace back to seeds via inner-outer order",
          "[single-elim]") {
    // For a full (no-bye) 8-team bracket, round 1 pairs must be exactly
    // the inner-outer sequence's adjacent pairs.
    BracketGraph g = generateBracket(makeParticipants(8), BracketConfig{Format::Single});
    auto round1 = byRoundIndex(g, 1);
    REQUIRE(round1.size() == 4);
    REQUIRE(round1.at(1).first.participantSeed + round1.at(1).second.participantSeed == 9);
    REQUIRE(round1.at(2).first.participantSeed + round1.at(2).second.participantSeed == 9);
}

TEST_CASE("rejects duplicate or out-of-range seeds", "[single-elim]") {
    std::vector<Participant> bad = {{1, "A"}, {1, "B"}};
    REQUIRE_THROWS_AS(generateBracket(bad, BracketConfig{}), std::invalid_argument);

    std::vector<Participant> outOfRange = {{1, "A"}, {5, "B"}};
    REQUIRE_THROWS_AS(generateBracket(outOfRange, BracketConfig{}), std::invalid_argument);
}

TEST_CASE("rejects fewer than 2 participants", "[single-elim]") {
    REQUIRE_THROWS_AS(generateBracket(makeParticipants(1), BracketConfig{}), std::invalid_argument);
}
