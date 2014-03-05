#include<iostream>
#include<fstream>
using namespace std;

enum option {
  yes = 0,
  nonfinal = 1,
  no = 2
};

struct state {
  int current_x, current_y;
  bool kropki[13][9];
  bool vertical[12][9];
  bool horizontal[11][10];
  bool diags [12][10];
  bool adiags [12][10];
  void init();
};

void write(state);
void writeToFile(state, string);
state loadFromFile(string);
bool existsLine(int move, state g_st);
bool existsDot(int move, state g_st);
option isPossible(int move, state g_s);
state applyStickAndDot(int move, state g_st);
