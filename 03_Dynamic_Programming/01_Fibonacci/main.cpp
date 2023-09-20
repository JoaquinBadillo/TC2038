/*
  Fibonacci Dynamic Programming
  Driver Code
*/

#include "./lib/fib.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;

  if (argc > 1) {
    n = std::stoi(argv[1]);
  }

  std::cout << fib(n) << std::endl;

  return 0;
}
