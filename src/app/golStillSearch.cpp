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
#include <golGameOfLife.h>
#include <golExceptionMacro.h>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char** argv)
{
  std::string s1 = "./test/data/oscillators.txt";
  std::string s2 = "./test/data/glider.txt";
  std::string s3 = "./test/data/still_lifes.txt";
  
    gol::Grid g1 = gol::Grid(s1);
    gol::Grid g2 = gol::Grid(s2);
    gol::Grid g3 = gol::Grid(s3);
    
    GameOfLife gol1 = GameOfLife(g3);
    gol1.printGrid();
    gol1.takeStep();
    gol1.printGrid();
    gol1.takeStep();
    gol1.printGrid();
    gol1.takeStep();
    gol1.printGrid();
    gol1.takeStep();
    gol1.printGrid();
    gol1.takeStep();
    gol1.printGrid();
  

 


  

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
