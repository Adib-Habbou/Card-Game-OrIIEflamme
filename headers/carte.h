#ifndef CARTE_H  /* pour éviter des inclusions multiples */
#define CARTE_H

/* importation du module plateau */
#include "plateau.h"

#include<stddef.h>
#include <time.h>
#include <stdlib.h>

/* définition du type abstrait des cartes */
typedef struct carte *carte;

// GETTERS ET SETTERS 

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie le nombre de carte dans liste_carte */
int get_nombre_liste_carte();

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie la liste de toutes les cartes du jeu */
carte* get_liste_carte();

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char* get_carte_nom(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char* get_carte_description(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nombre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie le nom de la carte */
void set_carte_nom(carte carte, char* nom);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char* description);

/*  @requires   une carte valide et un entier
    @assigns    carte
    @ensures    modifie le nomnre d'occurrences de la carte */
void set_carte_nombre_occurrences(carte carte, int nombre_occurrences);

#endif
