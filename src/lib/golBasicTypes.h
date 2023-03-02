/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golBasicTypes_h
#define golBasicTypes_h

/**
* \defgroup internal internal
* \brief Internal stuff, not for end-users.
*/

/**
* \defgroup types types
* \brief Package-wide data types.
*/

/**
* \defgroup utilities utilities
* \brief Groups of c-style functions.
*/

/**
* \defgroup applications applications
* \brief Small, end-user applications, most likely command line.
*/

/**
* \file golBasicTypes.h
* \brief Defines types and typedefs used in this library.
* \ingroup types
*/

//! Single namespace for all code in this package
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

namespace gol
{
  // Grid is the class used to represent the grid in the Game of Life game
  // it can be initialised all dead, random or from a file
  // cells can be individually set dead or alive after initialisation
  // there is functionality for printing, and counting the alive neighbouring cells for a single cell
  class Grid{
    public:
    Grid(int N, int M);
    Grid(int N, int M, int nAlive);
    Grid(std::string s);

    void setCell(int N, int M, bool value);
    bool getCell(int N, int M);

    int getGridRows();
    int getGridCols();

    void printGrid();
    int getLiveNeighbours(int N, int M);

    // implement countAlive to test random initialisation 
    int countAlive();
    // override = for equality check between randomly initialized grids
    // need to throw exception for mismatched size
    bool operator==(Grid &y);

    private:   
    void randomInit(int nAlive); 
    std::vector<std::vector<bool>> grid;
    int nRows;
    int nCols;
  };

} // end namespace

#endif
