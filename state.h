#include <iostream>
#include <vector>

class GameState {
  private:
    int ball_x, ball_y;
    int h, w;
    bool *dots; // h+2, w+1
    bool *vert; // h+2, w+1
    bool *hor;  // h  , w+2    
    bool *diag; // h+2, w+2
    bool *adiag;// h+2, w+2
  public:
    GameState(int, int);
    void show();
};
