#include <GLFW/glfw3.h>
#include <iostream>
#include "tree_search.hxx"
#include "maze.hxx"

tree_search::tree_search(maze* mazeToSolve){
    curMaze = mazeToSolve;
}

    //mazeSolving
bool tree_search::move(maze* curMaze) {
    
    char dir = '/';

    if (abs(rot) % 4 == 0) { //pointing north
        dir = 'N';
    }
    else if (abs(rot) % 4 == 1) {
        dir = 'E';
    }
    else if (abs(rot) % 4 == 2) {
        dir = 'S';
    }
    else if (abs(rot) % 4 == 3) {
        dir = 'W';
    }

    switch (dir) {
    case 'E':   
        if ((pos + 1) % size != 0) {
            if (curMaze->walls[pos + 1][0] == 1) {
                //prevPos = pos;
                pos += 1;

                pathIndex++;
                path[pos] = pathIndex;
                
                return true;
            }
            else { return false; }
        }
        else { return false; }

    break;
    case 'S':
        if (pos < size * (size - 1)) {
            if (curMaze->walls[pos + size][1] == 1) {
               // prevPos = pos;
                pos += size;

                pathIndex++;
                path[pos] = pathIndex;

                return true;
            }
            else { return false; }
        }
        else { return false; }
        
    break;
    case 'W':
        if (pos % size != 0) {
            if (curMaze->walls[pos][0] == 1) {
               // prevPos = pos;
                pos -= 1;

                pathIndex++;
                path[pos] = pathIndex;

                return true;
            }
            else { return false; }
        }
        else { return false; }
        
    break;
    case 'N':  
        if (pos >= size) {
            if (curMaze->walls[pos][1] == 1) {
              //  prevPos = pos;
                pos -= size;

                pathIndex++;
                path[pos] = pathIndex;

                return true;
            }
            else { return false; }
        }
        else { return false; }
       
    break;

    default:
        break;
    }
}

