#include <iostream>
#include <vector>
#include "SimplexTableau.h"
#include "PrimalSimplexAlgorithm.h"

int main() {
    std::vector<std::vector<int>> test = {
            {1,  0,   1, 0, 0, 8000},
            {0,  1,   0, 1, 0, 5000},
            {1,  1,   0, 0, 1, 10000},
            {60, 120, 0, 0, 0, 0}};
    SimplexTableau *simplexTableau = new SimplexTableau(test);
    PrimalSimplexAlgorithm *algorithm = new PrimalSimplexAlgorithm();

    algorithm->solve(simplexTableau);

    return 0;
}