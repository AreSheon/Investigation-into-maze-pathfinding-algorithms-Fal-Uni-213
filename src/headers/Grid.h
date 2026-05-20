#pragma once

//forward declarations
class Cell;

class Grid
{
public:
/**constructor of class*/
    Grid(int t_iterationCount, int height, int width);
    ~Grid();
private:

    int m_iterationCount;//how many times does program iterate/ generate nodes
    
    

    //Cell cellsInGrid[];
    Cell* m_cells;

public:
    void generateGrid();


    void renderGrid();

};
