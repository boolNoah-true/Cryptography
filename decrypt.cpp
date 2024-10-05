//
// Created by NoahP on 9/22/2024.
//

#include "decrypt.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
void decryptText(const string& path) {

    ifstream inputFile(path);
    vector<vector<long long>> v;
    vector<long long> row;
    if(!inputFile) {
        cerr << "Error opening file: " << path << endl;

        return;
    }
    long long num;
    int i = 0;
    while(inputFile >> num) {
        if(i == 2) {
            row.push_back(num);
            v.push_back(row);
            row.clear();
        }
        else {
            row.push_back(num);
            i++;
        }

    }





}