#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/* importation de tous les modules des interfaces */
#include "main.h"




// Initialisations 

/* Vérifie la bonne initialisation d'une faction :
    - le nom n'est pas vide ;
    - le nombre initial de points DDRS est nul ;
    - la main de départ est vide ;
    - la pioche de départ est vide. 
    - */
void test_initialisation_faction() {
    // arrange : aucune 

    // action
    faction faction = init_faction();

    // test
        // La faction possède un nom valide
    CU_ASSERT(get_faction_nom(faction) != "");
        // La faction n'a pas encore de points DDRS
    CU_ASSERT(get_faction_nombre_points_DDRS(faction) == 0);
        // La main de la faction est vide
    CU_ASSERT_TRUE(pile_est_vide(get_faction_main(faction)));
        // La pioche contient encore l'entierete des cartes
    CU_ASSERT(NULL == get_faction_pioche(faction));
        // L'option rémélanger n'a pas encore été utilisée par la faction  
    CU_ASSERT(get_faction_option_remelanger(faction) == test_remelanger(faction));
    CU_ASSERT(0 == test_remelanger(faction));
        // La faction n'a pas encore gagné aucune manche
    CU_ASSERT(0 == get_faction_manches_gagnees(faction));
}





/* Vérifie la bonne initialisation d'un plateau :
    - bonne allocation de mémoire
    - il n'y a que deux joueurs pour une partie
    -  */
void test_initialisation_plateau(plateau plateau) {
    // arrange
        // On initialise les factions à placer sur le plateau
    faction faction = init_faction();

    // action
    plateau plateau = init_plateau();

    // test
        // Nombre correct de joueurs sur le plateau
    CU_ASSERT_NULL(liste_faction[NOMBRE_JOUEURS]);
        // Plateau vide
    CU_ASSERT
}









/* La faction qui remporte deux manches gagne la partie. */

/* Il n'y a pas de limite au nombre de points que peut avoir une faction dans une manche mais elle ne peut en avoir moins de 0. */
