/*
  Bactracking Solution Header File


  Last Update: 30 Sept 2023
  Author: Joaquín Badillo
*/

#include <utility>
#include <vector>

int N;

struct pairToInt {
  size_t operator(const std::pair<int, int> x) const {
    return x.first * N + x.second;
  }
}

std::vector<int>
backtracking();
bool solved(std::pair<int, int> node);
std::vector<std::pair<int, int>> children(std::pair<int, int> node);
bool promissory(std::pair<int, int> node);
