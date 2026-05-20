#pragma once

#include "maze.h"

class binary_tree: public maze{

public:
    binary_tree(int size);
    ~binary_tree() = default;

protected:
    int nextCell(int pos, int size) override;

    void genAlgorithm(int pos, int size) override;

};

