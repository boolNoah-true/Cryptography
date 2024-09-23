//
// Created by NoahP on 9/22/2024.
//

#include "linear.h"

linear::linear() {}

int linear::getScalar() const {
    return scalar;
}

void linear::setScalar(const int &newScalar) {
    scalar = newScalar;
}

std::vector<std::vector<long long>> linear::generateMatrix() {

    std::vector<std::vector<long long>> matrix;

    for (int i = 0; i<3; i++){
        std::vector<long long> row;
        for (int j = 0; j<3; j++) {

            row.push_back(j);

        }

        matrix.push_back(row);
    }

    return matrix;

}


long long linear::findDeter(std::vector<std::vector<long long>>& matrix){
    long long determinant = 0;







    return determinant;
}














std::vector<long long> linear::multiply() {

}

std::vector<std::vector<long long>> linear::inverse() {

}