#include "golGameOfLife.h"

GameOfLife::GameOfLife(gol::Grid& g):grid(g) {}

void GameOfLife::takeStep(){
    // create a copy of current cell
    gol::Grid nextGrid = grid;
    int rows = grid.getGridRows();
    int cols = grid.getGridCols();
    int aliveNeigh = 0;

    // iterate through every cell and apply game rules
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            aliveNeigh = grid.getLiveNeighbours(i,j);
            //std::cout << grid.getGridRows() << std::endl;
            //std::cout << grid.getGridCols() << std::endl;
            //std::cout << rows << std::endl;
            //std::cout << cols << std::endl;
            //std::cout << "this0" << std::endl;
            //std::cout << i << std::endl;
            //std::cout << j << std::endl;
            grid.getCell(i,j);
            if((!grid.getCell(i,j) && aliveNeigh==3) || (grid.getCell(i,j) && (aliveNeigh==2 || aliveNeigh==3))){
                //std::cout << "this1" << std::endl;
                nextGrid.setCell(i,j,true);
            } else{
                //std::cout << "this1" << std::endl;
                nextGrid.setCell(i,j, false);
            }
        }
    }

    // refresh grid status
    grid = nextGrid;
}

bool GameOfLife::getCell(int row, int col){
    return grid.getCell(row, col);
}

int GameOfLife::getAlive(){
    return grid.countAlive();
}