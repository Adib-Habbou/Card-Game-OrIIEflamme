#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/* importation de tous les modules des interfaces */
#include "main.h"




// Initialisations 

/* Vérifie la bonne initialisation d'une faction :
    - le nom n'est pas vide ;
    - le nombre initial de points DDRS est nul ;
    - la main de départ est vide ;
    - la pioche de départ est vide ;
    - l'option rémélanger n'a pas encore été utilisée ;
    - aucune manche n'a encore été gagnée. 
*/
void test_initialisation_faction() {
    // arrange : aucune 

    // action
        // On initialise deux factions et on effectue les tests sur la première
        faction* liste_factions = liste_faction();

    // test
        for (int i=0, i<2, i++) {
            // La faction possède un nom valide
            CU_ASSERT(get_faction_nom(liste_factions[i]) != "");
            // La faction n'a pas encore de points DDRS
            CU_ASSERT(get_faction_nombre_points_DDRS(liste_factions[i]) == 0);
            // La main de la faction est vide
            CU_ASSERT_TRUE(pile_est_vide(get_faction_main(liste_factions[i])));
            // La pioche contient encore l'entierete des cartes
            CU_ASSERT(NULL == get_faction_pioche(liste_factions[i]));
            // L'option rémélanger n'a pas encore été utilisée par la faction  
            CU_ASSERT(get_faction_option_remelanger(liste_factions[i]) == test_remelanger(liste_factions[i]));
            CU_ASSERT(0 == test_remelanger(liste_factions[i]));
            // La faction n'a pas encore gagné aucune manche
            CU_ASSERT(0 == get_faction_manches_gagnees(liste_factions[i]));
    }
}





/* Vérifie la bonne initialisation d'un plateau :
    - bonne allocation de mémoire ;
    - il n'y a que deux joueurs pour une partie ;
    - il est possible d'initialiser une manche.
*/
void test_initialisation_plateau() {
    // arrange
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();

    // action
        plateau plateau = init_plateau();

    // test
        // Nombre correct de joueurs sur le plateau
        CU_ASSERT_NULL(liste_faction[NOMBRE_JOUEURS]); // comme les indices des listes démarrent à zéro, on s'attend à que liste_faction[NOMBRE_JOUEURS] renvoie NULL
        // Plateau vide : aucune case du plateau n'est occupée
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                CU_ASSERT_NULL(get_case_carte(plateau->tab[i][j]))
            }   
        }
        // Le jeu n'est pas terminé
        CU_ASSERT_EQUAL(init_manche(plateau, liste_factions), 1) // init_manche renvoie 1 s'il est possible de commencer une manche de jeu
}





/* Vérifie l'ordre aléatoire des factions à la première manche :
        une faction au hasard est désignée "Première faction"
*/
void test_ordre_aleatoire_factions_premiere_manche() {
    // arrange
        // On initialise le plateau de jeu
    plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
    faction* liste_factions = liste_faction();

    // action
        // On initialise la première manche
        init_manche(plateau, liste_factions);
  
    // test
       
}


/* Vérifie l'ordre déterministe des factions à la deuxième manche :
    - la "Deuxième faction" lors de la première manche est désignée "Première faction"
*/
void test_ordre_deterministe_factions_deuxieme_manche() {
    // arrange
        // On initialise le plateau de jeu
    plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
    faction* liste_factions = liste_faction();
        // On initialise la première manche
    init_manche(plateau, liste_factions);

    // action
        // On initialise la deuxième manche
    init_manche(plateau, liste_factions);
  
    // test
       
}



/* Vérifie la présence ou non d'une troisième manche :
        si au bout de deux manches, chaque faction en a gagnée une, une troisième manche est demarrée
*/
void test_presence_troisieme_manche() {
    // arrange
        // On initialise le plateau de jeu
    plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
    faction* liste_factions = liste_faction();
        // On initialise la première manche
    init_manche(plateau, liste_factions);
        // On initialise la deuxième manche
    init_manche(plateau, liste_factions);

    // action
        // On vérifie si selon les règles du jeu, il faudrait commencer une troisième manche
    CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions[0]), 1)
    CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions[0]), 1)

    // test
        // On vérifie que, si nécessaire, une troisième manche peut être demarrée
    CU_ASSERT_EQUAL(init_manche(plateau, liste_factions), 1)
}



/* Vérifie le bon fonctionnement de l'option pour repiocher
*/
void test_option_repiocher() {
    // arrange
         // On initialise deux factions et on effectue les tests sur la première
    faction* liste_factions = liste_faction();
    faction faction = liste_factions[0];

    // action
        // On utilise l'option pour repiocher 

        // La faction veut utiliser l'option


        // L'option n'a pas déjà été utilisée par cette faction pendant les manches de cette partie 
    CU_ASSERT_EQUAL(test_remelanger(faction), 0);
    vider_main(faction);
    CU_ASSERT_NULL(get_faction_main(faction)); // on vérifie que la main est bien vide après avoir utilisé la fonction vider_main
    remelanger(faction);
    repiocher(faction);
    CU_ASSERT_EQUAL(taille_pile(get_faction_main(faction)), 8); // on vérifie que la faction a bien repioché 8 cartes

    // test
        // 
        
}


si elle n'est pas satisfaite de son tirage,
une fois dans l'ensemble des manches du jeu, 
remettre sa main dans la boîte à idées, 
la remélanger et repiocher 8 cartes


/* À la troisième manche s'il y en a une, la première faction est de nouveau désignée au hasard. */

/* La faction qui remporte deux manches gagne la partie. */

/* Il n'y a pas de limite au nombre de points que peut avoir une faction dans une manche mais elle ne peut en avoir moins de 0. */
