#include "golGameOfLife.h"

GameOfLife::GameOfLife(gol::Grid& g):grid(g) {}

int GameOfLife::takeStep(){
    // create a copy of current cell
    gol::Grid nextGrid = grid;
    int rows = grid.getGridRows();
    int cols = grid.getGridCols();
    int aliveNeigh = 0;
    int counter = 0;

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
                if(!nextGrid.getCell(i,j))
                    counter++;
                nextGrid.setCell(i,j,true);
            } else{
                //std::cout << "this1" << std::endl;
                if(nextGrid.getCell(i,j))
                    counter++;
                nextGrid.setCell(i,j, false);
            }
        }
    }

    // refresh grid status
    grid = nextGrid;

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