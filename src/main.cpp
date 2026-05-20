#include <iostream>


#include "Grid.h"


using namespace std;

int main(int argc, char* argv[]){
    cout << "boop";
    
    Grid grid(5, 5, 5);

    grid.generateGrid();
    
    return 0;
}
