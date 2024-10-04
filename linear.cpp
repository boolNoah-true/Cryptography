//
// Created by NoahP on 9/22/2024.
//

#include "linear.h"

#include <cstdlib>
#include <ctime>

linear::linear() {}

int linear::getScalar() const {
    return scalar;
}

void linear::setScalar(const int &newScalar) {
    scalar = newScalar;
}

std::vector<std::vector<long long>> linear::generateMatrix() {

    std::srand(static_cast<unsigned int>(std::time(0)));

    std::vector<std::vector<long long>> matrix;

    std::vector<std::vector<long long>> chosen;

    std::vector<std::vector<long long>> a  = {
            {0, 6, 5},
            {4, 1, 0},
            {3, 2, 1}
    };

    std::vector<std::vector<long long>> b  = {
            {1, 0, 0},
            {4, 1, 0},
            {3, 2, 1}
    };

    std::vector<std::vector<long long>> c  = {
            {1, 1, 0},
            {0, 1, 0},
            {0, 0, 1}
    };

    int randNum = std::rand() % 3 + 1;

    if (randNum == 1) {
        chosen = a;
    } else
    if (randNum == 2) {
        chosen = b;
    } else {
        chosen = c;
    }

    for (int i = 2; i >= 0; i--){
        std::vector<long long> row;
        for (int j = 2; j >= 0; j--) {

            row.push_back(chosen[i][j]);

        }

        matrix.push_back(row);
    }

    return matrix;

}


long long linear::findDeter(std::vector<std::vector<long long>>& matrix){

    long long a = matrix[0][0];
    long long b = matrix[0][1];
    long long c = matrix[0][2];
    long long d = matrix[1][0];
    long long e = matrix[1][1];
    long long f = matrix[1][2];
    long long g = matrix[2][0];
    long long h = matrix[2][1];
    long long i = matrix[2][2];

    long long ma = a*((e*i) - (f*h));
    long long mb = b*((d*i) - (f*g));
    long long mc = c*((d*h) - (e*g));

    std::cout << ma << " " << mb << " " << mc << std::endl;



    long long determinant = ma - mb + mc;






    return determinant;
}














std::vector<long long> linear::multiply(std::vector<std::vector<long long>> matrix1, std::vector<long long> matrix2) {

    std::vector<long long> result;

    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            result[i] += matrix2[j] * matrix1[j][i];
        }
    }

    return result;

}

std::vector<std::vector<long long>> linear::inverse(std::vector<std::vector<long long>>& matrix) {
    std::vector<std::vector<long long>> inversed;
    std::vector<std::vector<long long>> temp;

    long long a = matrix[0][0];
    long long b = matrix[0][1];
    long long c = matrix[0][2];
    long long d = matrix[1][0];
    long long e = matrix[1][1];
    long long f = matrix[1][2];
    long long g = matrix[2][0];
    long long h = matrix[2][1];
    long long i = matrix[2][2];

    long long ma = ((e*i) - (f*h));
    long long mb = ((d*i) - (f*g));
    long long mc = ((d*h) - (e*g));

    long long md = ((b*i) - (c*h));
    long long me = ((a*i) - (c*g));
    long long mf = ((a*h) - (b*g));

    long long mg = ((b*f) - (c*e));
    long long mh = ((a*f) - (c*d));
    long long mi = ((a*e) - (b*d));

    std::vector<long long> cofactors = {ma, mb, mc, md, me, mf, mg, mh, mi};
    int k = 0;
    int sign = 1;
    for (int x = 0; x < 3; x++) {
        std::vector<long long> row;
        for (int j = 0; j < 3; j++){
           row.push_back(cofactors[k]*sign);
           sign *= -1;
           k++;
        }

        temp.push_back(row);

    }

    std::cout << "Pre Transpose: " << std::endl;

    for(int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            std::cout << temp[x][y] << " ";
        }

        std::cout << std::endl;
    }



    for (int x = 0; x < 3; x++) {
        std::vector<long long> row;
        for (int y = 0; y < 3; y++) {

            row.push_back(temp[y][x]);

        }

        inversed.push_back(row);

    }
std::cout << std::endl;
    std::cout << "Transpose: " << std::endl;

    for(int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            std::cout << inversed[x][y] << " ";
        }

        std::cout << std::endl;
    }

    return inversed;

}