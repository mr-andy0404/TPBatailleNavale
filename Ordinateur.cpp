#include "Ordinateur.h"
#include <vector.h>

void choixTir(Joueur& adv, int& x, int& y) {
	if (aTouche(adv) =! -1) {

	}
}

int aTouche(Joueur& player) {
	int touche = -1;
	int i = -1;
	bool aTouche = false;
	while (i < (*player).board.grille.size() && !aTouche) {
		i++;
		if ((*player).board.grille[i] == 2) {
			touche = i;
			aTouche = true;
		}
	}
	return touche;
}

void toucheTir(Joueur& adv, int touche, int& i, Direction& dir) {
	Case droite = MUR;
	Case haut = MUR;
	Case gauche = MUR;
	Case bas = MUR;
	if (*i == 0 && *dir == NONE) {
		*i += 1;
		if (touche % 10 =! 9) { droite = (*adv).board.grille[touche + 1]; }
		if (touche > 9) { haut = (*adv).board.grille[touche - 10]; }
		if (touche % 10 =! 0) { gauche = (*adv).board.grille[touche - 1]; }
		if (touche < 90) { bas = (*adv).board.grille[touche + 10]; }
		if (droite == TOUCHE) { *dir = EST; }
		else if (haut == TOUCHE) { *dir = NORD; }
		else if (gauche == TOUCHE) { *dir = OUEST; }
		else if (bas == TOUCHE) { *dir = SUD; }
		if (*dir == NONE) {
			if (droite == EAU) { *dir = EST; }
			else if (haut == EAU) { *dir = NORD; }
			else if (gauche == EAU) { *dir = OUEST; }
			else if (bas == EAU) { *dir = SUD; }
		}
		else {
			toucheTir(adv, touche, i, dir);
		}
	}
	else {
		*i += 1;
		switch dir {
			case EST:
			if ((touche + (*i)) % 10 =! 9) { droite = (*adv).board.grille[touche + (*i) + 1]; }
			if (droite == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (droite =! EAU) {
				*dir = OUEST;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
			break;
			case NORD:
			if ((touche - 10 * (*i)) > 9) { haut = (*adv).board.grille[touche - 10 * (*i)]; }
			if (haut == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (haut =! EAU) {
				*dir = SUD;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
			break;
			case OUEST:
			if ((touche - (*i)) % 10 =! 0) { gauche = (*adv).board.grille[touche - (*i) - 1]; }
			if (gauche == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (gauche =! EAU) {
				*dir = EST;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
			break;
			case SUD:
			if ((touche + 10 * (*i)) < 90) { haut = (*adv).board.grille[touche + 10 * (*i)]; }
			if (bas == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (bas =! EAU) {
				*dir = NORD;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
		}
	}
}