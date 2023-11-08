#ifndef READER_H
#define READER_H

#include <fstream>
#include <iostream>
#include <string>

#include "./utils.hpp"

namespace sp {
    Graph graph;
    int nodes;
    int edges;

    void init(std::string filename) {
        std::ifstream file;
        file.open(filename);

        if (!file.is_open()) {
            std::cout << "Error: File not found" << std::endl;
            return;
        }

        std::string line;

        std::getline(file, line, ' ');
        nodes = std::stoi(line);

        std::getline(file, line);
        edges = std::stoi(line);

        for (int i = 0; i < nodes; ++i)
            graph.push_back(std::unordered_map<int, int>());

        for (int i = 0; i < edges; ++i) {
            std::getline(file, line, ' ');
            int src = std::stoi(line);

            std::getline(file, line, ' ');
            int dest = std::stoi(line);

            std::getline(file, line);
            int weight = std::stoi(line);

            graph[src][dest] = weight;
        }

        file.close();
    }
}

#endif