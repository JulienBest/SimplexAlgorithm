cmake_minimum_required(VERSION 3.14)
project(Simplex)

set(CMAKE_CXX_STANDARD 17)

add_executable(Simplex main.cpp PrimalSimplexAlgorithm.cpp PrimalSimplexAlgorithm.h SimplexTableau.cpp SimplexTableau.h)