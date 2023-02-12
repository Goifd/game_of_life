#include "Grid.h"

// N is the number of rows, M is the number of columns
Grid::Grid(int N, int M) : nRows(N), nCols(M){
    for(int i=0; i<N; i++){
        std::vector<bool> row(nCols, false); // initialise vector with all false values
        grid.push_back(row);
    }
}

bool Grid::getCell(int N, int M){
    return grid.at(N).at(M);
}

void Grid::setCell(int N, int M, bool value){
    grid.at(N).at(M) = value;
}

void Grid::printGrid(){
    for(auto &row : grid){
        for(auto x : row){
            if(x)
                std::cout << "o ";
            else
                std::cout << "- ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}