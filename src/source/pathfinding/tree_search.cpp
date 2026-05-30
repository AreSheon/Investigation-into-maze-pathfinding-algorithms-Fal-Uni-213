#include <GLFW/glfw3.h>
#include <iostream>
#include "pathfinding/tree_search.h"
#include "mazeGen/maze.h"

tree_search::tree_search(maze* mazeToSolve){
    curMaze = mazeToSolve;
}

    //mazeSolving
int tree_search::move(maze* curMaze, int pos, int dir) {
    
    dir %= 4; //safe guard if value is greater than 4....thoooooooooooo clamp would maybe be better

    switch (dir) {
    case 0:   //north

        if (pos >= size) {
            if (curMaze->walls[pos].topWall == 0) {//is there a top wall or not on the current cell
              //  prevPos = pos;
                return pos - size;

                //pathIndex++;
                //path[pos] = pathIndex;

                //return true;
            }
            else { return -1; }
        }
        else { return -1; }

        

    break;
    case 1://east

        if ((pos + 1) % size != 0) {
            if (curMaze->walls[pos + 1].leftWall == 0) {
                //prevPos = pos;
                return pos + 1;
            }
            else { return -1; }
        }
        else { return -1; }

        
        
    break;
    case 2://south

        if (pos < size * (size - 1)) {
            if (curMaze->walls[pos + size].topWall == 0) {
               // prevPos = pos;
                return pos + size;

            }
            else { return -1; }
        }
        else { return -1; }
        
        
    break;
    case 3://west
        if (pos % size != 0) {
            if (curMaze->walls[pos].leftWall == 0) {
               // prevPos = pos;
                return pos - 1;
            }
            else { return -1; }
        }
        else { return -1; }

       
    break;

    default:
        break;
    }
    return -1;//warning as can reach end. in practice can't buuuutt could be as value is char
}

