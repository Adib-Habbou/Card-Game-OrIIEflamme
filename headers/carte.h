#ifndef CARTE_H  /* pour éviter des inclusions multiples */
#define CARTE_H

#include "type.h"

#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/* importation du module plateau */
#include "plateau.h"

// GETTERS ET SETTERS 

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie le nombre de carte dans liste_carte */
int get_nombre_liste_carte();

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie la liste de toutes les cartes du jeu */
carte* get_liste_carte();

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char* get_carte_nom(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char* get_carte_description(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nombre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie le nom de la carte */
void set_carte_nom(carte carte, char* nom);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char* description);

/*  @requires   une carte valide et un entier
    @assigns    carte
    @ensures    modifie le nomnre d'occurrences de la carte */
void set_carte_nombre_occurrences(carte carte, int nombre_occurrences);

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 1
*/
void FISE(faction _faction, int ligne, int colonne, plateau _plateau) ;
/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 2
*/
void FISA(faction _faction, plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 4
*/
void FC(faction _faction, plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 1 pour chaque carte FISE, FISA ou FC retournées
*/
void EcologIIE(faction _faction, plateau _plateau, int ligne, int colonne) ;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau
@ensures Prend toutes les cartes FISE/FISA/FC retournées, les retire du plateau, 
les mélange et les repose face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, 
dans cet ordre et les prochaines cartes à être retournées sont ces cartes là
*/
void lIIEns(plateau _plateau, int ligne, int colonne);

/*
@requires faction valide
@assigns l'attribut DDRS de la faction ou le plateau
@ensures Si au moins une carte alcool est retournée, 
supprime toutes les cartes FISE/FISA/FC retournées du plateau-> 
Supprime ensuite la première et la dernière ligne du plateau-> 
Sinon la faction qui a posé cette carte gagne 5 points DDRS
*/
void Soiree_sans_alcool(faction _faction, plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns le plateau
@ensures Supprimez du plateau toutes les cartes qui touchent cette carte Alcool
*/
void Alcool(plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns l'attribut DDRS de la faction et le plateau
@ensures Supprime toutes les cartes Thé et Alcool retournées sur le plateau-> 
Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS-> Sinon elle perd 1 point DDRS
*/
void Cafe(faction _faction, plateau _plateau, int ligne, int colonne);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Supprimez toutes les cartes Café et Alcool retournées sur le plateau-> 
Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS-> Sinon elle perd 1 point DDRS
*/
void The(faction _faction, plateau _plateau, int ligne, int colonne) ;

/*
@requires rien
@assigns rien
@ensures sans effet
*/
void Ecocup(int ligne, int colonne, plateau _plateau) ;

/*
@requires faction valide
@assigns l'attribut DDRS de la faction adverse
@ensures La faction adverse de celle qui a posé cette carte perd 1 points DDRS pour chaque paire de cartes retournées et identiques sur le plateau
*/
void Reprographie(faction _faction_oppose, plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns l'attribut DDRS des factions
@ensures Chaque faction gagne 1 point DDRS par carte non retournée et non supprimée du plateau qu'elle a posée sur le plateau
*/
void Isolation_du_batiment(faction _faction, faction _faction_oppose, plateau _plateau, int ligne, int colonne) ;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau
@ensures Retournez toutes les cartes non retournées les plus à gauche et à droite de chaque ligne, sans appliquer leur effet
*/
void Parcours_sobriete_numerique(plateau _plateau, int ligne, int colonne) ;
/*
@requires faction valide
@assigns l'attribut DDRS de la faction adverse
@ensures La faction adverse de celle qui a posé cette carte perd 3 points DDRS par carte Heures supplémentaires retournée sur le plateau
*/
void Heures_supplementaires(faction _faction_oppose, plateau _plateau, int ligne, int colonne);



/*
@requires faction valide
@assigns le plateau
@ensures Supprimez une carte non retournée du plateau choisie au hasard
*/
void Kahina_Bouchama(plateau _plateau, int ligne, int colonne);
/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Supprimez une ligne au hasard, la faction qui a posé cette carte gagne 2 points DDRS par carte supprimée ainsi->
*/
void Kevin_Goilard(faction _faction, plateau _plateau, int ligne, int colonne) ;


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau et/ou l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte réactive l'effet de la dernière carte retournée avant Massinissa Merabet, en faisant comme elle l'avait posée elle-même, même si ce n'est pas le cas
*/
void Massinissa_Merabet(faction _faction,faction _faction_oppose, plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns l'attribut DDRS d'une faction
@ensures La faction qui a le moins de points DDRS gagne 3 points DDRS
*/
void Vitera_Y(faction _faction, faction _faction_oppose, int ligne, int colonne, plateau _plateau);




/*
@requires faction valide
@assigns le plateau
@ensures Supprimez toutes les cartes Heures supplémentaires retournées du plateau
*/
void Jonas_Senizergues(plateau _plateau, int ligne, int colonne);
/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, 
supprimez toutes les cartes de la ligne et de la colonne où est posée cette carte (y compris celle-ci)-> 
Sinon la faction qui a posé cette carte gagne 1 point DDRS par carte Catherine Dubois, 
Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest et Dimitri Watel retournée sur le plateau
*/
void Fetia_Bannour(faction _faction, plateau _plateau, int ligne, int colonne);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau
@ensures Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte
*/
void Catherine_Dubois(plateau _plateau, int ligne, int colonne);
/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Pour chaque carte EcologIIE, Ecocup, Isolation du bâtiment et parcours Sobriété numérique retournée, 
la faction qui a posé cette carte gagne 3 points DDRS et la dernière carte non retournée du plateau est supprimée
*/
void Anne_Laure_Ligozat(faction _faction, plateau _plateau, int ligne, int colonne) ;




/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures Si la faction adverse de celle qui a posé cette carte a plus de points DDRS, la seconde lui vole 3 points DDRS->
*/
void Guillaume_Burel(faction _faction, faction _faction_oppose, int ligne, int colonne, plateau _plateau) ;

/*
@requires faction valide
@assigns le plateau
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes retournées du plateau sauf les cartes Christophe Mouilleron et Heures supplémentaires
*/
void Christophe_Mouilleron(plateau _plateau, int ligne, int colonne) ;


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Si Julien Forest n'est par retourné sur le plateau, 
la faction qui a posé cette carte gagne 3 points DDRS par carte FISE retournée sur le plateau-> 
Sinon la faction adverse perd 1 point DDRS par carte FISE retournée sur le plateau
*/
void Thomas_Lim(faction _faction, faction _faction_oppose, plateau _plateau, int ligne, int colonne) ;
/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte gagne 6 points DDRS par carte FISE retournée sur le plateau si au moins une carte Café est retournée sur le plateau
*/
void Julien_Forest(faction _faction, plateau _plateau, int ligne, int colonne) ;
/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte gagne 3 points DDRS par carte FISA ou FC retournée sur le plateau si au moins une carte Thé est retournée sur le plateau
*/
void Dimitri_Watel(faction _faction, plateau _plateau, int ligne, int colonne);
/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures S'il y a plus de 3 cartes retournées sur la ligne de cette carte, la faction qui a posé cette carte gagne 5 points DDRS
*/
void Djibril_Aurelien_Dembele_Cabot(faction _faction, plateau _plateau, int ligne, int colonne);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau
@ensures Prenez au hasard 5 cartes retournées du plateau (ou toutes les cartes retournées du plateau s'il y a moins de 5)-> 
Si une de ces cartes est une carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, 
Julien Forest ou Dimitri Watel, mélangez les et placez les à gauche de la case la plus à gauche de la première ligne-> 
Les prochaines cartes à être retournées sont ces cartes là-> Sinon, supprimez ces cartes du plateau
*/
void Eric_Lejeune(plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures S'il y a une carte FISA retournée dans la même ligne ou la même colonne que cette carte, la faction qui a posé cette carte gagne 5 points DDRS
*/
void Lucienne_Pacave(faction _faction, plateau _plateau, int ligne, int colonne) ;

/*
@requires faction valide
@assigns le plateau ou l'attribut DDRS de la faction
@ensures Si les cartes Djibril-Aurélien Djembele-Cabeau, 
Eric Lejeune et Lucienne Pacavé sont retournées, 
la faction qui a posé cette carte gagne 10 points DDRS->
 Sinon, retournez toutes les cartes dans la même ligne de cette carte sans appliquer leurs effets
*/
void Katrin_Salhab(faction _faction, plateau _plateau, int ligne, int colonne);
/*
@requires factions valides
@assigns les points DDRS de la faction
@ensures Si Laurent Prével est la dernière carte retournée du plateau, la faction qui a posé cette carte gagne la manche, quel que soit le nombre de points DDRS des deux factions
*/
void Laurent_Prevel(faction _faction, faction _faction_oppose, plateau _plateau, int ligne, int colonne);


#endif
