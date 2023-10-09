/*
  Driver Program


*/

#include "./lib/io.hpp"
#include "./lib/backtracking.hpp"
#include "./lib/bnb.hpp"

int main(int argc, char *argv[]) { 
  std::string file;
  file = (argc > 1) ? argv[1] : "datos.txt";

  leeArchivo(file);
  backtracking();
  branchAndBound();
  imprimeSolucion();

}
