#ifndef STRUCTURE_H
#define STRUCTURE_H

/* importation du fichier pour avoir accès au type carte */
#include "carte.c"

/*  implementation des piles avec des listes chaînées */
typedef struct maillon {
    carte sommet; // la valeur du premier maillon représente le sommet de la pile
    struct maillon *suivant;
} *pile;

/*  @requires rien
    @assigns rien
    @ensures renvoie une pile vide */
pile pile_vide();

/*  @requires p une pile valide
    @assigns rien
    @ensures renvoie 1 si la pile est vide ou 0 sinon */
int pile_est_vide(pile p);

/*  @requires un pointeur p vers une pile valide
    @assigns ajoute la carte c au sommet de la pile
    @ensures rien */
void empile(pile* p, carte c);

/*  @requires un pointeur p vers une pile valide
    @assigns supprime la carte au sommet de la pile
    @ensures renvoie la carte au sommet de la pile */
carte depile(pile* p);

/*  @requires une pile p valide
    @assigns rien
    @ensures affiche la pile p */
void affiche_pile(pile p);

/*  @requires une pile p valide
    @assigns rien
    @ensures renvoie la taille de la pile */
int taille_pile(pile p);

#endif
