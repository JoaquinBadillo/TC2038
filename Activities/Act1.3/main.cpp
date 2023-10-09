/*
  Driver Program

  Contains the main function to execute the program.

  Author: Joaquín Badillo A01026364
  Last Update: 09 Oct 2023
*/

#include "./lib/io.hpp"
#include "./lib/backtracking.hpp"
#include "./lib/bnb.hpp"

/* Main - Entry Point
  Reads the file, executes the algorithms and prints the solution.

  Params:
  int argc - The number of arguments passed to the program
  char *argv[] - The arguments passed to the program

  Returns:
  int - Status (0 if the program executed successfully).
*/
int main(int argc, char *argv[]) { 
  std::string file;
  file = (argc > 1) ? argv[1] : "datos.txt";

  leeArchivo(file);
  backtracking();
  branchAndBound();
  imprimeSolucion();

  return 0;
}
