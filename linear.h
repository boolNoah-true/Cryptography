//
// Created by NoahP on 9/22/2024.
//

#ifndef CRYPTOGRAPHY_LINEAR_H
#define CRYPTOGRAPHY_LINEAR_H

#include <iostream>
#include <vector>

class linear {

public:

    linear();

    std::vector<std::vector<long long>> generateMatrix();

    std::vector<long long> multiply(std::vector<std::vector<long long>> matrix1, std::vector<long long> matrix2);

    std::vector<std::vector<long long>> inverse(std::vector<std::vector<long long>>& matrix);

    long long findDeter(std::vector<std::vector<long long>>& matrix);




    int getScalar() const;

    void setScalar(const int& newScalar);









private:

    int scalar = 1;

};


#endif //CRYPTOGRAPHY_LINEAR_H
