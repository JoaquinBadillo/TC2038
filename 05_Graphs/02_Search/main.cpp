#include "./lib/search.hpp"

int main(int argc, char const *argv[]) {
    search::Maze maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    search::Heuristic heuristic = [](search::Position& position) {
        return 0;
    };

    search::a_star(maze, heuristic);

    return 0;
}
