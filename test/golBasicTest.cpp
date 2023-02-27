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

// check if grid is correctly initialised using the constructors
TEST_CASE("Initialisation with 2 parameters", "[init1]" ) {

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
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);

  // check exception
  exception = false;
  try{
    gol::Grid grid3 = gol::Grid(1,-1);
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);
}

TEST_CASE("Random initialization test","[init2]"){
  // testing with large enough grids so that the probability of the two grids accidentally being equal is almost 0
  gol::Grid grid1 = gol::Grid(50,50,20);
  REQUIRE(grid1.countAlive()==20);

  gol::Grid grid2 = gol::Grid(50,50,20);
  REQUIRE(grid2.countAlive()==20);

  bool val=false;
  if(grid1==grid2){
    val=true;
  }
  REQUIRE(!val);

  gol::Grid g1 = gol::Grid(1,1,1);
  gol::Grid g2 = gol::Grid(1,1,1);
  val=false;
  if(g1==g2)
    val=true;
  REQUIRE(val);

  // test exception handling
  bool exception = false;
  try{
    gol::Grid grid3 = gol::Grid(3,3,10);
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);

  exception = false;
  try{
    gol::Grid grid3 = gol::Grid(3,3,-1);
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);
  
}

TEST_CASE("Initialisation from file", "[init3]"){}

TEST_CASE("== operator test"){
  gol::Grid g1 = gol::Grid(3,3);
  gol::Grid g2 = gol::Grid(3,3);
  bool val=false;
  if(g1==g2)
    val=true;
  // REQUIRE didn't allow for directly checking g1==g2
  REQUIRE(val);

  val = false;
  g1.setCell(1,2,true);
  if(!(g1==g2))
    val=true;
  REQUIRE(val);

  g2.setCell(1,2,true);
  val=false;
  if(g1==g2)
    val=true;
  REQUIRE(val);

  // text exception
  bool exception = false;
  try{
    gol::Grid grid3 = gol::Grid(3,1);
    grid3==g1;
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);
}

TEST_CASE("setters and getters","[setget]"){
  gol::Grid grid2 = gol::Grid(10,5);
  // check setter
  grid2.setCell(9,4,true);
  grid2.setCell(9,0,true);
  grid2.setCell(0,4,true);

  REQUIRE(grid2.getCell(9,4));
  REQUIRE(grid2.getCell(9,0));
  REQUIRE(grid2.getCell(0,4));
}

TEST_CASE("countAlive test","[countAlive]"){

  gol::Grid g1 = gol::Grid(1,1);
  REQUIRE(g1.countAlive() == 0);


  gol::Grid g2 = gol::Grid(2,2);
  REQUIRE(g2.countAlive() == 0);

  g2.setCell(0,0,true);
  g2.setCell(1,1,true);
  REQUIRE(g2.countAlive() == 2);
}

TEST_CASE("getLiveNeighbours test"){}

