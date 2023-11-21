#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <utility>
#include <functional>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

namespace search {
    typedef std::vector<std::vector<int>> Maze;
    typedef std::pair<int, int> Position;

    typedef struct Node {
        Position position;
        Position previous;
        int cost;
    } Node;

    struct Comparator {
        bool operator()(const Node &n1, const Node &n2) {
            return n1.cost > n2.cost;
        }
    };

    typedef std::priority_queue<Node, std::vector<Node>, Comparator> MinHeap;

    typedef std::vector<Position> Neighbors;

    Neighbors neighbors(const Maze &maze, const Position &position) {
        Neighbors neighbors;
        int N = maze.size();

        if (position.first > 0 && 
            maze[position.first - 1][position.second] == 1) {
            neighbors.push_back(std::make_pair(
                position.first - 1,
                position.second
            ));
        }
        
        if (position.second > 0 && 
            maze[position.first][position.second - 1] == 1) {
            neighbors.push_back(std::make_pair(
                position.first,
                position.second - 1
            ));
        }

        if (position.first < N - 1 && 
            maze[position.first + 1][position.second] == 1) {
            neighbors.push_back(std::make_pair(
                position.first + 1,
                position.second
            ));
        }

        if (position.second < N - 1 && 
            maze[position.first][position.second + 1] == 1) {
            neighbors.push_back(std::make_pair(
                position.first,
                position.second + 1
            ));
        }

        return neighbors;
    }

    typedef std::function<int(Position &)> Heuristic;
    void a_star(const Maze &maze, Heuristic heuristic) {
        MinHeap frontier;
        std::unordered_map<int, Node> visited;

        Node start = {
            .position = std::make_pair(0, 0),
            .previous = std::make_pair(-1, -1),
            .cost = 0};

        Position goal = std::make_pair(maze.size() - 1, maze.size() - 1);
        frontier.push(start);
        Node current;

        // Find path
        while (!frontier.empty()) {
            current = frontier.top();
            frontier.pop();

            if (current.position == goal)
                break;

            for (auto neighbor : neighbors(maze, current.position)) {
                int new_cost = current.cost + 1 + heuristic(neighbor);
                int index = neighbor.first * maze.size() + neighbor.second;

                if (visited.find(index) != visited.end() && visited[index].cost <= new_cost)
                    continue;

                Node next = {
                    .position = neighbor,
                    .previous = current.position,
                    .cost = new_cost
                };

                frontier.push(next);
                visited[index] = current;
            }
        }

        // Process results
        if (current.position != goal) {
            std::cout << "No path found" << std::endl;
            return;
        }

        std::vector<char> path;

        while (current.position != start.position) {
            Position pos = current.position;
            int index = pos.first * maze.size() + pos.second;
            Node previous = visited[index];
            Position prev = previous.position;

            if (prev.first == pos.first) {
                if (prev.second < pos.second)
                    path.push_back('R');
                else
                    path.push_back('L');
            }
            else {
                if (prev.first < pos.first)
                    path.push_back('D');
                else
                    path.push_back('U');
            }

            current = previous;
        }

        for (auto it = path.rbegin(); it != path.rend(); ++it)
            std::cout << *it;

        std::cout << std::endl;
    }

}

#endif