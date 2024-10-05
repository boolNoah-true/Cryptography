//
// Created by NoahP on 9/22/2024.
//

#include "decrypt.h"
#include "genKeys.h"
#include "linear.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
void decrypt::decryptText(const string& path) {

    genKeys gk;
    linear lin;

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
    string keyPath;
    cout << "Enter path to the private key" << endl;
    getline(cin, keyPath);


    vector<vector<long long>> matrix = gk.readKey(keyPath, 0);


    for (int i = 0; i < v.size(); ++i) {
        v[i] = lin.multiply(matrix, v[i]);
        cout << v[i][1] << " ";
    }

    string cipher;

    for (int i = 0; i < v.size(); ++i){
        cout << v[1][i] <<endl;
        long long j = (v[1][i])/100;


        char c = static_cast<int>(j) + '0';
        cipher += c;

    }

    cout << "This text reads as follows: " << endl;

    cout << cipher << endl;


}