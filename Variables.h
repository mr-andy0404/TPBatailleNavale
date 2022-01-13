#ifndef __VARIABLES_H
#define __VARIABLES_H

// Definir les variables

#define taille 10

#define EAU 0
#define RATE 1
#define TOUCHE 2
#define COULE 3


// Longeur du bateau 
#define PORTE_AVION 5
#define CROISEUR 4
#define CONTRE_TORPILLEUR 3
#define SOUS_MARIN 3
#define TORPILLEUR 2

// Direction du bateau
#define VERTICAL 0
#define HORIZONTAL 1


typedef struct{
  int x,y; // La position
  bool est_touche; 
}Pos;

typedef int grille[taille][taille];

#endif