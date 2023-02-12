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

  bool Grid::getCell(int N, int M){
      return grid.at(N-1).at(M-1);
  }

  void Grid::setCell(int N, int M, bool value){
      grid.at(N-1).at(M-1) = value;
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
    // randomly generate the x,y coordinates and then set value to true, if value is already true run loop once more
    std::mt19937 rng_mt;
    std::uniform_int_distribution<int> distributionRow(1, nRows);
    std::uniform_int_distribution<int> distributionCol(1, nCols);
    int row;
    int col;
    // set it to all alive if larger than number of total cells
    int alive = (nAlive>(nRows*nCols)) ? (nRows*nCols) : nAlive;
    for(int i=0; i<alive; i++){
      // generate random position
      row = distributionRow(rng_mt);
      col = distributionCol(rng_mt);
      if(getCell(row, col)){
        i--;
      } 
      else {
        std::cout << "set a cell" << std::endl;
        setCell(row, col, true);
      }      
    }
  }

} // end namespace
