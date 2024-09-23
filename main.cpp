#include <iostream>
#include <vector>
#include <unordered_map>
#include <windows.h>
#include "linear.h"
#include <locale>
#include <codecvt>

using namespace std;

int main() {

    linear lin;

    vector<vector<long long>> matrix = lin.generateMatrix();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }



    lin.findDeter(matrix);



    return 0;
}
