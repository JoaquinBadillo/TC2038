#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <limits>

// Type definitions, declaration for INF and a comparator for a minheap
namespace sp {
    typedef std::pair<int, int> Node;

    struct comparator {
        bool operator()(const Node& p1, const Node& p2) {
            return p1.first > p2.first;
        }
    };

    typedef std::vector<std::unordered_map<int, int>> Graph;
    typedef std::vector<std::vector<int>> AdjMatrix;
    typedef std::priority_queue<Node, std::vector<Node>, comparator> MinHeap;
    int INF = std::numeric_limits<int>::max();
}

#endif