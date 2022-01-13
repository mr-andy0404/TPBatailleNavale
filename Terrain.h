#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Variables.h"
#include "Bateau.h"

class Terrain {
private: //Attributs privés
	grille situation;
	vector<Bateau> bateaux;

public:
	Terrain();
	Terrain(string path);

	vector<Bateau> getBateaux();
	grille getSituation();

	bool recevoirTir(int x, int y);

private: //Méthodes privées
	void lectureFicher(string nomFichier);
	vector<string> decouperLigne(string line);
};

#endif
