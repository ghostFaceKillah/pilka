#include "GameState.h"

class Player {

public:
  virtual int decide(GameState &game) = 0;

};

class AIPlayer : public Player {
  private:
    int max_depth;
    int judgeState(bool, GameState &, int);
  public:
    AIPlayer() {
      max_depth = 8;
    };
    int decide(GameState &game);
};

class HumanPlayer : public Player {
  public:
    int decide(GameState &game);

};
