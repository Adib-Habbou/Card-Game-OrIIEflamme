
/* importation du module plateau */
#include "../headers/plateau.h"

#include<stddef.h>

/* définition de la structure des cartes */
struct carte {
    char* nom;
    char* description;
    int nombre_occurrences;
};


// CONSTANTES ET VARIABLES GLOBALES 

/* noms des différentes cartes */
// FISE
struct carte FISE = { .nom="FISE", .description="La faction qui a posé cette carte gagne 1 point DDRS.", .nombre_occurrences=4};

// FISA
struct carte FISA = { .nom="FISA", .description="La faction qui a posé cette carte gagne 2 points DDRS si le nombre de cartes retournées sur le plateau (y compris celle-ci) est pair, et 0 sinon.", .nombre_occurrences=4};

// FC
struct carte FC = { .nom="FC", .description="La faction qui a posé cette carte gagne 4 points DDRS si au moins une autre carte FC est retournée sur le plateau et 0 sinon.", .nombre_occurrences=4};

// EcologIIE
struct carte EcologIIE = { .nom="EcologIIE", .description="La faction qui a posé cette carte gagne 1 point DDRS par carte FISE/FISA/FC retournée.", .nombre_occurrences=2};

// lIIEns
struct carte lIIEns = { .nom="lIIEns", .description="Prenez toutes les cartes FISE/FISA/FC retournées, retirez les du plateau, mélangez les et reposez les face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, dans cet ordre. Les prochaines cartes à être retournées sont ces cartes là.", .nombre_occurrences=2};

// Soirée sans alcool
struct carte Soirée_sans_alcool = { .nom="Soirée sans alcool", .description="Prenez toutes les cartes FISE/FISA/FC retournées, retirez les du plateau, mélangez les et reposez les face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, dans cet ordre. Les prochaines cartes à être retournées sont ces cartes là.", .nombre_occurrences=1};

// Alcool
struct carte Alcool = { .nom="Alcool", .description="Supprimez du plateau toutes les cartes qui touchent cette carte-ci (mais laissez la carte Alcool sur le plateau).", .nombre_occurrences=1};

// Café
struct carte Café = { .nom="Café", .description="Supprimez toutes les cartes Thé et Alcool retournées sur le plateau. Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS. Sinon elle perd 1 point DDRS.", .nombre_occurrences=1};

// Thé
struct carte Thé = { .nom="Thé", .description="Supprimez toutes les cartes Café et Alcool retournées sur le plateau. Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS. Sinon elle perd 1 point DDRS.", .nombre_occurrences=3};

// Ecocup
struct carte Ecocup = { .nom="Ecocup", .description="Cette carte est sans effet.", .nombre_occurrences=1};

// Reprographie
struct carte Reprographie = { .nom="Reprographie", .description="La faction adverse de celle qui a posé cette carte perd 1 points DDRS pour chaque paire de cartes retournées et identiques sur le plateau. (S'il y a 3 cartes identiques, cela fait 3 paires).", .nombre_occurrences=1};

// Isolation du bâtiment 	
struct carte Isolation_du_bâtiment = { .nom="Isolation du bâtiment", .description="Chaque faction gagne 1 point DDRS par carte non retournée et non supprimée du plateau qu'elle a posée sur le plateau.");
set_carte_nombre_occurrences(Isolation_du_bâtiment, 1);

// Parcours sobriété numérique
struct carte Parcours_sobriété_numérique = { .nom="Parcours sobriété numérique", .description="Retournez toutes les cartes non retournées les plus à gauche et à droite de chaque ligne, sans appliquer leur effet.");
set_carte_nombre_occurrences(Parcours_sobriété_numérique, 1);

// Heures supplémentaires
struct carte Heures_supplémentaires = { .nom="Heures supplémentaires", .description="La faction adverse de celle qui a posé cette carte perd 3 points DDRS par carte Heures supplémentaires retournée sur le plateau (y compris celle-ci).");
set_carte_nombre_occurrences(Heures_supplémentaires, 1);

// Kahina Bouchama 	
struct carte Kahina_Bouchama = { .nom="Kahina Bouchama", .description="Supprimez une carte non retournée du plateau choisie au hasard.");
set_carte_nombre_occurrences(Kahina_Bouchama, 1);

// Kevin Goilard
struct carte Kevin_Goilard = { .nom="Kevin Goilard", .description="Supprimez une ligne au hasard, la faction qui a posé cette carte gagne 2 points DDRS par carte supprimée ainsi.");
set_carte_nombre_occurrences(Kevin_Goilard, 1);

// Massinissa Merabet
struct carte Massinissa_Merabet = { .nom="Massinissa Merabet", .description="La faction qui a posé cette carte réactive l'effet de la dernière carte retournée avant Massinissa Merabet, en faisant comme elle l'avait posée elle-même, même si ce n'est pas le cas.");
set_carte_nombre_occurrences(Massinissa_Merabet, 1);

// Vitéra Y
struct carte Vitéra_Y = { .nom="Vitéra Y", .description="La faction qui a le moins de points DDRS gagne 3 points DDRS.");
set_carte_nombre_occurrences(Vitéra_Y, 1);

// Jonas Senizergues
struct carte Jonas_Senizergues = { .nom="Jonas Senizergues", .description="Supprimez toutes les cartes Heures supplémentaires retournées du plateau.");
set_carte_nombre_occurrences(Jonas_Senizergues, 1);

// Fetia Bannour
struct carte Fetia_Bannour = { .nom="Fetia Bannour", .description="Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes de la ligne et de la colonne où est posée cette carte (y compris celle-ci). Sinon la faction qui a posé cette carte gagne 1 point DDRS par carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest et Dimitri Watel retournée sur le plateau.");
set_carte_nombre_occurrences(Fetia_Bannour, 1);

// Catherine Dubois
struct carte Catherine_Dubois = { .nom="Catherine Dubois", .description="Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte.");
set_carte_nombre_occurrences(Catherine_Dubois, 1);

// Anne-Laure Ligozat
struct carte Anne_Laure_Ligozat = { .nom="Anne-Laure Ligozat", .description="Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte.");
set_carte_nombre_occurrences(Anne_Laure_Ligozat, 1);

// Guillaume Burel
struct carte Guillaume_Burel = { .nom="Guillaume Burel", .description="Si la faction adverse de celle qui a posé cette carte a plus de points DDRS, la seconde lui vole 3 points DDRS.");
set_carte_nombre_occurrences(Guillaume_Burel, 1);

// Christophe Mouilleron
struct carte Christophe_Mouilleron = { .nom= "Christophe Mouilleron", .description="Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes retournées du plateau sauf les cartes Christophe Mouilleron et Heures supplémentaires.");
set_carte_nombre_occurrences(Christophe_Mouilleron, 1);

// Thomas Lim
struct carte Thomas_Lim = { .nom="Thomas Lim", .description="Si Julien Forest n'est par retourné sur le plateau, la faction qui a posé cette carte gagne 3 points DDRS par carte FISE retournée sur le plateau. Sinon la faction adverse perd 1 point DDRS par carte FISE retournée sur le plateau.");
set_carte_nombre_occurrences(Thomas_Lim, 1);

// Julien Forest
struct carte Julien_Forest = { .nom="Julien Forest", .description="La faction qui a posé cette carte gagne 6 points DDRS par carte FISE retournée sur le plateau si au moins une carte Café est retournée sur le plateau.");
set_carte_nombre_occurrences(Julien_Forest, 1);

// Dimitri Watel
struct carte Dimitri_Watel = { .nom="Dimitri Watel", .description="La faction qui a posé cette carte gagne 3 points DDRS par carte FISA ou FC retournée sur le plateau si au moins une carte Thé est retournée sur le plateau.");
set_carte_nombre_occurrences(Dimitri_Watel, 1);

// Djibril-Aurélien Dembele-Cabot
struct carte Djibril_Aurélien_Dembele_Cabot = { .nom="Djibril-Aurélien Dembele-Cabot", .description="S'il y a plus de 3 cartes retournées sur la ligne de cette carte, la faction qui a posé cette carte gagne 5 points DDRS.");
set_carte_nombre_occurrences(Djibril_Aurélien_Dembele_Cabot, 1);

// Eric Lejeune
struct carte Eric_Lejeune = { .nom="Eric Lejeune", .description="Prenez au hasard 5 cartes retournées du plateau (ou toutes les cartes retournées du plateau s'il y a moins de 5). Si une de ces cartes est une carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel, mélangez les et placez les à gauche de la case la plus à gauche de la première ligne. Les prochaines cartes à être retournées sont ces cartes là. Sinon, supprimez ces cartes du plateau.");
set_carte_nombre_occurrences(Eric_Lejeune, 1);

// Lucienne Pacavé
struct carte Lucienne_Pacavé = { .nom="Lucienne Pacavé", .description="S'il y a une carte FISA retournée dans la même ligne ou la même colonne que cette carte, la faction qui a posé cette carte gagne 5 points DDRS.");
set_carte_nombre_occurrences(Lucienne_Pacavé, 1);

// Katrin Salhab
struct carte Katrin_Salhab = { .nom="Katrin Salhab", .description="Si les cartes Djibril-Aurélien Djembele-Cabeau, Eric Lejeune et Lucienne Pacavé sont retournées, la faction qui a posé cette carte gagne 10 points DDRS. Sinon, retournez toutes les cartes dans la même ligne de cette carte sans appliquer leurs effets.");
set_carte_nombre_occurrences(Katrin_Salhab, 1);

// Laurent Prével
struct carte Laurent_Prével = { .nom="Laurent Prével", .description="Si Laurent Prével est la dernière carte retournée du plateau, la faction qui a posé cette carte gagne la manche, quel que soit le nombre de points DDRS des deux factions.");
set_carte_nombre_occurrences(Laurent_Prével, 1);


// GETTERS ET SETTERS

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie la liste de toutes les cartes du jeu */
carte* get_liste_carte() {
    return liste_carte;
}

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char* get_carte_nom(carte carte) {
    return carte->nom;
}

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char* get_carte_description(carte carte) {
    return carte->description;
}

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nomnre d'occurrences de la carte */
int get_carte_nombre_occurrences(carte carte) {
    return carte->nombre_occurrences;
}

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie le nom de la carte */
void set_carte_nom(carte carte, char* nom) {
    carte->nom = nom;
}

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char* description) {
    carte->description = description;
}

/*  @requires   une carte valide et un entier
    @assigns    carte
    @ensures    modifie le nomnre d'occurrences de la carte */
void set_carte_nombre_occurrences(carte carte, int nombre_occurrences) {
    carte->nombre_occurrences = nombre_occurrences;
}



/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 1
*/
void FISE_F(faction _faction) {
    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+1); 
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 2
*/
void FISA_F(faction _faction, plateau _plateau) {
    int nb_pair=0;
    int i,j;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1) {
                nb_pair+=1;//si 1 indique que la carte est retournée 
            }
        }
    }
    if (nb_pair%2 == 0) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+2);
    }
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 4
*/
void FC_F(faction _faction, plateau _plateau) {
    int drapeau_FC=0;
    int i,j;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "FC" && get_case_etat(get_plateau_case(_plateau,i,j))==1) {
                drapeau_FC=1;//si 1 indique que une carte FC est présente et retournée
            }
        }
    }
    if (drapeau_FC) { //au moins une carte FC était retournée
       set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+4);
    }
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 1 pour chaque carte FISE, FISA ou FC retournées
*/
void EcologIIE_F(faction _faction, plateau _plateau) {
    int total = 0;
    int i,j;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "FC") || (get_plateau_carte_nom(_plateau,i,j) == "FISE") || (get_plateau_carte_nom(_plateau,i,j) == "FISA") )) {
                total+=1; 
            }
        }
    }
    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+total) ;//TODO setter 
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau
@ensures Prend toutes les cartes FISE/FISA/FC retournées, les retire du plateau, 
les mélange et les repose face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, 
dans cet ordre et les prochaines cartes à être retournées sont ces cartes là
*/
void lIIEns_F(faction _faction, plateau _plateau) {


}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction ou le plateau
@ensures Si au moins une carte alcool est retournée, 
supprime toutes les cartes FISE/FISA/FC retournées du plateau-> 
Supprime ensuite la première et la dernière ligne du plateau-> 
Sinon la faction qui a posé cette carte gagne 5 points DDRS
*/
void Soiree_sans_alcool_F(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns le plateau
@ensures Supprimez du plateau toutes les cartes qui touchent cette carte Alcool
*/
void Alcool_F(faction _faction, plateau _plateau, int ligne, int colonne) {

    if (get_plateau_case(_plateau,ligne+1,colonne) != NULL) {
        set_case_etat(get_plateau_case(_plateau,ligne+1,colonne),-1);
    }

    if (get_plateau_case(_plateau,ligne,colonne+1) != NULL) {
        set_case_etat(get_plateau_case(_plateau,ligne,colonne+1),-1);
    }

    if (get_plateau_case(_plateau,ligne-1,colonne) != NULL) {
        set_case_etat(get_plateau_case(_plateau,ligne-1,colonne),-1);
    }

    if (get_plateau_case(_plateau,ligne,colonne-1) != NULL) {
        set_case_etat(get_plateau_case(_plateau,ligne,colonne-1),-1);
    }
    
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction et le plateau
@ensures Supprime toutes les cartes Thé et Alcool retournées sur le plateau-> 
Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS-> Sinon elle perd 1 point DDRS
*/
void Cafe_F(faction _faction, plateau _plateau) {
    int i,j;
    int drapeau_Ecocup = 0;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "Thé") || (get_plateau_carte_nom(_plateau,i,j) == "Alcool")) ) {
                set_case_etat(get_plateau_case(_plateau,i,j),-1); //ATTENTION A CHANGER PAR UNE FONCTION QUI MET LA CASE EN NULL
            }
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "Ecocup"))) {
                drapeau_Ecocup = 1;
            }
        }
    }

    if (drapeau_Ecocup) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+1);
    }
    else {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)-1);
    }
    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Supprimez toutes les cartes Café et Alcool retournées sur le plateau-> 
Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS-> Sinon elle perd 1 point DDRS
*/
void The_F(faction _faction, plateau _plateau) {
    int i,j;
        int drapeau_Ecocup = 0;
        for (i=0;i<1000;i++) {  //plateau de taille 1000
            for (j=0;j<1000;j++) {  
                if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "Café") || (get_plateau_carte_nom(_plateau,i,j) == "Alcool")) ) {
                    set_case_etat(get_plateau_case(_plateau,i,j),-1); //ATTENTION A CHANGER PAR UNE FONCTION QUI MET LA CASE EN NULL
                }
                if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "Ecocup"))) {
                    drapeau_Ecocup = 1;
                }
            }
        }

        if (drapeau_Ecocup) {
            set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+1);
        }
        else {
            set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)-1);
        }
        
}

/*
@requires rien
@assigns rien
@ensures sans effet
*/
void Ecocup_F() {
 
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction adverse
@ensures La faction adverse de celle qui a posé cette carte perd 1 points DDRS pour chaque paire de cartes retournées et identiques sur le plateau
*/
void Reprographie_F(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns l'attribut DDRS des factions
@ensures Chaque faction gagne 1 point DDRS par carte non retournée et non supprimée du plateau qu'elle a posée sur le plateau
*/
void Isolation_du_batiment_F(faction _faction, faction _faction_oppose, plateau _plateau) {
    int nb_faction_1 = 0;
    int nb_faction_2 = 0;
    int i,j;
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if ( get_faction_nom(get_case_faction(get_plateau_case(_plateau,i,j)) ==get_faction_nom(_faction)) && get_case_etat(get_plateau_case(_plateau,i,j)) == 0  ) {
                nb_faction_1++;
            }
            
            if ( get_faction_nom(get_case_faction(get_plateau_case(_plateau,i,j)) ==get_faction_nom(_faction)) && get_case_etat(get_plateau_case(_plateau,i,j)) == 0 ) {
                nb_faction_2++;
            }
        }
    }
    
    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+nb_faction_1);
    set_faction_nombre_points_DDRS(_faction_oppose,get_faction_nombre_points_DDRS(_faction_oppose)+nb_faction_2);

    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau
@ensures Retournez toutes les cartes non retournées les plus à gauche et à droite de chaque ligne, sans appliquer leur effet
*/
void Parcours_sobriete_numerique_F(faction _faction, plateau _plateau) {
    int ligne;
    for (ligne = 0;ligne <1000; ligne++) {
        int ligne1 = get_plateau_carte_gauche(_plateau,ligne,1)[0];
        int colonne1 = get_plateau_carte_gauche(_plateau,ligne,1)[1];
        int ligne2 = get_plateau_carte_droite(_plateau,ligne,1)[0];
        int colonne2 = get_plateau_carte_droite(_plateau,ligne,1)[1];
        set_case_etat( get_plateau_case(_plateau,ligne1,colonne1) , 1 );
        set_case_etat( get_plateau_case(_plateau,ligne2,colonne2) , 1 );
    }
    
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction adverse
@ensures La faction adverse de celle qui a posé cette carte perd 3 points DDRS par carte Heures supplémentaires retournée sur le plateau
*/
void Heures_supplementaires(faction _faction, plateau _plateau) {

    
}





/*
@requires faction valide
@assigns le plateau
@ensures Supprimez une carte non retournée du plateau choisie au hasard
*/
void Kahina_Bouchama_F(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Supprimez une ligne au hasard, la faction qui a posé cette carte gagne 2 points DDRS par carte supprimée ainsi->
*/
void Kevin_Goilard_F(faction _faction, plateau _plateau) {

    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau et/ou l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte réactive l'effet de la dernière carte retournée avant Massinissa Merabet, en faisant comme elle l'avait posée elle-même, même si ce n'est pas le cas
*/
void Massinissa_Merabet_F(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns l'attribut DDRS d'une faction
@ensures La faction qui a le moins de points DDRS gagne 3 points DDRS
*/
void Vitera_Y_F(faction _faction, plateau _plateau) {

    
}






/*
@requires faction valide
@assigns le plateau
@ensures Supprimez toutes les cartes Heures supplémentaires retournées du plateau
*/
void Jonas_Senizergues_F(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, 
supprimez toutes les cartes de la ligne et de la colonne où est posée cette carte (y compris celle-ci)-> 
Sinon la faction qui a posé cette carte gagne 1 point DDRS par carte Catherine Dubois, 
Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest et Dimitri Watel retournée sur le plateau
*/
void Fetia_Bannour_F(faction _faction, plateau _plateau) {

    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau
@ensures Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte
*/
void Catherine_Dubois_F(faction _faction, plateau _plateau, int ligne, int colonne) {

    
}

/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Pour chaque carte EcologIIE, Ecocup, Isolation du bâtiment et parcours Sobriété numérique retournée, 
la faction qui a posé cette carte gagne 3 points DDRS et la dernière carte non retournée du plateau est supprimée
*/
void Anne_Laure_Ligozat_F(faction _faction, plateau _plateau) {

    
}






/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures Si la faction adverse de celle qui a posé cette carte a plus de points DDRS, la seconde lui vole 3 points DDRS->
*/
void Guillaume_Burel_F(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns le plateau
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes retournées du plateau sauf les cartes Christophe Mouilleron et Heures supplémentaires
*/
void Christophe_Mouilleron_F(faction _faction, plateau _plateau) {
    int i,j;
    int drapeau_heures_supp = 0;

    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_tableau_carte_nom(_plateau,i,j) == "Heures supplémentaires") {
                    drapeau_heures_supp=1;
            }
        }
    }
    if (drapeau_heures_supp) {
        
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if ( (get_plateau_case(_plateau,i,j) != NULL) && (get_case_etat(get_plateau_case(_plateau,i,j)) == 1) && (get_plateau_carte_nom(_plateau,i,j) != "Christophe Mouilleron") && (get_plateau_carte_nom(_plateau,i,j) != "Heures supplémentaires") ) {
                set_case_etat(get_plateau_case(_plateau,i,j),-1);
             }
        }
    }

    }
  
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Si Julien Forest n'est par retourné sur le plateau, 
la faction qui a posé cette carte gagne 3 points DDRS par carte FISE retournée sur le plateau-> 
Sinon la faction adverse perd 1 point DDRS par carte FISE retournée sur le plateau
*/
void Thomas_Lim_F(faction _faction, faction _faction_oppose, plateau _plateau) {
    int Julien_Forest_present = 0;

    //TODO présence Julien via historique

    int nb_FISE = 0;
    int i,j;
        
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_tableau_carte_nom(_plateau,i,j) == "FISE") {
                nb_FISE+=1;
            }
        }
    }

    if (Julien_Forest_present) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+3*nb_FISE);
    }

    else { 
        set_faction_nombre_points_DDRS(_faction_oppose,get_faction_nombre_points_DDRS(_faction_oppose)-nb_FISE);
    }
    
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte gagne 6 points DDRS par carte FISE retournée sur le plateau si au moins une carte Café est retournée sur le plateau
*/
void Julien_Forest_F(faction _faction, plateau _plateau) {
    int nb_FISE = 0;
    int i,j;
    int drapeau = 0;

    //TODO historique cartes retounéés 

    if (drapeau) { 
        for (i=0;i<1000;i++) {  //plateau de taille 1000
            for (j=0;j<1000;j++) {  
                if (get_tableau_carte_nom(_plateau,i,j) == "FISE") {
                    nb_FISE+=1;
                }
            }
        }
    }
    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+6*nb_FISE);
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte gagne 3 points DDRS par carte FISA ou FC retournée sur le plateau si au moins une carte Thé est retournée sur le plateau
*/
void Dimitri_Watel_F(faction _faction, plateau _plateau) {
    int nb_FISA_FC = 0;
    int i,j;
    int drapeau = 0;

    //TODO historique cartes retounéés 

    if (drapeau) { 
        for (i=0;i<1000;i++) {  //plateau de taille 1000
            for (j=0;j<1000;j++) {  
                if (get_tableau_carte_nom(_plateau,i,j) == "FISA" || get_tableau_carte_nom(_plateau,i,j) == "FC" ) {
                    nb_FISA_FC+=1;
                }
            }
        }
    }
    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+3*nb_FISA_FC);
    
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures S'il y a plus de 3 cartes retournées sur la ligne de cette carte, la faction qui a posé cette carte gagne 5 points DDRS
*/
void Djibril_Aurelien_Dembele_Cabot_F(faction _faction, plateau _plateau, int ligne) {
    int nb_retournee =0;
    int j;
    for (j=0;j<1000;j++) { //optimisation possible avec getter border du "plateau" effectif
        if (get_case_etat(get_plateau_case(_plateau,ligne,j)) == 1) {
            nb_retournee+=1;
        }
    }
    if (nb_retournee>= 3) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+5);
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau
@ensures Prenez au hasard 5 cartes retournées du plateau (ou toutes les cartes retournées du plateau s'il y a moins de 5)-> 
Si une de ces cartes est une carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, 
Julien Forest ou Dimitri Watel, mélangez les et placez les à gauche de la case la plus à gauche de la première ligne-> 
Les prochaines cartes à être retournées sont ces cartes là-> Sinon, supprimez ces cartes du plateau
*/
void Eric_Lejeune_F(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures S'il y a une carte FISA retournée dans la même ligne ou la même colonne que cette carte, la faction qui a posé cette carte gagne 5 points DDRS
*/
void Lucienne_Pacave_F(faction _faction, plateau _plateau, int ligne, int colonne) {
    int drapeau_FISA = 0;
    int i;

   
    while (drapeau_FISA = 0) {

//parcours de la ligne
    for (i=0;i<1000;i++) {
        if (get_plateau_carte_nom(_plateau,i,colonne)== "FISA") {
            drapeau_FISA = 1;
        }
    }
//parcours de la colonne
    for (i=0;i<1000;i++) {
        if (get_plateau_carte_nom(_plateau,ligne,i) == "FISA") {
            drapeau_FISA = 1;
        }
    }
    }

    if (drapeau_FISA) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+5);
    }
    
}

/*
@requires faction valide
@assigns le plateau ou l'attribut DDRS de la faction
@ensures Si les cartes Djibril-Aurélien Djembele-Cabeau, 
Eric Lejeune et Lucienne Pacavé sont retournées, 
la faction qui a posé cette carte gagne 10 points DDRS->
 Sinon, retournez toutes les cartes dans la même ligne de cette carte sans appliquer leurs effets
*/
void Katrin_Salhab_F(faction _faction, plateau _plateau, int ligne, int colonne) {
    int i,j;
    int drapeau_Djibril = 0;
    int drapeau_Eric = 0;
    int drapeau_Lucienne = 0;

    for(i=0;i<1000;i++){
        for(j=0;j<1000;j++){

            if (get_plateau_carte_nom(_plateau,i,j) == "Djibril-Aurélien Djembele-Cabeau") {
            drapeau_Djibril = 1;
            }
            if (get_plateau_carte_nom(_plateau,i,j) == "Eric Lejeune") {
            drapeau_Eric = 1;
            }
            if (get_plateau_carte_nom(_plateau,i,j) == "Lucienne Pacavé") {
            drapeau_Lucienne = 1;
            }
        }
        }


    if (drapeau_Djibril && drapeau_Lucienne && drapeau_Eric) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+10);
    }

    else {
        //retourne les cartes sur la meme ligne
        for(j=0;j<1000;j++) {
            if (get_plateau_case(_plateau,ligne,j) != NULL) {
                set_case_etat( get_plateau_case(_plateau,ligne,j) , 1 );
            }
        }
        //pareil sur la colonne
        for(j=0;j<1000;j++) {
            if (get_plateau_case(_plateau,j,colonne) != NULL) {
                set_case_etat(get_plateau_case(_plateau,j,colonne),1);
            }
        }
    }
}

/*
@requires faction valide
@assigns rien
@ensures Si Laurent Prével est la dernière carte retournée du plateau, la faction qui a posé cette carte gagne la manche, quel que soit le nombre de points DDRS des deux factions
*/
void Laurent_Prevel_F(faction _faction, plateau _plateau, int ligne, int colonne) {

    
}