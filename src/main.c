#include "../headers/main.h"

int main(){
/*
    // Initialisation du plateau
    plateau _plateau;

    // Initialisation de la liste des factions
    faction* _factions = liste_faction();

    int manche = 1;
    int JoueurCommence = 0;
    srand(time(NULL));

    // Initialisation d'une manche si le jeu n'est pas terminé 
    while(init_manche(_factions) != 0){

        _plateau = init_plateau();

        affiche_plateau(_plateau);

        if(manche%2 == 1){
            JoueurCommence = rand()%2;
        }else{
            JoueurCommence++;
        }
        // Initialisation des joueurs
        for(int i = 0; i < NOMBRE_JOUEURS; i++){
            // Affichage la main de la faction i dans la console
            affiche_main(_factions[i],i);
            // Demande à la faction actuelle si elle veut utiliser son option permettant de repiocher
            if(decision()){
                // Renvoie 1 si l'option remélanger a été utilisée, 0 autrement 
                if(test_remelanger(_factions[i]))
                    // Remelange les cartes de la fonction
                    remelanger(_factions[i]);
            }
        }

        // Phase 1 :
        
        for(int i = JoueurCommence; i < NOMBRE_CARTES_MAIN_INITIAL*NOMBRE_JOUEURS+JoueurCommence; i++){
            printf("oklm\n");
            // Affiche la main d'une faction tour par tour
            affiche_main(_factions[i%2],i%2);
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
            if(_carte == NULL)
                break;
            afficher_effet(_carte);
            affiche_plateau(_plateau);
        }

        manche++; // passage à la manche suivante
        libere_plateau(_plateau);
    }

    // Affichage du gagnant
    gagnant(_factions,_plateau);
*/
    main_test();
    return 0;
}
