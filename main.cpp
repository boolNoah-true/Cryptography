#include <iostream>
#include <vector>
#include <unordered_map>

#include "linear.h"
#include "breakString.h"
#include "genKeys.h"

#include <locale>
#include <codecvt>
#include <string>

using namespace std;

int main() {
    breakString br;
    linear lin;
    string s;
    getline(cin, s);

    genKeys gk;

    gk.writeKey("test");

    vector<vector<int>> test = br.breakS(s);

    for(int i = 0; i < test.size(); i++) {
        for(int j = 0; j < test[i].size(); j++) {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<long long>> matrix = lin.generateMatrix();
    cout << "run" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }



    cout << lin.findDeter(matrix) << endl << endl;

    lin.inverse(matrix);



    return 0;
}
