/* importation du module test */
#include "../headers/test.h"

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
        for (int i=0; i < NOMBRE_JOUEURS; i++) {
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
        CU_ASSERT_PTR_NULL(liste_factions[NOMBRE_JOUEURS]); // comme les indices des listes démarrent à zéro, on s'attend à que liste_faction[NOMBRE_JOUEURS] renvoie NULL
        // Plateau vide : aucune case du plateau n'est occupée
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, i, j)), -1); // état : -1 si la case est vide
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
        init_manche(plateau, liste_factions);

    // test
        // Une quatrième manche ne peut pas être demarrée
        CU_ASSERT_EQUAL(init_manche(plateau, liste_factions), 0);
        // Le plateau a été vidé : aucune case du plateau n'est occupée
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, i, j)), -1); // état : -1 si la case est vide
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

/* Fonction auxiliaire pour tester l'appartenance d'une carte à la main d'une faction
    @requires   une main valide
    @assigns    rien
    @ensures    renvoie 1 si _carte appartient à la main, 0 sinon
*/
        int appartient(carte _carte, pile main_faction) {
            for (int i=0; i < NOMBRE_CARTES_MAIN_INITIAL; i++) {
                carte top = pile_sommet(main_faction);
                /* strcmp() compaire deux chaines de caractères, caractère par caractère. 
                    Si les deux chaines sont égales, la fonction renvoie 0. */
                if ( (strcmp(get_carte_nom(top), get_carte_nom(_carte))) == 0 ) { 
                    return 1;
                } 
                main_faction = pile_suivant(main_faction); // pile_suivant renvoie le reste de la pile, sans le sommet 
            }
            return 0;
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
        for (int i=0; i < NOMBRE_CARTES_MAIN_INITIAL; i++) {
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
        set_plateau_case(plateau, TAILLE_PLATEAU-1, TAILLE_PLATEAU-1, carte_a_poser, 0, 0); // état : 0 si la carte est face cachée

        Case case_carte_posee = get_plateau_case(plateau, TAILLE_PLATEAU-1, TAILLE_PLATEAU-1);

    // test
        // La case choisie est maintenant occupée et la carte est face cachée
        CU_ASSERT_EQUAL(get_case_etat(case_carte_posee), 0); // Etat d'une case : 0 si la carte est face cachée
        // La bonne carte est sur la case
        CU_ASSERT_EQUAL(strcmp(get_carte_nom(get_case_carte(case_carte_posee)), get_carte_nom(carte_a_poser)), 0);
        // La pose est attribuée à la bonne faction
        CU_ASSERT_EQUAL(strcmp(get_faction_nom(get_case_faction(case_carte_posee)), get_faction_nom(faction)), 0);
        // La main de la faction compte une carte de moins 
        int nombre_cartes_main_actuel = taille_pile(get_faction_main(faction));
        CU_ASSERT_EQUAL(nombre_cartes_main_actuel, nombre_cartes_main_initial-1);
        // La carte n'appartient plus à la main de la faction 
        CU_ASSERT_EQUAL(appartient(carte_a_poser, get_faction_main(faction)), 0);
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
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();

        // On positionne sur le plateau une carte lIIEns, qu'on gardera donc tout en haut à gauche
        set_plateau_case(plateau, 0, 4, liste_cartes[4], 0, 0); // lIIEns en position (0, 4) pour laisser la place pour positionner les cartes FISE/FISA/FC après remélange

        // On positionne sur le plateau des cartes FISE/FISA/FC retournées
        set_plateau_case(plateau, 0, 5, liste_cartes[0], 1, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau, 1, 5, liste_cartes[1], 0, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau, 1, 4, liste_cartes[2], 1, 1); // FC en position (1, 4) : à gauche de FISA

        // On retient le nom de la carte la plus en haut à gauche avant de la retourner
        int* position_premier = get_plateau_carte_premier(plateau);
        char* nom_carte_premier = get_plateau_carte_nom(plateau, position_premier[0], position_premier[1]);
        

    // action
        retourner(plateau, liste_factions); // lIIEns est la carte la plus en haut à gauche qui va donc être retournée


    // test
        // Parcourons toutes les cartes avant (ici lIIEns) 
        int* position_dernier = get_plateau_carte_dernier(plateau);
        for (int i = position_premier[0]; i < position_dernier[0]; i++) {
            for (int j = position_premier[1]; j < position_dernier[1]; j++) {
                while (1 == strcmp(get_plateau_carte_nom(plateau, i, j), nom_carte_premier)) {
                    // Toutes les cartes avant lIIEns sont soit FISE, soit FISA, soit FC    
                    char* nom_carte = get_plateau_carte_nom(plateau, i, j);
                    CU_ASSERT( (0 == strcmp(nom_carte, "FISE")) || (0 == strcmp(nom_carte, "FISA")) || (0 == strcmp(nom_carte, "FC")) ); 
                    // Toutes les cartes avant lIIEns, à priori que des cartes FISE/FISA/FC, sont reposées face cachée
                    Case case_carte = get_plateau_case(plateau, i, j);
                    CU_ASSERT_EQUAL(get_case_etat(case_carte), 0); // Etat d'une case : 0 si la carte est face cachée    
                }   
            } 
        }

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
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();

        // On positionne sur le plateau une carte Soirée sans alcool, qu'on gardera donc tout en haut à gauche
        set_plateau_case(plateau, 0, 4, liste_cartes[5], 0, 0); // Position (0, 4) pour laisser la place pour positionner les cartes FISE/FISA/FC après remélange

        // On positionne sur le plateau des cartes FISE/FISA/FC retournées
        set_plateau_case(plateau, 0, 5, liste_cartes[0], 1, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau, 1, 5, liste_cartes[1], 0, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau, 1, 4, liste_cartes[2], 1, 1); // FC en position (1, 4) : à gauche de FISA

       

    // action
        retourner(plateau, liste_factions); // Soirée sans alcool est la carte la plus en haut à gauche qui va donc être retournée


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
void test_vainqueur_manche_non_egalite() {
// Cas de non égalité
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        // On "joue" artificiellement une manche : on se positionne en cas de non égalité
        set_faction_nombre_points_DDRS(liste_factions[0], 20);
        set_faction_nombre_points_DDRS(liste_factions[1], 34);
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();
        // On positionne des cartes fictives sur le plateau : dans le jeu chaque faction en a posées 8 (ici, on suppose que chacune en avait deux)
        set_plateau_case(plateau, 0, 5, liste_cartes[0], 1, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau, 1, 5, liste_cartes[1], 0, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau, 1, 4, liste_cartes[2], 1, 1); // FC en position (1, 4) : à gauche de FISA
        set_plateau_case(plateau, 2, 4, liste_cartes[23], 0, 1); // Christophe Mouilleron en position (2, 4) : en bas de Ecocup

    // action
        // On termine la manche : toutes les cartes sont retournées
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                Case _case = get_plateau_case(plateau, i, j);
                set_case_etat(_case, 1); // état : 1 si la carte est face visible
            }   
        }

    // test
        // La faction gagnante (ici la faction 2 car avec le plus de points DDRS) voit sa manche comptabilisée
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions[1]), 1); // ici une seule manche a été jouée
        // Le nombre de manches gagnées de l'autre faction ne varie pas
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions[0]), 0);
}

void test_vainqueur_manche_egalite() {
// Cas d'égalité
    // arrange
        // On initialise un nouveau plateau de jeu
        plateau plateau_egalite = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions_egalite = liste_faction();
        // On "joue" artificiellement la manche : on se positionne  cette fois-ci en cas d'égalité
        set_faction_nombre_points_DDRS(liste_factions_egalite[0], 20);
        set_faction_nombre_points_DDRS(liste_factions_egalite[1], 20);
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();
        // On positionne des cartes fictives sur le plateau : dans le jeu chaque faction en a posées 8 (ici, on suppose que chacune en avait deux)
        set_plateau_case(plateau_egalite, 0, 5, liste_cartes[0], 1, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau_egalite, 1, 5, liste_cartes[1], 0, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau_egalite, 1, 4, liste_cartes[2], 1, 1); // FC en position (1, 4) : à gauche de FISA
        set_plateau_case(plateau_egalite, 2, 4, liste_cartes[23], 0, 1); // Christophe Mouilleron en position (2, 4) : en bas de Ecocup

    // action
        // On termine la manche : toutes les cartes sont retournées
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                Case _case = get_plateau_case(plateau_egalite, i, j);
                set_case_etat(_case, 1); // état : 1 si la carte est face visible
            }   
        }

    // test
        // La faction gagnante voit sa manche comptabilisée
            // Déterminons la faction gagnante 

        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions_egalite[1]), 1); // ici une seule manche a été jouée
        // Le nombre de manches gagnées de l'autre faction ne varie pas
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(liste_factions_egalite[0]), 0);
}







/* À la troisième manche s'il y en a une, la première faction est de nouveau désignée au hasard. */

/* La faction qui remporte deux manches gagne la partie. */

/* Il n'y a pas de limite au nombre de points que peut avoir une faction dans une manche mais elle ne peut en avoir moins de 0. */



/* Test suite setup and cleanup functions */
int init_suite() {
    return 0;
}

int clean_suite() {
    return 0;
}

int main_test() {
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
   // Run all tests using the console interface
    CU_console_run_tests();
    
    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
    return 0;
}
