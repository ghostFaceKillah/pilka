#include<iostream>
#include "state.h"
using namespace std;

int main(int argc, char *argv[]) {
  cout << "Gra w pilkarzyki." << endl;
  // adding some stupid comment to see if git works as wanted

  state game;
  game.loadFromFile("init_pos");
  game.init();
  game.writeToFile("test.state");

};
