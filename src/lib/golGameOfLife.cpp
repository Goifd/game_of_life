#include "golGameOfLife.h"

GameOfLife::GameOfLife(gol::Grid& g):grid(g) {}

void GameOfLife::takeStep(){
    // create a copy of current cell
    gol::Grid nextGrid = grid;
    int rows = grid.getGridRows();
    int cols = grid.getGridCols();

    // iterate through every cell and apply game rules
    for(int i=0; i<rows; i++){
        for(int j=0; i<cols; j++){
            int aliveNeigh = grid.getLiveNeighbours(i,j);
            if((!grid.getCell(i,j) && aliveNeigh==3) || (grid.getCell(i,j) && (aliveNeigh==2 || aliveNeigh==3))){
                nextGrid.setCell(i,j,true);
            } else{
                nextGrid.setCell(i,j, false);
            }
        }
    }

    // refresh grid status
    grid = nextGrid;
}