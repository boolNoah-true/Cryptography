//
// Created by NoahP on 9/22/2024.
//

#ifndef CRYPTOGRAPHY_ENCRYPT_H
#define CRYPTOGRAPHY_ENCRYPT_H

#include <string>


class encrypt {
public:
    bool isValidPath(const std::string& path);

    void encryptText(const std::string& path, const std::string& s);
};


#endif //CRYPTOGRAPHY_ENCRYPT_H
