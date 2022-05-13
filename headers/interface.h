#ifndef INTERFACE_H
#define INTERFACE_H

/* importation du module carte */
#include "carte.h"
/* importation du module faction */
#include "faction.h"
/* importation du module plateau */
#include "plateau.h"
/* importation du module carte */
#include "carte.h"
/* importation du module sdl */
#include "sdl.h"

#include "pile.h"
#include "list_dynamic.h"

#include <stdio.h>
#include <string.h>

#define TAILLE_PLATEAU_MAX 13

/* 
@requires rien
@assigns rien
@ensures Affiche le plateau de jeu dans son état actuel
*/
void affiche_plateau(fenetre _fenetre, plateau _plateau);

/* 
@requires rien
@assigns rien
@ensures Affiche la main actuel de la faction
*/
void affiche_main(fenetre _fenetre, faction _faction, plateau _plateau);

//NB : j'ai supposé que la main et le plateau sont stocké en tant que variables globales,
//     à changer l'argument selon l'implémentation

/* 
@requires rien
@assigns rien
@ensures retourne 1 si la faction décide de remélanger sa main, retourne 0 sinon
*/
int decision(fenetre _fenetre); //à changer selon l'implémentation des factions

/* 
@requires cartes valides
@assigns rien
@ensures retourne la carte qui va être posée
*/
carte carte_choisie(fenetre _fenetre, faction _faction); //potentiellement une variable contenant la main

/* 
@requires plateau valide
@assigns rien
@ensures retourne le couple (x,y) les coordonnées de la position de la carte que l'on pose
*/
int* carte_positon(fenetre _fenetre, plateau _plateau);

/* 
@requires carte valide
@assigns rien
@ensures affiche les effets de la carte
*/
void afficher_effet(fenetre _fenetre, carte _carte, plateau _plateau);

/* 
@requires liste faction valide
@assigns rien
@ensures retourne la faction gagnante selon les règles
*/
void gagnant(fenetre _fenetre, faction* _factions, plateau _plateau);

/* 
@requires rien
@assigns rien
@ensures affiche string sur l'écran
*/
void affiche(char *string);


#endif


