#include "maze.hxx"

class depth_first:public maze
{
protected:
    int nextCell(int pos, int size) override;

    void genAlgorithm(int pos, int size) override;

};