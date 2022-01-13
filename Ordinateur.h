#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#include "Joueur.h"
#include "Variables.h"
#include <vector.h>
#include <random>

enum class Direction { EST, NORD, OUEST, SUD, NONE };

int alea(int min, int max);

void choixTir(Joueur& adv, int& x, int& y);

int aTouche(Joueur& player);

void toucheTir(Joueur& adv, int touche, int& i, Direction& dir);

#endif