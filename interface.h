#ifndef INTERFACE_H
#define INTERFACE_H

/* importation du module carte */
#include 'carte.h'

/* importation du module faction */
#include 'faction.h'

/* importation du module plateau */
#include 'plateau.h'


/* 
@requires rien
@assigns rien
@ensures Affiche le plateau de jeu dans son état actuel
*/
void affiche_plateau();

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
@ensures retourne -1 si la faction veut vider sa main, 0 si elle veut mélanger sa pioche et 1 si elle veut repiocher
*/
int decision(faction f); //à changer selon l'implémentation des factions

/* 
@requires cartes valides
@assigns rien
@ensures retourne la carte qui va être posée
*/
carte carte_poser(); //potentiellement une variable contenant la main

/* 
@requires rien
@assigns rien
@ensures retourne 0 pour la position vertical 1 pour la position horizontal
*/
int carte_positon();

/* 
@requires carte valide
@assigns rien
@ensures affiche les effets de la carte
*/
void afficher_effet(carte c);
 
/* 
@requires faction f1 et f2 sont les factions en jeu
@assigns rien
@ensures retourne la faction gagnante selon les règles
*/
void gagnant(faction f1, faction f2);

#endif
