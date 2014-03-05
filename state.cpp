#include "state.h"
#include<string>


void write(state g_s) {
  int k,l;
  
  cout << "current_x" << endl;
  cout << g_s.current_x << endl;
  cout << "current_y" << endl;
  cout << g_s.current_y << endl;

  cout << "kropki" << endl;
  k = 13; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      cout <<  g_s.kropki[i][j] << " ";
    } cout << endl;
  };

  cout << "vertical" << endl;
  k = 12; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      cout <<  g_s.vertical[i][j] << " ";
    } cout << endl;
  };

  cout << "horizontal" << endl;
  k = 11; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      cout <<  g_s.horizontal[i][j] << " ";
    } cout << endl;
  };

  cout << "diags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) { 
      cout <<  g_s.diags[i][j] << " "; 
    } cout << endl;
  };

  cout << "adiags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) { 
    for (int j = 0; j<l; j++) {
      cout <<  g_s.adiags[i][j] << " "; 
    } cout << endl;
  };
};


void writeToFile(state g_s, string s) {
  int k,l;
  ofstream myfile;
  myfile.open (s);

  myfile << "current_x" << endl;
  myfile << g_s.current_x << endl;
  myfile << "current_y" << endl;
  myfile << g_s.current_y << endl;

  myfile << "kropki" << endl;
  k = 13; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile <<  g_s.kropki[i][j] << " ";
    } myfile << endl;
  };

  myfile << "vertical" << endl;
  k = 12; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile <<  g_s.vertical[i][j] << " ";
    } myfile << endl;
  };

  myfile << "horizontal" << endl;
  k = 11; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile <<  g_s.horizontal[i][j] << " ";
    } myfile << endl;
  };

  myfile << "diags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) { 
      myfile <<  g_s.diags[i][j] << " "; 
    } myfile << endl;
  };

  myfile << "adiags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) { 
    for (int j = 0; j<l; j++) {
      myfile <<  g_s.adiags[i][j] << " "; 
    } myfile << endl;
  };
  myfile.close();
};

state loadFromFile(string s) {
  int k,l;
  string drop;
  state resu;
  ifstream myfile (s);

  // x, y 
  myfile >> drop;
  myfile >> resu.current_x;
  myfile >> drop;
  myfile >> resu.current_y;

  // kropki
  myfile >> drop;
  k = 13; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile >> resu.kropki[i][j];
    }
  };

  //vertical
  myfile >> drop;
  k = 12; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile >>  resu.vertical[i][j];
    }
  };

  //horizontal
  myfile >> drop;
  k = 11; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile >>  resu.horizontal[i][j];
    }
  };

  //diags
  myfile >> drop;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) { 
      myfile >>  resu.diags[i][j];
    }
  };

  //adiags
  myfile >> drop;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) { 
    for (int j = 0; j<l; j++) {
      myfile >>  resu.adiags[i][j];
    }
  };

  myfile.close();
  return resu;
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

