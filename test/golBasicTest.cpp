/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golCatchMain.h"
#include "golMyFunctions.h"
#include "golBasicTypes.h"
#include <iostream>
#include <vector>

// check if cells have been initialised
TEST_CASE( "My first test", "[ex1.1]" ) {

  // basic check
  gol::Grid grid1 = gol::Grid(1, 1);
  REQUIRE( grid1.getCell(0,0) == false);


  // check corner cells and getter
  gol::Grid grid2 = gol::Grid(10,5);
  REQUIRE(grid2.getCell(9,4) == false);
  REQUIRE(grid2.getCell(9,0) == false);
  REQUIRE(grid2.getCell(0,4) == false);

  // check exception
  bool exception = false;
  try{
    gol::Grid grid3 = gol::Grid(-1,1);
  }catch(std::invalid_argument error){
    exception = true;
  }
  REQUIRE(exception);

  // check exception
  bool exception = false;
  try{
    gol::Grid grid3 = gol::Grid(1,-1);
  }catch(std::invalid_argument error){
    exception = true;
  }
  REQUIRE(exception);

  // check setter
  grid2.setCell(9,4,true);
  grid2.setCell(9,0,true);
  grid2.setCell(0,4,true);

  REQUIRE(grid2.getCell(9,4));
  REQUIRE(grid2.getCell(9,0));
  REQUIRE(grid2.getCell(0,4));
}

// test if total number of placed cells is correct how???
// test that different instances generate different patterns - overload = 
TEST_CASE( "My second test", "[ex2.2]" ) {
  gol::Grid grid = gol::Grid(4, 10, 6);
  REQUIRE( 0 == 0 );
}

TEST_CASE( "Simple add", "[MyFirstAddFunction]") {
  REQUIRE( gol::MyFirstAddFunction(1, 2) == 3);
}
