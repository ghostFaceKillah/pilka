#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum option {
  yes = 0,
  nonfinal = 1,
  no = 2,
  win = 3,
  loss = 4
};

struct GameState {
  int ball_x, ball_y;
  int h, w;
  bool *dots; // h+3, w+1
  bool *vert; // h+2, w+1 
  bool *hor;  // h+1, w+2    
  bool *diag; // h+2, w+2
  bool *adiag;// h+2, w+2

  GameState(int, int);
  void show();
  void writeToFile(std::string filename);
  bool existsLine(int move);
  bool existsDot(int move);
  bool dotNeeded(int, int);
  option isPossible(int move, bool isMin);
  void applyStickAndDot(int move);
  void deapplyStickAndDot(int move);
  void applyTurn(std::string turn);
  bool isWinningMove(bool isMin, int move);
  bool isLosingMove(int move);
  bool goalDot(bool isMin);
  bool withoutExit();
};
