  #include <golBasicTypes.h>
  #include <iostream>

  class GameOfLife{
    public:
    GameOfLife(gol::Grid& g);
    void takeStep();
    void printGrid(){
        grid.printGrid();
        std::cout << "--------------------------------------------------------" << std::endl;
    }

    private:   
    gol::Grid grid;
  };