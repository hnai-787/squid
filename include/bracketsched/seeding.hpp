#ifndef BRACKETSCHED_SEEDING_HPP
#define BRACKETSCHED_SEEDING_HPP

#include <cstddef>
#include <vector>

namespace bracketsched {

// Smallest power of two >= n (n >= 1).
std::size_t bitCeil(std::size_t n);

// The "inner-outer" (recursive reflection) seed placement: for a bracket
// of `size` slots (size must be a power of two), returns the seed that
// should occupy each slot, in bracket order, such that:
//   - every first-round pair sums to size + 1
//   - the top 2^r seeds occupy 2^r distinct regions of the draw, for every r
// This is the same construction implemented by real bracket-generation
// tools (see README "Design decisions" for the citation) -- not
// bit-reversal permutation, which produces a different (and pedagogically
// wrong) sequence.
std::vector<int> innerOuterSeedOrder(std::size_t size);

}  // namespace bracketsched

#endif
