#include "../include/Joueur.h"

Terrain Joueur::getTerrain() {
    return terrain;
}

string Joueur::getNom() {
    return nom;
}

void Joueur::tir(int x, int y, Joueur adversaire) {
    adversaire.recevoirTir(x, y);
}

void Joueur::recevoirTir(int x, int y) {
    if(terrain.recevoirTir(x,y)){
        cout << "Recois Tir!" << endl;
    }
    else {
        cout << "Miss!" << endl;
    }
    
}

bool Joueur::aPerdu() {
    vector<Bateau> myBateaux;
    myBateaux = terrain.getBateaux();
    for (int i = 0; i < myBateaux.size(); i++) {
        if(!myBateaux[i].estCoule())
            return false;
    }
    return true;
}