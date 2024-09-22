cmake_minimum_required(VERSION 3.26)
project(Cryptography)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cryptography
        main.cpp
        genKeys.cpp
        genKeys.h)
