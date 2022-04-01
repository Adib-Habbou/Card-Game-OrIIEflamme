#ifndef CARTE_H  /* pour éviter des inclusions multiples */
#define CARTE_H

/* définition du type abstrait des cartes */
typedef struct carte *carte;

// GETTERS ET SETTERS 

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char* get_carte_nom(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char* get_carte_description(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nombre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie le nom de la carte */
void set_carte_nom(carte carte, char* nom);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char* description);

/*  @requires   une carte valide et un entier
    @assigns    carte
    @ensures    modifie le nomnre d'occurrences de la carte */
void set_carte_nombre_occurrences(carte carte, int nombre_occurrences);


<<<<<<< HEAD
// GETTERS ET SETTERS 

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char get_carte_nom(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char get_carte_description(carte carte);

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nombre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie le nom de la carte */
void set_carte_nom(carte carte, char* nom);

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char* description);

/*  @requires   une carte valide et un entier
    @assigns    carte
    @ensures    modifie le nomnre d'occurrences de la carte */
void set_carte_nombre_occurrences(carte carte, int nombre_occurrences);
=======
// CONSTANTES ET VARIABLES GLOBALES 

/* noms des différentes cartes */
// FISE
carte FISE;
set_carte_nom(FISE, "FISE");
set_carte_description(FISE, "La faction qui a posé cette carte gagne 1 point DDRS.");
set_carte_nombre_occurrences(FISE, 4);

// FISA
carte FISA;
set_carte_nom(FISA, "FISA");
set_carte_description(FISA, "La faction qui a posé cette carte gagne 2 points DDRS si le nombre de cartes retournées sur le plateau (y compris celle-ci) est pair, et 0 sinon.")
set_carte_nombre_occurrences(FISA, 4);

// FC
carte FC;
set_carte_nom(FC, "FC");
set_carte_description(FC, "La faction qui a posé cette carte gagne 4 points DDRS si au moins une autre carte FC est retournée sur le plateau et 0 sinon.");
set_carte_nombre_occurrences(FC, 4);

// EcologIIE
carte EcologIIE;
set_carte_nom(EcologIIE, "EcologIIE");
set_carte_description(EcologIIE, "La faction qui a posé cette carte gagne 1 point DDRS par carte FISE/FISA/FC retournée.");
set_carte_nombre_occurrences(EcologIIe, 2);

// lIIEns
carte lIIEns;
set_carte_nom(lIIEns, "lIIEns");
set_carte_description(lIIEns, "Prenez toutes les cartes FISE/FISA/FC retournées, retirez les du plateau, mélangez les et reposez les face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, dans cet ordre. Les prochaines cartes à être retournées sont ces cartes là.");
set_carte_nombre_occurrences(lIIEns, 2);

// Soirée sans alcool
carte Soirée sans alcool;
set_carte_nom(Soirée sans alcool, "Soirée sans alcool");
set_carte_description(Soirée sans alcool, "Prenez toutes les cartes FISE/FISA/FC retournées, retirez les du plateau, mélangez les et reposez les face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, dans cet ordre. Les prochaines cartes à être retournées sont ces cartes là.");
set_carte_nombre_occurrences(Soirée sans alcool, 1);

// Alcool
carte Alcool;
set_carte_nom(Alcool, "Alcool");
set_carte_description(Alcool, "Supprimez du plateau toutes les cartes qui touchent cette carte-ci (mais laissez la carte Alcool sur le plateau).");
set_carte_nombre_occurrences(Alcool, 1);

// Café
carte Café;
set_carte_nom(Café, "Café");
set_carte_description(Café, "Supprimez toutes les cartes Thé et Alcool retournées sur le plateau. Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS. Sinon elle perd 1 point DDRS.");
set_carte_nombre_occurrences(Café, 1);

// Thé
carte Thé;
set_carte_nom(Thé, "Thé");
set_carte_description(Thé, "Supprimez toutes les cartes Café et Alcool retournées sur le plateau. Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS. Sinon elle perd 1 point DDRS.");
set_carte_nombre_occurrences(Thé, 3);

// Ecocup
carte Ecocup;
set_carte_nom(Ecocup, "Ecocup");
set_carte_description(Ecocup, "Cette carte est sans effet.");
set_carte_nombre_occurrences(Ecocup, 1);

// Reprographie
carte Reprographie;
set_carte_nom(Reprographie, "Reprographie");
set_carte_description(Reprographie, "La faction adverse de celle qui a posé cette carte perd 1 points DDRS pour chaque paire de cartes retournées et identiques sur le plateau. (S'il y a 3 cartes identiques, cela fait 3 paires).");
set_carte_nombre_occurrences(Reprographie, 1);

// Isolation du bâtiment 	
carte Isolation_du_bâtiment;
set_carte_nom(Isolation_du_bâtiment, "Isolation du bâtiment");
set_carte_description(Isolation_du_bâtiment, "Chaque faction gagne 1 point DDRS par carte non retournée et non supprimée du plateau qu'elle a posée sur le plateau.");
set_carte_nombre_occurrences(Isolation_du_bâtiment, 1);

// Parcours sobriété numérique
carte Parcours_sobriété_numérique;
set_carte_nom(Parcours_sobriété_numérique, "Parcours sobriété numérique");
set_carte_description(Parcours_sobriété_numérique, "Retournez toutes les cartes non retournées les plus à gauche et à droite de chaque ligne, sans appliquer leur effet.");
set_carte_nombre_occurrences(Parcours_sobriété_numérique, 1);

// Heures supplémentaires
carte Heures_supplémentaires;
set_carte_nom(Heures_supplémentaires, "Heures supplémentaires");
set_carte_description(Heures_supplémentaires, "La faction adverse de celle qui a posé cette carte perd 3 points DDRS par carte Heures supplémentaires retournée sur le plateau (y compris celle-ci).");
set_carte_nombre_occurrences(Heures_supplémentaires, 1);

// Kahina Bouchama 	
carte Kahina_Bouchama;
set_carte_nom(Kahina_Bouchama, "Kahina Bouchama");
set_carte_description(Kahina_Bouchama, "Supprimez une carte non retournée du plateau choisie au hasard.");
set_carte_nombre_occurrences(Kahina_Bouchama, 1);

// Kevin Goilard
carte Kevin_Goilard;
set_carte_nom(Kevin_Goilard, "Kevin Goilard");
set_carte_description(Kevin_Goilard, "Supprimez une ligne au hasard, la faction qui a posé cette carte gagne 2 points DDRS par carte supprimée ainsi.");
set_carte_nombre_occurrences(Kevin_Goilard, 1);

// Massinissa Merabet
carte Massinissa_Merabet;
set_carte_nom(Massinissa_Merabet, "Massinissa Merabet");
set_carte_description(Massinissa_Merabet, "La faction qui a posé cette carte réactive l'effet de la dernière carte retournée avant Massinissa Merabet, en faisant comme elle l'avait posée elle-même, même si ce n'est pas le cas.");
set_carte_nombre_occurrences(Massinissa_Merabet, 1);

// Vitéra Y
carte Vitéra_Y;
set_carte_nom(Vitéra_Y, "Vitéra Y");
set_carte_description(Vitéra_Y, "La faction qui a le moins de points DDRS gagne 3 points DDRS.");
set_carte_nombre_occurrences(Vitéra_Y, 1);

// Jonas Senizergues
carte Jonas_Senizergues;
set_carte_nom(Jonas_Senizergues, "Jonas Senizergues");
set_carte_description(Jonas_Senizergues, "Supprimez toutes les cartes Heures supplémentaires retournées du plateau.");
set_carte_nombre_occurrences(Jonas_Senizergues, 1);

// Fetia Bannour
carte Fetia_Bannour;
set_carte_nom(Fetia_Bannour, "Fetia Bannour");
set_carte_description(Fetia_Bannour, "Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes de la ligne et de la colonne où est posée cette carte (y compris celle-ci). Sinon la faction qui a posé cette carte gagne 1 point DDRS par carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest et Dimitri Watel retournée sur le plateau.");
set_carte_nombre_occurrences(Fetia_Bannour, 1);

// Catherine Dubois
carte Catherine_Dubois;
set_carte_nom(Catherine_Dubois, "Catherine Dubois");
set_carte_description(Catherine_Dubois, "Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte.");
set_carte_nombre_occurrences(Catherine_Dubois, 1);

// Anne-Laure Ligozat
carte Anne-Laure_Ligozat;
set_carte_nom(Anne-Laure_Ligozat, "Anne-Laure Ligozat");
set_carte_description(Anne-Laure_Ligozat, "Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte.");
set_carte_nombre_occurrences(Anne-Laure_Ligozat, 1);

// Guillaume Burel
carte Guillaume_Burel;
set_carte_nom(Guillaume_Burel, "Guillaume Burel");
set_carte_description(Guillaume_Burel, "Si la faction adverse de celle qui a posé cette carte a plus de points DDRS, la seconde lui vole 3 points DDRS.");
set_carte_nombre_occurrences(Guillaume_Burel, 1);

// Christophe Mouilleron
carte Christophe_Mouilleron;
set_carte_nom(Christophe_Mouilleron, "Christophe Mouilleron");
set_carte_description(Christophe_Mouilleron, "Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes retournées du plateau sauf les cartes Christophe Mouilleron et Heures supplémentaires.");
set_carte_nombre_occurrences(Christophe_Mouilleron, 1);

// Thomas Lim
carte Thomas_Lim;
set_carte_nom(Thomas_Lim, "Thomas Lim");
set_carte_description(Thomas_Lim, "Si Julien Forest n'est par retourné sur le plateau, la faction qui a posé cette carte gagne 3 points DDRS par carte FISE retournée sur le plateau. Sinon la faction adverse perd 1 point DDRS par carte FISE retournée sur le plateau.");
set_carte_nombre_occurrences(Thomas_Lim, 1);

// Julien Forest
carte Julien_Forest;
set_carte_nom(Julien_Forest, "Julien Forest");
set_carte_description(Julien_Forest, "La faction qui a posé cette carte gagne 6 points DDRS par carte FISE retournée sur le plateau si au moins une carte Café est retournée sur le plateau.");
set_carte_nombre_occurrences(Julien_Forest, 1);

// Dimitri Watel
carte Dimitri_Watel;
set_carte_nom(Dimitri_Watel, "Dimitri Watel");
set_carte_description(Dimitri_Watel, "La faction qui a posé cette carte gagne 3 points DDRS par carte FISA ou FC retournée sur le plateau si au moins une carte Thé est retournée sur le plateau.");
set_carte_nombre_occurrences(Dimitri_Watel, 1);

// Djibril-Aurélien Dembele-Cabot
carte Djibril-Aurélien_Dembele-Cabot;
set_carte_nom(Djibril-Aurélien_Dembele-Cabot, "Djibril-Aurélien Dembele-Cabot");
set_carte_description(Djibril-Aurélien_Dembele-Cabot, "S'il y a plus de 3 cartes retournées sur la ligne de cette carte, la faction qui a posé cette carte gagne 5 points DDRS.");
set_carte_nombre_occurrences(Djibril-Aurélien_Dembele-Cabot, 1);

// Eric Lejeune
carte Eric_Lejeune;
set_carte_nom(Eric_Lejeune, "Eric Lejeune");
set_carte_description(Eric_Lejeune, "Prenez au hasard 5 cartes retournées du plateau (ou toutes les cartes retournées du plateau s'il y a moins de 5). Si une de ces cartes est une carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel, mélangez les et placez les à gauche de la case la plus à gauche de la première ligne. Les prochaines cartes à être retournées sont ces cartes là. Sinon, supprimez ces cartes du plateau.");
set_carte_nombre_occurrences(Eric_Lejeune, 1);

// Lucienne Pacavé
carte Lucienne_Pacavé;
set_carte_nom(Lucienne_Pacavé, "Lucienne Pacavé");
set_carte_description(Lucienne_Pacavé, "S'il y a une carte FISA retournée dans la même ligne ou la même colonne que cette carte, la faction qui a posé cette carte gagne 5 points DDRS.");
set_carte_nombre_occurrences(Lucienne_Pacavé, 1);

// Katrin Salhab
carte Katrin_Salhab;
set_carte_nom(Katrin_Salhab, "Katrin Salhab");
set_carte_description(Katrin_Salhab, "Si les cartes Djibril-Aurélien Djembele-Cabeau, Eric Lejeune et Lucienne Pacavé sont retournées, la faction qui a posé cette carte gagne 10 points DDRS. Sinon, retournez toutes les cartes dans la même ligne de cette carte sans appliquer leurs effets.");
set_carte_nombre_occurrences(Katrin_Salhab, 1);

// Laurent Prével
carte Laurent_Prével;
set_carte_nom(Laurent_Prével, "Laurent Prével");
set_carte_description(Laurent_Prével, "Si Laurent Prével est la dernière carte retournée du plateau, la faction qui a posé cette carte gagne la manche, quel que soit le nombre de points DDRS des deux factions.");
set_carte_nombre_occurrences(Laurent_Prével, 1);
>>>>>>> 6e4e38aefbd7d038af4eed85b9e3e9a1ba71c8c6

#endif
