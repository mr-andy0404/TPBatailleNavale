#include "Ordinateur.h"

int alea(int min, int max) {
	// Fonction qui renvoie un entier aléatoire entre min et max
	random_device rand;
	default_random_engine eng(rand());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(eng);
}

void choixTir(Joueur& adv, int& x, int& y) {
	// Fonction qui renvoie les coordonnées de la case sur laquelle l'ordinateur tir
	int touche = aTouche(adv);
	if (touche =! -1) {
		// Si le terrain adverse comprend une case "TOUCHE",
		// on va effectuer un tir "stratégique" afin de couler le bateau
		int i = 0;
		Direction dir = NONE;
		continuitir(adv, touche, &i, &dir);
		switch (dir) {
			// On transforme les infos de continuitir en coordonnées
			case EST:
			*x = touche % 10 + i;
			*y = touche / 10;
			break;
			case NORD:
			*x = touche % 10;
			*y = touche / 10 - i;
			break;
			case OUEST:
			*x = touche % 10 - i
			*y = touche / 10;
			break;
			case SUD:
			*x = touche % 10;
			*y = touche / 10 + i;
		}
	}
	else {
		// Sinon c'est qu'on ne dispose d'aucune info sur l'emplacement des bateaux restants,
		// on tire au hasard dans l'océan
		vector<int> ocean;
		for (int i = 0; i < taille * taille; i++) {
			if ((*adv).board.situation[i] == EAU) { ocean.push_back(i); }
		}
		int tir = ocean[alea(0, ocean.size())];
		*x = tir % 10;
		*y = tir / 10;
	}
}

int aTouche(Joueur& player) {
	// Fonction qui renvoie la 1ère case du
	// terrain adverse dans l'état "TOUCHE",
	// ou -1 s'il n'y en a pas
	int touche = -1;
	int i = -1;
	bool aTouche = false;
	while (i < (*player).board.situation.size() && !aTouche) {
		i++;
		if ((*player).board.situation[i] == 2) {
			touche = i;
			aTouche = true;
		}
	}
	return touche;
}

void continuitir(Joueur& adv, int touche, int& i, Direction& dir) {
	// Fonction récursive qui s'arrête lorsqu'elle a 
	// déterminé la direction (dir) et la distance (i) 
	// de la prochaine case sur laquelle tirer par rapport
	// à la case évaluée (touche)
	Case droite = MUR;
	Case haut = MUR;
	Case gauche = MUR;
	Case bas = MUR;
	if (*i == 0 && *dir == NONE) { // Si c'est le premier appel de la fonction
		// On stocke l'état des cases voisines qui ne sont pas hors-terrain
		if (touche % 10 =! 9) { droite = (*adv).board.situation[touche + 1]; } 
		if (touche > 9) { haut = (*adv).board.situation[touche - 10]; }
		if (touche % 10 =! 0) { gauche = (*adv).board.situation[touche - 1]; } 
		if (touche < 90) { bas = (*adv).board.situation[touche + 10]; }
		// Si une des voisines a été touchée, on se prépare à rappeler la fonction sur celle-ci
		*i += 1;
		if (droite == TOUCHE) { *dir = EST; }
		else if (haut == TOUCHE) { *dir = NORD; }
		else if (gauche == TOUCHE) { *dir = OUEST; }
		else if (bas == TOUCHE) { *dir = SUD; }
		if (*dir == NONE) {
			// Sinon si aucune n'a été touchée, on tire sur la première case où aucun tir n'a été effectué
			// (Une case contenant une portion de bateau en contient forcément une autre dans son voisinage)
			if (droite == EAU) { *dir = EST; }
			else if (haut == EAU) { *dir = NORD; }
			else if (gauche == EAU) { *dir = OUEST; }
			else if (bas == EAU) { *dir = SUD; }
		}
		else {
			// On rappelle la fonction sur la nouvelle case qui a déjà subi un "touché"
			toucheTir(adv, touche, i, dir);
		}
	}
	else { // Sinon, si ce n'est pas le 1er appel de la fonction
		*i += 1;
		switch dir {
			case EST: 
			// Si la case précédemment évaluée était à gauche de la case courante
			// on stocke l'état de la case de droite (dans "la continuité du bateau")
			// si elle n'est pas hors-terrain
			if ((touche + (*i)) % 10 =! 9) { droite = (*adv).board.situation[touche + (*i) + 1]; }
			// Si elle a été touchée, on continue dans la même direction
			if (droite == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (droite =! EAU) {
				// Si il n'est pas intéressant de tirer dessus, on réinitialise la distance,
		    	// et on test de l'autre côté de la case de départ
				*dir = OUEST;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
			// Sinon si on n'y a jamais tiré (la case vaut "EAU"), on tire dessus (on sort de la fonction)
			break;
			case NORD: // Même fonctionnement
			if ((touche - 10 * (*i)) > 9) { haut = (*adv).board.situation[touche - 10 * (*i)]; }
			if (haut == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (haut =! EAU) {
				*dir = SUD;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
			break;
			case OUEST: // Même fonctionnement
			if ((touche - (*i)) % 10 =! 0) { gauche = (*adv).board.situation[touche - (*i) - 1]; }
			if (gauche == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (gauche =! EAU) {
				*dir = EST;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
			break;
			case SUD: // Même fonctionnement
			if ((touche + 10 * (*i)) < 90) { haut = (*adv).board.situation[touche + 10 * (*i)]; }
			if (bas == TOUCHE) { toucheTir(adv, touche, i, dir); }
			else if (bas =! EAU) {
				*dir = NORD;
				*i = 0;
				toucheTir(adv, touche, i, dir);
			}
		}
	}
}