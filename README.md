[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10103844)
PHAS0100ASSIGNMENT1
------------------

Purpose
-------

This project serves as a starting point for the PHAS0100 2022/23 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.

Credits
-------

This project is maintained by [Dr. Jamie Quinn](http://jamiejquinn.com/). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](https://github-pages.ucl.ac.uk/research-computing-with-cpp/) course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james) and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).

Build Instructions
------------------

To run cmake:

```
cmake -B build
```

To compile:

```
cmake --build build
```

To test:

```
cd build
ctest
```

User Instructions
-----------------------------

the appplication comes with two main executable files:
golSimulator
golStillSearch

golSimulator:
- this file creates a grid and runs the game of life simulation for an arbitrary number of steps and prints the grid after every step
- the grid can be initialised two ways:

From file the following flags have to be specified:
-f / --file
-s / --steps
optional flag:
-h / --help

E.g.:
golSimulator -s 20 -f /path/to/file/input.txt or 
golSimulator -s 20 -file /path/to/file/input.txt

Using random initial conditions the following flags have to be specified:
-r / --row: number of grid rows
-c / --col: number of grid columbs
-s / --steps: how many steps to simulate
-a / --alive:

E.g.:
golSimulator -r 10 -c 10 -a 13 -s 50 or
golSimulator --row 10 --col 10 --alive 13 --steps 50


golStillSearch:
- this file can be used to search for still lives on the grid
- after the user specifies the initial grid the application runs until it finds a still life, or reaches the maximum number of steps defined by --number.
- after finding a still life the application prints it

The following flags have to be specified:
-r / --row 
-c / --col
-s / --steps
-a / --alive
-n / --number
optional flag:
-h /--help

E.g.:
golSimulator -r 10 -c 10 -a 13 -s 50 -n 200
golSimulator --row 10 --col 10 --alive 13 --steps 50 --number 200

Example still lives on a 4x4 grid:






