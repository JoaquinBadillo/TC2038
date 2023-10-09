/*
  Input/Output Header File

  Contains functions to read a text input file containing
  a maze and to print the solution to the maze using
  global variables.

  Author: Joaquín Badillo A0102634
  Last update: 08/Oct/2023
*/

#ifndef IO_H
#define IO_H

#include <fstream>
#include <iostream>
#include <string>

#include "global.hpp"

void leeArchivo(std::string file);
void imprimeSolucion();

/* File reader
  
  Reads a text file containing a maze and saves it to
  global variables.

  Params:
  std::string inFile - The name of the file to read

  Returns:
  void - Saves results to global variables (gl::rows, gl::cols, gl::maze)

  Time Complexity:
  O(NM), where N is the number of lines and M is the number of characters to read.
*/
void leeArchivo(std::string inFile) {
  std::ifstream file;
  file.open(inFile);

  if (file.is_open()) {
    std::string line;

    std::getline(file, line, ' ');
    gl::rows = std::stoi(line);

    std::getline(file, line);
    gl::cols = std::stoi(line);
  
    for (int row = 0; row < gl::rows; row++) {
      for (int col = 0; col < gl::cols - 1; col++) {
        std::getline(file, line, ' ');
        gl::maze.push_back(std::stoi(line));
      }

      std::getline(file, line);
      gl::maze.push_back(std::stoi(line));
    }

    file.close();
  }
}

/* Print as Matrix

  Outputs a vector as the desired matrix to 
  the standard output.

  Params:
  std::vector<int> v - The vector to print

  Returns:
  void - (side effect).

  Time Complexity:
  O(|v|), where |v| is the size of the vector.
*/
void printAsMatrix(const std::vector<int> &v) {
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << (gl::getColumn(i) == gl::cols - 1 ? "\n" : " "); 
}

/* Solution Printer

  Prints the solution to the maze using the global variables
  gl::btSolution and gl::bnbSolution.

  Side effect function: () => void
  No params, no returns.

  Time Complexity:
  O(NM), where N is the number of rows and M is the number of columns.
*/
void imprimeSolucion() {
  if (gl::btSolution.size() == 0) {
    std::cout << "No hay solución." << std::endl;
    return;
  }

  printAsMatrix(gl::btSolution);
  std::cout << std::endl;
  printAsMatrix(gl::bnbSolution);
}

#endif
