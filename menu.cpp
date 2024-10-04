//
// Created by NoahP on 9/22/2024.
//

#include "menu.h"
#include "genKeys.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool menu::isValidPath(const std::string &path) {

    ofstream file(path, ios::binary);

    if(!file) {
        return false;
    }

    file.close();
    return true;

}

void menu::start(bool validInput) {

    genKeys gk;


    cout << "Matrix Encryption Software" << endl;
    cout << "---------------------------------------" << endl;

    if(!validInput) {
        cout<<endl;
        cout << "INVALID INPUT DETECTED!" << endl;
        cout << "PLEASE ENTER 1-4" << endl;
        cout << endl;
    }


    int userInput = 0;

    cout << "1. Generate Keys" << endl;
    cout << "2. Encrypt" << endl;
    cout << "3. Decrypt" << endl;
    cout << "4. Quit" << endl;

    cin >> userInput;

    switch (userInput) {
        case 1:
            string path;
            while (true) {
                path = "";
                cout << "Enter path for file" << endl;
                getline(cin, path);

                if (isValidPath(path)) {
                    cout << "Valid path. Ready to write the binary file." << endl;
                    break; // Exit loop if path is valid
                } else {
                    cerr << "Invalid path. Please enter a valid path." << endl;
                }
            }
            gk.writeKey(path);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
        default:
            start(false);
            break;
    }





}