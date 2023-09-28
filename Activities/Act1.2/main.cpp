#include "./lib/global.hpp"
#include "./lib/solution.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  int n;
  int price;
  int payment;

  if (argc > 1) {
    n = std::stoi(argv[1]);
  } else {
    std::cout << "Enter the value of n: ";
    std::cin >> n;
  }

  std::cout << "Enter the values (in order and one per line):\n";

  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;

    gl::denominations.push_back(val);
  }

  std::cout << "Denominations saved." << std::endl;
  std::cout << "Write the price of the product: ";
  std::cin >> price;

  std::cout << "Write the quantity paid: ";
  std::cin >> payment;

  escribeRespuesta(payment - price);
  return 0;
}
