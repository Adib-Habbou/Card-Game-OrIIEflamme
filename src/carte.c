/* importation du module carte */
#include "../headers/carte.h"

/* importation du module faction */
#include "../headers/faction.h"

/* importation du module plateau */
#include "../headers/plateau.h"

/* définition de la structure des cartes */
struct carte {
    char nom;
    char description;
    int nombre_occurrences;
};

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char get_carte_nom(carte carte) {
    return carte.nom;
}

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char get_carte_description(carte carte) {
    return carte.description;
}

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nomnre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte) {
    return carte.nombre_occurrences;
}

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie le nom de la carte */
void set_carte_nom(carte carte, char nom) {
    carte.nom = nom;
}

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char description) {
    carte.description = description;
}

/*  @requires   une carte valide et un entier
    @assigns    carte
    @ensures    modifie le nomnre d'occurrences de la carte */
void set_carte_nombre_occurrences(carte carte, int nombre_occurrences) {
    carte.nombre_occurrences = nombre_occurrences;
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 1
*/
void FISE(faction f) {
    f.DDRS+=1;
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 2
*/
void FISA(faction f, plateau p) {
    int nb_pair=0;
    int i,j;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (p[i][j].case.etat == 1) {
                nb_pair+=1;//si 1 indique que la carte est retournée 
            }
        }
    }
    if (nb_pair%2 == 0) {
        f.DDRS+=2;
    }
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 4
*/
void FC(faction f) {
    int drapeau_FC=0;
    int i,j;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (p[i][j].case.carte == "FC" && p[i][j].case.etat==1) {
                drapeau_FC=1;//si 1 indique que une carte FC est présente et retournée
            }
        }
    }
    if (drapeau_FC) { //au moins une carte FC était retournée
        f.DDRS+=4;
    }
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 1 pour chaque carte FISE, FISA ou FC retournées
*/
void EcologIIE(faction f) {
    int total = 0;
    int i,j;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (p[i][j].case.etat == 1 && ( (p[i][j].case.carte == "FC") || (p[i][j].case.carte == "FISE") || (p[i][j].case.carte == "FISA") )) {
                total+=1; 
            }
        }
    }
    f.DDRS+=total ;
}

