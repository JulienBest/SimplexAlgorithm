#include <iostream>
#include <vector>
#include "SimplexTableau.h"

#ifndef SIMPLEX_PRIMALSIMPLEXALGORITHM_H
#define SIMPLEX_PRIMALSIMPLEXALGORITHM_H


class PrimalSimplexAlgorithm {

public:
    PrimalSimplexAlgorithm();

    bool solve(SimplexTableau *&);

    bool checkResultValid(SimplexTableau *&tableau);

    void printResult(SimplexTableau *&tableau) const;

    int getPivotCol(SimplexTableau *&tableau);

    int getPivotRow(SimplexTableau *&tableau);

    void calcQuotientRS(SimplexTableau *&tableau, int pivotCol);
};


#endif //SIMPLEX_PRIMALSIMPLEXALGORITHM_H
