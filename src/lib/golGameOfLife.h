  #include <golBasicTypes.h>
  #include <iostream>

  class GameOfLife{
    public:
    // to avoid having to implement the grid functionalities again
    // grid is passed as an argument instead of being initialised 
    // in this class, since the user interacts with the command line app
    // this does not come with a more demanding user experience
    GameOfLife(gol::Grid& g);
    bool getCell(int row, int col);
    void takeStep();
    int getAlive();
    void printGrid(){
        grid.printGrid();
        std::cout << "--------------------------------------------------------" << std::endl;
    }

    private:   
    gol::Grid grid;
  };