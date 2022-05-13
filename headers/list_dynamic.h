#ifndef LIST_DYNAMIC_H
#define LIST_DYNAMIC_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define INITSIZE 10
#define ADDSIZE INITSIZE

typedef void* element;
/*  implementation des piles avec des listes chaînées */
typedef struct listD *listD;

/*  @requires rien
    @assigns rien
    @ensures renvoie une pile vide */
listD listD_vide();

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie 1 si la pile est vide ou 0 sinon */
int listD_est_vide(listD _listD);

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la carte au sommet de la pile */
element get(listD _listD, int index);

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la carte au sommet de la pile */
element set(listD* _listD, int index, element _element);

/*  @requires un pointeur vers une pile valide
    @assigns pile
    @ensures supprime la carte au sommet de la pile */
element remove_byindex(listD* _listD, int index);

/*  @requires une pile valide
    @assigns rien
    @ensures renvoie la taille de la pile */
int taille_listD(listD _listD);

void add_list(listD* _listD, element _element);

element pop_list(listD* _listD);

/*  @requires une pile valide
    @assigns rien
    @ensures affiche la pile */
void affiche_liste(listD _listD);

#endif