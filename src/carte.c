#include "../headers/carte.h"

#include "../headers/faction.h"

#include "../headers/plateau.h"

/* définition de la structure des cartes */
struct carte {
    char nom;
    char description;
    int nombre_occurrences;
};

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

