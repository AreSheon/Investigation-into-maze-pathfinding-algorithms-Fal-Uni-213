#pragma once

#include "maze.h"

class recursive_backtracker:public maze
{
public:

    recursive_backtracker(int size);
    ~recursive_backtracker() = default;

protected:
    int nextCell(int pos, int size) override;

    void genAlgorithm(int pos, int size) override;

};
