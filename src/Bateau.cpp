#include "Bateau.h"

//using namespace std;

Bateau::Bateau(string _nom, int _type, Pos _positionInit, bool direction) {

    nom = _nom;
    type = _type;
    position.push_back(_positionInit);
    for (int i = 1; i <= type; i++) {
        Pos newPos;
        newPos.x = _positionInit.x + i * direction;
        newPos.y = _positionInit.y + i * (1 - direction);
        newPos.est_touche = false;
        position.push_back(newPos);
    }
}