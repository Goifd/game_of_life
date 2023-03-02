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
      // throw exception if grid size arguments are invalid
      if(N<1 || M<1){
        std::string errorMessage = "Invalid arguments for grid size: \n"
                                   "nRows: " + std::to_string(N) + "\n"
                                   "nCols: " + std::to_string(M) + "\n" 
                                   "nRows and nCols should be larger than 1.";
        throw std::invalid_argument(errorMessage);
      }
        
      for(int i=0; i<N; i++){
          std::vector<bool> row(nCols, false); // initialise vector with all false values
          grid.push_back(row);
      }
  }

  Grid::Grid(int N, int M, int nAlive) : nRows(N), nCols(M){
    // throw exception if grid size arguments are invalid
    if(N<1 || M<1){
      std::string errorMessage = "Invalid arguments for grid size: \n"
                                 "nRows: " + std::to_string(N) + "\n"
                                 "nCols: " + std::to_string(M) + "\n" 
                                 "nRows and nCols should be larger than 1.";
      throw std::invalid_argument(errorMessage);
    }
      
    for(int i=0; i<N; i++){
        std::vector<bool> row(nCols, false); // initialise vector with all false values
        grid.push_back(row);
    }
    Grid::randomInit(nAlive);   
  }

  Grid::Grid(std::string s){
    std::string line;
    std::ifstream myFile(s, std::ios::in);
    bool flag = true;
    bool isSpace = false;
    int len = 0;

      if(myFile.is_open()){
      // CHECK FOR USER INPUT
      // each line should be same length as first line
      // lines should only contain - and o and maximum one consecutive space

      // get input from txt line by line
        while(std::getline(myFile, line)){
          
          std::vector<bool> row;

          // save length of first line
          if(flag){
            len=line.size();
            flag=false;
          }

          // throw exception if line length changes, special case for last line since enter is missing
          if(line.size()!=len){ 
            if(!(!std::getline(myFile, line) && line.size()==(len-1))){
              std::string errorMessage = "File input format is invalid. 1";
              throw std::invalid_argument(errorMessage);
            }              
          }
            
          // iterate through line string and save values into the grid vector, throw exception for wrong format
          for(char x : line){
            if(isSpace && !std::isspace(x) && x!='\n'){
              std::string errorMessage = "File input format is invalid. 2";
              throw std::invalid_argument(errorMessage); 
            } else if(x=='-'){
              row.push_back(false);           
            } else if(x=='o'){
              row.push_back(true); 
            } 
            isSpace = !isSpace;
          }
          grid.push_back(row);
        }
        myFile.close();
      }

    else {
      std::string errorMessage =  "Unable to open file path is invalid.";
      throw std::invalid_argument(errorMessage);
    }
    nRows = grid.size();
    nCols = grid.at(0).size();
    
  }

  // using the .at method to throw exception automatically
  bool Grid::getCell(int N, int M){
      return grid.at(N).at(M);
  }

  // using the .at method to throw exception automatically
  void Grid::setCell(int N, int M, bool value){
      grid.at(N).at(M) = value;
  }

  int Grid::getGridRows(){
    return nRows;
  }

  int Grid::getGridCols(){
    return nCols;
  }

  int Grid::countAlive(){
    int alive=0;
    for(auto &row : grid){
          for(auto x : row){
              if(x){
                alive++;
              }               
          }
    }
    return alive;
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
      };
  }

  void Grid::randomInit(int nAlive){
    // throw exception for invalid argument
    if(nAlive<0 || nAlive>(nRows*nCols)){
      std::string errorMessage = "Number of alive cells must be between 0 and the total number of cells, inclusive. \n" 
                                " Alive: " + std::to_string(nAlive) + ", nRows*nCols: " + std::to_string(nRows*nCols);
      throw std::invalid_argument(errorMessage);
    }

    // to initialize the grid use std::shuffle, otherwise duplicate draws would slow down the random initialization (E.g. if code randomly picked a x and y value)
    // each grid point is labelled by an integer, total of nCols*nRows, shuffle array, first nAlive array elements will be the locations of the alive cells
    // assign true to cell setCell(int(num/nCols), )
    // this comes with memory overhead theta(nCols*nRows), but the time complexity of random initialisation becomes theta(nCols*nRows)
    // this is especially important when using large grids and a large number of alive cells where duplicate position draws would massively effect runtime

    std::vector<int> v(nRows*nCols);
    for(int i=0; i<nRows*nCols; i++){
      v[i]=i;
    }
    // shuffle array
    std::random_shuffle(v.begin(), v.end());
    // use shuffled array values as indicies and set cells residing at these locations alive
    for(int i=0; i<nAlive; i++){
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
        //std::cout << "k: " << k << " l: " << l << std::endl;
        
        if (k >= 0 && k < nRows && l >= 0 && l < nCols && !(k == row && l == col)) {
          //std::cout << "added"<< std::endl;
          try{
              alive += grid.at(k).at(l);
          }catch(std::out_of_range &e){
            //std::cout << "this is not working" << std::endl;
          }
          
        }
      }
    }
    return alive;
  }

  bool Grid::operator==(Grid &y){
    // confirm that the two grid has the same dimensions
    if(nRows!=y.getGridRows() || nCols!=y.getGridCols()){
      std::string errorMessage = "= is only defined for grids with the same number of columns and rows.";
      throw std::invalid_argument(errorMessage);
    }

    // iterate through grid and compare element-by-element
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
          if(getCell(i,j)!=y.getCell(i,j))
            return false;
        }
        std::cout << "\n";
    }
    return true;
  }

} // end namespace
