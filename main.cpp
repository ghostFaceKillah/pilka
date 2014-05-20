#include "GameState.h"

using namespace std;

int main() {
  GameState game(8, 6);
  game.writeToFile("display/test.state");
  int move;
  while (1) {
    cin >> move;
    if (game.isPossible(move) != no ) {
      game.applyStickAndDot(move);
      game.writeToFile("display/test.state");
    } else {
      cout << "move impossible man" << endl;
    };
  };
};

