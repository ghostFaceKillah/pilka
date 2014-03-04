#include<iostream>
#include "state.h"
using namespace std;

int main(int argc, char *argv[]) {
  cout << "Gra w pilkarzyki." << endl;

  state game;
  game.loadFromFile("init_pos");
  game.init();
  game.writeToFile("test.state");

};
