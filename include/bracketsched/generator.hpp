#ifndef BRACKETSCHED_GENERATOR_HPP
#define BRACKETSCHED_GENERATOR_HPP

#include <vector>

#include "bracketsched/types.hpp"

namespace bracketsched {

// Generates a full bracket dependency graph for `participants` (must have
// unique seeds 1..N, N >= 2 -- see README for why unranked/random-draw
// input is out of scope for v1). Deterministic: the same participants and
// config always produce the identical graph (see README "Reproducibility
// contract").
BracketGraph generateBracket(const std::vector<Participant>& participants, const BracketConfig& config);

}  // namespace bracketsched

#endif
