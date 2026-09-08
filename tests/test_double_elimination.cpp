#include <catch2/catch_test_macros.hpp>

#include "bracketsched/generator.hpp"

using namespace bracketsched;

namespace {

std::vector<Participant> makeParticipants(int n) {
    std::vector<Participant> ps;
    for (int i = 1; i <= n; ++i) ps.push_back({i, "Seed " + std::to_string(i)});
    return ps;
}

int countByBracket(const BracketGraph& g, BracketKind kind) {
    int count = 0;
    for (const Match& m : g.matches) if (m.id.bracket == kind) ++count;
    return count;
}

}  // namespace

TEST_CASE("double elimination match count is 2N-2 without a possible reset, 2N-1 with one", "[double-elim]") {
    for (int n : {2, 3, 4, 5, 6, 7, 8, 16, 32}) {
        BracketConfig singleGf{Format::Double, SeedPolicy::InnerOuter, CrossBracketPolicy::Alternating,
                                GrandFinalPolicy::SingleMatch};
        BracketGraph g1 = generateBracket(makeParticipants(n), singleGf);
        REQUIRE(static_cast<int>(g1.matches.size()) == 2 * n - 2);

        BracketConfig resetGf{Format::Double, SeedPolicy::InnerOuter, CrossBracketPolicy::Alternating,
                               GrandFinalPolicy::ResetIfNecessary};
        BracketGraph g2 = generateBracket(makeParticipants(n), resetGf);
        REQUIRE(static_cast<int>(g2.matches.size()) == 2 * n - 1);
    }
}

TEST_CASE("8-team double elimination matches the hand-derived round structure", "[double-elim]") {
    // Winners: R1=4, R2=2, R3(final)=1 -> 7 matches.
    // Losers:  R1=2 (consolidate WB1 losers), R2=2 (inject WB2 losers),
    //          R3=1 (consolidate), R4=1 (inject WB-final loser) -> 6 matches.
    // Grand final: 1 (+1 conditional reset).
    BracketGraph g = generateBracket(makeParticipants(8),
                                      BracketConfig{Format::Double, SeedPolicy::InnerOuter,
                                                    CrossBracketPolicy::Alternating,
                                                    GrandFinalPolicy::ResetIfNecessary});

    REQUIRE(countByBracket(g, BracketKind::Winners) == 7);
    REQUIRE(countByBracket(g, BracketKind::Losers) == 6);
    REQUIRE(countByBracket(g, BracketKind::GrandFinal) == 2);
    REQUIRE(static_cast<int>(g.matches.size()) == 15);  // 2*8-1

    int lbRound1 = 0, lbRound2 = 0, lbRound3 = 0, lbRound4 = 0;
    for (const Match& m : g.matches) {
        if (m.id.bracket != BracketKind::Losers) continue;
        if (m.id.round == 1) ++lbRound1;
        else if (m.id.round == 2) ++lbRound2;
        else if (m.id.round == 3) ++lbRound3;
        else if (m.id.round == 4) ++lbRound4;
    }
    REQUIRE(lbRound1 == 2);
    REQUIRE(lbRound2 == 2);
    REQUIRE(lbRound3 == 1);
    REQUIRE(lbRound4 == 1);
}

TEST_CASE("Grand Final: first match is unconditional, reset match is conditional with identical sources",
          "[double-elim]") {
    BracketGraph g = generateBracket(makeParticipants(4),
                                      BracketConfig{Format::Double, SeedPolicy::InnerOuter,
                                                    CrossBracketPolicy::Alternating,
                                                    GrandFinalPolicy::ResetIfNecessary});
    const Match *gf1 = nullptr, *gf2 = nullptr;
    for (const Match& m : g.matches) {
        if (m.id.bracket == BracketKind::GrandFinal && m.id.round == 1) gf1 = &m;
        if (m.id.bracket == BracketKind::GrandFinal && m.id.round == 2) gf2 = &m;
    }
    REQUIRE(gf1 != nullptr);
    REQUIRE(gf2 != nullptr);
    REQUIRE_FALSE(gf1->conditional);
    REQUIRE(gf2->conditional);

    // Same two source slots -- GF2 is a rematch of GF1's participants, not
    // "winner of GF1" (see README "Design decisions").
    REQUIRE(gf1->first.kind == gf2->first.kind);
    REQUIRE(gf1->first.sourceMatch == gf2->first.sourceMatch);
    REQUIRE(gf1->second.sourceMatch == gf2->second.sourceMatch);
}

TEST_CASE("SingleMatch grand final policy produces exactly one grand final match", "[double-elim]") {
    BracketGraph g = generateBracket(
        makeParticipants(4), BracketConfig{Format::Double, SeedPolicy::InnerOuter,
                                            CrossBracketPolicy::Alternating, GrandFinalPolicy::SingleMatch});
    REQUIRE(countByBracket(g, BracketKind::GrandFinal) == 1);
}

TEST_CASE("regression: double elimination with byes still satisfies the 2N-2/2N-1 match-count invariant",
          "[double-elim]") {
    // N=5 -> bracketSize=8 -> 3 byes. This is exactly the case that broke
    // the first version of buildLosersBracket: round-1 byes produce
    // "empty" losers-bracket positions that must keep propagating as
    // byes (not be silently dropped) until a real competitor reaches
    // them, or the losers-bracket population size desynchronizes from
    // the next incoming wave of winners-bracket losers and a match goes
    // missing. See PROJECT_NOTES.md for the full story.
    BracketGraph g = generateBracket(
        makeParticipants(5), BracketConfig{Format::Double, SeedPolicy::InnerOuter,
                                            CrossBracketPolicy::Alternating, GrandFinalPolicy::SingleMatch});
    REQUIRE(countByBracket(g, BracketKind::Winners) == 4);   // N-1
    REQUIRE(static_cast<int>(g.matches.size()) == 8);        // 2N-2
}

TEST_CASE("2-team double elimination has no losers-bracket match (loser goes straight to grand final)",
          "[double-elim]") {
    BracketGraph g = generateBracket(
        makeParticipants(2), BracketConfig{Format::Double, SeedPolicy::InnerOuter,
                                            CrossBracketPolicy::Alternating, GrandFinalPolicy::SingleMatch});
    REQUIRE(countByBracket(g, BracketKind::Winners) == 1);
    REQUIRE(countByBracket(g, BracketKind::Losers) == 0);
    REQUIRE(countByBracket(g, BracketKind::GrandFinal) == 1);
    REQUIRE(static_cast<int>(g.matches.size()) == 2);  // 2*2-2
}
