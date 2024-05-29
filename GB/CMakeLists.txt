cmake_minimum_required(VERSION 3.27)
project(GB)

set(CMAKE_CXX_STANDARD 17)

add_executable(GB main.cpp
        Compte.h
        CompteEpargne.h
        ComptePayant.h
        Compte.cpp
        CompteEpargne.cpp
        ComptePayant.cpp)
