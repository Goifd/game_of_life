/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golBasicTypes.h"

namespace gol {
  // N is the number of rows, M is the number of columns
  Grid::Grid(int N, int M) : nRows(N), nCols(M){
      for(int i=0; i<N; i++){
          std::vector<bool> row(nCols, false); // initialise vector with all false values
          grid.push_back(row);
      }
  }

  Grid::Grid(int N, int M, int nAlive){
    Grid(N, M);
    Grid::randomInit(nAlive);   
  }

  Grid::Grid(std::string s){
    std::string line;
    std::ifstream myFile(s, std::ios::in);

    if(myFile.is_open()){
      // get input from txt line by line
      while(std::getline(myFile, line)){
        // iterate through line string and save values into the grid vector
        std::vector<bool> row;

        for(char& x : line){
          if(x=='-'){
            row.push_back(false);
          } else if(x=='o'){
            row.push_back(true);
          }
        }
        grid.push_back(row);
      }
      myFile.close();
    }

    else std::cout << "Unable to open file" << std::endl;

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

  void Grid::randomInit(int nAlive){

    // set it to all alive if larger than number of total cells
    int alive = (nAlive>(nRows*nCols)) ? (nRows*nCols) : nAlive;

    // to initialize the grid use std::shuffle, otherwise duplicate draws would slow down the random initialization
    // each grid point is labelled by an integer, total of nCols*nRows, draw number 0-(nCols*nRows-1) 
    // assign true to cell setCell(int(num/nCols), )
    // this comes with memory overhead theta(nCols*nRows), but the time complexity of random initialisation becomes theta(nCols*nRows)

    std::vector<int> v(nRows*nCols);
    for(int i=0; i<nRows*nCols; i++){
      v[i]=i;
    }
    // shuffle array
    std::random_shuffle(v.begin(), v.end());
    for(int i=0; i<alive; i++){
      int num=v[i];
      setCell(int(num/nCols), num%nCols, true);
    }
  }

  int Grid::getLiveNeighbours(int row, int col){
    int alive = 0;
    // check 8 neighbouring cells one-by-one, by iterating through the cells
    for (int k = row-1; k <= row+1; k++) {
      for (int l = col-1; l <= col+1; l++) {
        //std::cout << "this is fine" << std::endl;
        if (k >= 0 && k < nRows && l >= 0 && l < nCols && !(k == row && l == col)) {
          //std::cout << "added"<< std::endl;
          alive += grid[k][l];
        }
      }
    }

    return alive;
  }

} // end namespace
