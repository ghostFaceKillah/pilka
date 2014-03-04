#include<iostream>
#include "state.h"
using namespace std;

enum option {
  yes = 0,
  nonfinal = 1,
  no = 2
};

bool existsLine(int move, state g_st) {
  bool resu;
  switch (move)
  {
    // watch out, as making array bigger can cause a possible bug
    case 0:
      resu = g_st.vertical[g_st.current_x-1][g_st.current_y];
    break;
    case 1:
      resu = g_st.diags[g_st.current_x-1][g_st.current_y+1];
    break;
    case 2:
      resu = g_st.horizontal[g_st.current_x-1][g_st.current_y+1];
    break;
    case 3:
      resu = g_st.adiags[g_st.current_x][g_st.current_y+1];
    break;
    case 4:
      resu = g_st.vertical[g_st.current_x][g_st.current_y];
    break;
    case 5:
      resu = g_st.diags[g_st.current_x][g_st.current_y];
    break;
    case 6:
      resu = g_st.horizontal[g_st.current_x-1][g_st.current_y];
    break;
    case 7:
      resu = g_st.adiags[g_st.current_x-1][g_st.current_y];
    break;
  };
  return resu;
};

bool existsDot(int move, state g_st) {
  bool resu;
  switch (move)
  {
    // watch out, as making array bigger can cause a possible bug
    case 0:
      resu = g_st.kropki[g_st.current_x-1][g_st.current_y];
    break;
    case 1:
      resu = g_st.kropki[g_st.current_x-1][g_st.current_y+1];
    break;
    case 2:
      resu = g_st.kropki[g_st.current_x][g_st.current_y+1];
    break;
    case 3:
      resu = g_st.kropki[g_st.current_x+1][g_st.current_y+1];
    break;
    case 4:
      resu = g_st.kropki[g_st.current_x+1][g_st.current_y];
    break;
    case 5:
      resu = g_st.kropki[g_st.current_x+1][g_st.current_y-1];
    break;
    case 6:
      resu = g_st.kropki[g_st.current_x][g_st.current_y-1];
    break;
    case 7:
      resu = g_st.kropki[g_st.current_x-1][g_st.current_y-1];
    break;

  };
  return resu;
};


option isPossible(int move, state g_s) { 
  if (existsLine(move,g_s)) 
    {return no;}
  else {
    if (existsDot(move, g_s) )
      {return nonfinal;}
    else 
     {return yes;};
  };
};

state applyStickAndDot(int move, state g_st) {
  switch (move)
  {
    // watch out, as making array bigger can cause a possible bug
    case 0:
      g_st.vertical[g_st.current_x-1][g_st.current_y] = true;
      g_st.kropki[g_st.current_x-1][g_st.current_y] = true;
      g_st.current_x -= 1; 
    break;
    case 1:
      g_st.diags[g_st.current_x-1][g_st.current_y+1] = true;
      g_st.kropki[g_st.current_x-1][g_st.current_y+1] = true;
      g_st.current_x -= 1; 
      g_st.current_y += 1; 
    break;
    case 2:
      g_st.horizontal[g_st.current_x-1][g_st.current_y+1] = true;
      g_st.kropki[g_st.current_x][g_st.current_y+1] = true;
      g_st.current_y += 1; 
    break;
    case 3:
      g_st.adiags[g_st.current_x][g_st.current_y+1] = true;
      g_st.kropki[g_st.current_x+1][g_st.current_y+1] = true;
      g_st.current_x += 1; 
      g_st.current_y += 1; 
    break;
    case 4:
      g_st.vertical[g_st.current_x][g_st.current_y] = true;
      g_st.kropki[g_st.current_x+1][g_st.current_y] = true;
      g_st.current_x += 1; 
    break;
    case 5:
      g_st.diags[g_st.current_x][g_st.current_y] = true;
      g_st.kropki[g_st.current_x+1][g_st.current_y-1] = true;
      g_st.current_x += 1; 
      g_st.current_y -= 1; 
    break;
    case 6:
      g_st.horizontal[g_st.current_x-1][g_st.current_y] = true;
      g_st.kropki[g_st.current_x][g_st.current_y-1] = true;
      g_st.current_y -= 1; 
    break;
    case 7:
      g_st.adiags[g_st.current_x-1][g_st.current_y] = true;
      g_st.kropki[g_st.current_x-1][g_st.current_y-1] = true;
      g_st.current_x -= 1; 
      g_st.current_y -= 1; 
    break;
  };
  return g_st;
};



int main(int argc, char *argv[]) {
  cout << "Gra w pilkarzyki." << endl;

  state game;
  game.loadFromFile("init_pos");
  game.writeToFile("display/test.state");
  int k;
  option opt;
  while (true) {
    cout << "insert your move muchacho" << endl;
    cin >> k;
    opt = isPossible(k, game);
    if (opt != no) {
      game = applyStickAndDot(k, game);
      game.writeToFile("display/test.state");
    } else {
      cout << "move impossible man" << endl;
    };
  };
};
