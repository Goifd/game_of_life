  #include <golBasicTypes.h>
  #include <iostream>
  #include <string>

  class GameOfLife{
    public:
    // to avoid having to implement the grid functionalities again
    // grid is passed as an argument instead of being initialised 
    // in this class, since the user interacts with the command line app
    // this does not come with a more demanding user experience
    GameOfLife(gol::Grid& g);
    bool getCell(int row, int col);

    // takeStep returns the number of changed cells
    int takeStep();
    int getAlive();
    void printGrid();

    private:   
    gol::Grid grid;
  };