#include <stdio.h>
#include <stdlib.h>

#include "../headers/structure.h"

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
        printf("Erreur d'allocation mémoire.\n");
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
        printf("La pile est vide.\n");
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
    @ensures affiche la pile */
void affiche_pile(pile pile) {
    // on vérifie que la pile n'est pas vide
    if(pile_est_vide(pile)){
        printf("La pile est vide.\n");
    }
    // tant que la pile est vide on affiche le nom de la carte
    while(!pile_est_vide(pile)) {
        printf("-> [ %s ] ", pile->sommet->nom);
    }
    // on affiche un saut de ligne par soucis esthétique
    printf("\n");
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
