/*
  Solutions Header File

  Executes the greedy and dynamic programming algorithms, then prints the
  solutions.

  Author: Joaquín Badillo A01026364
  Last Update: 27/Sept/2023
*/

#ifndef SOLUTION_H
#define SOULTION_H
#include "./dp.hpp"
#include "./global.hpp"
#include "./greedy.hpp"

#include <iostream>
#include <optional>
#include <utility>
#include <vector>

/*
  Print Result

  Gets an optional vector containing the number of coins used per
  denomination and formats the expected output in the standard output.

  Params:
  vector<int>? data: vector with denominations used

  Returns:
  void (side-effect function)

  Time Complexity:
  O(n), where n is the size of the vector
*/
void printRes(const std::optional<std::vector<int>> &res) {
  if (!res.has_value()) {
    std::cout << "Failed to get change\n";
    return;
  }

  int i = 0;

  // Loop to display only the coins that are used (greater than 0)
  for (int val : *res) {
    if (val > 0) {
      std::cout << val << (val > 1 ? " monedas " : " moneda ");
      std::cout << "de ";
      std::cout << gl::denominations[i] << std::endl;
    }
    i++;
  }
}

/*
  Write Results

  Gets a value representing the quantity to pay and uses
  both the Greedy and DP approaches to print the denominations
  to use.

  Params:
  int n - The quantity to return in cash

  Returns:
  void (side-effect function)

  Time Complexity:
  O(nd), where n is the quantity to pay and d = |denominations|
*/
void escribeRespuesta(int n) {
  std::optional<std::vector<int>> res1 = minNumMonGR(n);
  std::cout << "Usando Greedy\n";
  printRes(res1);

  std::cout << "Usando DP\n";
  std::optional<std::vector<int>> res2 = minNumMonDP(n);
  printRes(res2);
}

#endif
