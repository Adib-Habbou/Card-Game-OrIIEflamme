#ifndef CARTE_H  /* pour éviter des inclusions multiples */
#define CARTE_H

/* définition du type abstrait des cartes */
typedef struct carte *carte;

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
    @ensures    renvoie le nomnre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte);

#endif
