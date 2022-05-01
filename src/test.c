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
            CU_ASSERT_NOT_EQUAL(strcmp(get_faction_nom(liste_factions[i]), ""), 0); // Si deux chaines de caractères sont égales, la fonction strcmp() renvoie 0.
            // La faction n'a pas encore de points DDRS
            CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(liste_factions[i]), NOMBRE_POINTS_DDRS_INITIAL);
            // La main de la faction est vide
            // CU_ASSERT_EQUAL(pile_est_vide(get_faction_main(liste_factions[i])), 1);
            // La pioche contient encore l'entierete des cartes
            // CU_ASSERT_PTR_NULL(get_faction_pioche(liste_factions[i]));
            // L'option rémélanger n'a pas encore été utilisée par la faction  
            CU_ASSERT_EQUAL(get_faction_option_remelanger(liste_factions[i]), 0);
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
                CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 0)), -1);  // état : -1 si la case est vide
            }   
        }
        // Le jeu n'est pas terminé
        CU_ASSERT_EQUAL(init_manche(liste_factions), 1) // init_manche renvoie 1 s'il est possible de commencer une manche de jeu
}





/* Vérifie l'ordre aléatoire des factions à la première manche :
        une faction au hasard est désignée "Première faction"
*/
/* void test_ordre_aleatoire_factions_premiere_manche() {
    // Nous allons simuler 100 premières manches et compter le nombre d'apparitions des factions en tant que premier joueur
    int compteur_faction0 = 0;
    int compteur_faction1 = 0;

    for (int i=0; i<100; i++) {
        // arrange
            // On initialise le plateau de jeu
        plateau plateau = init_plateau();
            // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();

        // action
            // On initialise la première manche
            init_manche(liste_factions);

        if (0 == JoueurCommence) {
            compteur_faction0++;
        }
        else {compteur_faction1++}

    }
  
    // test
       // TODO
} 
*/

/* Vérifie l'ordre déterministe des factions à la deuxième manche :
    - la "Deuxième faction" lors de la première manche est désignée "Première faction"
*/
/* void test_ordre_deterministe_factions_deuxieme_manche() {
    // arrange
        // On initialise le plateau de jeu
    plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
    faction* liste_factions = liste_faction();
        // On initialise la première manche
    init_manche(liste_factions);

    // action
        // On initialise la deuxième manche
    init_manche(liste_factions);
  
    // test
       // TODO
}

*/


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
        init_manche(liste_factions);

    // test
        // Le plateau a été vidé : aucune case du plateau n'est occupée
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                // printf("i : %i , j : %i , etat : %i \n", i, j, get_case_etat(get_plateau_case(plateau, i, j)));
                CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, i, j)), -1); // état : -1 si la case est vide
            }   
        }
        // Au début de chaque manche, les deux factions ont 0 points DDRS
        CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(liste_factions[0]), NOMBRE_POINTS_DDRS_INITIAL);
        CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(liste_factions[1]), NOMBRE_POINTS_DDRS_INITIAL);
        // Une quatrième manche ne peut pas être demarrée
            // On joue virtuellement la troisième manche : chacune des deux factions possède un nombre strictement supérieur à zero de points DDRS
            set_faction_nombre_points_DDRS(liste_factions[0], 20);
            set_faction_nombre_points_DDRS(liste_factions[1], 34);
        CU_ASSERT_EQUAL(init_manche(liste_factions), 0);
}



/* Vérifie le bon fonctionnement de l'option pour repiocher */

/* Fonction auxiliaire pour tester l'appartenance d'une carte à la main d'une faction
    @requires   une main valide
    @assigns    rien
    @ensures    renvoie 1 si _carte appartient à la main, 0 sinon
*/
        int appartient(carte _carte, pile main_faction) {
            if (!pile_est_vide(main_faction)) {
                int taille_main = taille_pile(main_faction); // on retient la taille initiale de la main pour pouvoir la parcourir
                pile* buffer_main = main_faction; // buffer pour parcourir la main sans la modifier
                for (int i=0; i < taille_main; i++) {
                    carte top = pile_sommet(buffer_main);
                    /* strcmp() compaire deux chaines de caractères, caractère par caractère. 
                        Si les deux chaines sont égales, la fonction renvoie 0. */
                    if ( (strcmp(get_carte_nom(top), get_carte_nom(_carte))) == 0 ) { 
                        return 1;
                    } 
                    depile(&buffer_main); // on passe à l'élément suivant de la pile 
                }
                return 0;
            }
            else { return 0; } // la main est vide donc la carte n'y appartient pas 
        }

void test_option_repiocher() {
    // arrange
         // On initialise deux factions et on effectue les tests sur la première
        faction* liste_factions = liste_faction();
        // On initialise una manche : les mains des factions seront initialisées également
        init_manche(liste_factions);
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
            // Retenons que l'idéntifiant de la faction qui va poser la carte est 0 (indice de position dans la liste des factions)
            int id_faction_posant_attendu = 0;
        // On initialise una manche : les mains des factions seront initialisées également
        init_manche(liste_factions);
        // On retient le nombre initial de cartes dans la main
        int nombre_cartes_main_initial = taille_pile(get_faction_main(faction));

    // action
        // On pose une carte (interface va demander quelle carte poser à l'utilisateur, donc le testeur devra input un entier dans la console)
        carte carte_a_poser = carte_choisie(faction);
        // On se positionne tout en bas à droite du plateau, case très probablement vide
        set_plateau_case(plateau, TAILLE_PLATEAU-1, TAILLE_PLATEAU-1, carte_a_poser, 0, 0); // état : 0 si la carte est face cachée
        Case case_carte_posee = get_plateau_case(plateau, TAILLE_PLATEAU-1, TAILLE_PLATEAU-1);

    // test
        // La case choisie est maintenant occupée et la carte est face cachée
        CU_ASSERT_EQUAL(get_case_etat(case_carte_posee), 0); // Etat d'une case : 0 si la carte est face cachée
        // La bonne carte est sur la case
        char* nom_carte_posee = get_plateau_carte_nom(plateau,TAILLE_PLATEAU-1, TAILLE_PLATEAU-1);
        CU_ASSERT_EQUAL(strcmp(nom_carte_posee, get_carte_nom(carte_a_poser)), 0);
        // La pose est attribuée à la bonne faction
        int id_faction_posant = get_case_id_faction(case_carte_posee);
        CU_ASSERT_EQUAL(id_faction_posant, id_faction_posant_attendu);
        // La main de la faction compte une carte de moins 
        int nombre_cartes_main_actuel = taille_pile(get_faction_main(faction));
        CU_ASSERT_EQUAL(nombre_cartes_main_actuel, nombre_cartes_main_initial-1);
        // La carte n'appartient plus à la main de la faction 
        affiche_main(get_faction_main(faction), 0);
        int test_appartenance = appartient(carte_a_poser, get_faction_main(faction));
        CU_ASSERT_EQUAL(test_appartenance, 0);
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
        // On initialise una manche : les mains des factions seront initialisées également
        init_manche(liste_factions);
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();

        // On positionne sur le plateau une carte lIIEns, qu'on gardera donc tout en haut à gauche
        set_plateau_case(plateau, 0, 4, liste_cartes[4], 0, 0); // lIIEns en position (0, 4) pour laisser la place pour positionner les cartes FISE/FISA/FC après remélange

        // On positionne sur le plateau des cartes FISE/FISA/FC retournées
        set_plateau_case(plateau, 0, 5, liste_cartes[0], 1, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau, 1, 5, liste_cartes[1], 0, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau, 1, 4, liste_cartes[2], 1, 1); // FC en position (1, 4) : à gauche de FISA

        // On retient le nom de la carte la plus en haut à gauche avant de la retourner
        int* position_carte_retournee = get_plateau_carte_premier(plateau);
        char* nom_carte_retournee = get_plateau_carte_nom(plateau, position_carte_retournee[0], position_carte_retournee[1]);
        

    // action
    printf("avant retourne\n");
        retourner(plateau, liste_factions); // lIIEns est la carte la plus en haut à gauche qui va donc être retournée
    printf("retourne\n");

    // test
        // Parcourons toutes les cartes avant celle qui vient d'être retournée (ici lIIEns)
        int* position_premier = get_plateau_carte_premier(plateau); 
        int* position_dernier = get_plateau_carte_dernier(plateau);
        for (int i = position_premier[0]; i < position_dernier[0]; i++) {
            for (int j = position_premier[1]; j < position_dernier[1]; j++) {
                while (1 == strcmp(get_plateau_carte_nom(plateau, i, j), nom_carte_retournee)) {
                    // Toutes les cartes avant sont soit FISE, soit FISA, soit FC    
                    char* nom_carte = get_plateau_carte_nom(plateau, i, j);
                    CU_ASSERT( (0 == strcmp(nom_carte, "FISE")) || (0 == strcmp(nom_carte, "FISA")) || (0 == strcmp(nom_carte, "FC")) ); 
                    // Toutes les cartes avant, à priori que des cartes FISE/FISA/FC, sont reposées face cachée
                    Case case_carte = get_plateau_case(plateau, i, j);
                    CU_ASSERT_EQUAL(get_case_etat(case_carte), 0); // Etat d'une case : 0 si la carte est face cachée    
                }   
            } 
        }
        // Parcourons toutes les cartes après celle qui vient d'être retournée (ici lIIEns)
        for (int i = position_carte_retournee[0]; i < TAILLE_PLATEAU-1; i++) {
            for (int j = position_carte_retournee[1]; j < TAILLE_PLATEAU-1; j++) {
                // Il n'y a pas d'autres cartes FISE/FISA/FC sur le plateau (hormis celles reposées sur la gauche de la carte la plus en haut à gauche du plateau)
                char* nom_carte = get_plateau_carte_nom(plateau, i, j);
                CU_ASSERT( (1 == strcmp(nom_carte, "FISE")) && (1 == strcmp(nom_carte, "FISA")) && (1 == strcmp(nom_carte, "FC")) );    
            } 
        }
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
        set_plateau_case(plateau, 0, 4, liste_cartes[5], 0, 0); // id_faction = 0 : c'est faction (=liste_factions[0]) à avoir posé la carte

        // On positionne sur le plateau des cartes FISE/FISA/FC retournées
        set_plateau_case(plateau, 0, 5, liste_cartes[0], 1, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau, 1, 5, liste_cartes[1], 0, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau, 1, 4, liste_cartes[2], 1, 1); // FC en position (1, 4) : à gauche de FISA

        // On retient la ligne la plus en haut et celle la plus en bas avant activation de la carte Soirée sans alcool
        int* position_premier_avant = get_plateau_carte_premier(plateau);
        int ligne_plus_haute_avant = position_premier_avant[0];
        int* position_dernier_avant = get_plateau_carte_dernier(plateau);
        int ligne_plus_basse_avant = position_dernier_avant[0];
        // On retient le nombre de points DDRS de la faction ayant posé la carte Soirée sans alcool avant son activation
        int points_DDRS_avant = get_faction_nombre_points_DDRS(faction);


    // action
    printf("avant retourne\n");
        retourner(plateau, liste_factions); // Soirée sans alcool est la carte la plus en haut à gauche qui va donc être retournée
    printf("apres retourne\n");

    // test
        // Si au moins une carte alcool est retournée :
        set_plateau_case(plateau, 0, 3, liste_cartes[6], 1, 1); // Alcool en position (0, 3) : tout en haut à gauche, juste avant Soirée sans alcool
            // Il n'y a pas de cartes FISE/FISA/FC face visible sur le plateau : toutes les cartes FISE/FISA/FC retournées du plateau sont supprimées
            for (int i = 0; i < TAILLE_PLATEAU-1; i++) {
                for (int j = 0; j < TAILLE_PLATEAU-1; j++) {
                    char* nom_carte = get_plateau_carte_nom(plateau, i, j);
                    Case case_carte = get_plateau_case(plateau, i, j);
                    if ( (0 == strcmp(nom_carte, "FISE")) || (0 == strcmp(nom_carte, "FISA")) || (0 == strcmp(nom_carte, "FC")) ) {
                        CU_ASSERT_EQUAL(get_case_etat(case_carte), 0); 
                    }
                } 
            }
            // La première et la dernière ligne du plateau sont supprimées
            int* position_premier_apres = get_plateau_carte_premier(plateau);
            int ligne_plus_haute_apres = position_premier_apres[0];
            CU_ASSERT_EQUAL(ligne_plus_haute_apres, ligne_plus_haute_avant+1);
            int* position_dernier_apres = get_plateau_carte_dernier(plateau);
            int ligne_plus_basse_apres = position_dernier_apres[0];
            CU_ASSERT_EQUAL(ligne_plus_basse_apres, ligne_plus_basse_avant-1)

        // Si aucune carte alcool est retournée :
            set_plateau_case(plateau, 0, 3, liste_cartes[6], 1, 0); // Carte Alcool en position (0, 3) mise en face cachée
            // La faction qui a posé la carte "Soirée sans alcool" gagne 5 points DDRS
            Case case_carte = get_plateau_case(plateau, position_premier_avant[0], position_premier_avant[1]);
            CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(get_case_faction(case_carte)), points_DDRS_avant+5);
}



// Massinissa Merabet
void test_activation_effet_Massinissa_Merabet() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        faction faction0 = liste_factions[0];
        faction faction1 = liste_factions[1];
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();

        // On positionne sur le plateau une carte Massinissa Merabet, qu'on gardera donc après une carte dèjà retournée
        set_plateau_case(plateau, 0, 4, liste_cartes[16], 0, 0); // Massinissa Merabet mis en position (0, 4) par la faction d'id 0 pour laisser la place pour positionner une carte retournée avant elle

        // On positionne sur le plateau une carte avant Massinissa Merabet retournée, on choisit arbitrairement FISE
        set_plateau_case(plateau, 0, 3, liste_cartes[0], 1, 1); // FISE avec face visible en position (0, 3) : à gauche de Massinissa Merabet, c'est la dernière carte à avoir été retournée
        
        // On retient le nombre de points DDRS de la faction ayant posé la carte Massinissa Merabet avant son activation
        int points_DDRS_avant_faction0 = get_faction_nombre_points_DDRS(faction0);
        // On retient le nombre de points DDRS de la faction ayant posé la carte activée avant Massinissa Merabet
        int points_DDRS_avant_faction1 = get_faction_nombre_points_DDRS(faction1);


    // action
        retourner(plateau, liste_factions); // Messinisa Merabet est la carte la plus en haut à gauche avec une face cachée : ce sera la prochaine à être retournée


    // test
        // L'effet de la dernière carte retournée avant Massinissa Merabet a été réactivé, comme si la faction ayant posé la carte MM l'avait posée elle-même
            // ici, la faction ayant posé la carte MM doit activer l'effet de la carte FISE : elle doit gagner 1 points DDRS
            CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(faction0), points_DDRS_avant_faction0+1);
            // la faction ayant posé la carte activée avant MM garde le même nombre de points DDRS qu'avant l'activation de MM
            CU_ASSERT_EQUAL(get_faction_nombre_points_DDRS(faction1), points_DDRS_avant_faction1);
}


// Catherine Dubois
void test_activation_effet_Catherine_Dubois() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();

        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();

        // On positionne sur le plateau une carte Catherine Dubois, tout en haut à gauche, prochaine à être retournée
        set_plateau_case(plateau, 25, 25, liste_cartes[20], 0, 0); // Catherine Dubois mis en position (25, 25) au centre du plateau, pour laisser la place pour poser des cartes sur la même ligne et colonne 

        // On positionne sur le plateau des cartes sur la même ligne et colonne que Catherine Dubois
        set_plateau_case(plateau, 25, 24, liste_cartes[0], 1, 1); // FISE en position (25, 24) : à gauche de Catherine Dubois (retournée car avant Catherine Dubois)
        set_plateau_case(plateau, 25, 26, liste_cartes[1], 0, 0); // FISA en position (25, 26) : à droite de Catherine Dubois
        set_plateau_case(plateau, 24, 25, liste_cartes[2], 1, 1); // FC en position (24, 25) : en haut de Catherine Dubois (retournée car plus en haut que Catherine Dubois)
        set_plateau_case(plateau, 26, 25, liste_cartes[3], 0, 0); // EcologIIE en position (26, 25) : en bas de Catherine Dubois


    // action
        retourner(plateau, liste_factions); // Catherine Dubois est la carte la plus en haut à gauche avec une face cachée : ce sera la prochaine à être retournée


    // test
       // La première et la dernière carte de la ligne et de la colonne où est posée Catherine Dubois ont étés supprimées 
       CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 25, 24)), -1); // état : -1 si la case est vide
       CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 25, 26)), -1);
       CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 24, 25)), -1);
       CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 26, 25)), -1);
}

// Eric Lejeune
// Cas 1 : parmi les cartes retournées il y en a au moins une Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel
void test_activation_effet_Eric_Lejeune_cas1() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();

        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();

        // On positionne sur le plateau une carte Eric Lejeune, tout en haut à gauche, prochaine à être retournée
        set_plateau_case(plateau, 0, 6, liste_cartes[28], 0, 0); // Eric Lejeune mis en position (0, 6) pour laisser la place pour poser au moins 5 cartes à sa gauche

        // On positionne sur le plateau des cartes dont au moins une Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel
        set_plateau_case(plateau, 0, 7, liste_cartes[20], 1, 1); // Catherine Dubois en position (0, 7) 
        set_plateau_case(plateau, 0, 8, liste_cartes[23], 0, 1); // Christophe Mouilleron en position (0, 8) 
        set_plateau_case(plateau, 0, 9, liste_cartes[15], 1, 1); // Kevin Goilard en position (0, 9) 
        set_plateau_case(plateau, 0, 10, liste_cartes[26], 0, 1); // Dimitri Watel en position (0, 10) 
        set_plateau_case(plateau, 0, 11, liste_cartes[3], 1, 0); // EcologIIE en position (0, 11)


    // action
        retourner(plateau, liste_factions); // Eric Lejeune est la carte la plus en haut à gauche avec une face cachée : ce sera la prochaine à être retournée


    // test
        // Cas 1 : parmi les cartes retournées il y en a au moins une Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel
        /* Il y a moins de cinq cartes retournées sur le plateau : Catherine Dubois, Christophe Mouilleron, Kevin Goilard et Dimitri Watel. Elles sont donc toutes selectionnées par l'activation de la carte Eric Lejeune.
            Parmi ces cartes, on a Catherine Dubois, Christophe Mouilleron et Dimitri Watel, dans cet ordre d'apparition sur le plateau.
            Après les avoir melangées, l'activation de Eric Lejeune les place à gauche de la carte la plus en haut à gauche, c'est à dire Eric Lejeun dans ce cas ci. 
            On veut que ça soit les prochaines cartes à être retournées, donc elles doivent être face cachée. */

            // Les trois cartes à gauche de Eric Lejeune sont Catherine Dubois, Christophe Mouilleron et Dimitri Watel, dans un ordre différent de celui-ci (c'est peu probable de retomber sur cette combination après avoir remelangé).
            char* nom_carte1 = get_plateau_carte_nom(plateau, 0, 3);
            char* nom_carte2 = get_plateau_carte_nom(plateau, 0, 4);
            char* nom_carte3 = get_plateau_carte_nom(plateau, 0, 5);
            CU_ASSERT( (0 == strcmp(nom_carte1, "Christophe Mouilleron")) || (0 == strcmp(nom_carte1, "Dimitri Watel")) ); // La carte la plus à gauche n'est pas Catherine Dubois 
            CU_ASSERT( (0 == strcmp(nom_carte2, "Catherine Dubois")) || (0 == strcmp(nom_carte2, "Dimitri Watel")) ); // Celle d'après n'est pas Christophe Mouilleron
            CU_ASSERT( (0 == strcmp(nom_carte3, "Catherine Dubois")) || (0 == strcmp(nom_carte3, "Christophe Mouilleron")) ); // Celle encore après n'est pas Dimitri Watel
            // Ces trois cartes sont face cachée
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 3)), 1); // état : 1 si la carte est face cachée
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 4)), 1); 
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 5)), 1);  
            // Les cases précedamment occupées par ces cartes sont maintenant vides   
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 7)), -1); // état : -1 si la case est vide
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 8)), -1);
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 10)), -1);
}

// Cas 2 : parmi les cartes retournées il n'y aucune carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel.
void test_activation_effet_Eric_Lejeune_cas2() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();

        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();

        // On positionne sur le plateau une carte Eric Lejeune, tout en haut à gauche, prochaine à être retournée
        set_plateau_case(plateau, 0, 6, liste_cartes[28], 0, 0); // Eric Lejeune mis en position (0, 6), tout en haut à gauche par rapport aux autres cartes

        // On positionne sur le plateau des cartes dont au moins une Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel
            // On retourne face cachée les cartes Catherine Dubois, Christophe Mouilleron et Dimitri Watel.
        set_plateau_case(plateau, 0, 7, liste_cartes[20], 1, 0); // Catherine Dubois en position (0, 7) 
        set_plateau_case(plateau, 0, 8, liste_cartes[23], 0, 0); // Christophe Mouilleron en position (0, 8) 
        set_plateau_case(plateau, 0, 9, liste_cartes[15], 1, 1); // Kevin Goilard en position (0, 9) 
        set_plateau_case(plateau, 0, 10, liste_cartes[26], 0, 0); // Dimitri Watel en position (0, 10) 
        set_plateau_case(plateau, 0, 11, liste_cartes[3], 1, 1); // EcologIIE en position (0, 11)


    // action
        retourner(plateau, liste_factions); // Eric Lejeune est la carte la plus en haut à gauche avec une face cachée : ce sera la prochaine à être retournée


    // test
        // Cas 2 : parmi les cartes retournées il n'y aucune carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel.
            // Il y a deux cartes retournées sur le plateau : Kevin Goilard et EcologIIE. Elle sont supprimées. 
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 9)), -1);
            CU_ASSERT_EQUAL(get_case_etat(get_plateau_case(plateau, 0, 11)), -1);
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
        init_manche(liste_factions);
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

        init_manche(liste_factions);

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
        init_manche(liste_factions_egalite);
        set_faction_nombre_points_DDRS(liste_factions_egalite[0], 20);
        set_faction_nombre_points_DDRS(liste_factions_egalite[1], 20);
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();
        // On positionne des cartes fictives sur le plateau : dans le jeu chaque faction en a posées 8 (ici, on suppose que chacune en avait deux)
        set_plateau_case(plateau_egalite, 0, 5, liste_cartes[0], 0, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau_egalite, 1, 5, liste_cartes[1], 1, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau_egalite, 1, 4, liste_cartes[2], 0, 1); // FC en position (1, 4) : à gauche de FISA
        set_plateau_case(plateau_egalite, 2, 4, liste_cartes[23], 1, 1); // Christophe Mouilleron en position (2, 4) : en bas de Ecocup
        // Retenons la position de la carte qui est la plus en haut à gauche du plateau
        int* position_premier = get_plateau_carte_premier(plateau_egalite);

    // action
        // On termine la manche : toutes les cartes sont retournées
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            for (int j = 0; j < TAILLE_PLATEAU; j++) {
                Case _case = get_plateau_case(plateau_egalite, i, j);
                if (get_case_etat(_case) == 0) {
                    set_case_etat(_case, 1); // état : 1 si la carte est face visible
                }
            }   
        }

        init_manche(liste_factions_egalite);

    // test
        // La faction gagnante voit sa manche comptabilisée
            // Déterminons la faction gagnante, c'est à dire celle qui a posé la carte qui est la plus en haut à gauche du plateau à l'issue de la manche
            Case case_premier = get_plateau_case(plateau_egalite, position_premier[0], position_premier[1]);
            int id_faction_gagnante = get_case_id_faction(case_premier);
            faction faction_gagnante = liste_factions_egalite[id_faction_gagnante];
            printf("fac_gagn : %p \n", faction_gagnante); 
        
            printf("manche gagnees fac %p : %i \n", liste_factions_egalite[0], get_faction_manches_gagnees(liste_factions_egalite[0]));
            printf("manche gagnees fac %p : %i \n", liste_factions_egalite[1], get_faction_manches_gagnees(liste_factions_egalite[1]));

        CU_ASSERT_EQUAL(get_faction_manches_gagnees(faction_gagnante), 1); // ici une seule manche a été jouée
        printf("equal manches gagnees\n");
        // Le nombre de manches gagnées de l'autre faction ne varie pas
            // Déterminons la faction perdante
            faction faction_perdante;
            if (0 == strcmp( get_faction_nom(faction_gagnante), get_faction_nom(liste_factions_egalite[0]) )) { // Si la faction gagnante est la première
                faction_perdante = liste_factions_egalite[1];
                printf("if");
            }
            else { faction_perdante = liste_factions_egalite[0]; 
            } // Si la faction gagnante est la seconde
        CU_ASSERT_EQUAL(get_faction_manches_gagnees(faction_perdante), 0);
}


/* Vérifie la bonne désignation du vainqueur du jeu :
    La faction qui remporte deux manches gagne la partie.
*/
void test_vainqueur_jeu() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        // On "joue" artificiellement deux manches et on se positionne dans le cas où le jeu est terminé : 
            // chaque faction a remporté une manche
            set_faction_manches_gagnees(liste_factions[0], 1);
            set_faction_manches_gagnees(liste_factions[1], 1);
            // chacune des deux factions possède un nombre strictement supérieur à zero de points DDRS
            set_faction_nombre_points_DDRS(liste_factions[0], 20);
            set_faction_nombre_points_DDRS(liste_factions[1], 34);
        // On initialise une troisième manche
        init_manche(liste_factions);
        // Liste de cartes. Pour les indexes des cartes, cf à partir de la ligne 131 de src/carte.c
        carte* liste_cartes = get_liste_carte();
        // On positionne des cartes fictives sur le plateau : dans le jeu chaque faction en a posées 8 (ici, on suppose que chacune en avait deux)
        set_plateau_case(plateau, 0, 5, liste_cartes[0], 1, 1); // FISE en position (0, 5) : à droite de lIIEns
        set_plateau_case(plateau, 1, 5, liste_cartes[1], 0, 1); // FISA en position (1, 5) : en bas de FISE
        set_plateau_case(plateau, 1, 4, liste_cartes[2], 1, 1); // FC en position (1, 4) : à gauche de FISA
        set_plateau_case(plateau, 2, 4, liste_cartes[23], 0, 1); // Christophe Mouilleron en position (2, 4) : en bas de Ecocup


    // action
        // On termine la troisième manche : toutes les cartes sont retournées et le jeu s'achève
        for (int i = 0; i < TAILLE_PLATEAU-1; i++) {
            for (int j = 0; j < TAILLE_PLATEAU-1; j++) {
                Case _case = get_plateau_case(plateau, i, j);
                set_case_etat(_case, 1); // état : 1 si la carte est face visible
            }   
        }


    // test
        // Une quatrième manche ne peut pas être demarrée : déjà testé dans la fonction test_presence_troisieme_manche()
        // Bon gagnant de la manche : déjà testé dans les fonctions test_vainqueur_manche_non_egalite() et test_vainqueur_manche_egalite()
    // TODO : gagnant() in interface.c est un void qui ne fait que print le nom du gagnant. 
}



/* Vérifie le bon démarrage du jeu :
    - bonne initialisation du plateau ;
    - bonne initialisation des factions ;
    - bonne initialisation de la première manche ;
    - détermination aléatoire du premier joueur ;
    - TODO : quoi d'autre? toutes ces choses ont déjà été testées...
*/
void test_demarrage_jeu() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();

    // action
        // On initialise la première manche
        init_manche(liste_factions);

    // test
        // TODO
}



/* Vérifie la bonne terminaison du jeu :
    - présence d'une faction gagnante ;
    - présence d'une faction perdante ;
    - TODO : quoi d'autre? ...
*/
void test_terminaison_jeu() {
    // arrange
        // On initialise le plateau de jeu
        plateau plateau = init_plateau();
        // On initialise les factions à placer sur le plateau
        faction* liste_factions = liste_faction();
        // On "joue" artificiellement trois manches et on se positionne dans le cas où le jeu est terminé : 
            // chacune des deux factions a remporté une manche
            set_faction_manches_gagnees(liste_factions[0], 1);
            set_faction_manches_gagnees(liste_factions[1], 1);
            // chacune des deux factions possède un nombre strictement supérieur à zero de points DDRS
            set_faction_nombre_points_DDRS(liste_factions[0], 20);
            set_faction_nombre_points_DDRS(liste_factions[1], 34);

    // action
        // On termine le jeu : une faction a remporté 2 manches 
        set_faction_manches_gagnees(liste_factions[1], 2);


    // test
        // TODO
}


/* À la troisième manche s'il y en a une, la première faction est de nouveau désignée au hasard. */
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

   /* add a suite to the registry */
/*  pSuite = CU_add_suite("ordre_factions_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }
*/
   /* add the tests to the suite */
/*   if ((NULL == CU_add_test(pSuite, "test_ordre_aleatoire_factions_premiere_manche", test_ordre_aleatoire_factions_premiere_manche)) ||
       (NULL == CU_add_test(pSuite, "test_ordre_deterministe_factions_deuxieme_manche", test_ordre_deterministe_factions_deuxieme_manche))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
*/
    /* add a suite to the registry */
   pSuite = CU_add_suite("manches_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_presence_troisieme_manche", test_presence_troisieme_manche)) ||
       (NULL == CU_add_test(pSuite, "test_vainqueur_manche_non_egalite", test_vainqueur_manche_non_egalite)) ||
       (NULL == CU_add_test(pSuite, "test_vainqueur_manche_egalite", test_vainqueur_manche_egalite))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }


    /* add a suite to the registry */
   pSuite = CU_add_suite("positions_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
    if ( (NULL == CU_add_test(pSuite, "test_pose_carte", test_pose_carte)) ||
        (NULL == CU_add_test(pSuite, "test_placement_cartes_espace2D", test_placement_cartes_espace2D))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }


   /* add a suite to the registry */
   pSuite = CU_add_suite("option_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( NULL == CU_add_test(pSuite, "test_option_repiocher", test_option_repiocher) )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

    /* add a suite to the registry */
   pSuite = CU_add_suite("effets_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
/*   if ( (NULL == CU_add_test(pSuite, "test_activation_effet_lIIEns", test_activation_effet_lIIEns)) ||
        (NULL == CU_add_test(pSuite, "test_activation_effet_soiree_sans_alcool", test_activation_effet_soiree_sans_alcool)) ||
        (NULL == CU_add_test(pSuite, "test_activation_effet_Massinissa_Merabet", test_activation_effet_Massinissa_Merabet)) ||
        (NULL == CU_add_test(pSuite, "test_activation_effet_Eric_Lejeune_cas1", test_activation_effet_Eric_Lejeune_cas1)) || 
        (NULL == CU_add_test(pSuite, "test_activation_effet_Eric_Lejeune_cas2", test_activation_effet_Eric_Lejeune_cas2)) 
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
*/
    /* add a suite to the registry */
   pSuite = CU_add_suite("vainqueurs_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "test_vainqueur_manche_non_egalite", test_vainqueur_manche_non_egalite)) ||
        (NULL == CU_add_test(pSuite, "test_vainqueur_manche_egalite", test_vainqueur_manche_egalite)) ||
        (NULL == CU_add_test(pSuite, "test_vainqueur_jeu", test_vainqueur_jeu)) 
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

    /* add a suite to the registry */
   pSuite = CU_add_suite("partie_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "test_demarrage_jeu", test_demarrage_jeu)) ||
        (NULL == CU_add_test(pSuite, "test_terminaison_jeu", test_terminaison_jeu))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

    /* Run all tests using the basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
    
    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
    return 0;
}
