#ifndef SP_FLOYD_H
#define SP_FLOYD_H

#include "utils.hpp"
#include "reader.hpp"

namespace sp {

    void floyd(bool print) {
        AdjMatrix dist(nodes, std::vector<int>(nodes));

        // Build the adjacency matrix
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                if (i == j)
                    dist[i][j] = 0;
                else if (graph[i].find(j) != graph[i].end())
                    dist[i][j] = graph[i][j];
                else
                    dist[i][j] = INF;
            }
        }

        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                for (int k = 0; k < nodes; ++k) {
                    // Avoid overflow
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        if (print) {
            for (auto& row : dist) {
                for (auto& col : row) {
                    std::cout << (col == INF ? "INF" : std::to_string(col)) << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}

#endif