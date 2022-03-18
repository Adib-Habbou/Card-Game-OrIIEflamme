#ifndef PLATEAU_H
#define PLATEAU_H

/* importation du module carte */
#include "carte.h"

/* importation du module faction */
#include "faction.h"

/* importation du module structure */
#include "structure.h"

/* implémentation du type case */
typedef struct case {
    carte carte; // carte posée sur la case en question
    int id_faction; // 0 ou 1 qui détermine la faction qui a posée la carte
    int etat; // 0 si la carte est face cachée ou 1 si elle est face visible
} case;

/* implémentation du type plateau */
typedef struct plateau {
    case tab[1000][1000]; // matrice de cases de taille 1000 x 1000
} plateau;

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie un nouveau plateau */
plateau init_plateau();

/*  @requires   un plateau p valide
    @assigns    plateau p
    @ensures    libère la mémoire associée au plateau et à ses deux factions */
void libere_plateau(plateau p);

/*  @requires   un plateau p valide
    @assigns    rien
    @ensures    renvoie 1 si il initialise une nouvelle manche de jeu
                renvoie 0 si le jeu est terminé */
int fin_manche(plateau p);

/*  @requires   un plateau p valide
    @assigns    rien
    @ensures    renvoie la liste des deux factions du jeu sous forme de tableau */
faction* liste_faction(plateau p);

/*  @requires   un plateau p valide, une carte c valide et un tableau pos = [x, y] contenant les deux coordonnées de la position où on pose la carte
    @assigns    ajoute la carte c à la case en position x et y de plateau p
    @ensures    pose la carte c face cachée sur le plateau p */
void poser(plateau p, carte c, int* pos);

/*  @requires   un plateau p valide
    @assigns    change l'état de la carte la plus en haut à gauche du plateau p
    @ensures    retourne la carte la plus en haut à gauche face visible et active son effet
                renvoie la carte retournée ou NULL si toutes les cartes du plateau sont déjà face visible */
carte retourner(plateau p);

#endif
