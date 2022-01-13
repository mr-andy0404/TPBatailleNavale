#ifndef __JOUEUR_H
#define __JOUEUR_H

#include "Terrain.h"
#include "Variables.h"

class Joueur{
private:
    Terrain terrain;
    string nom;

public:
    Joueur() {};
    Joueur(Terrain _terrain, string _nom) : terrain(_terrain), nom(_nom) {};

    Terrain getTerrain();
    string getNom();

    void tir(int x, int y, Joueur adversaire);
    void recevoirTir(int x, int y);
    bool aPerdu();

};

#endif