#include "plateau.h"

/* implémentation du type case */
struct case {
    carte carte; // carte posée sur la case en question
    int id_faction; // 0 ou 1 qui détermine la faction qui a posée la carte
    int etat; // 0 si la carte est face cachée ou 1 si elle est face visible
};

/* implémentation du type plateau */
struct plateau {
    case tab[1000][1000]; // matrice de cases de taille 1000 x 1000
<<<<<<< HEAD
};
=======
} plateau;

plateau init_plateau(){

}

void libere_plateau(plateau p){

}

int fin_manche(plateau p){

}

faction* liste_faction(){

}

void poser(plateau p, carte c, int* pos){

}

carte retourner(plateau p, faction* facs){

}
>>>>>>> 2af9bccde026a905907e5a64b94c2e40e23a75f5
