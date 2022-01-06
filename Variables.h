#ifndef __VARIABLES_H
#define __VARIABLES_H

// Definir les variables

#define taille 10

#define RATE 0
#define TOUCHE 1
#define COULE 2

#define PORTE_AVION 0
#define CROISEUR 1
#define CONTRE_TORPILLEUR 2
#define SOUS_MARIN 3
#define TORPILLEUR 4

typedef struct{
  int x,y; // La position
  bool est_touche; 
}Pos;

typedef int grille[taille][taille];

#endif