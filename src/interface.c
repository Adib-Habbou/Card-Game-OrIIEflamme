
/* importation du module plateau */
#include "../headers/interface.h"

#include <stdio.h>




/* 
@requires rien
@assigns rien
@ensures Affiche le plateau de jeu dans son état actuel
*/
void affiche_plateau(plateau p);

/* 
@requires rien
@assigns rien
@ensures Affiche la main actuel de la faction
*/
void affiche_main(faction f);

//NB : j'ai supposé que la main et le plateau sont stocké en tant que variables globales,
//     à changer l'argument selon l'implémentation

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
carte carte_choisie(faction f); //potentiellement une variable contenant la main

/* 
@requires plateau valide
@assigns rien
@ensures retourne le couple (x,y) les coordonnées de la position de la carte que l'on pose
*/
int* carte_positon(plateau p);

/* 
@requires carte valide
@assigns rien
@ensures affiche les effets de la carte
*/
void afficher_effet(carte c);

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
