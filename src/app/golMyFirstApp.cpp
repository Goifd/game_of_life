/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golMyFunctions.h>
#include <golBasicTypes.h>
#include <golExceptionMacro.h>
#include <iostream>

int main(int argc, char** argv)
{
  gol::Grid grid = gol::Grid("/workspaces/game-of-life-Goifd/test/data/glider.txt");
  std::cout << "this is fine" << std::endl;
  grid.printGrid();
  std::cout << grid.getLiveNeighbours(0,0) << std::endl;
  std::cout << grid.getLiveNeighbours(0,1) << std::endl;
  std::cout << grid.getLiveNeighbours(0,2) << std::endl;
  std::cout << grid.getLiveNeighbours(0,3) << std::endl;
  std::cout << grid.getLiveNeighbours(0,4) << std::endl;
  std::cout << grid.getLiveNeighbours(0,5) << std::endl;
  std::cout << grid.getLiveNeighbours(1,0) << std::endl;
  std::cout << grid.getLiveNeighbours(1,1) << std::endl;
  std::cout << grid.getLiveNeighbours(1,2) << std::endl;
  std::cout << grid.getLiveNeighbours(1,3) << std::endl;
  std::cout << grid.getLiveNeighbours(1,4) << std::endl;
  std::cout << grid.getLiveNeighbours(1,5) << std::endl;
  std::cout << grid.getLiveNeighbours(2,0) << std::endl;
  std::cout << grid.getLiveNeighbours(2,1) << std::endl;
  std::cout << grid.getLiveNeighbours(2,2) << std::endl;
  std::cout << grid.getLiveNeighbours(2,3) << std::endl;
  std::cout << grid.getLiveNeighbours(2,4) << std::endl;
  std::cout << grid.getLiveNeighbours(2,5) << std::endl;
  std::cout << grid.getLiveNeighbours(3,0) << std::endl;
  std::cout << grid.getLiveNeighbours(3,1) << std::endl;
  std::cout << grid.getLiveNeighbours(3,2) << std::endl;
  std::cout << grid.getLiveNeighbours(3,3) << std::endl;
  std::cout << grid.getLiveNeighbours(3,4) << std::endl;
  std::cout << grid.getLiveNeighbours(3,5) << std::endl;
  std::cout << grid.getLiveNeighbours(4,0) << std::endl;
  std::cout << grid.getLiveNeighbours(4,1) << std::endl;
  std::cout << grid.getLiveNeighbours(4,2) << std::endl;
  std::cout << grid.getLiveNeighbours(4,3) << std::endl;
  std::cout << grid.getLiveNeighbours(4,4) << std::endl;
  std::cout << grid.getLiveNeighbours(4,5) << std::endl;
  grid.setCell(0,4,true);
  std::cout << grid.getCell(0,4) << std::endl;
  grid.printGrid();
  //grid.randomInit(5);
  //grid.printGrid();
  //grid.randomInit(10);
  //grid.printGrid();
  //grid.randomInit(50);
  //grid.printGrid();
  

  int returnStatus = EXIT_FAILURE;

  try
  {
    throw std::runtime_error("Something went wrong!");

    returnStatus = EXIT_SUCCESS;
  }
  catch (gol::Exception& e)
  {
    std::cerr << "Caught gol::Exception: " << e.GetDescription() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << "Caught std::exception: " << e.what() << std::endl;
  }

  return returnStatus;
}
