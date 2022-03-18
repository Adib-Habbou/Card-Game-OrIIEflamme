#ifndef PLATEAU_H
#define PLATEAU_H

/* importation du module carte */
#include "carte.h"

/* importation du module faction */
#include "faction.h"

/* implémentation du type abstrait plateau */
typedef struct plateau *plateau;

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

/*  @requires   rien
    @assigns    rien
    @ensures    initialise la liste avec deux factions en jeu */
faction* liste_faction();

/*  @requires   un plateau p valide, une carte c valide et un tableau pos = [x, y] contenant les deux coordonnées de la position où on pose la carte
    @assigns    ajoute la carte c à la case en position x et y de plateau p
    @ensures    pose la carte c face cachée sur le plateau p */
void poser(plateau p, carte c, int* pos);

/*  @requires   un plateau p valide et une liste des factions en jeu
    @assigns    change l'état de la carte la plus en haut à gauche du plateau p
    @ensures    retourne la carte la plus en haut à gauche face visible et active son effet
                renvoie la carte retournée ou NULL si toutes les cartes du plateau sont déjà face visible */
carte retourner(plateau p, faction* facs);

#endif
