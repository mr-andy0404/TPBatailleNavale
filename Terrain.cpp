#include "Terrain.h"

Terrain::Terrain(){
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            (*situation)[i][j] = EAU;
        }
    }
}

Terrain::Terrain(string path){

    lectureFicher(path);
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            (*situation)[i][j] = EAU;
        }
    }
}

void Terrain::lectureFicher(string nomFichier) {
    fstream fichier, out;
    fichier.open(nomFichier, ios::in);
    if (fichier.is_open()) {
        string line;
        while (getline(fichier, line))
        {
            vector<string> lineD = decouperLigne(line);

            int type = 0;
            if (lineD[0] == "PORTE_AVION"){
                type = PORTE_AVION;
            } else if (lineD[0] == "CROISEUR") {
            	type = CROISEUR;
            } else if (lineD[0] == "CONTRE_TORPILLEUR") {
            	type = CONTRE_TORPILLEUR;
            } else if (lineD[0] == "SOUS_MARIN") {
                type = SOUS_MARIN;
            } else if (lineD[0] == "TORPILLEUR") {
            	type = TORPILLEUR;
            }


            if (type > 0) {
            	Pos posInit;
            	bool direction;

            	posInit.x = stoi(lineD[1]);
            	posInit.y = stoi(lineD[2]);

            	if (lineD[3] == "Vertical") {
            		direction = VERTICAL;
            	}
            	else if (lineD[3] == "Horizontal") {
            		direction = HORIZONTAL;
            	}

            	int maxX = posInit.x + direction*(type-1);
            	int maxY = posInit.y + (1-direction)*(type-1);

            	if(maxX > taille || maxY > taille || posInit.x < 0 || posInit.y < 0){
            		cout << lineD[4] << " n'a pas pu etre ajoute car il est en dehors du terrain" << endl;
            	} else {

            		this->bateaux.push_back(Bateau(lineD[4], type, posInit, direction));
            	}
            }

        }
    }

    fichier.close();
}

vector<string> Terrain::decouperLigne(string line) {
    vector<string> res;

    string temp;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] != ' ') {
            temp.push_back(line[i]);
        }
        else {
            res.push_back(temp);
            temp = "";
        }
    }
    res.push_back(temp);
    return res;
}

vector<Bateau> Terrain::getBateaux(){
	return this->bateaux;
}

grille* Terrain::getSituation() {
	return situation;
}

bool Terrain::recevoirTir(int x, int y) {
    
    bool touche = false;
    bool coule = false;

    int i = 0;

    while (i< this->bateaux.size() && !touche) {
        touche = this->bateaux[i].estTouche(x, y);
        if (!touche) {
            i++;
        }
    }

    coule = bateaux[i].estCoule();

    if (touche && coule) {
        for (int j = 0; j < bateaux[i].getType(); j++) {
            Pos elementBateau = bateaux[i].getPos(j);
            (*situation)[elementBateau.x][elementBateau.y] = COULE;
        }
    }
    else if (touche && !coule) {
        (*situation)[x][y] = TOUCHE;
    }
    else {
        (*situation)[x][y] = RATE;
    }

    return touche;


}