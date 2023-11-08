#ifndef SP_DIJKSTRA_H
#define SP_DIJKSTRA_H

#include <iostream>
#include <limits>
#include "reader.hpp"

namespace sp {
    std::vector<int> distances(int source, bool print) {
        // Initialization
        MinHeap pq;
        std::vector<int> dist(nodes, INF);
        dist[source] = 0;

        pq.push(std::make_pair(0, source));

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            for (auto& [destination, weight] : graph[current.second]) {
                if (dist[destination] > dist[current.second] + weight) {
                    dist[destination] = dist[current.second] + weight;
                    pq.push(std::make_pair(dist[destination], destination));
                }
            }
        }

        if (print) {
            for (int i = 0; i < nodes; ++i) {
                if (i == source)
                    continue;

                std::cout 
                    << "Node " 
                    << source + 1 
                    << " to node "
                    << i + 1
                    << ": " 
                    << (dist[i] == INF ? "INF" : std::to_string(dist[i]))
                    << std::endl;
            }
        }

        return dist;
    }

}

#endif