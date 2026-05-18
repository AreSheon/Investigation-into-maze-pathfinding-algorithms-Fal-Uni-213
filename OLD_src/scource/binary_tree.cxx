//general algorithm from https://weblog.jamisbuck.org/2011/2/1/maze-generation-binary-tree-algorithm

#include "binary_tree.hxx"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>

using namespace std::this_thread;
using namespace std::chrono;

int binary_tree::nextCell(int pos, int size)
{
   //i = x + width*y;
    
    //genned from top left

    //for ease just keeping bias down & right

    int optionCount = 0;
    int options[2];


    //these are the directions?
    if (pos > size) //is it above row 1
    //reduce y by 1(width is size)
        {options[optionCount] = -size; optionCount++;} 

    //doesn't need to track if visited or not
    if (pos % size != 0) //go right
        {options[optionCount] = -1; optionCount++; }

    if (optionCount == 0) { return 0; };//bottom right cell

    return (options[rand() % optionCount]); //random direction
}

void binary_tree::genAlgorithm(int pos, int size)
{
    
    
    for(int i = 0; i < size * size; i++){
        //go cell by cell
        visited[i] = 1;
        //get the cell to carve passage too
        int carveCell = i + nextCell(i, size);
        sleep_for(nanoseconds(delay)); //delay to watch maze getting created
        connect(i, carveCell);
        
    }
}