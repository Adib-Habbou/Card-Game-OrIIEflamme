/*  fichier utilisé dans le même dossier que test_structure.h en local
    pour tester le bon fonctionnement des piles avec des entiers */

/* importation du module structure */
#include "structure.h"

/*  implementation des piles avec des listes chaînées */
struct maillon {
    int sommet; // la valeur du premier maillon représente le sommet de la pile
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
    @ensures renvoie l'entier au sommet de la pile */
int pile_sommet(pile pile) {
    return pile->sommet;
}

/*  @requires un pointeur vers une pile valide
    @assigns rien
    @ensures renvoie l'élement suivant de la pile */
pile pile_suivant(pile pile) {
    return pile->suivant;
}

/*  @requires un pointeur vers une pile valide
    @assigns ajoute l'entier au sommet de la pile
    @ensures rien */
void empile(pile *_pile, int x) {
    // on alloue la mémoire nécessaire à la variable res
    pile res = malloc(sizeof(pile));
    // on vérifie que la mémoire a été allouée correctement
    if (res == NULL) {
        exit(1); // si la mémoire n'a pas été allouée correctement on sort du programme
    }
    // on empile l'entier en ajoutant notre pile à la suite de la pile res qui contient la carte
    res->sommet = x;
    res->suivant = *_pile;
    *_pile = res;
}

/*  @requires un pointeur vers une pile valide
    @assigns pile
    @ensures supprime l'entier au sommet de la pile */
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

int main() {
    // on initialise la pile :
    pile test = pile_vide();
    printf("Taille de la pile : %i\n", taille_pile(test)); // 0
    printf("%i\n", pile_est_vide(test)); // 1

    // on rajoute 10 à la pile :
    empile(&test, 10);
    printf("%i\n", pile_est_vide(test)); // 0
    printf("Le sommet de la pile : %i\n", pile_sommet(test)); // 10
    printf("Taille de la pile : %i\n", taille_pile(test)); // 1

    // on rajoute 20 à la pile :
    empile(&test, 20);
    printf("Le sommet de la pile : %i\n", pile_sommet(test)); // 20
    printf("Taille de la pile : %i\n", taille_pile(test)); // 2

    // on rajoute 30 à la pile :
    empile(&test, 30);
    printf("Le sommet de la pile : %i\n", pile_sommet(test)); // 20
    printf("Taille de la pile : %i\n", taille_pile(test)); // 3

    // on enlève 30 de la pile :
    depile(&test);
    printf("Le sommet de la pile : %i\n", pile_sommet(test)); // 20
    printf("Taille de la pile : %i\n", taille_pile(test)); // 2

    // on enlève 20 de la pile :
    depile(&test);
    printf("Le sommet de la pile : %i\n", pile_sommet(test)); // 10
    printf("Taille de la pile : %i\n", taille_pile(test)); // 1

    // on enlève 10 de la pile :
    depile(&test);
    printf("Taille de la pile : %i\n", taille_pile(test)); // 0

    return 0;
}
