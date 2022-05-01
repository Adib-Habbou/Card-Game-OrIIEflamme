
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
- La faction gagnante est à déterminer à la fin de la manche, donc il faut recuperer la faction ayant posé la carte la plus en haut à gauche avant de libérer le plateau : déplacement de la fonction libere_plateau() après la fonction gagnant() ;
- Les manches gagnées ne sont pas attribuées à la bonne faction : get_faction_manches_gagnees() renvoie 
CORRIGER



## Positions_suite
### test_pose_carte
- Nous avons un temps infini de parcours de la pile pour connaitre le nombre de cartes dans une main : initialisation des mains des factions dans init_manche(). (Corrigé juste dans le test)
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