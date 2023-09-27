#ifndef DP_H
#define DP_H

#include "./global.hpp"
#include <optional>
#include <utility>
#include <vector>

/* Todo */
std::optional<std::vector<std::pair<int, int>>> minNumMonDP(int n) {
  std::vector<std::pair<int, int>> memo;
  memo.push_back(std::make_pair(0, 0));

  for (int i = 1; i < n + 1; i++) {
    int state = -1;

    for (auto denomination : gl::denominations) {
      if (denomination > i)
        continue;

      int temp = i - denomination;
      state =
          (state == -1 || memo[temp].first < memo[state].first) ? temp : state;
    }

    if (state == -1)
      return {};

    memo.push_back(std::make_pair(memo[state].first + 1, state));
  }

  return memo;
}

#endif
