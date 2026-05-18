#pragma once

#include "maze.hxx"

class binary_tree: public maze{

public:
    binary_tree() = default;
    ~binary_tree() = default;

protected:
    int nextCell(int pos, int size) override;

    void genAlgorithm(int pos, int size) override;

};

