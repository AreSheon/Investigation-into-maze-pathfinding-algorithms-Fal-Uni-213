#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
#include <cstring>
#include "general_settings.h"
#include "maze.h"
#include "depth_first.h"
#include "binary_tree.h"
//#include "scource/depth_first.cxx"

using namespace std::this_thread;
using namespace std::chrono;
using namespace general_settings;

int lineWidth = 10;

maze* curMaze;



//mazeSolving
int start = 0; // start position
               
int goal = size * size - 1; // end position

int path[size * size] = {0}; //path array
int mazeBlocks[size * size][5]; //1 is g, 2 is h, 3 is f, 4 is explored, 5 is previous for a star

int pos = start;
int rot = 0; //0 north, rotating clockwise
int pathIndex = 0;
int emptyWalls[4] = { 0 }; //0 not empty, !0 empty
int emptyWallsCount = 0;

/*
//mazeSolving
bool move(maze* curMaze) {
    
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
//utility function that gets the number of empty walls and adds the path to the empty walls array
void getEmptyWalls(maze* curMaze) {
    emptyWallsCount = 0;

    for (int i = 0; i < 4; i++) {
        emptyWalls[i] = 0;
    }

    //north wall
    if (pos >= size) {
        if (curMaze->walls[pos][1]) {
            emptyWalls[emptyWallsCount] = -size;
            emptyWallsCount++;
        }
    }
    
    //east wall
    if ((pos + 1) % size != 0) {
        if (curMaze->walls[pos + 1][0]) {
            emptyWalls[emptyWallsCount] = 1;
            emptyWallsCount++;
        }
    }

    //south wall
    if (pos < size * (size - 1)) {
        if (curMaze->walls[pos + size][1]) {
            emptyWalls[emptyWallsCount] = size;
            emptyWallsCount++;
        }
    }
    
    //west wall
    if (pos % size != 0) {
        if (curMaze->walls[pos][0]) {
            emptyWalls[emptyWallsCount] = -1;
            emptyWallsCount++;
        }
    }
}
void aStarCalculate(int position) {
    int g = mazeBlocks[pos][0] + 1;;
    int h = abs(position % size - goal % size) + abs((position - position % size) / size - (goal - goal % size) / size);
    int f = g + h;

    if (mazeBlocks[position][2] == 0 || mazeBlocks[position][2] < f) {
        mazeBlocks[position][0] = g;
        mazeBlocks[position][1] = h;
        mazeBlocks[position][2] = f;

        mazeBlocks[position][4] = pos;
    }  
}


void solveMazeRH(maze* curMaze) {
    path[0] = 1;
    rot = 1; // look south

    while (pos != goal) {
        rot++;

        if (!move(curMaze)) {
            rot--;
            if (!move(curMaze)) {
                rot--;
                if (!move(curMaze)) {
                    rot--;
                    move(curMaze);
                }
            }
        }
        sleep_for(nanoseconds(delay)); //delay to watch maze getting solved
    }
}
void solveMazeAstar(maze* curMaze) {

    //set everything to 0
    for (int i = 0; i < size * size; i++) {
        for (int j = 0; j < 5; j++) {
            mazeBlocks[i][j] = 0;
        }
    }

    mazeBlocks[pos][0] = 0;
    mazeBlocks[pos][1] = abs(pos % size - goal % size) + abs((pos - pos % size) / size - (goal - goal % size) / size);
    mazeBlocks[pos][2] = mazeBlocks[pos][1];
    mazeBlocks[pos][3] = 1;

    while (pos != goal) {

        sleep_for(nanoseconds(delay)); //delay to watch maze getting solved

        int minf = size * size;
        int minh = size * size;
        int nextCell = start;

        getEmptyWalls(curMaze);

        //iterate through all neighbours
        for (int i = 0; i < emptyWallsCount; i++) {
            //check if neighbor has been visited before
            if (!mazeBlocks[pos + emptyWalls[i]][3]) {
                aStarCalculate(pos + emptyWalls[i]);       
            }
        }
            
        for (int i = 0; i < size * size; i++) {
            //unvisted but calculated
            if (mazeBlocks[i][3] == 0 && mazeBlocks[i][2] != 0) {
                //if it is less than the lowest f make it the lowest f and make it the next cell
                if (mazeBlocks[i][2] < minf) {
                    minf = mazeBlocks[i][2];
                    minh = mazeBlocks[i][1];
                    nextCell = i;
                }else if (mazeBlocks[i][2] == minf && mazeBlocks[i][1] < minh) {
                    minf = mazeBlocks[i][2];
                    minh = mazeBlocks[i][1];
                    nextCell = i;
                }
            }

        }
    
        
        pos = nextCell;
        mazeBlocks[pos][3] = 1;
    }

    while (pos != start) {
        sleep_for(nanoseconds(delay)); 

        path[pos] = -1;
        pos = mazeBlocks[pos][4];
    }

    path[start] = -1;
    pos = goal;
}
*/
int draw() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(700,700, "Maze Solver", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        float gridSize = size;
        int maxPathIndex = 0;

        for (int j = 0; j < size; j++) {
            for (int i = 0; i < size; i++) {

                // j is y
                // i is x

                int position = i + j * size;
                int cpathIndex = path[i + size * j];

                if (cpathIndex > maxPathIndex) {
                    maxPathIndex = cpathIndex;
                }
                if (position == pos) {
                    glColor3f(0, 1, 0);
                }
                else if (position == start) {
                    glColor3f(1, 0, 0);
                }
                else  if (cpathIndex == -1) {
                    glColor3f(1, 1, 0.4);
                }
                else if (mazeBlocks[position][3] != 0) {
                    glColor3f(0.7, 1, 0.7);
                }
                else if (mazeBlocks[position][2] != 0) {
                    glColor3f(0.6, 0.6, 1);
                }
                else if (cpathIndex > 0) {
                    glColor3f(1, 0.6, 0.6);
                }
                else {
                    glColor3f(1, 1, 1);
                }

                glBegin(GL_QUADS);

                glVertex2f(-1 + (2 * i) / gridSize, 1 - (2 * j) / gridSize);
                glVertex2f(-1 + (2 * i) / gridSize + 2 / gridSize, 1 - (2 * j) / gridSize);
                glVertex2f(-1 + (2 * i) / gridSize + 2 / gridSize, 1 - ((2 * j) / gridSize) - 2 / gridSize);
                glVertex2f(-1 + (2 * i) / gridSize, 1 - ((2 * j) / gridSize) - 2 / gridSize);

                glEnd();

                glColor3f(0, 0, 0);

                //vertical walls
                if (curMaze->walls[i + j * size].leftWall == 0) {
                    for (int l = 1; l < lineWidth; l++){
                        glBegin(GL_LINES);
                        glVertex2f(-1 + (2 * i) / gridSize + 0.001 * l, 1 - (2 * j) / gridSize);
                        glVertex2f(-1 + (2 * i) / gridSize + 0.001 * l, 1 - ((2 * j) / gridSize) - 2 / gridSize);
                        glEnd();
                    }   
                }
                

                //horizontal walls
                if (curMaze->walls[i + j * size].topWall == 0) {
                    for (int l = 1; l < lineWidth; l++){
                        glBegin(GL_LINES);
                        glVertex2f(-1 + (2 * i) / gridSize, 1 - (2 * j) / gridSize + 0.001 * l);
                        glVertex2f(-1 + (2 * i) / gridSize + 2 / gridSize, 1 - (2 * j) / gridSize + 0.001 * l);
                        glEnd();
                    }   
                }
            }
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

int main(int argc, char* argv[])
{

    if(argc = 2)
    {
        if(std::strcmp(argv[1], "dp") == 0)//pray
        {
            depth_first dp(size);
            curMaze = &dp;
        }else{
            binary_tree bp(size);
            curMaze = &bp;
        }
    }
    
    srand(time(NULL));

    //red is right hand
    //yellow is a*
    std::thread drawMaze(draw);

    
    curMaze->createMaze();
    

    
    //solveMazeRH(curMaze);
    //pos = start;
    //solveMazeAstar(curMaze);

    drawMaze.join();
    
    return 0;
}
