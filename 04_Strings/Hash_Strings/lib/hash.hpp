/* 
    Hash Header File

    Includes a function: hashFile(string, int) => string,
    that hashes a file using the algorithm described in the 
    assignment.

    Author: Joaquín Badillo A01026364
    Last Update: 14/Oct/2023
*/

#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>

std::string hashFile(const std::string &filename, int n) {
    std::ifstream file;
    file.open(filename);

    // The table is not required, but the assignment asks for it.
    std::vector<std::vector<char>> table;
    std::vector<int> results(n, 0);
    
    if (file.is_open()) {
        char c;
        int i = 0;
        while (file.get(c)) {
            if (i == 0)
                table.push_back(std::vector<char>());

            table[table.size() - 1].push_back(c);
            results[i] += c % 256;

            i = (i + 1) % n;
        }

        if (i != 0) {
            std::string padding = std::to_string(n);
            while (i != 0) {
                for (auto c : padding) {
                    if (i == 0) break;
                    table[table.size() - 1].push_back(c);
                    results[i] += c % 256;
                    i = (i + 1) % n;
                }
            }
        }
        file.close();
    }

    std::stringstream stream;
    for (int i : results) {
        stream << std::hex 
        << std::uppercase
        << std::setfill('0')
        << std::setw(2)
        << i % 256;
    }    

    return stream.str();
}


#endif
