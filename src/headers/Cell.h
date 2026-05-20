#pragma once

class Passage;

class Cell
{
public:
    Cell(int t_wallCount);
    Cell() = default;
    ~Cell();
    bool currentCell;//am I the current cell being looked at
    
    int wallCount() {return m_wallCount;}
    Cell* adjacentCells(){return m_adjacentCells;}
    Passage* passages(){return m_passages;}


private:
    int m_wallCount;
    Cell* m_adjacentCells;
    bool* m_wallExists;
    Passage* m_passages;

public:
    void moveCell();
    
};
