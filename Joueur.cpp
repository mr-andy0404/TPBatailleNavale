#include "Joueur.h"

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
    
}

bool Joueur::aPerdu() {

}