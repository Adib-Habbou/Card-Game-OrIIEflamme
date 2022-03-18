/* importation du module carte */
#include "carte.h"

/* importation du module faction */
#include "faction.h"

/* importation du module structure */
#include "interface.h"

/* importation du module plateau */
#include "plateau.h"

#include <stddef.h>

int main(){
    plateau p = init_plateau();
    faction* facs = liste_faction();
    affiche_plateau(p);

    // Manche
    while(fin_manche(p) != 0){
        // Init joueur
        for(int i = 0; i < 2; i++){
            affiche_main(facs[i]);
            decision();
            if(test_remelanger(facs[i]))
                remelanger(facs[i]);
        }

        // Phase 1
        for(int i = 0; i < 16; i++){
            affiche_main(facs[i%2]);
            carte c = carte_choisie(facs[i%2]);
            int* pos = carte_positon(p);
            poser(p, c, pos);
        }

        // Phase 2
        while(1){
            carte c = retourner(p, facs);
            if(c == NULL)
                break;
            afficher_effet(c);
        }
    }

    gagnant(facs);
    return 0;
}