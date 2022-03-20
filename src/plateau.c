#include "plateau.h"

#define LENGTH 1000

/* implémentation du type case */
struct Case {
    carte carte; // carte posée sur la case en question
    int id_faction; // 0 ou 1 qui détermine la faction qui a posée la carte
    int etat; // 0 si la carte est face cachée ou 1 si elle est face visible
};

/* implémentation du type plateau */
struct plateau {
    Case** tab; // matrice de cases de taille 1000 x 1000
};

struct faction {
    char nom;
    int nombre_points_DDRS;
    pile main; /* type liste défini dans structure.h */
    pile pioche; /* type pile défini dans structure.h */
};

plateau init_plateau(){
    plateau _plateau;
    _plateau.tab = (Case**) malloc(LENGTH * sizeof(Case*));
    for(int i = 0; i < LENGTH; i++){
        _plateau.tab[i] = (Case*) malloc(LENGTH * sizeof(Case));
    }
    return _plateau;
}

void libere_plateau(plateau _plateau){
    for(int i = 0; i < LENGTH; i++){
        free(_plateau.tab[i]);
    }
    free(_plateau.tab);
}

int init_manche(plateau p){
    //tire carte
    // 1 si fin 0 sinon
}

faction* liste_faction(){

}

void poser(plateau p, carte c, int* pos){

}

carte retourner(plateau p, faction* facs){

}