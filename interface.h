#ifndef interface_h
#define interface_h

/* importation du module carte */
#include 'carte.h'

/* importation du module faction */
#include 'faction.h'
//importation du module plateau
#include 'plateau.h'


/* 
@requires rien
@assigns rien
@ensures Affiche le plateau de jeu dans son état actuel
*/
void AffichePlateau();

/* 
@requires rien
@assigns rien
@ensures Affiche la main actuel de la faction
*/
void AfficheMain(faction f);

//NB : j'ai supposé que la main et le plateau sont stocké en tant que variables globales,
//     à changer l'argument selon l'implémentation

/* 
@requires rien
@assigns rien
@ensures retourne -1 si la faction veut vider sa main, 0 si elle veut mélanger sa pioche et 1 si elle veut repiocher
*/
int Decision(faction f); //à changer selon l'implémentation des factions

/* 
@requires cartes valides
@assigns rien
@ensures retourne la carte qui va être posée
*/
carte CartePoser(); //potentiellement une variable contenant la main

/* 
@requires rien
@assigns rien
@ensures retourne 0 pour la position vertical 1 pour la position horizontal
*/
int CartePositon();

/* 
@requires carte valide
@assigns rien
@ensures affiche les effets de la carte
*/
void AfficherEffet(carte c);

/* 
@requires faction f1 et f2 sont les factions en jeu
@assigns rien
@ensures retourne la faction gagnante selon les règles
*/
void Gagnant(faction f1,faction f2);

#endif