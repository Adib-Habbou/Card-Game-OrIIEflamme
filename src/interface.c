
/* importation du module plateau */
#include "../headers/interface.h"
#include "../src/plateau.c"

#include "structure.c"
#include <stdio.h>




/* 
@requires rien
@assigns rien
@ensures Affiche le plateau de jeu dans son état actuel
*/
void affiche_plateau(plateau _plateau);

/* 
@requires rien
@assigns rien
@ensures Affiche la main actuel de la faction
*/
void affiche_main(faction _faction) {
    // on vérifie que la pile n'est pas vide
    if(pile_est_vide(_faction.main)){
        printf("La main est vide.\n");
    }
    // tant que la pile est vide on affiche le nom de la carte
    while(!pile_est_vide()) {
        printf("-> [ %s ] ", _faction.main->sommet->nom);
    }
    // on affiche un saut de ligne par soucis esthétique
    printf("\n");
}


/* 
@requires rien
@assigns rien
@ensures retourne 1 si la faction décide de remélanger sa main, retourne 0 sinon
*/
int decision(); //à changer selon l'implémentation des factions

/* 
@requires cartes valides
@assigns rien
@ensures retourne la carte qui va être posée
*/
carte carte_choisie(faction _faction); //potentiellement une variable contenant la main

/* 
@requires plateau valide
@assigns rien
@ensures retourne le couple (x,y) les coordonnées de la position de la carte que l'on pose
*/
int* carte_positon(plateau _plateau);

/* 
@requires carte valide
@assigns rien
@ensures affiche les effets de la carte
*/
void afficher_effet(carte _carte);

/* 
@requires liste faction valide
@assigns rien
@ensures retourne la faction gagnante selon les règles
*/
void gagnant(faction* factions);

/* 
@requires rien
@assigns rien
@ensures affiche string sur l'écran
*/
void affiche(char string) {
    printf("%s\n",string);
}

