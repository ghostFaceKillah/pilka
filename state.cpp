#include "state.h"
using namespace std;

bool* makeArray(int n, int m) {
  bool *a = new bool[n*m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      a[i*m + j] = ( i == 0 | j == 0 | i == n-1 | j == m-1 ) &&
                   ( j != (m - 1) / 2 ) && ( j != m / 2);
  };
  return a;
};

void printArray (bool a[], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) 
      cout << a[i*m + j] << " ";
    cout << endl;
  };
};

void correctDots(bool *a, int n, int m) {
  a[ (m-1)/2 + 1] = a[ (m-1)/2 - 1] = 0;
  a[ m*(n-1) + (m-1)/2 + 1] = a[ m*(n-1) + (m-1)/2 - 1] = 0;
  a[ m*(n-1)/2 + (m-1)/2 ] = 1;
  for (int j = 1; j < m-1; j++) 
    a[m*(n-2) + j] = a[m + j] = j != (m-1)/2;
};

GameState::GameState(int n, int m) {
  ball_x = m / 2;
  ball_y = n / 2;
  h = n;
  w = m;
  dots  = makeArray(h+3, w+1);
  correctDots(dots, h+3, w+1);
  vert  = makeArray(h+2, w+1);
  hor   = makeArray(h  , w+2);
  diag  = makeArray(h+2, w+2);
  adiag = makeArray(h+2, w+2);
};

void GameState::show() {
  cout << "ball_x" << endl;
  cout << ball_x << endl;
  cout << "ball_y" << endl;
  cout << ball_y << endl;
  cout << "dots" << endl;
  printArray(dots, h+3, w+1);
  cout << "vert" << endl;
  printArray(vert, h+2, w+1);
  cout << "horizontal" << endl;
  printArray(hor, h  , w+2);
  cout << "diags" << endl;
  printArray(diag, h+2, w+2);
  cout << "adiag" << endl;
  printArray(adiag, h+2, w+2);
};
