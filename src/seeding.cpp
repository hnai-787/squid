#include "bracketsched/seeding.hpp"

#include <stdexcept>

namespace bracketsched {

std::size_t bitCeil(std::size_t n) {
    if (n == 0) throw std::invalid_argument("bitCeil: n must be >= 1");
    std::size_t p = 1;
    while (p < n) p <<= 1;
    return p;
}

std::vector<int> innerOuterSeedOrder(std::size_t size) {
    if (size == 0 || (size & (size - 1)) != 0) {
        throw std::invalid_argument("innerOuterSeedOrder: size must be a power of two");
    }

    std::vector<int> order{1};
    while (order.size() < size) {
        std::size_t nextSize = order.size() * 2;
        std::vector<int> next;
        next.reserve(nextSize);
        for (int seed : order) {
            next.push_back(seed);
            next.push_back(static_cast<int>(nextSize) + 1 - seed);
        }
        order = std::move(next);
    }
    return order;
}

}  // namespace bracketsched
