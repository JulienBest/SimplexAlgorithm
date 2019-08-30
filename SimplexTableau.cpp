#include <iostream>
#include <utility>
#include <vector>
#include "SimplexTableau.h"

int getMaxLength(std::vector<std::vector<int>> &input);

int lengthOfInt(int num);

SimplexTableau::SimplexTableau(std::vector<std::vector<int>> input) {
    this->tableau = std::move(input);
    this->rowCount = this->tableau.size();
    this->columnCount = this->tableau[1].size();

    std::cout << "Row Count: " << rowCount << "\n";
    std::cout << "Column Count: " << columnCount << "\n";
}

void SimplexTableau::printTableau() {
    int maxLength = getMaxLength(this->tableau);
    int tempLength = 0;
    for (int i = 0; i < this->tableau.size(); i++) {
        for (int j = 0; j < this->tableau[i].size(); j++) {
            std::cout << this->tableau[i][j];
            //Formatting stuff
            tempLength = lengthOfInt(this->tableau[i][j]);
            for (int k = 0; k < (maxLength * 2) - (tempLength + 1); k++) {
                k == maxLength - tempLength ? std::cout << "|" : std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

int lengthOfInt(int num) {
    return std::to_string(num).length();
}

int SimplexTableau::getValue(int row, int col) const {
    return this->tableau[row][col];
}

void SimplexTableau::setValue(int row, int col, int value) {
    this->tableau[row][col] = value;
}

int getMaxLength(std::vector<std::vector<int>> &input) {
    int maxLength = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            int length = lengthOfInt(input[i][j]);
            if (length > maxLength) {
                maxLength = length;
            }
        }
    }
    return maxLength;
}

int SimplexTableau::getRowCount() {
    return this->rowCount;
}

int SimplexTableau::getColumnCount() {
    return this->columnCount;
}