#include "mazeGen/recursive_backtracker.h"
#include "general_settings.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>

using namespace std::this_thread;
using namespace std::chrono;
using namespace general_settings;

recursive_backtracker::recursive_backtracker(int size) : maze(size)
{
    
}

int recursive_backtracker::nextCell(int pos, int size)
{
    //i = x + width*y;
    
    //genned from top left = 0,0

    int optionCount = 0;
    int options[4];

    //this is bad. imma need to re do the cells ;-;

    //these are the directions?
    //down
    if (pos > size) //is it above row 1
    { if (visited[pos - size] == 0) //reduce y by 1(width is size)
        {options[optionCount] = -size; optionCount++;} }
    //left
    if ((pos + 1) % size != 0) //increase x by 1. is it at the end of a row
    { if (visited[pos + 1] == 0)
        {options[optionCount] = 1; optionCount++; } }
    //up
    if (pos < size * (size - 1)) //is up availiable
    { if (visited[pos + size] == 0) 
        {options[optionCount] = size; optionCount++; } }
    //right
    if (pos % size != 0) //
    { if (visited[pos - 1] == 0) 
        {options[optionCount] = -1; optionCount++; } }

    if (optionCount == 0) { return 0; };

    return (options[rand() % optionCount]); //random direction
}

void recursive_backtracker::genAlgorithm(int pos, int size)
{
    visited[pos] = 1;

    int next = pos + nextCell(pos, size);

    while (next != pos) {
        //sleep_for(nanoseconds(delay)); //delay to watch maze getting created
        connect(pos, next);
        pos = next;
        genAlgorithm(pos, size);
        next = pos + nextCell(pos, size);
    }
}
