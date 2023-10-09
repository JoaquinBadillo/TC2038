/*
  Branch and Bound Header File

  Functions to find an optimal solution to the maze using a branch 
  and bound algorithm.

  Author: Joaquín Badillo A01026364
  Last Update: 09 Oct 2023
*/

#ifndef BNB_H
#define BNB_H

#include "./global.hpp"
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <limits>

#define MAX std::numeric_limits<int>::max()

void branchAndBound();

namespace bnb { 
  typedef struct node {
    int index;
    int bound;
    int prev;
    int steps;
  } node;

  // Used to construct min heap of nodes
  struct compare {
    bool operator()(node const& u, node const& v) const {
        return u.bound > v.bound;
    }
  };

  int bound(int node, int steps);
  bool promissory(int node, int steps);
  std::vector<int> getChildren(int node);
  void saveSolution(const std::unordered_map<int, bnb::node> &visited);
}

/* Branch And Bound
  
  Solves the maze using a branch and bound algorithm.
  Besides using the bounding function it also reduces the 
  search space by cutting branches where nodes have already
  been visited.

  Side effect function: () => void
  No params, no returns.

  Time Complexity:
  Since we exclude already visted nodes, in the worst case
  we will have to visit all nodes in the maze.
  Thus the while loop exectues at most NM times, since
  that is the number of nodes in the maze.

  Similarly to simplify the analysis, the frontier will have
  at most NM nodes (this might not be a tight bound). And thus
  the push and pop operations will have a time complexity of O(lg(NM)).
  Since there are at most 3 children per node that are not cut off.

  => The while loop has a time complexity of O(NM * lg(NM)).
  
  Finally since the amount of visited nodes is at most NM, saving the solution
  takes O(NM) time, which means that this whole function has the order of growth:

  O(NM * lg(NM))
*/
void branchAndBound() {
  if (gl::impossibleMaze())
    return;
  
  int best = MAX;
  std::unordered_map<int, bnb::node> visited;
  std::priority_queue<bnb::node, std::vector<bnb::node>, bnb::compare> frontier;
  
  // Initialize frontier
  frontier.push({
    index: 0, 
    bound: bnb::bound(0, 0), 
    prev: -1, 
    steps: 0
  });

  while (!frontier.empty()) {
    // Best node - O(lg(n))
    bnb::node current = frontier.top();
    frontier.pop();

    // Cut branch using bounding function
    if (current.bound > best) 
      continue;

    // Add node to visited
    visited[current.index] = current;

    // Update best if node is solved
    if (gl::solved(current.index)) {
      best = current.steps;
      continue;
    }

    // Add children to frontier
    std::vector<int> children = bnb::getChildren(current.index);
    for (int child : children) {
      // Cut branches if the node has been already visited
      if (visited.find(child) == visited.end()) {
        frontier.push({
          index: child,
          bound: bnb::bound(child, current.steps + 1),
          prev: current.index,
          steps: current.steps + 1
        });
      }
    }
  }

  // Save solution only if it exists
  if (best != MAX)
    bnb::saveSolution(visited);
}

// Branch and bound utilities
namespace bnb {
  /* Bound 

    The bound is obtained by relaxing the optimization problem. 
    It is calculated as the sum of the remaining steps to the goal, 
    ignoring the fact that the path might be blocked 

    Params:
      node: index of the node to calculate the bound for
      steps: number of steps taken to reach the node

    Returns:
      The bound for the node

    Time Complexity:
      O(1)
  */
  int bound(int node, int steps) {
    int pos[]  = {gl::getRow(node), gl::getColumn(node)};
    int limit[] = {gl::rows - 1, gl::cols - 1};
    return (limit[0] - pos[0]) + (limit[1] - pos[1]) + steps;
  }

  /* Get Children
    Returns the children of a node (not blocked neighbors)

    Params:
      node: index of the node to calculate the bound for

    Returns:
      A vector containing the children of the node

    Time Complexity:
      O(1)
  */
  std::vector<int> getChildren(int node) {
    std::vector<int> res;  
    int pos[]  = {gl::getRow(node), gl::getColumn(node)};
    int limit[] = {gl::rows - 1, gl::cols - 1};
    
    for (int i = 0; i < 2; i++) {
      int shift = i == 0 ? gl::cols : 1;
      
      if (pos[i] != 0) {
        int child = node - shift;
        if (gl::maze[child] == 1)
          res.push_back(node - shift);
      }

      if (pos[i] < limit[i]) {
        int child = node + shift;
        if (gl::maze[child] == 1)
          res.push_back(child);
      }
    } 

    return res;
  }

  /* Save Solution
    Saves the solution to the global variable bnbSolution

    Params:
      visited: a map containing the visited nodes

    Time Complexity:
      O(n), where n is the size of the hash map
  */
  void saveSolution(const std::unordered_map<int, bnb::node> &visited) {
    int node = gl::maze.size() - 1;
    std::vector<int> path(gl::maze.size() - 1, 0);

    while (node != -1) {
      auto it = visited.find(node);

      if (it == visited.end())
        break;
      
      path[node] = 1;
      node = it -> second.prev;
    }

    for (int i : path)
      gl::bnbSolution.push_back(i);
    
    // Push last node
    gl::bnbSolution.push_back(1);
  }
}

#endif