//
// Created by NoahP on 9/21/2024.
//

#include "genKeys.h"
#include "linear.h"

#include <iostream>
#include <ctime>
#include <fstream>

std::vector<std::vector<long long>> genKeys::readKey(std::string path) {}

std::vector<std::vector<long long>> genKeys::writeKey(std::string path) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    linear lin;
    std::vector<std::vector<long long>> matrix = lin.generateMatrix();

    std::vector<std::vector<long long>> inverse = lin.inverse(matrix);

    int scalar = std::rand() % 1000 + 1;

    std::ofstream binaryFile("pubKey.bin", std::ios::binary);

    if (!binaryFile) {
        std::cerr << "Error opening file!" << std::endl;
        return {};
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            long long number = matrix[i][j] * scalar;

            binaryFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
        }
    }


    binaryFile.close();



    return matrix;
}