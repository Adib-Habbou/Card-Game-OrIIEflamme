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
        for (int i=0, i < NOMBRE_JOUEURS, i++) {
            // La faction possède un nom valide
            CU_ASSERT_EQUAL(strcmp(get_faction_nom(liste_factions[i]), ""), 1); // Si deux chaines de caractères sont égales, la fonction strcmp() renvoie 0.
            // La faction n'a pas encore de points DDRS
            CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(liste_factions[i]), NOMBRE_POINTS_DDRS_INITIAL);
            // La main de la faction est vide
            CU_ASSERT_TRUE(pile_est_vide(get_faction_main(liste_factions[i])));
            // La pioche contient encore l'entierete des cartes
            CU_ASSERT_PTR_NULL(get_faction_pioche(liste_factions[i]));
            // L'option rémélanger n'a pas encore été utilisée par la faction  
            CU_ASSERT_EQUAL(get_faction_option_remelanger(liste_factions[i]), test_remelanger(liste_factions[i]));
            CU_ASSERT_EQUAL(test_remelanger(liste_factions[i]), 0);
            // La faction n'a pas encore gagné aucune manche
            CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions[i]), 0);
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
        CU_ASSERT_PTR_NULL(liste_faction[NOMBRE_JOUEURS]); // comme les indices des listes démarrent à zéro, on s'attend à que liste_faction[NOMBRE_JOUEURS] renvoie NULL
        // Plateau vide : aucune case du plateau n'est occupée
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                CU_ASSERT_PTR_NULL(get_case_carte(plateau->tab[i][j]))
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
       // TODO
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
       // TODO
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
        // On "joue" artificiellement deux manches et on se positionne dans le cas où une troisième manche devrait être initialisée : 
            // chacune des deux factions a déjà gagné une manche
            set_faction_manches_gagnees(liste_factions[0], 1);
            set_faction_manches_gagnees(liste_factions[1], 1);
            // chacune des deux factions possède un nombre strictement supérieur à zero de points DDRS
            set_faction_nombre_points_DDRS(liste_factions[0], 20);
            set_faction_nombre_points_DDRS(liste_factions[1], 34);

    // action
        // On initialise une troisième manche
        init_manche(plateau, liste_factions)

    // test
        // Une quatrième manche ne peut pas être demarrée
        CU_ASSERT_EQUAL(init_manche(plateau, liste_factions), 0)
        // Le plateau a été vidé : aucune case du plateau n'est occupée
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                CU_ASSERT_PTR_NULL(get_case_carte(plateau->tab[i][j]));
            }   
        }
        // La main de chaque faction est vide
            CU_ASSERT_TRUE(pile_est_vide(get_faction_main(liste_factions[0])));
            CU_ASSERT_TRUE(pile_est_vide(get_faction_main(liste_factions[1])));
        // Au début de chaque manche, les deux factions ont 0 points DDRS
        CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(liste_factions[0]), NOMBRE_POINTS_DDRS_INITIAL);
        CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(liste_factions[1]), NOMBRE_POINTS_DDRS_INITIAL);
}



/* Vérifie le bon fonctionnement de l'option pour repiocher */

// Fonction auxiliaire pour tester l'appartenance d'une carte à la main d'une faction
        int appartient(carte _carte, faction _faction) {
            pile main_faction = get_faction_main(_faction);
            for (int i=0, i < NOMBRE_CARTES_MAIN_INITIAL, i++) {
                carte top = pile_sommet(main_faction);
                /* strcmp() compaire deux chaines de caractères, caractère par caractère. 
                    Si les deux chaines sont égales, la fonction renvoie 0. */
                if ( (strcmp(get_carte_nom(top), get_carte_nom(_carte))) == 0 ) { 
                    return 1;
                } 
                else {return 0;}
                main_faction = pile_suivant(main_faction); // pile_suivant renvoie le reste de la pile, sans le sommet 
            }
        }

void test_option_repiocher() {
    // arrange
         // On initialise deux factions et on effectue les tests sur la première
        faction* liste_factions = liste_faction();
        /* On choisit de travailler avec une seule faction.
            Nous avons testé la bonne initialisation des deux factions. 
            Comme elles sont dans le même état, il suffit donc de tester les règles de jeu sur une seule des deux. */
        faction faction = liste_factions[0]; 
        pile ancienne_main = get_faction_main(faction);

    // action
        // On utilise l'option pour repiocher 
        remelanger(faction);
    
    // test
        // La faction a bien repioché 8 cartes
        CU_ASSERT_EQUAL(taille_pile(get_faction_main(faction)), NOMBRE_CARTES_MAIN_INITIAL); 
        // La nouvelle main est différente de l'ancienne
        pile nouvelle_main = get_faction_main(faction);
        int nombre_cartes_egales = 0; // compteur du nombre de cartes de l'ancienne main présentes dans la nouvelle
        carte carte_a_verifier;
        for (int i=0, i < NOMBRE_CARTES_MAIN_INITIAL, i++) {
            carte_a_verifier = pile_sommet(ancienne_main);
            nombre_cartes_egales += appartient(carte_a_verifier, nouvelle_main);
            ancienne_main = pile_suivant(ancienne_main);
        }
        CU_ASSERT_NOT_EQUAL(nombre_cartes_egales, NOMBRE_CARTES_MAIN_INITIAL); // au moins une carte de la nouvelle main n'était pas présente dans l'ancienne
        // La faction ne pourra plus utiliser l'option remelanger 
        CU_ASSERT_EQUAL(get_faction_option_remelanger(faction), 1);
}



/* Vérifie la bonne pose d'une carte sur le plateau */
void test_pose_carte() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        faction faction = liste_factions[0];
        int nombre_cartes_main_initial = taille_pile(get_faction_main(faction));

    // action
        carte carte_a_poser = carte_choisie(faction);
        // On se positionne tout en bas à droite du plateau, case très probablement vide
        int* position = malloc(2*sizeof(int));
        position = [TAILLE_PLATEAU-1, TAILLE_PLATEAU-1]; 
        poser(plateau, carte_a_poser, position); 
        Case _case = get_plateau_case(plateau, position[0], position[1])

    // test
        // La case choisie est maintenant occupée et la carte est face cachée
        CU_ASSERT_EQUAL(get_case_etat(_case), 0); // Etat d'une case : 0 si la carte est face cachée
        // La bonne carte est sur la case
        CU_ASSERT_EQUAL(strcmp(get_carte_nom(get_case_carte(_case)), get_carte_nom(carte_a_poser)), 0);
        // La pose est attribuée à la bonne faction
        CU_ASSERT_EQUAL(strcmp(get_faction_nom(get_case_faction(_case)), get_faction_nom(faction)), 0);
        // La main de la faction compte une carte de moins 
        int nombre_cartes_main_actuel = taille_pile(get_faction_main(faction));
        CU_ASSERT_EQUAL(nombre_cartes_main_actuel, nombre_cartes_main_initial-1);
        // La carte n'appartient plus à la main de la faction 
        CU_ASSERT_EQUAL(appartient(carte_a_poser, faction));
}



/* Vérifie le bon placement des cartes sur l'espace 2D */
void test_placement_cartes_espace2D() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        faction faction = liste_factions[0];

    // action

    // test
}



/* Vérifie la bonne activation des effets des cartes */

// lIIEns
void test_activation_effet_lIIEns() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        faction faction = liste_factions[0];

        // On positionne sur le plateau une carte lIIEns, qu'on gardera donc tout en haut à gauche
        poser(plateau, c_lIIEns, [0, 4]); // Position [0, 4] pour laisser la place pour positionner les cartes FISE/FISA/FC après remélange

        // On positionne sur le plateau des cartes FISE/FISA/FC retournées
        poser(plateau, c_FISE, [0, 5]); // Position [0, 5] : à droite de lIIEns
        poser(plateau, c_FISA, [1, 5]); // Position [1, 5] : en bas de FISE
        poser(plateau, c_FC, [1, 4]); // Position [1, 4] : à gauche de FISA

        Case case_FISE = plateau[0,5];
        Case case_FISA = plateau[1,5];
        Case case_FC = plateau[1,4];
        set_case_etat(case_FISE, 1); // etat : 0 si la carte est face cachée
        set_case_etat(case_FISA, 1);
        set_case_etat(case_FC, 1);

    // action
        retourner(plateau, faction) // lIIEns est la carte la plus en haut à gauche qui va donc être retournée


    // test
        // Toutes les cartes FISE/FISA/FC retournées sur le plateau sont retirées

        // Toutes les cartes FISE/FISA/FC sont reposées face cachée 

        // Toutes les cartes FISE/FISA/FC sont reposées sur la gauche de la carte la plus en haut à gauche du plateau

}


// Soirée sans alcool
void test_activation_effet_soiree_sans_alcool() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        faction faction = liste_factions[0];

        // On positionne sur le plateau une carte Soirée sans alcool, qu'on gardera donc tout en haut à gauche
        poser(plateau, c_Soiree_sans_alcool, [0, 4]); // Position [0, 4] pour laisser la place pour positionner les cartes FISE/FISA/FC après remélange

        // On positionne sur le plateau des cartes FISE/FISA/FC retournées
        poser(plateau, c_FISE, [0, 5]); // Position [0, 5] : à droite de lIIEns
        poser(plateau, c_FISA, [1, 5]); // Position [1, 5] : en bas de FISE
        poser(plateau, c_FC, [1, 4]); // Position [1, 4] : à gauche de FISA

        Case case_FISE = plateau[0,5];
        Case case_FISA = plateau[1,5];
        Case case_FC = plateau[1,4];
        set_case_etat(case_FISE, 1); // etat : 0 si la carte est face cachée
        set_case_etat(case_FISA, 1);
        set_case_etat(case_FC, 1);

       

    // action
        retourner(plateau, faction) // lIIEns est la carte la plus en haut à gauche qui va donc être retournée


    // test
        // Si au moins une carte alcool est retournée :
            // Toutes les cartes FISE/FISA/FC retournées du plateau sont supprimées


            // La première et la dernière ligne du plateau sont supprimées

        // Si aucune carte alcool est retournée :
            // La faction qui a posé la carte "Soirée sans alcol" gagne 5 points DDRS


}






/* Vérifie la bonne désignation du vainqueur de manche :
       faction qui a le plus de points DDRS à l'issue de la manche
       Attention : en cas d'égalité, la faction qui a posé la carte qui est la plus en haut à gauche du plateau à l'issue de la manche gagne
*/
void test_vainqueur_manche() {
// Cas de non égalité
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        // On "joue" artificiellement une manche : on se positionne en cas de non égalité
        set_faction_nombre_points_DDRS(liste_factions[0], 20);
        set_faction_nombre_points_DDRS(liste_factions[1], 34);
        // On positionne des cartes fictives sur le plateau : dans le jeu chaque faction en a posées 8 (ici, on suppose que chacune en avait deux)
        poser(plateau, c_FISE, [0, 5]); // Position [0, 5] : à droite de lIIEns
        poser(plateau, c_FISA, [1, 5]); // Position [1, 5] : en bas de FISE
        poser(plateau, c_Ecocup, [1, 4]); // Position [1, 4] : à gauche de FISA
        poser(plateau, c_Christophe_Mouilleron, [2, 4]); // Position [2, 4] : en bas de Ecocup

    // action
        // On termine la manche : toutes les cartes sont retournées
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                Case _case = plateau[i][j];
                set_case_etat(_case, 1); // état : 1 si la carte est face visible
            }   
        }

    // test
        // La faction gagnante (ici la faction 2 car avec le plus de points DDRS) voit sa manche comptabilisée
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions[1], 1); // ici une seule manche a été jouée
        // Le nombre de manches gagnées de l'autre faction ne varie pas
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions[0], 0);

// Cas d'égalité
    // arrange
        // On initialise un nouveau plateau de jeu
        plateau plateau_egalite = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions_egalite = liste_faction();
        // On remet à zero le compteur et on "rejoue" artificiellement la manche : on se positionne  cette fois-ci en cas d'égalité
        set_faction_nombre_points_DDRS(liste_factions_egalite[0], 20);
        set_faction_nombre_points_DDRS(liste_factions_egalite[1], 20);
        // On positionne des cartes fictives sur le nouveau plateau : chaque faction en a posées 8 (ici, on suppose que chacune en avait deux)
        poser(plateau_egalite, c_FISE, [0, 5]); // Position [0, 5] : à droite de lIIEns
        poser(plateau_egalite, c_FISA, [1, 5]); // Position [1, 5] : en bas de FISE
        poser(plateau_egalite, c_Ecocup, [1, 4]); // Position [1, 4] : à gauche de FISA
        poser(plateau_egalite, c_Christophe_Mouilleron, [2, 4]); // Position [2, 4] : en bas de Ecocup

    // action
        // On termine la manche : toutes les cartes sont retournées
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                Case _case = plateau_egalite[i][j];
                set_case_etat(_case, 1); // état : 1 si la carte est face visible
            }   
        }

    // test
        // La faction gagnante voit sa manche comptabilisée
            // Déterminons la faction gagnante 
            
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions_egalite[1], 1); // ici une seule manche a été jouée
        // Le nombre de manches gagnées de l'autre faction ne varie pas
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions_egalite[0], 0);
}







/* À la troisième manche s'il y en a une, la première faction est de nouveau désignée au hasard. */

/* La faction qui remporte deux manches gagne la partie. */

/* Il n'y a pas de limite au nombre de points que peut avoir une faction dans une manche mais elle ne peut en avoir moins de 0. */


int main ( void )
{
   CU_pSuite pSuite = NULL;
   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();
   /* add a suite to the registry */
   pSuite = CU_add_suite( "initialisation_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "test_initialisation_faction", test_initialisation_faction)) ||
        (NULL == CU_add_test(pSuite, "test_initialisation_plateau", test_initialisation_plateau))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   // Run all tests using the basic interface
     CU_basic_set_mode(CU_BRM_VERBOSE);
     CU_basic_run_tests();
     printf("\n");
     CU_basic_show_failures(CU_get_failure_list());
     printf("\n\n");
  /*
     // Run all tests using the automated interface
     CU_automated_run_tests();
     CU_list_tests_to_file();
     // Run all tests using the console interface
     CU_console_run_tests();
  */
     /* Clean up registry and return */
     CU_cleanup_registry();
      return CU_get_error();
}