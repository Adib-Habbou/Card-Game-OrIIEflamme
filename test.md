
# Test : log des bugs et des corrections

## Initialisation_suite

### test_initialisation_faction
- segfault pour la fonction get_faction_manches_gagnees() : modification de l'allocation de mémoire lors de la création de la liste des factions ;
- rimotion des assert pour vérifier que la main et la pioche sont vides car pas d'initialisation de ces propriétés lors de l'initialisation des faction.

### test_initialisation_plateau
Passé au premier essai : rien à signaler.



## Ordre_factions_suite
### test_ordre_aleatoire_factions_premiere_manche
test TODO
### test_ordre_deterministe_factions_deuxieme_manche
test TODO



## Manches_suite
### test_presence_troisieme_manche
Passé au premier essai : rien à signaler.
### test_vainqueur_manche_non_egalite
Passé au premier essai : rien à signaler.
### test_vainqueur_manche_egalite
- La faction gagnante est à déterminer à la fin de la manche, donc il faut recuperer la faction ayant posé la carte la plus en haut à gauche avant de libérer le plateau : déplacement de la fonction libere_plateau() après la fonction gagnant().



## Positions_suite
### test_pose_carte
- Nous avions un temps infini de parcours de la pile pour connaitre le nombre de cartes dans une main : initialisation des mains des factions dans init_manche(). (Corrigé juste dans le fichier test.c car la fonction init_manche() n'avait pas été appellée)
- Dernier point (_La carte n'appartient plus à la main de la faction_) uniquement testé pour les cartes à une unique occurrence : pour des cartes avec un nombre d'occurrences supérieur à 1, il faudrait pouvoir recuperer l'input de l'utilisateur à travers interface.c, le stocker pour recuperer le nombre d'occurrences de la carte dans la main de la faction puis vérifier avec un CU_ASSERT_EQUAL que la carte apparait une fois de moins qu'avant dans la main. 

``` c
// Si la carte posée a un nombre d'occurences supérieur à 1, on vérifie que maintenant elle apparait dans la main une fois de moins que son nombre d'occurrences 
        int nombre_occurrences_carte_posee_main = nombre_occurrences_main(carte_a_poser, get_faction_main(faction);
        CU_ASSERT_EQUAL(nombre_occurrences_carte_posee_main + 1, nombre_occurrences_carte_posee);
```

``` c
/* Fonction auxiliaire pour connaitre le nombre d'occurrences d'une carte dans une main
    @requires   une main valide
    @assigns    rien
    @ensures    renvoie le nombre d'occurrences d'une carte dans une main
*/
        int nombre_occurrences_main(carte _carte, pile main_faction) {
            int nombre_occurrences = 0;
            if (!pile_est_vide(main_faction)) {
                int taille_main = taille_pile(main_faction); // on retient la taille initiale de la main pour pouvoir la parcourir
                pile* buffer_main = &main_faction; // buffer pour parcourir la main sans la modifier
                for (int i=0; i < taille_main; i++) {
                    carte top = pile_sommet(*buffer_main);
                    /* strcmp() compaire deux chaines de caractères, caractère par caractère. 
                        Si les deux chaines sont égales, la fonction renvoie 0. */
                    if ( (strcmp(get_carte_nom(top), get_carte_nom(_carte))) == 0 ) { 
                        nombre_occurrences++;
                    } 
                    depile(buffer_main); // on passe à l'élément suivant de la pile 
                }
            }
            return nombre_occurrences;
        }
 ```
       
### test_placement_cartes_espace2D
test TODO : verificare che ogni volta che c'è una carta sul plateau (sauf quand une seule carte), c'è n'è una soit sopra, soit sotto, soit a destra, soit a sinistra



## Option_suite
### test_option_repiocher



## Effets_suite
### test_activation_effet_lIIEns
### test_activation_effet_soiree_sans_alcool 
### test_activation_effet_Massinissa_Merabet
### test_activation_effet_Eric_Lejeune_cas1
### test_activation_effet_Eric_Lejeune_cas2



## Vainqueurs_suite
### test_vainqueur_manche_non_egalite
### test_vainqueur_manche_egalite
### test_vainqueur_jeu
test TODO 



## Partie_suite
### test_demarrage_jeu
test TODO
### test_terminaison_jeu
test TODO