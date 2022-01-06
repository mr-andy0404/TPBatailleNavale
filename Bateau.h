#ifndef __Bateau_h
#define __Bateau_h

#include <string>
#include <vector>
using namespace std;

#include "Variables.h"

class Bateau {
private:
  vector<Pos> position;
  string nom;
  int type;
  bool est_coule;

public:
  Bateau() {};
  Bateau(string _nom, int _type, Pos _positionInit, bool direction);

  bool Est_touche(int x, int y, Board* Terrain);

}

#endif