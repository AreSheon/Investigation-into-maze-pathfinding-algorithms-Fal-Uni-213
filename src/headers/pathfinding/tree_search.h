#pragma once

#include <vector>
#include "general_settings.h"// error due to maze.hxx also including this, and due to compilation. include hell

using namespace general_settings;
using std::vector;


class maze;
class tree_search{
public:
    explicit tree_search(maze* curMaze);
    virtual ~tree_search() = default;

        //mazeSolving
    int start = 0; // start position
    int goal = size * size - 1; // end position

    vector<int> path; //path array
    int mazeBlocks[size * size][5] ; //1 is g, 2 is h, 3 is f, 4 is explored, 5 is previous for a star
    int pos = start;
    int rot = 0; //0 north, rotating clockwise
    int pathIndex = 0;
    int emptyWalls[4] = { 0 }; //0 not empty, !0 empty
    int emptyWallsCount = 0;

protected:
    
    maze* curMaze;
    
    /** function that returns the position of space to move to. if can't move to that spot returns -1 */
    int move(maze* curMaze, int pos, int dir);

public:
    virtual void solveMaze(maze* curMaze) = 0;

};
