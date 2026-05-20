#pragma once

#include "tree_search.h"

class RHS:public tree_search
{
public:

    RHS() = default;
    ~RHS() = default;

protected:

public:
    
    virtual void solveMaze(maze* curMaze) override;

};
