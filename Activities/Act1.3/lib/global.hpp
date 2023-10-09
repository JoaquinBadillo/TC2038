/*
  Global Namespace Header File

  Global variables and general utilities to handle them.

  Author: Joaquín Badillo A01026364
  Last Update: 09 Oct 2023
*/

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
  
  /* Get Column 

    Gets the column (in the matrix representation) of a node given 
    its index (vector representation).

    Params:
    int index - The index of the node in the vector representation

    Returns:
    int - The column of the node in the matrix representation

    Time Complexity:
    O(1)
  */
  int getColumn(int index) {
    return index % gl::cols;
  }

  /* Get Row 

    Gets the row (in the matrix representation) of a node given 
    its index (vector representation).

    Params:
    int index - The index of the node in the vector representation

    Returns:
    int - The row of the node in the matrix representation

    Time Complexity:
    O(1)
  */
  int getRow(int index) {
    return index / gl::cols;
  }

  /* Solved

    Checks if the maze is solved: if the last node is reached.

    Params:
    int node - The node to check (index of vector)

    Returns:
    bool - Whether the maze is solved or not

    Time Complexity:
    O(1)
  */
  bool solved(int node) {
    return node == gl::maze.size() - 1;
  }

  /* Impossible Maze

    Checks if the maze is impossible: if the maze is empty or if the
    first or last node are blocked.

    Returns:
    bool - Whether the maze is impossible or not

    Time Complexity:
    O(1)
  */
  bool impossibleMaze() {
    return (
      gl::maze.size() == 0 || 
      gl::maze[0] == 0 || 
      gl::maze[gl::maze.size() - 1] == 0
    );
  }
}

#endif