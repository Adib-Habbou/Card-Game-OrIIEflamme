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
    carte tab[1000][1000]; // matrice de cartes de taille 1000x1000
} plateau;

/*  @requires   rien
    @assigns    rien
    @ensures    un nouveau plateau */
plateau init_plateau();

/*  @requires   un pointeur vers un plateau p valide
    @assigns    libère la mémoire associée au plateau
    @ensures    rien */
void libere_plateau(plateau *p);

/*  @requires   un plateau p valide
    @assigns    rien
    @ensures    renvoie 1 si il initialise une nouvelle manche de jeu
                renvoie 0 si le jeu est terminé */
int fin_manche(plateau p);    

/*  @requires   un plateau p valide
    @assigns    rien
    @ensures    renvoie la liste des deux factions du jeu */
liste_faction liste_faction(plateau p);

/*  @requires   un pointeur vers un plateau p et une carte c valides
    @assigns    pose la carte c face cachée sur le plateau p
    @ensures    rien */
void poser(plateau *p, carte c);

/*  @requires   un pointeur vers un plateau p et une carte c valides
    @assigns    retourne la carte c face visible et active son effet
    @ensures    rien */
void retourner(plateau *p, carte c);

#endif
