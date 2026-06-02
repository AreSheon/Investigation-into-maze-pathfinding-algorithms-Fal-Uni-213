#include "pathfinding/RHS.h"
#include "mazeGen/maze.h"
#include <iostream>

RHS::RHS(maze* mazeToSolve) : tree_search(mazeToSolve){

}

int RHS::incrementRot(){//turn right
    if(rot < 3){
        return rot + 1;
    }
    else{
        return 0;
    }
}
int RHS::decrementRot() // turn left
{
    if(rot > 0){
        return rot - 1;
    }
    else{
        return 3;
    }
}


void RHS::solveMaze(maze* curMaze){
    path.push_back(0);
    pos = 0;
    rot = 0;

    int index = 0;
    rot = 2;

    while(pos < goal && index < 100){//index is just a stopper so doesn't run forever
        index ++;
        int nextPos = move(curMaze,pos, incrementRot());
        if(nextPos >= 0){
            rot = incrementRot();
            //std::cout<<rot;
            pos = nextPos;
            path.push_back(pos);
            //return nextPos;
        }else if(move(curMaze,pos, rot) >= 0){//if can't turn right, try move forward
            nextPos = move(curMaze,pos,rot);
            pos = nextPos;
            //std::cout<<rot;
            path.push_back(pos);
            //return nextPos;
        }else{
            rot = decrementRot();
            //std::cout<<rot;
            //return TryNewDir();
        }
        std::cout<<pos<<" "<< curMaze->walls[pos].topWall << " "<< curMaze->walls[pos].leftWall <<"\n";
        //pos = TryNewDir();
        

        //rot = 2;
        
       /*
        if (!move(curMaze)) {
            rot--;
            if (!move(curMaze)) {
                rot--;
                if (!move(curMaze)) {
                  S  rot--;
                    move(curMaze);
                }
            }
        }*/
        //sleep_for(nanoseconds(delay)); //delay to watch maze getting solved
    }
}


