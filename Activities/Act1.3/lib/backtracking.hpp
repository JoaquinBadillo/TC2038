/*
  Bactracking Solution Header File


  Last Update: 30 Sept 2023
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

void backtracking() {
  if (gl::impossibleMaze())
    return;
  
  std::unordered_set<int> visited;
  bt::backtracking(0, &visited);
}

namespace bt {
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

  void saveSolution(std::unordered_set<int> *v) {
    for (int i = 0; i < gl::maze.size(); i++)
      gl::btSolution.push_back(v -> find(i) != v -> end() ? 1 : 0);
  }

  bool promissory(int node, const std::unordered_set<int> &visited) {
    return gl::maze[node] == 1 && visited.find(node) == visited.end();
  }

  /*
    Returns promissory children of a node.
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