/*
  Driver Program

  Simple entry point to use the greedy and dp algorithms
  to determine which denominations and how many of these
  should be returned to a client as change.

  Author: Joaquin Badillo
  Last Update: 28/Sept/2023
*/

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
    std::cout << "Escribe el número de denominaciones (n): ";
    std::cin >> n;
  }

  std::cout << "Escribe sus valores (en orden desc. y una por línea):\n";

  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;

    gl::denominations.push_back(val);
  }

  std::cout << "Denominaciones almacenadas." << std::endl;
  std::cout << "Escribe el precio del producto: ";
  std::cin >> price;

  std::cout << "Escriba la catidad pagada: ";
  std::cin >> payment;

  escribeRespuesta(payment - price);
  return 0;
}
