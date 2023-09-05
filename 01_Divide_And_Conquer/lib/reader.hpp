/* 
  File Reader Header File
  
  Contains functions to read a text input file:
   The input has the number of records in the first 
   line, followed by a list of integers (separated by 
   linebreaks) and returns a vector with the data.
  
  It also contains a function to print the contents of 
  a vector.
  
  Author: Joaquín Badillo A0102634
  Last update: 04/Sept/2023
*/

#ifndef READER_H
#define READER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<int> leeDatos(std::string nombreArchivo);
void imprimeDatos(std::vector<int> &datos);

/*
  Data Reader
  Reads a text file as specified in the problem statement and 
  returns a vector with the data.
  
  Params:
  std::string inFile: name of the file to be read
  
  Returns:
  std::vector<int>: vector with the data read from the file
  
  Time Complexity:
  O(nm) where n is the number of records in the file and m is
  the longest string of digits read.
*/
std::vector<int> leeDatos(std::string inFile) {
    std::vector<int> data;
    std::ifstream file;
    
    file.open(inFile);
    
    // Check if file is open to read contents (it may not be open if it doesn't exist)
    if (file.is_open()) {
        std::string line;

        // According to the problem statement, the first line is the number of records
        std::getline(file, line);
        int records = std::stoi(line);
        
        // Read the records
        for (int i = 0; i < records; i++){
            std::getline(file, line);
            data.push_back(std::stoi(line));
        }

        file.close();
    }

    return data;
}

/*
  Data Printer
  Prints the contents of a vector to the console.
  
  Params:
  std::vector<int> data: vector to be printed
  
  Returns:
  void (its a side effect function)
  
  Time Complexity:
  O(nm) where n is the number of elements in the vector and 
  m is the longest string of digits to be printed.
*/
void imprimeDatos(std::vector<int> &data) {
    // iterate over the vector and print each element separated by spaces
    for (auto i : data)
        std::cout << i << " ";

    std::cout << std::endl;
}

#endif
