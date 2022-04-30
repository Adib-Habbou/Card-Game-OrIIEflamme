/* importation du module structure */
#include "../headers/structure.h"

/*  implementation des piles avec des listes chaînées */
struct maillon {
    carte sommet; // la valeur du premier maillon représente le sommet de la pile
    struct maillon *suivant;
};

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
    return pile == NULL;
}

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la carte au sommet de la pile */
carte pile_sommet(pile pile) {
    return pile->sommet;
}

/*  @requires un pointeur vers une pile valide
    @assigns rien
    @ensures renvoie l'élement suivant de la pile */
pile pile_suivant(pile pile) {
    return pile->suivant;
}

/*  @requires un pointeur vers une pile valide
    @assigns ajoute la carte au sommet de la pile
    @ensures rien */
void empile(pile *_pile, carte carte) {
    // on alloue la mémoire nécessaire à la variable res
    pile res = malloc(sizeof(pile));
    // on vérifie que la mémoire a été allouée correctement
    if (res == NULL) {
        exit(1); // si la mémoire n'a pas été allouée correctement on sort du programme
    }
    // on empile la carte en ajoutant notre pile à la suite de la pile res qui contient la carte
    res->sommet = carte;
    res->suivant = *_pile;
    *_pile = res;
}

/*  @requires un pointeur vers une pile valide
    @assigns pile
    @ensures supprime la carte au sommet de la pile */
void depile(pile *pile) {
    // on vérifie que la pile n'est pas vide
    if (pile_est_vide(*pile)) {
        exit(1); // si la pile est vide on sort du programme
    }
    // on supprime le sommet de la pile en passant au maillon suivant
    *pile = pile_suivant(*pile);
}

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la taille de la pile */
int taille_pile(pile pile) {
    // on initialise la variable taille à 0 (taille si la pile est vide)
    int taille = 0;
    // tant que la pile n'est pas vide
    while(!pile_est_vide(pile)) {
        taille += 1; // on incrémente la taille de 1
        pile = pile_suivant(pile); // on passe au maillon suivant de la pile
    }
    // on renvoie la taille
    return taille;
}

