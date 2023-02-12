#pragma once
#include <vector>
#include <iostream>

class Grid{
    public:
    Grid(int N, int M);

    void setCell(int N, int M, bool value);
    bool getCell(int N, int M);
    void printGrid();

    private:
    std::vector<std::vector<bool>> grid;
    int nRows;
    int nCols;
};