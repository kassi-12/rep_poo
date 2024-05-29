cmake_minimum_required(VERSION 3.27)
project(TD3_TP)

set(CMAKE_CXX_STANDARD 17)

add_executable(TD3_TP main.cpp
        Vetement.h
        Produit.cpp
        Produit.cpp
        ProduitAlimentaire.cpp
        Vetement.cpp
        AppareilElectronique.h
        AppareilElectronique.cpp
        Tv.h
        Tv.cpp)
