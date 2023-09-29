/*
  Dynamic Programming Approach Header File

  Determines the minimum number of coins to use
  given a set of denomination and a value to pay,
  using a Dynamic Programming Approach.

  Author: Joaquín Badillo A01026364
  Last Update: 27/Sept/2023
*/

#ifndef DP_H
#define DP_H

#include "./global.hpp"
#include <optional>
#include <unordered_map>
#include <utility>
#include <vector>

/* Minimum Number of Coins (Dynamic Programming)

 Implementation of a DP approach to give out change with
 a particular set of denominations (which can be used indefinitely).

 To respect the desired function signature, it uses a global variable
 gl::denominations to get the denominations list.

 Params:
 int n - The quantity that needs to be paid.

 Result:
 vector<int>? - A vector that contains the number of coins used
                for each denomination if the program succeeds,
                empty otherwise.

  Time Complexity:
  O(nd), where n is the quantity to return in cash and d = |denominations|
*/
std::optional<std::vector<int>> minNumMonDP(int n) {
  // Memo contains pairs of  the form: (number of coins, previous state)
  std::vector<std::pair<int, int>> memo;
  memo.push_back(std::make_pair(0, 0));

  // Fill memo using DP
  for (int i = 1; i < n + 1; i++) {
    int state = -1;

    for (auto denomination : gl::denominations) {
      if (denomination > i)
        continue;

      int temp = i - denomination;
      state =
          (state == -1 || memo[temp].first < memo[state].first) ? temp : state;
    }

    // If a state cannot be reached, the program might fail: return empty option
    if (state == -1)
      return {};

    memo.push_back(std::make_pair(memo[state].first + 1, state));
  }

  // Encode solution:
  std::unordered_map<int, int> temp;

  for (auto denomination : gl::denominations)
    temp[denomination] = 0;

  int state = n;

  while (state != 0) {
    temp[state - memo[state].second]++;
    state = memo[state].second;
  }

  // Result vector
  std::vector<int> result(gl::denominations.size());

  for (int i = 0; i < gl::denominations.size(); i++) {
    result[i] = temp[gl::denominations[i]];
  }

  return result;
}

#endif
