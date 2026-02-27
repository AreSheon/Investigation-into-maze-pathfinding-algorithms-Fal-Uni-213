

class maze {

public:
  
  //maze(){

 // }
  //~maze(){

 // }

  // just globally set for all mazes
    static const int size = 30;
    int delay = 1500000; // delay in ns for visualisation
  
    bool visited[size * size];
    
    bool walls[size * size][2]; //0 for a wall, 1 for no wall left -> top
 


protected:


  virtual int nextCell(int pos, int size);

  /**connect 2 cells
   * 
   //function from forked repo
  */
  void connect(int pos1, int pos2) {
    if (pos2 > pos1) {
        if (pos2 == pos1 + 1) {
            walls[pos2][0] = 1;
        }
        else {
            walls[pos2][1] = 1;
        }
    }
    else {
        if (pos1 == pos2 + 1) {
            walls[pos1][0] = 1;
        }
        else {
            walls[pos1][1] = 1;
        }
    }
}

virtual void genAlgorithm(int pos, int size);

public:

void createMaze() {
      int pos = 0;
      
      for (int i = 0; i < size * size; i++) {
          visited[i] = 0;
      }

      genAlgorithm(pos, size);
  }
};