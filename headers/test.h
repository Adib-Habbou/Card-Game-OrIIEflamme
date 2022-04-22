/* Vérifie la bonne initialisation d'une faction :
    - le nom n'est pas vide ;
    - le nombre initial de points DDRS est nul ;
    - la main de départ est vide ;
    - la pioche de départ est vide ;
    - l'option rémélanger n'a pas encore été utilisée ;
    - aucune manche n'a encore été gagnée. 
*/
void test_initialisation_faction();


/* Vérifie la bonne initialisation d'un plateau :
    - bonne allocation de mémoire ;
    - il n'y a que deux joueurs pour une partie ;
    - il est possible d'initialiser une manche.
*/
void test_initialisation_plateau();


/* Vérifie l'ordre aléatoire des factions à la première manche :
        une faction au hasard est désignée "Première faction"
*/
void test_ordre_aleatoire_factions_premiere_manche();


/* Vérifie l'ordre déterministe des factions à la deuxième manche :
    - la "Deuxième faction" lors de la première manche est désignée "Première faction"
*/
void test_ordre_deterministe_factions_deuxieme_manche();


/* Vérifie la présence ou non d'une troisième manche :
        si au bout de deux manches, chaque faction en a gagnée une, une troisième manche est demarrée
*/
void test_presence_troisieme_manche();


/* Vérifie le bon fonctionnement de l'option pour repiocher */
    // Fonction auxiliaire pour tester l'appartenance d'une carte à la main d'une faction
        int appartient(carte _carte, faction _faction);

    void test_option_repiocher();


/* Vérifie la bonne pose d'une carte sur le plateau */
void test_pose_carte();


/* Vérifie le bon placement des cartes sur l'espace 2D */
void test_placement_cartes_espace2D();


/* Vérifie la bonne activation des effets des cartes */

    // lIIEns
    void test_activation_effet_lIIEns();

    // Soirée sans alcool
    void test_activation_effet_soiree_sans_alcool();

/* Vérifie la bonne désignation du vainqueur de manche :
       faction qui a le plus de points DDRS à l'issue de la manche
       Attention : en cas d'égalité, la faction qui a posé la carte qui est la plus en haut à gauche du plateau à l'issue de la manche gagne
*/
void test_vainqueur_manche();  
