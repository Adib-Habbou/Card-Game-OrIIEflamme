#ifndef CARTE_H  /* pour éviter des inclusions multiples */
#define CARTE_H

/* définition du type abstrait des cartes */
typedef struct carte *carte;


// CONSTANTES ET VARIABLES GLOBALES 

/* noms des différentes cartes */

/* FISE */
carte FISE;
set_carte_nom(FISE, "FISE");

/* FISA */
carte FISA;
set_carte_nom(FISA, "FISA");
set_carte_description(FISA, "La faction qui a posé cette carte gagne 2 points DDRS si le nombre de cartes retournées sur le plateau (y compris celle-ci) est pair, et 0 sinon.")



// GETTERS ET SETTERS 

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char get_carte_nom(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char get_carte_description(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nombre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie le nom de la carte */
void set_carte_nom(carte carte, char nom);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char description);

/*  @requires   une carte valide et un entier
    @assigns    carte
    @ensures    modifie le nomnre d'occurrences de la carte */
void set_carte_nombre_occurrences(carte carte, int nombre_occurrences);

#endif
