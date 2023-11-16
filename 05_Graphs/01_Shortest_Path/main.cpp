#include "./lib/dijkstra.hpp"
#include "lib/floyd.hpp"

int main(int argc, char const *argv[]) {
    std::string filename = "input.txt";

    if (argc > 1)
        filename = argv[1];

    sp::init(filename);

    if (sp::nodes == 0)
        return 0;

    std::cout << "Dijkstra:" << std::endl;
    for(int i = 0; i < sp::nodes; ++i)
        sp::distances(i, true);
    
    std::cout << "\nFloyd:" << std::endl;
    sp::floyd(true);

    return 0;
}
