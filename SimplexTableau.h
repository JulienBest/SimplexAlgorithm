//
// Created by User on 30.08.2019.
//
#include <vector>

#ifndef SIMPLEX_SIMPLEXTABLEAU_H
#define SIMPLEX_SIMPLEXTABLEAU_H


class SimplexTableau {
private:
    std::vector<std::vector<int>> tableau;
    int rowCount;
    int columnCount;

public:
    SimplexTableau(std::vector<std::vector<int>>);

    void setValue(int i, int j, int value);

    int getValue(int i, int j) const;

    void printTableau();

    int getRowCount();

    int getColumnCount();
};


#endif //SIMPLEX_SIMPLEXTABLEAU_H
