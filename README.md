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

The application comes with two main executable files found in /PHAS0100Assignment1/build/bin after building.
THe two files are:
- golSimulator
- golStillSearch

golSimulator:
-------------
- this file creates a random grid and runs the game of life simulation for an arbitrary number of steps and prints the grid after every step
- the grid can be initialized two ways:

To initialize from file the following flags have to be specified:
-f / --file: path to file
-s / --steps: number of steps to simulate
optional flag:
-h / --help: for basic instructions

The file input must be a .txt file with dead cells represented by - and alive cells represented by o. There must be a single space between each cell. Each row must be the same length. Example input can be found in /test/data folder.

E.g.:
```
./golSimulator -s 20 -f /path/to/file/input.txt or 
./golSimulator -s 20 -file /path/to/file/input.txt

// after building to run one of the examples, run the following command from PHAS0100Assignment1 folder
./build/bin/golSimulator  -f ./test/data/glider.txt --steps 5
```
This reads in input.txt and iterates the grid for 20 steps printing the grid after each step.

When using user defined initial conditions to specify the grid the following flags have to be specified:
-r / --rows: number of grid rows
-c / --columns: number of grid columns
-s / --steps: number of steps to simulate
-a / --alive: number of alive cells to place on grid randomly

E.g.:
``` 
./golSimulator -r 10 -c 10 -a 13 -s 50 or
./golSimulator --row 10 --col 10 --alive 13 --steps 50

// or to run an actual simulation run the following command from the PHAS0100Assignment1 folder
./build/bin/golSimulator  -r 10 -c 10 -a 40 -s 10
```
This creates a grid of size 10x10 with 13 alive cells randomly placed on the grid and then iterates the grid for 50 steps printing the grid after every iteration.

golStillSearch:
----------------
- this file can be used to search for still lives on the grid
- after the user specifies the initial grid the application runs until it finds a still life, or reaches the maximum number of steps defined by --steps.
- after finding a still life the application prints it

The following flags have to be specified:
-r / --rows : number of grid rows
-c / --columns : number of grid columns
-s / --steps : number of maximum steps for the simulation
-a / --alive : number of alive cells randomly initialized
-n / --configs: number of different random initial configurations to try
optional flag:
-h /--help

E.g.:
```
golStillSearch -r 10 -c 10 -a 13 -s 50 -n 200
golStillSearch --row 10 --col 10 --alive 13 --steps 50 --configs 200

// or to run a still search run the following command from PHAS0100Assignment1
./build/bin/golStillSearch  -r 10 -c 10 -a 13 -s 50 -n 200
```

This creates and iterates 200 randomly generated grids for 50 steps maximum. Each grid is 10x10 and starts with 13 alive cells. If a still life is found the program prints it.

Example still lives on a 4x4 grid:
```
o o - -
o - o - 
- o - -
- - - -

- - - -
- o o - 
- o o -
- - - -

- - o - 
- o - o
- o - o
- - o -

- o o -
o - - o
- o - o
- - o -

- o o -
o - - o
- o - o
- - o o

- - o o
- o - o
- o - o
- - o -

- - - -
- - o -
- o - o
- - o -

- o o -
o - - o
o - - o
- o o -
```

For further still lives look at the document
ex2_3-ex3-still_lives_collection.pdf






