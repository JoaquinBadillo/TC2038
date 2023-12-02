#ifndef SP_DIJKSTRA_H
#define SP_DIJKSTRA_H

#include <iostream>
#include <limits>
#include "reader.hpp"

namespace sp {
    /* Dijkstra's Algorithm
       
     * Find the shortest distance from source to all nodes
     * The graph is stored as a global variable.
     * A min heap is used as a priority queue.

     * @param source: the source node
     * @param print: print the distances from source to all nodes
     
     * Time complexity: O(E log V)
    */
    std::vector<int> distances(int source, bool print) {
        // Initialization
        MinHeap pq;
        std::vector<int> dist(nodes, INF);
        std::vector<bool> permanent(nodes, false);
        dist[source] = 0;

        pq.push(std::make_pair(0, source));

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            if (permanent[current.second])
                continue;

            permanent[current.second] = true;

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