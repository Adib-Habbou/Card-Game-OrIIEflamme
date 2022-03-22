#ifndef PLATEAU_H
#define PLATEAU_H

/* importation du module carte */
#include "carte.h"

/* importation du module faction */
#include "faction.h"

/* implémentation du type abstrait case utilisé pour implémenter plateau */
typedef struct Case Case;

/* implémentation du type abstrait plateau */
typedef struct plateau plateau;

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie un nouveau plateau */
plateau init_plateau();

/*  @requires   un plateau valide
    @assigns    plateau
    @ensures    libère la mémoire associée au plateau et à ses deux factions */
void libere_plateau(plateau plateau);

/*  @requires   un plateau valide
    @assigns    rien
    @ensures    renvoie 1 si il initialise une nouvelle manche de jeu
                renvoie 0 si le jeu est terminé */
int init_manche(plateau plateau);

/*  @requires   rien
    @assigns    rien
    @ensures    initialise la liste avec deux factions en jeu */
faction* liste_faction();

/*  @requires   un plateau, une carte valide et un tableau position = [x, y] contenant les deux coordonnées de la position où on pose la carte
    @assigns    ajoute la carte à la case en position x et y du plateau
    @ensures    pose la carte face cachée sur le plateau */
void poser(plateau plateau, carte carte, int* position);

/*  @requires   un plateau valide et une liste des factions en jeu
    @assigns    change l'état de la carte la plus en haut à gauche du plateau
    @ensures    retourne la carte la plus en haut à gauche face visible et active son effet
                renvoie la carte retournée ou NULL si toutes les cartes du plateau sont déjà face visible */
carte retourner(plateau plateau, faction* liste_faction);

#endif
