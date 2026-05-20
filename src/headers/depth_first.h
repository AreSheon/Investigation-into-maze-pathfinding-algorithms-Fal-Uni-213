#pragma once

#include "maze.h"

class depth_first:public maze
{
public:

    depth_first(int size);
    ~depth_first() = default;

protected:
    int nextCell(int pos, int size) override;

    void genAlgorithm(int pos, int size) override;

};
