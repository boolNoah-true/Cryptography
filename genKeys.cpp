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

    std::vector<std::vector<long long>> matrix(3, std::vector<long long>(3));

    std::vector<std::vector<long long>> inverse(3, std::vector<long long>(3));






    for(int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){

        }
    }




    if(choice == 1) {
        std::ifstream inputFile(path, std::ios::binary);

        if (!inputFile) {
            std::cerr << "Error opening file: " << path << std::endl;
            return{};
        }

        inputFile.read(reinterpret_cast<char*>(matrix[0].data()), 3 * 3 * sizeof(long long));

        inputFile.close();
        return matrix;
    } else {
        std::ifstream inputFile2(path, std::ios::binary);

        if (!inputFile2) {
            std::cerr << "Error opening file: " << path << std::endl;
            return{};
        }

        inputFile2.read(reinterpret_cast<char*>(inverse[0].data()), 3 * 3 * sizeof(long long));

        inputFile2.close();
        return inverse;
    }


}

void genKeys::writeKey(std::string path) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    linear lin;
    std::vector<std::vector<long long>> matrix = lin.generateMatrix();

    std::vector<std::vector<long long>> inverse = lin.inverse(matrix);



    std::string copy = path;
    std::string path1;
    std::string path2;
    std::string tail = "Public";
    std::string tail2 = "Private";

    path1 = path.insert(path.length()-4, tail);
    path2 = copy.insert(copy.length()-4, tail2);

    std::ofstream binaryFile(path1, std::ios::binary);

    if (!binaryFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            long long number = matrix[i][j];
            std::cout << matrix[i][j] << " ";
            binaryFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
        }
        std::cout << std::endl;
    }


    binaryFile.close();



    std::ofstream binaryFile2(path2, std::ios::binary);

    if (!binaryFile2) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            long long number = inverse[i][j];
            std::cout << "This is the inverse" << std::endl;
            std::cout << inverse[i][j] << " ";
            binaryFile2.write(reinterpret_cast<const char*>(&number), sizeof(number));
        }
        std::cout << std::endl;
    }


    binaryFile2.close();


}