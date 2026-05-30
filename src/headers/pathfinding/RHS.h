#pragma once

#include "tree_search.h"

class RHS:public tree_search
{
public:

    RHS(maze* curMaze);
    ~RHS() = default;

private:
    /** turn right */
    int incrementRot();

    /** turn left */
    int decrementRot();


public:
    
    virtual void solveMaze(maze* curMaze) override;

};
