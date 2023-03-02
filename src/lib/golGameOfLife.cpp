#include "golGameOfLife.h"

GameOfLife::GameOfLife(gol::Grid& g):grid(g) {}

int GameOfLife::takeStep(){
    // create a copy of current cell
    gol::Grid nextGrid = grid;
    int rows = grid.getGridRows();
    int cols = grid.getGridCols();
    int aliveNeigh = 0;

    // count how many cells change status, helpful for still life search
    int counter = 0;

    // iterate through every cell and apply game rules
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            // get the alive neighbours for current cell
            aliveNeigh = grid.getLiveNeighbours(i,j);

            // apply game rules 
            if((!grid.getCell(i,j) && aliveNeigh==3) || (grid.getCell(i,j) && (aliveNeigh==2 || aliveNeigh==3))){
                // increase counter if cell was dead and will be alive after step
                if(!nextGrid.getCell(i,j))
                    counter++;

                nextGrid.setCell(i,j,true);
            } else{
                // increase counter if cell was alive and will be dead after step
                if(nextGrid.getCell(i,j))
                    counter++;
                
                nextGrid.setCell(i,j, false);
            }
        }
    }

    // refresh grid status
    grid = nextGrid;

    // return the number of changed cells
    return counter;
}

bool GameOfLife::getCell(int row, int col){
    return grid.getCell(row, col);
}

int GameOfLife::getAlive(){
    return grid.countAlive();
}

void GameOfLife::printGrid(){
    // create separating line
    // linear in number of columns, so does not come with much 
    // computational overhead
    std::string s = "";
    for(int i=0; i<(grid.getGridCols()*2-1); i++){
        s = s + "-";
    }

    grid.printGrid();
    // print separating line after grid is printed
    std::cout << s << std::endl;
}