/*
  Bactracking Solution Header File

  Functions to find a solution to the maze using a backtracking 
  algorithm.

  Last Update: 09 Oct 2023
  Author: Joaquín Badillo
*/

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <vector>
#include <unordered_set>
#include "./global.hpp"

void backtracking();

namespace bt {
  void backtracking(int node, std::unordered_set<int> *visited);
  std::vector<int> getChildren(int node, const std::unordered_set<int> &visited);
  bool promissory(int node, const std::unordered_set<int> &visited);
  void saveSolution(std::unordered_set<int> *visited);
}

/* Backtracking 

  Solves the maze using a backtracking algorithm.

  Side effect function: () => void
  No params, no returns.

  Time Complexity:
  O(NM) - Same as inner function backtracking(int, unordered_set<int>*)
*/
void backtracking() {
  if (gl::impossibleMaze())
    return;
  
  std::unordered_set<int> visited;
  bt::backtracking(0, &visited);
}

namespace bt {
  /* Backtracking

    Function to execute the recursion of the backtracking algorithm.

    Params:
    int node - The current node (index on the vector)
    std::unordered_set<int> *visited - The already visited nodes

    Returns:
    void - Saves results to global variable (gl::btSolution)

    Time Complexity:
    Since the children are only the nodes that have not been visited yet,
    the recursion will execute at most NM times (where the maze is a N x M matrix).

    Inserting and deleting from the set take constant time, so does checking the solution.
    Saving the solution is done once and takes O(NM) time.

    Therefore the order is:
    O(NM)
  */
  void backtracking(int node, std::unordered_set<int> *visited) {
    visited -> insert(node);

    if (gl::solved(node)) {
      bt::saveSolution(visited);
      return;
    }
    
    std::vector<int> children = bt::getChildren(node, *visited);
    for (int child : children)
      bt::backtracking(child, visited);

    visited -> erase(node);
  }

  /* Save Solution
    Saves the set of visisted nodes to the global variable gl::btSolution.

    Params:
    std::unordered_set<int> *v - The set of visited nodes

    Returns:
    void - Saves results to global variable (gl::btSolution) 

    Time Complexity:
    O(NM), as it iterates through the whole maze.
  */
  void saveSolution(std::unordered_set<int> *v) {
    for (int i = 0; i < gl::maze.size(); i++)
      gl::btSolution.push_back(v -> find(i) != v -> end() ? 1 : 0);
  }

  /* Promissory 
       
    Returns whether a node is promissory or not.
    A node is promissory if it is traversable (contains 1)
    and has not been visited yet.

    Params:
    int node - The node to check (index of vector)
    std::unordered_set<int> *visited - The already visited nodes

    Returns:
    bool - Whether the node is promissory or not

    Time Complexity:
    O(1)
  */
  bool promissory(int node, const std::unordered_set<int> &visited) {
    return gl::maze[node] == 1 && visited.find(node) == visited.end();
  }

  /* Get Children

    Returns promissory children of a node.

    Params:
    int node - The node to get the children of (index of vector)
    std::unordered_set<int> *visited - The already visited nodes

    Returns:
    vector<int> - A vector containing the children (indexes) of the node

    Time Complexity:
    O(1)
  */
  std::vector<int> getChildren(int node, const std::unordered_set<int> &visited) {
    std::vector<int> res;

    int pos[]  = {gl::getRow(node), gl::getColumn(node)};
    int limit[] = {gl::rows - 1, gl::cols - 1};
    
    for (int i = 0; i < 2; i++) {
      int shift = i == 0 ? gl::cols : 1;
      
      if (pos[i] != 0) {
        int child = node - shift;
        if (bt::promissory(child, visited))
          res.push_back(child);
      }

      if (pos[i] < limit[i]) {
        int child = node + shift;
        if (bt::promissory(child, visited))
          res.push_back(child);
      }
    }

    return res;
  }
}

#endif