#ifndef SOLUTION_H
#define SOULTION_H
#include "./dp.hpp"
#include "./global.hpp"
#include "./greedy.hpp"

#include <iostream>
#include <optional>
#include <vector>

void printRes(const std::optional<std::vector<int>> &res) {
  if (!res.has_value()) {
    std::cout << "Failed to get change\n";
    return;
  }

  int i = 0;

  for (int val : *res) {
    if (val > 0) {
      std::cout << val << (val > 1 ? " monedas " : " moneda");
      std::cout << "de ";
      std::cout << gl::denominations[i] << std::endl;
    }
    i++;
  }
}

void escribeRespuesta(int n) {
  std::optional<std::vector<int>> res1 = minNumMonGR(n);
  printRes(res1);
}

#endif
