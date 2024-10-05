//
// Created by NoahP on 9/22/2024.
//

#include "menu.h"
#include "genKeys.h"
#include "encrypt.h"
#include "decrypt.h"

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;



void menu::start(bool validInput) {

    genKeys gk;
    encrypt enc;
    decrypt dec;

    cout << "Matrix Encryption Software" << endl;
    cout << "---------------------------------------" << endl;

    if(!validInput) {
        cout<<endl;
        cout << "INVALID INPUT DETECTED!" << endl;
        cout << "PLEASE ENTER 1-4" << endl;
        cout << endl;
    }


    int userInput = 0;

    cout << "1. Generate Keys(Not implemented)" << endl;
    cout << "2. Encrypt" << endl;
    cout << "3. Decrypt" << endl;
    cout << "4. Quit" << endl;

    cin >> userInput;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string path;
    string plainText;

    switch (userInput) {
        case 1:

            cout << "Enter the path to store your keys: " << endl;
            getline(cin, path);

            gk.writeKey(path);

            start(true);

            break;
        case 2:

            cout << "Enter text you would like to encrypt: " << endl;
            getline(cin, plainText);

                cout << "Enter path for file" << endl;
                getline(cin, path);
                enc.encryptText(path, plainText);


            cin.ignore();
            start(true);

            break;
        case 3:

                cout << "Enter path for file you want to decrypt" << endl;
                getline(cin, path);

                dec.decryptText(path);

                start(true);
            break;
        case 4:

            return;

        default:
            start(false);
            break;
    }





}