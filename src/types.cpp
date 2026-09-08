#include "bracketsched/types.hpp"

namespace bracketsched {

std::string toString(const MatchId& id) {
    std::string prefix = id.bracket == BracketKind::Winners ? "WB" : id.bracket == BracketKind::Losers ? "LB" : "GF";
    return prefix + "-R" + std::to_string(id.round) + "-M" + std::to_string(id.index);
}

}  // namespace bracketsched
