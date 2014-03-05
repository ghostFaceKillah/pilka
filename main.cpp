#include<iostream>
#include "state.h"
using namespace std;


int main(int argc, char *argv[]) {
  cout << "Gra w pilkarzyki." << endl;

  state game;
  game = loadFromFile("init_pos");
  writeToFile(game, "display/test.state");
  int k;
  option opt;
  while (true) {
    cout << "insert your move muchacho" << endl;
    cin >> k;
    opt = isPossible(k, game);
    if (opt != no) {
      game = applyStickAndDot(k, game);
      writeToFile(game, "display/test.state");
    } else {
      cout << "move impossible man" << endl;
    };
  };
};
