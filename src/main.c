#include "../headers/main.h"

int main(){

    // Initialisation du plateau
    plateau _plateau = init_plateau();

    // Initialisation de la liste des factions
    faction* _factions = liste_faction();

    // Affichage du plateau sur la console
    affiche_plateau(_plateau);

    int manche = 1;
    int JoueurCommence = 0;

    // Initialisation d'une manche si le jeu n'est pas terminé 
    while(init_manche(_plateau, _factions) != 0){
        if(manche%2 == 0){
            JoueurCommence = rand()%2;
        }else{
            JoueurCommence++;
        }
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
        
        for(int i = JoueurCommence; i < 16+JoueurCommence; i++){

            
            // Affiche la main d'une faction tour par tour
            affiche_main(_factions[i%2]);
            // Retourne la carte choisi par la faction
            carte _carte = carte_choisie(_factions[i%2]);
            // Retourne la position sur le plateau où la faction décide de poser la carte
            int* _position = carte_positon(_plateau,i%2); 
            //Pose la carte sur le plateau
            poser(_plateau, _carte, _position);
            affiche_plateau(_plateau);
            
        }

        // Phase 2 :

        // Boucle infini on s'arrete quand il n'y a plus de carte sur le plateau
        // Retourne la carte la plus haute à gauche si elle existe et affiche son effet
        while(1){
            carte _carte = retourner(_plateau, _factions);
            if(get_carte_nom(_carte) == NULL)
                break;
            afficher_effet(_carte);
        }
        manche++;
    }

    // Affichage du gagnant
    gagnant(_factions);

    return 0;
}
