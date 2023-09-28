/*
  Greedy Approach Header File

  Determines thenumber of coins to use
  given a set of denomination and a value to pay,
  using a Greedy Approach.

  * The algorithm is incorrect when trying to find
    the minimum number of coins as it may fail. *

  Author: Joaquín Badillo A01026364
  Last Update: 27/Sept/2023
*/

#ifndef GREEDY_H
#define GREEDY_H

#include "./global.hpp"
#include <optional>
#include <vector>

/*
 Minimum Number of Coins

 Implementation of a greedy approach to give out change with
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
  O(d), where d = |denomniations|
*/
std::optional<std::vector<int>> minNumMonGR(int n) {
  std::vector<int> result(gl::denominations.size(), 0);
  int current = 0;
  int sum = 0;

  while (sum != n) {
    if (current == gl::denominations.size()) {
      return {};
    } else if (gl::denominations[current] <= n - sum) {
      result[current] += (n - sum) / gl::denominations[current];
      sum += result[current] * gl::denominations[current];
    }

    current++;
  }

  return result;
}

#endif
