//
// Created by nplusplus on 9/30/24.
//

#include "breakString.h"
#include <iostream>
#include <ctime>


std::vector<std::vector<int>> breakString::breakS (const std::string& s) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::vector<int>> list;



    for (char c : s) {
        int i = c - '0';
        std::vector<int> row = {std::rand() % 1000 + 1, (i*100) + std::rand() % 99 + 0, std::rand() % 1000 + 1};
        list.push_back(row);
    }



    return list;

}