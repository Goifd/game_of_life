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
  std::string s4 = "./test/data/wrong_input_1.txt";
  std::string s5 = "./test/data/wrong_input_2.txt";
  std::string s6 = "./test/data/wrong_input_3.txt";
  std::string s7 = "./test/data/wrong_input_4.txt";
  
    //gol::Grid g1 = gol::Grid(s1);
    //g1.printGrid();
    gol::Grid g2 = gol::Grid(s2);
    g2.printGrid();
    int l = g2.getLiveNeighbours(0,1);
    std::cout << l;
    std::cout << g2.getCell(1,2);
    //gol::Grid g3 = gol::Grid(s3);
    ///g3.printGrid();
    //gol::Grid g4 = gol::Grid(s4);
    //g4.printGrid();
    //gol::Grid g5 = gol::Grid(s5);
    //g5.printGrid();
    //gol::Grid g6 = gol::Grid(s6);
    //g6.printGrid();
    //gol::Grid g7 = gol::Grid(s7);
    //g7.printGrid();
  

 


  

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
