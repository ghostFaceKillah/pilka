#include<iostream>
#include<fstream>
using namespace std;

struct state {
  int current_x, current_y;
  bool kropki[13][9];
  bool vertical[12][9];
  bool horizontal[11][10];
  bool diags [12][10];
  bool adiags [12][10];
  void write();
  void writeToFile(string);
  void loadFromFile(string);
  void init();
};

