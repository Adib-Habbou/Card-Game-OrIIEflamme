# Test : log des bugs et des corrections

Le commentaires de commit dans la branche ne comportent pas de "Tâche B.2" chaque fois, car on est sur la branche lot_b_test et tous les commits sont des commit de test par défault.

## Initialisation_suite

### test_initialisation_faction

- segfault pour la fonction get_faction_manches_gagnees() : modification de l'allocation de mémoire lors de la création de la liste des factions ;
- rimotion des assert pour vérifier que la main et la pioche sont vides car pas d'initialisation de ces propriétés lors de l'initialisation des faction.

### test_initialisation_plateau

Passé au premier essai : rien à signaler.



## Ordre_factions_suite

Pour la tâche de tests il faut vérifier également l’ordre aléatoire de jeu des factions.
Or, nous déterminons le joueur qui commence la manche à chaque fois à l’intérieur du main.
Donc, même stocker cette information dans une variable globale ne serait pas cohérent. 
Test.c comprend quand même les fonctions pour tester l’ordre aléatoire, si l’accès à la variable « JoueurCommence » était possible. Donc, cette partie a été testée sur console, mais vous trouverez l'algorithme dans test.c!

### test_ordre_aleatoire_factions_premiere_manche

### test_ordre_deterministe_factions_deuxieme_manche




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
       
### test_placement_cartes_espace2D
Il faut vérifier qu'à chaque fois qu'une positionne une nouvelle carte sur le plateau, elle touche d'au moins un bord une carte déjà posée. Comme cette information est donnée par l'interface, j'ai effectuée ces test sur console : il n'est effectivement pas possible de poser une carte en ne pas respectant ces regles. Chaque fois qu'on rentre une position pas possible, un message d'erreur s'affich et on est invités à rentrer une position valide. 



## Option_suite

### test_option_repiocher

- segfault dû à la fonction retourner()



## Effets_suite

### test_activation_effet_lIIEns

- segfault dû à la fonction retourner()

### test_activation_effet_soiree_sans_alcool

- pas de suppression de la ligne la plus en haut et celle la plus en bas dans le premier cas ;

- mauvaise affectation des points DDRS dans le deuxième cas.

### test_activation_effet_Massinissa_Merabet

- mauvaise affectation des points DDRS.

### test_activation_effet_Eric_Lejeune_cas1

- segfault lors de la recuperation des noms des cartes à la gauche d'Eric Lejeune : problème dans le déplacement des cartes ;

- changement de l'effet donc des assert : cette carte ne remelange pas elle même et Messinisa Merabet pour éViter des boucle infinies d'effets.

### test_activation_effet_Eric_Lejeune_cas2

- de même que pour le cas 1 : mauvais déplacement des cartes sur le plateau


## Vainqueurs_suite

### test_vainqueur_manche_non_egalite

### test_vainqueur_manche_egalite

### test_vainqueur_jeu

- La fonction gagnant() dans interface.c est un void qui ne fait que print le nom du gagnant : on ne peut pas recuperer l'information pour effectuer un test avec la faction qui a le plus de points DDRS, ou qui a posé la carte la plus en haut à gauche en cas de parité...



## Partie_suite

### test_demarrage_jeu

- Rien à signaler

### test_terminaison_jeu

- Rien à signaler