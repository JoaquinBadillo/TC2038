#include <iostream>
#include "./lib/knapsack.hpp"

int main(int argc, char const *argv[]){
  std::vector<int> values = { 30, 14, 16, 9 };
	std::vector<int> weights = { 6, 3, 4, 2 };

	result r = knapsack(10, values, weights);

	if (!r.has_value()) {
		std::cerr << "No solution found" << std::endl;
		return 1;
	}

	std::pair<std::vector<int>, int> p = r.value();

	std::cout 
		<< "Value: " 
		<< p.second 
		<< std::endl;

	std::cout << "[";
	for (int i = 0; i < p.first.size(); i++) {

  return 0;
}
