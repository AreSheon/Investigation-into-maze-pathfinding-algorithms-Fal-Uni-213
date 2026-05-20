#include "Passage.h"
#include "Cell.h"

Cell::Cell(int t_wallCount) : m_wallExists(new bool[t_wallCount]), m_adjacentCells(new Cell[t_wallCount]), m_passages(new Passage[2]/*without loops can stay hard coded to 2*/)
{
    m_wallCount = t_wallCount;
}

Cell::~Cell()
{
}


void Cell::moveCell()
{
}





