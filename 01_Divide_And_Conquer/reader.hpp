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
    
    if (file.is_open()){
        std::string line;
        std::getline(file, line);
        int records = std::stoi(line);
        
        for (int i = 0; i < records; i++){
            std::getline(file, line);
            data.push_back(std::stoi(line));
        }

        file.close();
    }

    return data;
}

void imprimeDatos(std::vector<int> &data) {
    for (auto i : data)
        std::cout << i << " ";

    std::cout << std::endl;
}

#endif
