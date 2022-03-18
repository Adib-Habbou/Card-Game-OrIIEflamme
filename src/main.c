/* importation du module carte */
#include "carte.h"

/* importation du module faction */
#include "faction.h"

/* importation du module structure */
#include "interface.h"

/* importation du module plateau */
#include "plateau.h"

/* Pour le null */
#include <stddef.h>

int main(){

    // Initialisation du plateau
    plateau p = init_plateau();

    // Initialisation de la liste des factions
    faction* facs = liste_faction();

    // Affichage du plateau sur la console
    affiche_plateau(p);

    // Initialisation d'une manche si le jeu n'est pas terminé 
    while(fin_manche(p) != 0){
        // Initialisation des joueurs
        for(int i = 0; i < 2; i++){
            // Affichage la main de la faction i dans la console
            affiche_main(facs[i]);
            // Demande à la faction actuelle si elle veut utiliser son option permettant de repiocher
            decision();
            // Renvoie 1 si l'option remélanger a été utilisée, 0 autrement 
            if(test_remelanger(facs[i]))
            // Remelange les cartes de la fonction
                remelanger(facs[i]);
        }

        // Phase 1 :

        // Boucle pour chaque carte qu'on va poser
        for(int i = 0; i < 16; i++){
            // Affiche la main d'une faction tour par tour
            affiche_main(facs[i%2]);
            // Retourne la carte choisi par la faction
            carte c = carte_choisie(facs[i%2]);
            // Retourne la position sur le plateau où la faction décide de poser la carte
            int* pos = carte_positon(p);
            // Pose la carte sur le plateau
            poser(p, c, pos);
        }

        // Phase 2 :

        // Boucle infini on s'arrete quand il n'y a plus de carte sur le plateau
        // Retourne la carte la plus haute à gauche si elle existe et affiche son effet
        while(1){
            carte c = retourner(p, facs);
            if(c == NULL)
                break;
            afficher_effet(c);
        }
    }

    // Affichage du gagnant
    gagnant(facs);

    return 0;
}
