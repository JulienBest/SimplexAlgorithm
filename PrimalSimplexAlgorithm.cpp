#include <iostream>
#include <vector>
#include "SimplexTableau.h"
#include "PrimalSimplexAlgorithm.h"

PrimalSimplexAlgorithm::PrimalSimplexAlgorithm() {
    std::cout << "Solving... \n";
}

bool PrimalSimplexAlgorithm::solve(SimplexTableau *&tableau) {
    std::cout << "Before:\n";
    tableau->printTableau();

    //while (true) {
    if (checkResultValid(tableau)) {
        return true;
    }
    //}

    printResult(tableau);
    return false;
}

bool PrimalSimplexAlgorithm::checkResultValid(SimplexTableau *&tableau) {
    for (int i = 0; i < tableau->getColumnCount(); i++) {
        int posCounter = 0;
        if (tableau->getValue(3, i) > 0) posCounter++;
        if (posCounter == 0) {
            printResult(tableau);
            return true;
        }
    }
    return false;
}

void PrimalSimplexAlgorithm::printResult(SimplexTableau *&tableau) const {
    std::cout << "\n\n\nAfter: \n";
    tableau->printTableau();
}

int PrimalSimplexAlgorithm::getPivotCol(SimplexTableau *&tableau) {
    int max = 0;
    int maxIndex = 0;

    for (int i = 0; i < tableau->getColumnCount(); i++) {
        int curr = tableau->getValue(tableau->getRowCount() - 1, i);
        if (curr > max) {
            max = curr;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int PrimalSimplexAlgorithm::getPivotRow(SimplexTableau *&tableau) {
    int min = 0;
    int minIndex = 0;

    for (int i = 0; i < tableau->getColumnCount(); i++) {
        int curr = tableau->getValue(i, tableau->getColumnCount() - 1);
        if (curr < min) {
            min = curr;
            minIndex = i;
        }
    }
    return minIndex;
}

void PrimalSimplexAlgorithm::calcQuotientRS(SimplexTableau *&tableau, int pivotCol) {
    for (int i = 0; i < tableau->getRowCount(); i++) {
        int old = tableau->getValue(i, tableau->getColumnCount() - 1);
        int pivotVal = tableau->getValue(i, pivotCol);
        int quotient = old / pivotVal;
        tableau->setValue(i, tableau->getColumnCount() - 1, quotient);
    }
}
