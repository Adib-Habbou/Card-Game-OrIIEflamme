
#include "../headers/main.h"

void AddCarte(fenetre _fenetre, int ligne, int colonne);

int main(){
    SDL_version nb;
    SDL_VERSION(&nb);

    printf("SDL v%d.%d.%d\n", nb.major, nb.minor, nb.patch);

    fenetre _fenetre = (fenetre) malloc(sizeof(fenetre));
    OpenFenetre("Oriieflamme", _fenetre);

    // Initialisation du plateau
    plateau _plateau = init_plateau();

    // Initialisation de la liste des factions
    faction* _factions = liste_faction();

    // Affichage du plateau sur la console
    affiche_plateau(_fenetre, _plateau);

    int manche = 1;
    int JoueurCommence = 0;

    init_manche(_plateau, _factions);
    printf("fin init_manche\n");

    // Initialisation d'une manche si le jeu n'est pas terminé 
    //while(init_manche(_plateau, _factions) != 0){
        if(manche%2 == 0){
            JoueurCommence = rand()%2;
        }else{
            JoueurCommence++;
        }

        // Initialisation des joueurs
        for(int i = 0; i < 2; i++){
            // Affichage la main de la faction i dans la console
            affiche_main(_fenetre, _factions[i], _plateau);
            
            // Demande à la faction actuelle si elle veut utiliser son option permettant de repiocher
            if(decision(_fenetre)){
                // Renvoie 1 si l'option remélanger a été utilisée, 0 autrement 
                if(test_remelanger(_factions[i]))
                    // Remelange les cartes de la fonction
                    remelanger(_factions[i]);
            }
            ClearAll(_fenetre);
            affiche_plateau(_fenetre, _plateau);
        }

        // Phase 1 :

        for(int i = JoueurCommence; i < NOMBRE_CARTES_MAIN_INITIAL*NOMBRE_JOUEURS+JoueurCommence; i++){
            // Affiche la main d'une faction tour par tour
            printf("affiche main\n");
            affiche_main(_fenetre, _factions[i%2], _plateau);
            // Retourne la carte choisi par la faction
            printf("choisi carte\n");
            carte _carte = carte_choisie(_fenetre, _factions[i%2]);
            // Retourne la position sur le plateau où la faction décide de poser la carte
            printf("choisi position\n");
            int* _position = carte_positon(_fenetre, _plateau);
            // Pose la carte sur le plateau
            printf("pose carte %s à la position x = %i et y= %i\n", get_carte_nom(_carte), _position[0], _position[1]);
            poser(_plateau, _carte, _position);

            printf("affiche plateau\n");
            ClearAll(_fenetre);
            affiche_plateau(_fenetre, _plateau);
        }

        // Phase 2 :

        // Boucle infini on s'arrete quand il n'y a plus de carte sur le plateau
        // Retourne la carte la plus haute à gauche si elle existe et affiche son effet
        while(1){
            printf("retourne\n");
            carte _carte = retourner(_plateau, _factions);
            printf("affiche plateau\n");
            ClearAll(_fenetre);
            affiche_plateau(_fenetre, _plateau);
            if(_carte == NULL)
                break;
            afficher_effet(_fenetre, _carte, _plateau);
        }
        printf("fin de la manche\n");
        manche++;


    //}

    // Affichage du gagnant
    gagnant(_fenetre, _factions, _plateau);

    CloseFenetre(_fenetre);
    return 0;
}