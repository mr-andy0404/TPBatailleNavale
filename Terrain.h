#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Variables.h"
#include "Bateau.h"

class Terrain {
private:
	grille situation;
	vector<Bateau> bateaux;

public:
	Terrain();
	Terrain(string path);


};

#endif
