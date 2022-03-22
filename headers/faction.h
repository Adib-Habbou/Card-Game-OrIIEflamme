#ifndef FACTION_H  /* pour éviter des inclusions multiples */
#define FACTION_H

/* importation du module structure */
#include "structure.h"

/* définition du tyoe abstrait des factions */
typedef struct faction *faction;


/* vérification de l'utilisation de l'option remélanger 
    @requires   faction valide
    @assigns    rien
    @ensures    renvoie 1 si l'option remélanger a été utilisée, 0 autrement */
int test_remelanger(faction fact);


/* utilisation de la fonction remélanger 
    @requires   faction valide
                boîte à idées pas vide
                option pas déjà utilisée dans la même manche par la même faction
    @assigns    rien
    @ensures    utilisation par une faction de l'option de remélanger sa main et la boîte à idée et de repiocher des cartes :
                    changement de la main de la faction
                    changement de la pioche de la faction
                    changement des cartes dans la boîte à idées */
void remelanger(faction fact);


/* vide de la main dans la pioche 
    @requires   faction valide
                main non vide
    @assigns    rien
    @ensures    permet à une faction de vider sa main dans sa pioche :
                    changement des cartes de la pioche de la faction */
void vider_main(faction fact);

/* mélange de la pioche 
    @requires   faction valide
                pioche non vide
    @assigns    rien
    @ensures    permet à une faction de mélanger sa pioche :
                    changement des cartes de la pioche de la faction */
void melanger_pioche(faction fact);

/* repioche d'une main
    @requires   faction valide
                main vide
    @assigns    rien
    @ensures    permet à une faction de repiocher les cartes de leur main :
                    changement de la main de la faction
                    changement des cartes de la pioche de la faction */
void repiocher(faction fact);

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie le nom de la faction */
char get_faction_nom(faction faction);

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie le nombre de points DDRS de la faction */
int get_faction_nombre_points_DDRS(faction faction);

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie la main de la faction */
pile get_faction_main(faction faction);

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie la pioche de la faction */
pile get_faction_pioche(faction faction);

/*  @requires   une faction valide et un chaîne de caractères
    @assigns    faction
    @ensures    modifie le nom de la faction */
void set_faction_nom(faction faction, char nom);

/*  @requires   une faction valide et un entier
    @assigns    faction
    @ensures    modifie le nombre de points DDRS de la faction */
void set_faction_nombre_points_DDRS(faction faction, int nomre_points_DDRS);

/*  @requires   une faction valide et une pile
    @assigns    faction
    @ensures    modifie la main de la faction */
void set_faction_main(faction faction, pile main);

/*  @requires   une faction valide et une pile
    @assigns    faction
    @ensures    modifie la pioche de la faction */
void set_faction_pioche(faction faction, pile pioche);

#endif
