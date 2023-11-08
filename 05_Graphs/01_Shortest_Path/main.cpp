#include "./lib/dijkstra.hpp"
#include "lib/floyd.hpp"

int main(int argc, char const *argv[]) {
    sp::init("input.txt");

    std::cout << "Dijkstra:" << std::endl;
    for(int i = 0; i < sp::nodes; ++i)
        sp::distances(i, true);
    
    std::cout << "\nFloyd:" << std::endl;
    sp::floyd(true);

    return 0;
}
