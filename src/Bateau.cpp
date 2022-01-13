#include "../include/Bateau.h"

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

Pos Bateau::getPos(int numero) {
    return position[numero];
}

int Bateau::getType() {
    return type;
}

bool Bateau::estTouche(int x, int y) {
    est_coule = true;
    bool touche = false;
    for(Pos i : position){
        if(i.x == x && i.y == y) {
            i.est_touche = true;
            touche = true;
        }
        if (!i.est_touche){
            est_coule = false;
        }
    }
    return touche;
}

bool Bateau::estCoule() {
    return est_coule;
}