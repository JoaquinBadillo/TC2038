#ifndef READER_H
#define READER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<int> leeDatos(std::string nombreArchivo);
void imprimeDatos(std::vector<int> &datos);

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

void imprimeDatos(std::vector<int> &data) {
    // iterate over the vector and print each element separated by spaces
    for (auto i : data)
        std::cout << i << " ";

    std::cout << std::endl;
}

#endif
