/* 
    Driver Program

    Contains the entry point of the program, which
    receives the filename and the number of columns to use 
    when hashing (n). It then uses the hashFile function to
    show in the standard output the hash of the file.

    Author: Joaquín Badillo A01026364
    Last Update: 14/Oct/2023
*/

#include <iostream>
#include <string>
#include "./lib/hash.hpp"

int main(int argc, char *argv[]) {
  int n = 16;
  std::string filename = "datos.txt";
  
  if (argc > 1)
    filename = argv[1];

  if (argc > 2)
    n = std::stoi(argv[2]);

  std::cout << hashFile(filename, n) << std::endl;
  return 0;
}