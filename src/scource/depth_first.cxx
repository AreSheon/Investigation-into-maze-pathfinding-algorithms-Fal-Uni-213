#include "depth_first.hxx"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>

using namespace std::this_thread;
using namespace std::chrono;

int depth_first::nextCell(int pos, int size)
{
    
    int optionCount = 0;
    int options[4];

    if (pos > size) { if (visited[pos - size] == 0) {options[optionCount] = -size; optionCount++;} }
    if ((pos + 1) % size != 0) { if (visited[pos + 1] == 0) {options[optionCount] = 1; optionCount++; } }
    if (pos < size * (size - 1)) { if (visited[pos + size] == 0) {options[optionCount] = size; optionCount++; } }
    if (pos % size != 0) { if (visited[pos - 1] == 0) {options[optionCount] = -1; optionCount++; } }

    if (optionCount == 0) { return 0; };

    return (options[rand() % optionCount]);
}

void depth_first::genAlgorithm(int pos, int size)
{
     visited[pos] = 1;
    int next = pos + nextCell(pos, size);

    while (next != pos) {
        sleep_for(nanoseconds(delay)); //delay to watch maze getting created
        connect(pos, next);
        pos = next;
        genAlgorithm(pos, size);
        next = pos + nextCell(pos, size);
    }
}