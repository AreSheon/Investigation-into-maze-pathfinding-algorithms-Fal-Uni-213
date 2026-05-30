#include <GLFW/glfw3.h>
#include "general_settings.h"
#include "mazeGen/maze.h"

using namespace general_settings;

//thank you joe :)
maze::maze(int size) : visited(new bool[size * size]), walls(new wall[size * size]) 
{

}

maze::~maze() {
    delete[] visited;
    delete[] walls;
}
//thank you joe :)

void maze::connect(int pos1, int pos2)
{
    if (pos2 > pos1) {
        if (pos2 == pos1 + 1) {
            walls[pos2].topWall = true;
        }
        else {
            walls[pos2].leftWall = true;
        }
    }
    else {
        if (pos1 == pos2 + 1) {
            walls[pos1].topWall = true;
        }
        else {
            walls[pos1].leftWall = true;
        }
    }
}

void maze::createMaze()
{
    int pos = 0;
      
    for (int i = 0; i < size * size; i++) 
    {
      visited[i] = 0;
    }

    genAlgorithm(pos, size);
}
