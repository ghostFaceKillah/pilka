#include "GameState.h"
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
  ball_y = 1 + n  / 2;
  h = n;
  w = m;
  dots  = makeArray(h+3, w+1); correctDots(dots, h+3, w+1);
  vert  = makeArray(h+2, w+1);
  hor   = makeArray(h+1, w+2);
  diag  = makeArray(h+2, w+2);
  adiag = makeArray(h+2, w+2);
};

void GameState::show() {
  cout << h << " " << w << endl;
  cout << "ball_x" << endl;
  cout << ball_x << endl;
  cout << "ball_y" << endl;
  cout << ball_y << endl;
  cout << "dots" << endl;
  printArray(dots, h+3, w+1);
  cout << "vert" << endl;
  printArray(vert, h+2, w+1);
  cout << "hor" << endl;
  printArray(hor, h+1, w+2);
  cout << "diag" << endl;
  printArray(diag, h+2, w+2);
  cout << "adiag" << endl;
  printArray(adiag, h+2, w+2);
};

void writeArrayToFile(bool a[], int n, int m, ofstream &myfile) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) 
      myfile << a[i*m + j] << " ";
    myfile << endl;
  };
};

void GameState::writeToFile(string filename) {
  ofstream myfile;
  myfile.open(filename);
  myfile << h << " " << w << endl;
  myfile << "ball_x" << endl;
  myfile << ball_x << endl;
  myfile << "ball_y" << endl;
  myfile << ball_y << endl;
  myfile << "dots" << endl;
  writeArrayToFile(dots, h+3, w+1, myfile);
  myfile << "vert" << endl;
  writeArrayToFile(vert, h+2, w+1, myfile);
  myfile << "hor" << endl;
  writeArrayToFile(hor, h+1, w+2, myfile);
  myfile << "diag" << endl;
  writeArrayToFile(diag, h+2, w+2, myfile);
  myfile << "adiag" << endl;
  writeArrayToFile(adiag, h+2, w+2, myfile);
};

bool GameState::existsLine(int move) {
  bool resu;
  switch (move)
  {
    // watch out, as making array bigger can cause a possible bug
    case 0:
      resu = vert[(ball_y-1)*(w+1) + ball_x];
    break;
    case 1:
      resu = diag[(ball_y-1)*(w+2) + ball_x+1];
    break;
    case 2:
      resu = hor[(ball_y-1)*(w+2) + ball_x+1];
    break;
    case 3:
      resu = adiag[(ball_y)*(w+2) + ball_x+1];
    break;
    case 4:
      resu = vert[ball_y*(w+1) + ball_x];
    break;
    case 5:
      resu = diag[ball_y*(w+2) + ball_x];
    break;
    case 6:
      resu = hor[(ball_y-1)*(w+2) + ball_x];
    break;
    case 7:
      resu = adiag[(ball_y-1)*(w+2) + ball_x];
    break;
  };
  return resu;
};

bool GameState::dotNeeded(int dot_y, int dot_x) {
  bool resu;
  resu = 
    ((dot_x == w / 2 ) && (dot_y == 1 + h  / 2 )) ||
    vert[(dot_y-1)*(w+1) + dot_x] ||
    diag[(dot_y-1)*(w+2) + dot_x+1] ||
    hor[(dot_y-1)*(w+2) + dot_x+1] ||
    adiag[(dot_y)*(w+2) + dot_x+1] ||
    vert[dot_y*(w+1) + dot_x] ||
    diag[dot_y*(w+2) + dot_x] ||
    hor[(dot_y-1)*(w+2) + dot_x] ||
    adiag[(dot_y-1)*(w+2) + dot_x];
  return resu;
};

bool GameState::withoutExit() {
  bool resu;
  resu = vert[(ball_y-1)*(w+1) + ball_x] &&
         diag[(ball_y-1)*(w+2) + ball_x+1] && 
         hor[(ball_y-1)*(w+2) + ball_x+1] && 
         adiag[(ball_y)*(w+2) + ball_x+1] && 
         vert[ball_y*(w+1) + ball_x] && 
         diag[ball_y*(w+2) + ball_x] && 
         hor[(ball_y-1)*(w+2) + ball_x] && 
         adiag[(ball_y-1)*(w+2) + ball_x];
  return resu;
};

bool GameState::goalDot(bool isMin) {
  if (isMin) {
    return (ball_y == 0) && ((ball_x == w/2 - 1) || 
                               (ball_x == w/2) || (ball_x == w/2 + 1) );
  } else {
    return (ball_y == h+2) && ((ball_x == w/2 - 1) || 
                               (ball_x == w/2) || (ball_x == w/2 + 1) );
  };
};

bool GameState::isLosingMove(int move) {
  applyStickAndDot(move);
  bool resu = withoutExit();
  deapplyStickAndDot(move);
  return resu;
};

bool GameState::isWinningMove(bool isMin, int move) {
  applyStickAndDot(move);
  bool resu = goalDot(isMin);
  deapplyStickAndDot(move);
  return resu;
};

bool GameState::existsDot(int move) {
  bool resu;
  switch (move)
  {
    // watch out, as making array bigger can cause a possible bug
    case 0:
      resu = dots[(ball_y-1)*(w+1) + ball_x];
    break;
    case 1:
      resu = dots[(ball_y-1)*(w+1) + ball_x + 1];
    break;
    case 2:
      resu = dots[(ball_y)*(w+1) + ball_x + 1];
    break;
    case 3:
      resu = dots[(ball_y+1)*(w+1) + ball_x + 1];
    break;
    case 4:
      resu = dots[(ball_y+1)*(w+1) + ball_x];
    break;
    case 5:
      resu = dots[(ball_y+1)*(w+1) + ball_x-1];
    break;
    case 6:
      resu = dots[(ball_y)*(w+1) + ball_x-1];
    break;
    case 7:
      resu = dots[(ball_y-1)*(w+1) + ball_x-1];
    break;
  };
  return resu;
};


option GameState::isPossible(int move, bool isMin) { 
  if (existsLine(move)) 
    {return no;}
  else {
    if (isLosingMove(move)) {
      return loss;
    } else if (isWinningMove(not(isMin), move)) {
      return loss;
    } else if (isWinningMove(isMin, move)) {
      return win;
    } else if (existsDot(move)) {
      return nonfinal;
    } else {
      return yes;
    };
  };
};

void GameState::applyStickAndDot(int move) {
  switch (move)
  {
    // watch out, as making array bigger can cause a possible bug
    case 0:
      vert[(ball_y-1)*(w+1) + ball_x] = true;
      dots[(ball_y-1)*(w+1) + ball_x] = true;
      ball_y -= 1; 
    break;
    case 1:
      diag[(ball_y-1)*(w+2) + ball_x+1] = true;
      dots[(ball_y-1)*(w+1) + ball_x + 1] = true;
      ball_y -= 1; 
      ball_x += 1; 
    break;
    case 2:
      hor[(ball_y-1)*(w+2) + ball_x+1] = true;
      dots[(ball_y)*(w+1) + ball_x + 1] = true;
      ball_x += 1; 
    break;
    case 3:
      adiag[(ball_y)*(w+2) + ball_x+1] = true;
      dots[(ball_y+1)*(w+1) + ball_x + 1] = true;
      ball_y += 1; 
      ball_x += 1; 
    break;
    case 4:
      vert[ball_y*(w+1) + ball_x] = true;
      dots[(ball_y+1)*(w+1) + ball_x] = true;
      ball_y += 1; 
    break;
    case 5:
      diag[ball_y*(w+2) + ball_x] = true;
      dots[(ball_y+1)*(w+1) + ball_x-1] = true;
      ball_y += 1; 
      ball_x -= 1; 
    break;
    case 6:
      hor[(ball_y-1)*(w+2) + ball_x] = true;
      dots[(ball_y)*(w+1) + ball_x-1] = true;
      ball_x -= 1; 
    break;
    case 7:
      adiag[(ball_y-1)*(w+2) + ball_x] = true;
      dots[(ball_y-1)*(w+1) + ball_x-1] = true;
      ball_y -= 1; 
      ball_x -= 1; 
    break;
  };
};

void GameState::deapplyStickAndDot(int move) {
  switch (move)
  {
    case 0:
      ball_y += 1; 
      vert[(ball_y-1)*(w+1) + ball_x] = false;
      dots[(ball_y-1)*(w+1) + ball_x] = dotNeeded(ball_y - 1, ball_x);
    break;
    case 1:
      ball_y += 1; 
      ball_x -= 1; 
      diag[(ball_y-1)*(w+2) + ball_x+1] = false;
      dots[(ball_y-1)*(w+1) + ball_x + 1] = dotNeeded(ball_y-1, ball_x + 1);
    break;
    case 2:
      ball_x -= 1; 
      hor[(ball_y-1)*(w+2) + ball_x+1] = false;
      dots[(ball_y)*(w+1) + ball_x + 1] = dotNeeded(ball_y, ball_x + 1);
    break;
    case 3:
      ball_y -= 1; 
      ball_x -= 1; 
      adiag[(ball_y)*(w+2) + ball_x+1] = false;
      dots[(ball_y+1)*(w+1) + ball_x + 1] = dotNeeded(ball_y + 1, ball_x + 1);
    break;
    case 4:
      ball_y -= 1; 
      vert[ball_y*(w+1) + ball_x] = false;
      dots[(ball_y+1)*(w+1) + ball_x] = dotNeeded(ball_y + 1, ball_x);
    break;
    case 5:
      ball_y -= 1; 
      ball_x += 1; 
      diag[ball_y*(w+2) + ball_x] = false;
      dots[(ball_y+1)*(w+1) + ball_x-1] = dotNeeded(ball_y + 1, ball_x - 1);
    break;
    case 6:
      ball_x += 1; 
      hor[(ball_y-1)*(w+2) + ball_x] = false;
      dots[(ball_y)*(w+1) + ball_x-1] = dotNeeded(ball_y, ball_x-1);
    break;
    case 7:
      ball_y += 1; 
      ball_x += 1; 
      adiag[(ball_y-1)*(w+2) + ball_x] = false;
      dots[(ball_y-1)*(w+1) + ball_x-1] = dotNeeded(ball_y-1, ball_x-1);
    break;
  };
};


void GameState::applyTurn(string turn)  {
  int k;
  for (int i = 0; i < turn.length(); i++) {
    k = turn[i] - '0';
    applyStickAndDot(k);
  };
};

