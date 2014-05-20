#include "Player.h"
#include <math.h>

using namespace std;

int main() {
  GameState game(10, 8);
  game.writeToFile("display/test.state");
  int move;
  HumanPlayer me;
  HumanPlayer me2;
  AIPlayer ai;
  int t = 1;
  int decision;

  while (t) {
    if (t % 2 == 0) {
      decision = ai.decide(game);
    } else {
      decision = me.decide(game);
    };
    if (game.isPossible(decision, (t % 2 == 1)) != nonfinal) {
      t++;
    } else {
      cout << "someone gets one more move" << endl;
    };
    game.applyStickAndDot(decision);
    game.writeToFile("display/test.state");
  };
};

