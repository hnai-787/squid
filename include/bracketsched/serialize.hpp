#ifndef BRACKETSCHED_SERIALIZE_HPP
#define BRACKETSCHED_SERIALIZE_HPP

#include <string>
#include <vector>

#include "bracketsched/types.hpp"

namespace bracketsched {

// Canonical JSON: fixed key order, fixed match order, no timestamps, no
// random IDs -- the same graph always serializes to the same bytes (see
// README "Reproducibility contract"). `pretty` controls indentation only,
// never key/field order.
std::string toCanonicalJson(const BracketGraph& graph, bool pretty = true);

struct ParsedRequest {
    bool ok = false;
    std::string error;
    std::vector<Participant> participants;
    BracketConfig config;
};

// Parses {"participants": [{"seed": 1, "name": "..."}], "format": "single"|"double",
//         "grand_final": "reset"|"single"} (format/grand_final optional, default single/reset).
ParsedRequest parseRequestJson(const std::string& json);

}  // namespace bracketsched

#endif
