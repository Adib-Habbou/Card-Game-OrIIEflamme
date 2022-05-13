#ifndef wPILE_H
#define wPILE_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef void* element;
/*  implementation des piles avec des listes chaînées */
typedef struct maillon *wpile;

/*  @requires rien
    @assigns rien
    @ensures renvoie une pile vide */
wpile wpile_vide();

/*  @requires une wpile valide
    @assigns rien
    @ensures renvoie 1 si la wpile est vide ou 0 sinon */
int wpile_est_vide(wpile _wpile);

/*  @requires une wpile valide
    @assigns rien
    @ensures renvoie la carte au sommet de la wpile */
element wpile_sommet(wpile _wpile);

/*  @requires un pointeur vers une wpile valide
    @assigns rien
    @ensures renvoie l'élement suivant de la wpile */
wpile wpile_suivant(wpile _wpile);

/*  @requires un pointeur vers une wpile valide
    @assigns ajoute l'element au sommet de la wpile
    @ensures rien */
void wempile(wpile* _wpile, element _element);

/*  @requires un pointeur vers une wpile valide
    @assigns ajoute touts les elements au sommet de la wpile
    @ensures rien */
void wempile_multiple(wpile* _wpile,int nb, ...);

/*  @requires un pointeur vers une wpile valide
    @assigns wpile
    @ensures supprime la carte au sommet de la wpile */
element wdepile(wpile* _wpile);

/*  @requires une wpile valide
    @assigns rien
    @ensures renvoie la taille de la wpile */
int taille_wpile(wpile _wpile);

/*  @requires une wpile valide
    @assigns rien
    @ensures affiche la wpile */
void affiche_wpile(wpile _wpile);

int mem_wpile(wpile _wpile, element _element);

#endif