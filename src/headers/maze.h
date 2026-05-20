#pragma once

//#include "general_settings.h"

//using namespace general_settings;

class maze {

public:
//thank you joe :)   
    struct wall {
        bool leftWall = false;
        bool topWall = false;
    };

    explicit maze(int size);
//end joe :)
    virtual ~maze();

    bool* visited;
    wall* walls; //0 for a wall, 1 for no wall left -> top
    
   

protected:


  virtual int nextCell(int pos, int size){
    return 0;
  }

  /**connect 2 cells
   * 
   //function from forked repo
  */
  void connect(int pos1, int pos2);

virtual void genAlgorithm(int pos, int size){}

public:

void createMaze();
};
