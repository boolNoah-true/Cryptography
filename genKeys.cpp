//
// Created by NoahP on 9/21/2024.
//

#include "genKeys.h"
#include "linear.h"

#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>

std::vector<std::vector<long long>> genKeys::readKey(std::string path, int choice) {
    linear lin;

    std::vector<std::vector<long long>> matrix = lin.generateMatrix();

    std::vector<std::vector<long long>> inverse = lin.inverse(matrix);



    for(int i=0)




    if(choice == 1) {
        return matrix;
    } else {
        return inverse;
    }


}

std::vector<std::vector<long long>> genKeys::writeKey(std::string path) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    linear lin;
    std::vector<std::vector<long long>> matrix = lin.generateMatrix();

    std::vector<std::vector<long long>> inverse = lin.inverse(matrix);

    long long scalar = std::rand() % 1000 + 1;

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

    std::ofstream binaryFile2("privKey.bin", std::ios::binary);

    if (!binaryFile2) {
        std::cerr << "Error opening file!" << std::endl;
        return {};
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            long long number = inverse[i][j];

            binaryFile2.write(reinterpret_cast<const char*>(&number), sizeof(number));
        }
    }


    binaryFile2.close();

    return matrix;
}