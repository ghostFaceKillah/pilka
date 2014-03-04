#include "state.h"
#include<string>

void state::init() {
  int k,l;
  int current_x, current_y;
  current_x = 0;
  current_y = 0;

  k = 13; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      kropki[i][j] = 0;
    }
  };

  k = 12; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      vertical[i][j] = 0;
    }
  };

  k = 11; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      horizontal[i][j] = 0;
    }
  };

  k = 12; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) { 
      diags[i][j] = 0;
    }
  };

  k = 12; l = 10;
  for (int i = 0; i<k; i++) { 
    for (int j = 0; j<l; j++) {
      adiags[i][j] = 0;
    }
  };
};


void state::write() {
  int k,l;
  
  cout << "current_x" << endl;
  cout << current_x << endl;
  cout << "current_y" << endl;
  cout << current_y << endl;

  cout << "kropki" << endl;
  k = 13; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      cout <<  kropki[i][j] << " ";
    } cout << endl;
  };

  cout << "vertical" << endl;
  k = 12; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      cout <<  vertical[i][j] << " ";
    } cout << endl;
  };

  cout << "horizontal" << endl;
  k = 11; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      cout <<  horizontal[i][j] << " ";
    } cout << endl;
  };

  cout << "diags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) { 
      cout <<  diags[i][j] << " "; 
    } cout << endl;
  };

  cout << "adiags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) { 
    for (int j = 0; j<l; j++) {
      cout <<  adiags[i][j] << " "; 
    } cout << endl;
  };
};


void state::writeToFile(string s) {
  int k,l;
  ofstream myfile;
  myfile.open (s);

  myfile << "current_x" << endl;
  myfile << current_x << endl;
  myfile << "current_y" << endl;
  myfile << current_y << endl;

  myfile << "kropki" << endl;
  k = 13; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile <<  kropki[i][j] << " ";
    } myfile << endl;
  };

  myfile << "vertical" << endl;
  k = 12; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile <<  vertical[i][j] << " ";
    } myfile << endl;
  };

  myfile << "horizontal" << endl;
  k = 11; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile <<  horizontal[i][j] << " ";
    } myfile << endl;
  };

  myfile << "diags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) { 
      myfile <<  diags[i][j] << " "; 
    } myfile << endl;
  };

  myfile << "adiags" << endl;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) { 
    for (int j = 0; j<l; j++) {
      myfile <<  adiags[i][j] << " "; 
    } myfile << endl;
  };
  myfile.close();
};

void state::loadFromFile(string s) {
  int k,l;
  string drop;
  ifstream myfile (s);

  // x, y 
  myfile >> drop;
  myfile >> current_x;
  myfile >> drop;
  myfile >> current_y;

  // kropki
  myfile >> drop;
  k = 13; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile >> kropki[i][j];
    }
  };

  //vertical
  myfile >> drop;
  k = 12; l = 9;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile >>  vertical[i][j];
    }
  };

  //horizontal
  myfile >> drop;
  k = 11; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) {
      myfile >>  horizontal[i][j];
    }
  };

  //diags
  myfile >> drop;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<l; j++) { 
      myfile >>  diags[i][j];
    }
  };

  //adiags
  myfile >> drop;
  k = 12; l = 10;
  for (int i = 0; i<k; i++) { 
    for (int j = 0; j<l; j++) {
      myfile >>  adiags[i][j];
    }
  };

  myfile.close();
};

