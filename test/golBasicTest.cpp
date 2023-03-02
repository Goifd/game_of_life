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
#include "golGameOfLife.h"
#include <iostream>
#include <vector>

// INSTANTIATION/INITIALIZATION CHECKS

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

TEST_CASE("Initialisation from file", "[init3]"){
  std::string s1 = "../../test/data/oscillators.txt";
  std::string s2 = "../../test/data/glider.txt";
  std::string s3 = "../../test/data/still_lifes.txt";
  std::string s4 = "../../test/data/wrong_input_1.txt";
  std::string s5 = "../../test/data/wrong_input_2.txt";
  std::string s6 = "../../test/data/wrong_input_3.txt";
  std::string s7 = "../../test/data/wrong_input_4.txt";

  // instead of hardcoding the patterns and comparing them these are to be checked by eye
  gol::Grid g1 = gol::Grid(s1);
  std::cout << "oscillator.txt" << std::endl;
  g1.printGrid();
  std::cout << "\n";
  std::cout << "glider.txt" << std::endl;
  gol::Grid g2 = gol::Grid(s2);
  g2.printGrid();
  std::cout << "\n";
  std::cout << "still_lives.txt" << std::endl;
  gol::Grid g3 = gol::Grid(s3);
  g3.printGrid();

  // checking exceptions
  bool exception = false;
  try{
    gol::Grid g5 = gol::Grid(s5);
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);

  exception = false;
  try{
    gol::Grid g6 = gol::Grid(s6);
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);

  exception = false;
  try{
    gol::Grid g7 = gol::Grid(s7);
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);

  exception = false;
  try{
    gol::Grid g4 = gol::Grid(s4);
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);

  // test invalid path exception
  exception = false;
  try{
    gol::Grid g4 = gol::Grid("wrongpath");
  }catch(const std::invalid_argument &e){
    exception = true;
  }
  REQUIRE(exception==true);


}


// FUNCTIONALITY TESTS

TEST_CASE("== operator test","[operator=]"){
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

TEST_CASE("getLiveNeighbours test", "[getLiveNeighbours]"){
  gol::Grid g1 = gol::Grid(1,1);
  REQUIRE(g1.getLiveNeighbours(0,0)==0);

  // testing row by row
  gol::Grid g2 = gol::Grid("../../test/data/glider.txt");
  REQUIRE(g2.getLiveNeighbours(0,0)==0);
  REQUIRE(g2.getLiveNeighbours(0,1)==1);
  REQUIRE(g2.getLiveNeighbours(0,2)==1);
  REQUIRE(g2.getLiveNeighbours(0,3)==1);
  REQUIRE(g2.getLiveNeighbours(0,4)==0);

  REQUIRE(g2.getLiveNeighbours(1,0)==1);
  REQUIRE(g2.getLiveNeighbours(1,1)==3);
  REQUIRE(g2.getLiveNeighbours(1,2)==1);
  REQUIRE(g2.getLiveNeighbours(1,3)==2);
  REQUIRE(g2.getLiveNeighbours(1,4)==0);

  REQUIRE(g2.getLiveNeighbours(2,0)==1);
  REQUIRE(g2.getLiveNeighbours(2,1)==5);
  REQUIRE(g2.getLiveNeighbours(2,2)==3);
  REQUIRE(g2.getLiveNeighbours(2,3)==3);
  REQUIRE(g2.getLiveNeighbours(2,4)==0);

  REQUIRE(g2.getLiveNeighbours(3,0)==2);
  REQUIRE(g2.getLiveNeighbours(3,1)==3);
  REQUIRE(g2.getLiveNeighbours(3,2)==2);
  REQUIRE(g2.getLiveNeighbours(3,3)==2);
  REQUIRE(g2.getLiveNeighbours(3,4)==0);

  REQUIRE(g2.getLiveNeighbours(4,0)==1);
  REQUIRE(g2.getLiveNeighbours(4,1)==2);
  REQUIRE(g2.getLiveNeighbours(4,2)==2);
  REQUIRE(g2.getLiveNeighbours(4,3)==1);
  REQUIRE(g2.getLiveNeighbours(4,4)==0);
}

TEST_CASE("takeStep test", "[takeStep]"){

  std::string s1 = "../../test/data/glider.txt";
  std::string s2 = "../../test/data/oscillators.txt";
  std::string s3 = "../../test/data/still_lifes.txt";
  
  gol::Grid g1 = gol::Grid(s1);
  gol::Grid g2 = gol::Grid(s2);
  gol::Grid g3 = gol::Grid(s3);
    
  GameOfLife gol1 = GameOfLife(g1);
  GameOfLife gol2 = GameOfLife(g2);
  GameOfLife gol3 = GameOfLife(g3);

  // only check for total number of alive cells and the alive cells

  // test glider.txt
  gol1.takeStep();
  REQUIRE(gol1.getAlive()==5);
  REQUIRE(gol1.getCell(1,1)==true);
  REQUIRE(gol1.getCell(2,2)==true);
  REQUIRE(gol1.getCell(2,3)==true);
  REQUIRE(gol1.getCell(3,1)==true);
  REQUIRE(gol1.getCell(3,2)==true);

  gol1.takeStep();
  REQUIRE(gol1.getAlive()==5);
  REQUIRE(gol1.getCell(1,2)==true);
  REQUIRE(gol1.getCell(2,3)==true);
  REQUIRE(gol1.getCell(3,1)==true);
  REQUIRE(gol1.getCell(3,2)==true);
  REQUIRE(gol1.getCell(3,3)==true);

  gol1.takeStep();
  REQUIRE(gol1.getAlive()==5);
  REQUIRE(gol1.getCell(2,1)==true);
  REQUIRE(gol1.getCell(2,3)==true);
  REQUIRE(gol1.getCell(3,2)==true);
  REQUIRE(gol1.getCell(3,3)==true);
  REQUIRE(gol1.getCell(4,2)==true);

  gol1.takeStep();
  REQUIRE(gol1.getAlive()==5);
  REQUIRE(gol1.getCell(2,3)==true);
  REQUIRE(gol1.getCell(3,1)==true);
  REQUIRE(gol1.getCell(3,3)==true);
  REQUIRE(gol1.getCell(4,2)==true);
  REQUIRE(gol1.getCell(4,3)==true);

  // test still_lifes.txt
  gol3.takeStep();
  REQUIRE(gol3.getAlive()==19);
  REQUIRE(gol3.getCell(1,1)==true);
  REQUIRE(gol3.getCell(1,2)==true);
  REQUIRE(gol3.getCell(2,0)==true);
  REQUIRE(gol3.getCell(2,3)==true);
  REQUIRE(gol3.getCell(2,6)==true);
  REQUIRE(gol3.getCell(2,7)==true);
  REQUIRE(gol3.getCell(3,1)==true);
  REQUIRE(gol3.getCell(3,2)==true);
  REQUIRE(gol3.getCell(3,6)==true);
  REQUIRE(gol3.getCell(3,8)==true);
  REQUIRE(gol3.getCell(4,7)==true);
  REQUIRE(gol3.getCell(7,1)==true);
  REQUIRE(gol3.getCell(7,6)==true);
  REQUIRE(gol3.getCell(7,7)==true);
  REQUIRE(gol3.getCell(8,0)==true);
  REQUIRE(gol3.getCell(8,2)==true);
  REQUIRE(gol3.getCell(8,6)==true);
  REQUIRE(gol3.getCell(8,7)==true);
  REQUIRE(gol3.getCell(9,1)==true);
}
