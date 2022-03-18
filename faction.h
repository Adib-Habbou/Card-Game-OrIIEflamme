#ifndef FACTION_H  /* pour éviter des inclusions multiples */
#define FACTION_H


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

#endif
