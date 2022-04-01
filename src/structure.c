#include <stdio.h>
#include <stdlib.h>

#include "../headers/structure.h"
#include "interface.c"

/*  implementation des piles avec des listes chaînées */
typedef struct maillon {
    carte sommet; // la valeur du premier maillon représente le sommet de la pile
    struct maillon *suivant;
} *pile;

/*  @requires rien
    @assigns rien
    @ensures renvoie une pile vide */
pile pile_vide() {
    return NULL;
}

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie 1 si la pile est vide ou 0 sinon */
int pile_est_vide(pile pile) {
    return (pile == NULL);
}

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la carte au sommet de la pile */
carte pile_sommet(pile pile) {
    return pile->sommet;
}

/*  @requires un pointeur vers une pile valide
    @assigns ajoute la carte au sommet de la pile
    @ensures rien */
void empile(pile* _pile, carte carte) {
    // on alloue la mémoire nécessaire à la variable res
    pile res = malloc(sizeof(pile));
    // on vérifie que la mémoire a été allouée correctement
    if (res == NULL) {
        affiche("Erreur d'allocation mémoire.");
        exit(1);
    }
    // on empile la carte
    res->sommet = carte;
    res->suivant = *_pile;
    *_pile = res;
}

/*  @requires un pointeur vers une pile valide
    @assigns pile
    @ensures supprime la carte au sommet de la pile */
void depile(pile* pile) {
    // on vérifie que la pile n'est pas vide
    if(*pile == NULL) {
        affiche("La pile est vide.");
        exit(1);
    }
    // on supprime le sommet de la pile
    carte sommet = (*pile)->sommet;
    (*pile) = (*pile)->suivant;
    // on libère la mémoire du sommet supprimé
    free(sommet);
}

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la taille de la pile */
int taille_pile(pile pile) {
    // on initialise la variable taille à 0 (taille si la pile est vide)
    int taille = 0;
    // tant que la pile n'est pas vide on incrémente la taille
    while(!pile_est_vide(pile)) {
        taille += 1;
        pile = pile->suivant;
    }
    // on renvoie la taille
    return taille;
}
