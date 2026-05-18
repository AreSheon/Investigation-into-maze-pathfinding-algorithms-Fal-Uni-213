#pragma once

#include "maze.hxx"

class depth_first:public maze
{
public:

    depth_first() = default;
    ~depth_first() = default;

protected:
    int nextCell(int pos, int size) override;

    void genAlgorithm(int pos, int size) override;

};