#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>

namespace gl {
  int cols;
  int rows;
  std::vector<int> maze;
  std::vector<int> btSolution;
  std::vector<int> bnbSolution;

  /* General Utilities for Global Variables */
  int getColumn(int index) {
    return index % gl::cols;
  }

  int getRow(int index) {
    return index / gl::cols;
  }

  bool solved(int node) {
    return node == gl::maze.size() - 1;
  }

  bool impossibleMaze() {
    return (
      gl::maze.size() == 0 || 
      gl::maze[0] == 0 || 
      gl::maze[gl::maze.size() - 1] == 0
    );
  }
}

#endif