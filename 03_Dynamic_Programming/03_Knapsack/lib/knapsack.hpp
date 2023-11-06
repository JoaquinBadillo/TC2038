#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <utility>
#include <optional>

typedef std::optional<std::pair<std::vector<int>, int>> result;

result knapsack(int capacity, const std::vector<int> &values, const std::vector<int> &weights) {
  int n = values.size();  
  if (n != weights.size())
    return std::nullopt;
  
  int memo[n + 1][capacity + 1];
  
  for (int i = 0; i <= n; i++)
    memo[0][i] = 0;

  for (int i = 0; i <= capacity; i++)
    memo[i][0] = 0;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= capacity; j++) {
      if (weights[i] > j)
        memo[i + 1][j] = memo[i][j];
      else
        memo[i + 1][j] = std::max(memo[i][j], memo[i][j - weights[i]] + values[i]);
    }
  }

  int value = memo[n][capacity];

  std::vector<int> items(n, 0);
  for(int i = n; i > 0; i--) {
    if (memo[i][capacity] == 0)
      break;

    if (memo[i][capacity] != memo[i - 1][capacity]) {
      items[i - 1] = 1;
      capacity -= weights[i - 1];
    }
  }

  return std::make_pair(items, value);
}

#endif
