
/* importation du module carte */
#include "carte.h"

/* importation du module faction */
#include "faction.h"

/* importation du module structure */
#include "interface.h"

/* importation du module plateau */
#include "plateau.h"

/* implémentation du type plateau */
struct plateau {
    carte tab[1000][1000]; // matrice de cartes de taille 1000x1000
};

int main(int argc, char* argv[]){
    plateau p = init_plateau();
    faction[2] facs = liste_faction();
    afficheplateau(p);

    // init joueur
    for(int i = 0; i < 2; i++){
        affichemain(facs[i]);
        afficheoptions();
        useoption(optionchoisi(), facs[i]);
    }

    // manche 1
    for(int i = 0, i < 16; i++){
        affichemain(facs[i%2]);
        carte c = cartechoisi();
        int pos = positioncartechoisi();
        poser(&p, c, pos);
    }

    //manche 2
    while(fin_manche(p) != 1){
        int pos = retourner(&p);
        affichereffet(p, pos);
    }

    affichevainqueur();
    return 0;
}