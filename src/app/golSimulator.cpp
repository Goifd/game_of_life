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
#include <CLI11.hpp>
#include <bits/stdc++.h>
#include <memory>
#include <thread>
#include <chrono>

int main(int argc, char** argv)
{
    CLI::App app{"Game of Life Simulator"};
    std::unique_ptr<GameOfLife> gof = nullptr; 

    // these will throw exceptions if not initialised
    std::string filename = "default";
    int nRows = INT_MIN;
    int nCols = INT_MIN;
    int alive = INT_MIN;
    int steps = INT_MIN;

    // build parser
    app.add_option("-f,--file", filename, "Path to input file.");
    app.add_option("-r, --row", nRows, "Number of rows, has to be larger than 1.");
    app.add_option("-c, --columns", nCols, "Number of columns, hast ot be larger than 1.");
    app.add_option("-a, --alive", alive, "Number of alive cells, has to be between 0 and the total number of cells.");
    app.add_option("-s, --steps", steps, "Number of steps to take. Has to be a positive number");

    // throw exception by the parser if input format is invalid
    try{
        app.parse(argc, argv);
    }catch(const CLI::ParseError &e){
        return app.exit(e);
    }

    int returnStatus = EXIT_FAILURE;
    // MAIN TRY BLOCK
    try
    {
        // TEST IF ALL OF THE NECESSARY INPUT WAS GIVEN
        // if both -f and any of -r -c -a are defined throw exception
        // if neither of those are defined throw exception
        // if defined correctly, pass on to Grid, let class handle exceptions for bad input
        if((filename!="default" && (nRows != INT_MIN || nCols != INT_MIN || alive != INT_MIN)) 
        || (filename=="default" && (nRows == INT_MIN || nCols == INT_MIN || alive == INT_MIN))
        || steps==INT_MIN){
            std::string errorMessage = "--file and --row --columns --alive flags cannot be used together" 
                                        "or the necessary input parameters were not defined";
            throw std::invalid_argument(errorMessage);

        }
        // INITIALIZE GRID
        else if(filename!="default"){
            gol::Grid grid = gol::Grid(filename);
            gof = std::make_unique<GameOfLife>(grid);
        }else{
            gol::Grid grid = gol::Grid(nRows, nCols, alive);
            gof = std::make_unique<GameOfLife>(grid);
        }

        // ITERATE GRID 
        std::cout << "Input grid" << std::endl;
        gof->printGrid();
        for(int i=0; i<steps; ++i){
            std::cout << "After iteration " << i+1  << ":" << std::endl;
            gof->takeStep();
            gof->printGrid();
            std::this_thread::sleep_for(std::chrono::seconds(1));      
        }
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
