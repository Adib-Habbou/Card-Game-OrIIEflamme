#ifndef PLATEAU_H
#define PLATEAU_H

/* importation du module carte */
#include "carte.h"

/* importation du module faction */
#include "faction.h"

/* importation du module structure */
#include "structure.h"

/* implémentation du type plateau */
typedef struct plateau {
    int tab[1000][1000]; // matrice de taille 1000x1000
} plateau;

/*  droite  :   plateau[i+1][j]
    gauche  :   plateau[i-1][j]
    haut    :   plateau[i][j-1]
    bas     :   plateau[i][j+1] */

/*  @requires   rien
    @assigns    rien
    @ensures    un nouveau plateau */
plateau init_plateau();

/*  @requires   un plateau p valide
    @assigns    libère la mémoire associée au plateau
    @ensures    rien */
void free_plateau(plateau p);

/*  @requires   un plateau p valide
    @assigns    rien
    @ensures    renvoie 1 si il initialise une nouvelle manche de jeu
                renvoie 0 si le jeu est terminé */
int end_round(plateau p);    

/*  @requires   un plateau p valide
    @assigns    rien
    @ensures    renvoie la liste des deux factions du jeu */
list list_faction(plateau p);

/*  @requires   un plateau p et une carte c valides
    @assigns    pose la carte c face cachée sur le plateau p
    @ensures    rien */
void put(plateau p, carte c);

/*  @requires   un plateau p et une carte c valides
    @assigns    retourne la carte c face visible et active son effet
    @ensures    rien */
void turn(plateau p, carte c);

#endif
