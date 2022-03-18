#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

/*  @requires rien
    @assigns rien
    @ensures renvoie une pile vide */
pile pile_vide() {
    return NULL;
}

/*  @requires p une pile valide
    @assigns rien
    @ensures renvoie 1 si la pile est vide ou 0 sinon */
int pile_est_vide(pile p) {
    return (p == NULL);
}

/*  @requires un pointeur p vers une pile valide
    @assigns ajoute la carte c au sommet de la pile
    @ensures rien */
void empile(pile* p, carte c) {
    // on alloue la mémoire nécessaire à la variable res
    pile res = malloc(sizeof(pile));
    // on vérifie que la mémoire a été allouée correctement
    if (res == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    // on empile la carte c
    res->top = c;
    res->next = *p;
    *p = res;
}

/*  @requires un pointeur p vers une pile valide
    @assigns supprime la carte au sommet de la pile
    @ensures renvoie la carte au sommet de la pile */
carte depile(pile* p) {
    // on vérifie que la pile n'est pas vide
    if(*p == NULL) {
        print("La pile est vide.\n");
        exit(1);
    }
    // on supprime le sommet de la pile
    carte sommet = (*p)->sommet;
    (*p) = (*p)->suivant;
    // on renvoie le sommet supprimé
    return sommet;
}

/*  @requires une pile p valide
    @assigns rien
    @ensures affiche la pile p */
void affiche_pile(pile p) {
    // on vérifie que la pile n'est pas vide
    if(pile_est_vide(p)){
        print("La pile est vide.\n");
    }
    // tant que la pile est vide on affiche le nom de la carte
    while(!pile_est_vide(p)) {
        printf("-> [ %s ] ", s->sommet.nom);
    }
    // on affiche un saut de ligne par soucis esthétique
    printf("\n");
}

/*  @requires une pile p valide
    @assigns rien
    @ensures renvoie la taille de la pile */
int taille_pile(pile p) {
    // on initialise la variable taille à 0 (taille si la pile est vide)
    int taille = 0;
    // tant que la pile n'est pas vide on incrémente la taille
    while(!pile_est_vide(p)) {
        taille += 1;
        p = p->suivant;
    }
    // on renvoie la taille
    return taille;
}
