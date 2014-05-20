#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum option {
  yes = 0,
  nonfinal = 1,
  no = 2
};

class GameState {
  private:
    int ball_x, ball_y;
    int h, w;
    bool *dots; // h+3, w+1
    bool *vert; // h+2, w+1 
    bool *hor;  // h+1, w+2    
    bool *diag; // h+2, w+2
    bool *adiag;// h+2, w+2
  public:
    GameState(int, int);
    void show();
    void writeToFile(std::string filename);
    bool existsLine(int move);
    bool existsDot(int move);
    option isPossible(int move);
    void applyStickAndDot(int move);
    void applyTurn(std::string turn);
};
