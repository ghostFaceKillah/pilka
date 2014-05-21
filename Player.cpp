#include "Player.h"
#include <math.h>

int AIPlayer::judgeState(bool is_min, GameState &game, int h) {
  if (h == max_depth) {
    return (3*game.ball_y)/2  + abs(game.ball_x - (game.w-1)/2);
  } else {
    int moves[8];
    option is;
    for (int i = 0; i < 8; i++) {
      is = game.isPossible(i, is_min);
      if (is == yes) {
        game.applyStickAndDot(i);
        moves[i] = judgeState(not(is_min), game, h+1);
        game.deapplyStickAndDot(i);
      } else if (is == nonfinal) {
        game.applyStickAndDot(i);
        moves[i] = judgeState(is_min, game, h+1);
        game.deapplyStickAndDot(i);
      } else if (is == win){
        if (is_min) {
          return -2*game.h*game.h;
        } else {
          return 2*game.h*game.h;
        }
      } else {
        if (is_min) {
          moves[i] = 2*game.h*game.h;
        } else {
          moves[i] = -2*game.h*game.h;
        };
      };
    };
    if (is_min) {
      int min_v = 3*game.h*game.h;
      int min = -1;
      for (int i = 0; i < 8; i++)
        if (moves[i] < min_v) {
          min_v = moves[i];
          min = i;
        };
      return min_v;
    } else {
      int max_v = -3*game.h*game.h;
      int max = -1;
      for (int i = 0; i < 8; i++)
        if (moves[i] > max_v) {
          max_v = moves[i];
          max = i;
        };
      return max_v;
    };
  };
  return 0;
};

int AIPlayer::decide(GameState &game) {
  // lets assume we play min
  int moves[8];
  option is;
  for (int i = 0; i < 8; i++) {
    is = game.isPossible(i, true);
    if (is == yes) {
      game.applyStickAndDot(i);
      moves[i] = judgeState(false, game, 0);
      game.deapplyStickAndDot(i);
    } else if (is == nonfinal) {
      game.applyStickAndDot(i);
      moves[i] = judgeState(true, game, 0);
      game.deapplyStickAndDot(i);
    } else if (is == win) {
      return i;
    } else if (is == loss ) {
      moves[i] = game.h*game.h;
    } else {
      moves[i] = 2*game.h*game.h;
    };
    // std::cout << "ai considered "<< i << std::endl;
  };
  int min_v = 3*game.h*game.h;
  int min = -1;
  for (int i = 0; i < 8; i++)
    if (moves[i] < min_v) {
      min_v = moves[i];
      min = i;
    };
  return min;
};

int HumanPlayer::decide(GameState &game) {
  int k;
  while (true) {
    std::cout << "please enter your move player" << std::endl;
    std::cin >> k;
    if (game.isPossible(k, false) != no) {
      return k;
    } else {
      std::cout << "move imposible man" << std::endl;
    };
  };
};
