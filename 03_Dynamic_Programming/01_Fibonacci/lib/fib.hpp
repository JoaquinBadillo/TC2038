/*
  Fibonacci Numbers using Memoization
*/

#include <unordered_map>

namespace dp {
std::unordered_map<int, int> memo = {{0, 0}, {1, 1}};
}

int fib(int n) {
  auto found = dp::memo.find(n);
  if (found != dp::memo.end())
    return found->second;

  int f = fib(n - 1) + fib(n - 2);
  dp::memo[n] = f;

  return f;
}
