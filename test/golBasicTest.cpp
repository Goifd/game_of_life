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
  gol::Grid grid = gol::Grid(4, 10);
  REQUIRE( grid.getCell(0,0) == false);
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
