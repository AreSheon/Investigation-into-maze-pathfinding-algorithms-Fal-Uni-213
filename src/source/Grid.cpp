#include "Cell.h"
#include <iostream>
#include "Grid.h"


Grid::Grid(int t_iterationCount, int height, int width) : m_cells(new Cell[t_iterationCount])
{
    if(t_iterationCount > height * width)
    {
        std::cout << "there will be some fun errors :) not";
    }
    m_iterationCount = t_iterationCount;

   //iterates amount of times within the grid -> help bypass need of 
    // index = i * collum * y
} 


Grid::~Grid()
{
    delete[] m_cells;//clear pointer i think;
}

void Grid::generateGrid()
{
    //hardcoding wall count too 4 for help

    

    //iterate throught the thingymajiga
    for(int i = 0; i < m_iterationCount; i++)
    {
        m_cells[i] = Cell(4);//wall size of 4
        std::cout << m_cells[i].wallCount();

    }
}

