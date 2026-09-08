#include <catch2/catch_test_macros.hpp>

#include "bracketsched/generator.hpp"
#include "bracketsched/serialize.hpp"

using namespace bracketsched;

TEST_CASE("parses a minimal valid request", "[serialize]") {
    std::string src = R"({"participants": [{"seed": 1}, {"seed": 2}]})";
    ParsedRequest r = parseRequestJson(src);
    REQUIRE(r.ok);
    REQUIRE(r.participants.size() == 2);
    REQUIRE(r.config.format == Format::Single);
}

TEST_CASE("parses format and grand_final overrides", "[serialize]") {
    std::string src = R"({"participants": [{"seed": 1}, {"seed": 2}], "format": "double", "grand_final": "single"})";
    ParsedRequest r = parseRequestJson(src);
    REQUIRE(r.ok);
    REQUIRE(r.config.format == Format::Double);
    REQUIRE(r.config.grandFinal == GrandFinalPolicy::SingleMatch);
}

TEST_CASE("malformed JSON fails closed", "[serialize]") {
    ParsedRequest r = parseRequestJson("{ not json");
    REQUIRE_FALSE(r.ok);
    REQUIRE_FALSE(r.error.empty());
}

TEST_CASE("missing participants field fails closed", "[serialize]") {
    ParsedRequest r = parseRequestJson(R"({"format": "single"})");
    REQUIRE_FALSE(r.ok);
}

TEST_CASE("invalid format value fails closed", "[serialize]") {
    ParsedRequest r = parseRequestJson(R"({"participants": [{"seed": 1}, {"seed": 2}], "format": "roundrobin"})");
    REQUIRE_FALSE(r.ok);
}

TEST_CASE("canonical JSON is byte-identical across repeated generation", "[serialize]") {
    std::vector<Participant> ps = {{1, "A"}, {2, "B"}, {3, "C"}, {4, "D"}};
    BracketGraph g1 = generateBracket(ps, BracketConfig{Format::Double});
    BracketGraph g2 = generateBracket(ps, BracketConfig{Format::Double});
    REQUIRE(toCanonicalJson(g1) == toCanonicalJson(g2));
}

TEST_CASE("canonical JSON contains the documented policy names", "[serialize]") {
    std::vector<Participant> ps = {{1, "A"}, {2, "B"}};
    BracketGraph g = generateBracket(ps, BracketConfig{Format::Single});
    std::string json = toCanonicalJson(g, false);
    REQUIRE(json.find("\"seed_policy\":\"inner_outer\"") != std::string::npos);
    REQUIRE(json.find("\"format\":\"single\"") != std::string::npos);
}
