#include "../headers/main.h"

int main(){

    // Initialisation du plateau
    plateau _plateau = init_plateau();

    // Initialisation de la liste des factions
    faction* _factions = liste_faction();

    // Affichage du plateau sur la console
    affiche_plateau(_plateau);

    // Initialisation d'une manche si le jeu n'est pas terminé 
    while(init_manche(_plateau, _factions) != 0){
        // Initialisation des joueurs
        for(int i = 0; i < 2; i++){
            // Affichage la main de la faction i dans la console
            affiche_main(_factions[i]);
            // Demande à la faction actuelle si elle veut utiliser son option permettant de repiocher
            if(decision()){
                // Renvoie 1 si l'option remélanger a été utilisée, 0 autrement 
                if(test_remelanger(_factions[i]))
                    // Remelange les cartes de la fonction
                    remelanger(_factions[i]);
            }
        }

        // Phase 1 :

        // Boucle pour chaque carte qu'on va poser
        for(int i = 0; i < 16; i++){
            // Affiche la main d'une faction tour par tour
            affiche_main(_factions[i%2]);
            // Retourne la carte choisi par la faction
            carte _carte = carte_choisie(_factions[i%2]);
            // Retourne la position sur le plateau où la faction décide de poser la carte
            int* _position = carte_positon(_plateau);
            // Pose la carte sur le plateau
            poser(_plateau, _carte, _position);
        }

        // Phase 2 :

        // Boucle infini on s'arrete quand il n'y a plus de carte sur le plateau
        // Retourne la carte la plus haute à gauche si elle existe et affiche son effet
        while(1){
            carte _carte = retourner(_plateau, _factions);
            if(_carte == NULL)
                break;
            afficher_effet(_carte);
        }
    }

    // Affichage du gagnant
    gagnant(_factions);

    return 0;
}
