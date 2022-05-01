/*  fichier utilisé dans le même dossier que test_structure.c en local
    pour tester le bon fonctionnement des piles avec des entiers */

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

/*  implementation des piles avec des listes chaînées */
typedef struct maillon *pile;

/*  @requires rien
    @assigns rien
    @ensures renvoie une pile vide */
pile pile_vide();

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie 1 si la pile est vide ou 0 sinon */
int pile_est_vide(pile pile);

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie l'entier au sommet de la pile */
int pile_sommet(pile pile);

/*  @requires un pointeur vers une pile valide
    @assigns rien
    @ensures renvoie l'élement suivant de la pile */
pile pile_suivant(pile pile);

/*  @requires un pointeur vers une pile valide
    @assigns ajoute l'entier au sommet de la pile
    @ensures rien */
void empile(pile *pile, int x);

/*  @requires un pointeur vers une pile valide
    @assigns pile
    @ensures supprime l'entier au sommet de la pile */
void depile(pile *pile);

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la taille de la pile */
int taille_pile(pile pile);

#endif
