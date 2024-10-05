//
// Created by NoahP on 9/22/2024.
//

#include "encrypt.h"
#include "breakString.h"
#include "linear.h"
#include "genKeys.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool encrypt::isValidPath(const std::string &path) {

    ofstream file(path, ios::binary);

    if(!file) {
        return false;
    }

    file.close();
    return true;

}


void encrypt::encryptText(const string& path, const string& s) {
    breakString bs;
    linear lin;
    ofstream file(path);
    genKeys gk;

    if(!file.is_open()) {
        cerr << "Failed to open file: " << path << endl;
        return;
    }
    string keyPath;
    cout << "Enter path to the public key" << endl;
    getline(cin, keyPath);

    vector<vector<long long>> matrix = gk.readKey(keyPath, 1);
    vector<vector<long long>> vec = bs.breakS(s);

    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = lin.multiply(matrix, vec[i]);
    }

    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            file << vec[i][j] << " ";
        }
    }


    file.close();

    cout << "Data successfully encrypted " << endl;

}
