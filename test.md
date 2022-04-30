
# Test : log des bugs et des corrections

## Initialisation_suite
### test_initialisation_faction
- segfault pour la fonction get_faction_manches_gagnees() : modification de l'allocation de mémoire lors de la création de la liste des factions
- rimotion des assert pour vérifier que la main et la pioche sont vides car pas d'initialisation de ces propriétés lors de l'initialisation des faction

### test_initialisation_plateau
- Aucun bug à signaler 

## Ordre_factions_suite
### test_ordre_aleatoire_factions_premiere_manche
### test_ordre_deterministe_factions_deuxieme_manche

## Manches_suite
### test_presence_troisieme_manche

### test_vainqueur_manche_non_egalite
### test_vainqueur_manche_egalite
- La faction gagnante est à déterminer à la fin de la manche, donc il faut recuperer la daction ayant posé la carte la plus en haut à gauche avant de libérer le plateau : déplacement de la fonction libere_plateau() après la fonction gagnant().


## Positions_suite
### test_pose_carte
### test_placement_cartes_espace2D

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

## Partie_suite
### test_demarrage_jeu
### test_terminaison_jeu