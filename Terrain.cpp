#include "Terrain.h"

Terrain::Terrain(){

}

Terrain::Terrain(string path){

}

/*
void lectureFicher(string nomFichier, vector<Vector3D>& vertices, vector<Vector3D>& uvs, vector<Vector3D>& normals, faces& fac) {
    fstream fichier, out;
    fichier.open(nomFichier, ios::in);
    Vector3D temp3D;
    if (fichier.is_open()) {
        string line;
        while (getline(fichier, line))
        {
            vector<string> lineD = decouperLigne(line);
            if (lineD[0] == "PORTE_AVION") {
            	Pos posInit;
            	posInit.x = stoi(lineD[1]);
            	posInit.y = stoi(lineD[2]);
            	
            	for (int i=0; i<PORTE_AVION; )

            } else if (lineD[0] == "CROISEUR") {

            }

        }
    }

    fichier.close();
}

vector<string> decouperLigne(string line) {
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
*/