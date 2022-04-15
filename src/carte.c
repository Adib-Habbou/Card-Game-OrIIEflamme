
/* importation du module plateau */
#include "../headers/plateau.h"

/* importation du module structure */
#include "../headers/structure.h"

#include<stddef.h>
#include <time.h>
#include <stdlib.h>

/* définition de la structure des cartes */
struct carte {
    char* nom;
    char* description;
    int nombre_occurrences;
};


// CONSTANTES ET VARIABLES GLOBALES 

/* noms des différentes cartes */
// FISE
carte c_FISE = { "FISE", "La faction qui a posé cette carte gagne 1 point DDRS.", 4};

// FISA
carte c_FISA = { "FISA", "La faction qui a posé cette carte gagne 2 points DDRS si le nombre de cartes retournées sur le plateau (y compris celle-ci) est pair, et 0 sinon.", 4};

// FC
carte c_FC = { "FC", "La faction qui a posé cette carte gagne 4 points DDRS si au moins une autre carte FC est retournée sur le plateau et 0 sinon.", 4};

// EcologIIE
carte c_EcologIIE = { "EcologIIE", "La faction qui a posé cette carte gagne 1 point DDRS par carte FISE/FISA/FC retournée.", 2};

// lIIEns
carte c_lIIEns = { "lIIEns", "Prenez toutes les cartes FISE/FISA/FC retournées, retirez les du plateau, mélangez les et reposez les face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, dans cet ordre. Les prochaines cartes à être retournées sont ces cartes là.", 2};

// Soirée sans alcool
carte c_Soiree_sans_alcool = { "Soirée sans alcool", "Prenez toutes les cartes FISE/FISA/FC retournées, retirez les du plateau, mélangez les et reposez les face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, dans cet ordre. Les prochaines cartes à être retournées sont ces cartes là.", 1};

// Alcool
carte c_Alcool = { "Alcool", "Supprimez du plateau toutes les cartes qui touchent cette carte-ci (mais laissez la carte Alcool sur le plateau).", 1};

// Café
carte c_Cafe = { "Café", "Supprimez toutes les cartes Thé et Alcool retournées sur le plateau. Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS. Sinon elle perd 1 point DDRS.", 1};

// Thé
carte c_The = { "Thé", "Supprimez toutes les cartes Café et Alcool retournées sur le plateau. Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS. Sinon elle perd 1 point DDRS.", 3};

// Ecocup
carte c_Ecocup = { "Ecocup", "Cette carte est sans effet.", 1};

// Reprographie
carte c_Reprographie = { "Reprographie", "La faction adverse de celle qui a posé cette carte perd 1 points DDRS pour chaque paire de cartes retournées et identiques sur le plateau. (S'il y a 3 cartes identiques, cela fait 3 paires).", 1};

// Isolation du bâtiment 	
carte c_Isolation_du_batiment = { "Isolation du bâtiment", "Chaque faction gagne 1 point DDRS par carte non retournée et non supprimée du plateau qu'elle a posée sur le plateau.", 1};

// Parcours sobriété numérique
carte c_Parcours_sobriete_numerique = { "Parcours sobriété numérique", "Retournez toutes les cartes non retournées les plus à gauche et à droite de chaque ligne, sans appliquer leur effet.", 1};

// Heures supplémentaires
carte c_Heures_supplementaires = { "Heures supplémentaires", "La faction adverse de celle qui a posé cette carte perd 3 points DDRS par carte Heures supplémentaires retournée sur le plateau (y compris celle-ci).", 1};

// Kahina Bouchama 	
carte c_Kahina_Bouchama = { "Kahina Bouchama", "Supprimez une carte non retournée du plateau choisie au hasard.", 1};

// Kevin Goilard
carte c_Kevin_Goilard = { "Kevin Goilard", "Supprimez une ligne au hasard, la faction qui a posé cette carte gagne 2 points DDRS par carte supprimée ainsi.", 1};

// Massinissa Merabet
carte c_Massinissa_Merabet = { "Massinissa Merabet", "La faction qui a posé cette carte réactive l'effet de la dernière carte retournée avant Massinissa Merabet, en faisant comme elle l'avait posée elle-même, même si ce n'est pas le cas.", 1};

// Vitéra Y
carte c_Vitera_Y = { "Vitéra Y", "La faction qui a le moins de points DDRS gagne 3 points DDRS.", 1};

// Jonas Senizergues
carte c_Jonas_Senizergues = { "Jonas Senizergues", "Supprimez toutes les cartes Heures supplémentaires retournées du plateau.", 1};

// Fetia Bannour
carte c_Fetia_Bannour = { "Fetia Bannour", "Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes de la ligne et de la colonne où est posée cette carte (y compris celle-ci). Sinon la faction qui a posé cette carte gagne 1 point DDRS par carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest et Dimitri Watel retournée sur le plateau.", 1};

// Catherine Dubois
carte c_Catherine_Dubois = { "Catherine Dubois", "Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte.", 1};

// Anne-Laure Ligozat
carte c_Anne_Laure_Ligozat = { "Anne-Laure Ligozat", "Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte.", 1};

// Guillaume Burel
carte c_Guillaume_Burel = { "Guillaume Burel", "Si la faction adverse de celle qui a posé cette carte a plus de points DDRS, la seconde lui vole 3 points DDRS.", 1};

// Christophe Mouilleron
carte c_Christophe_Mouilleron = {  "Christophe Mouilleron", "Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes retournées du plateau sauf les cartes Christophe Mouilleron et Heures supplémentaires.", 1};

// Thomas Lim
carte c_Thomas_Lim = { "Thomas Lim", "Si Julien Forest n'est par retourné sur le plateau, la faction qui a posé cette carte gagne 3 points DDRS par carte FISE retournée sur le plateau. Sinon la faction adverse perd 1 point DDRS par carte FISE retournée sur le plateau.", 1};

// Julien Forest
carte c_Julien_Forest = { "Julien Forest", "La faction qui a posé cette carte gagne 6 points DDRS par carte FISE retournée sur le plateau si au moins une carte Café est retournée sur le plateau.", 1};

// Dimitri Watel
carte c_Dimitri_Watel = { "Dimitri Watel", "La faction qui a posé cette carte gagne 3 points DDRS par carte FISA ou FC retournée sur le plateau si au moins une carte Thé est retournée sur le plateau.", 1};

// Djibril-Aurélien Dembele-Cabot
carte c_Djibril_Aurelien_Dembele_Cabot = { "Djibril-Aurélien Dembele-Cabot", "S'il y a plus de 3 cartes retournées sur la ligne de cette carte, la faction qui a posé cette carte gagne 5 points DDRS.", 1};

// Eric Lejeune
carte c_Eric_Lejeune = { "Eric Lejeune", "Prenez au hasard 5 cartes retournées du plateau (ou toutes les cartes retournées du plateau s'il y a moins de 5). Si une de ces cartes est une carte Catherine Dubois, Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest ou Dimitri Watel, mélangez les et placez les à gauche de la case la plus à gauche de la première ligne. Les prochaines cartes à être retournées sont ces cartes là. Sinon, supprimez ces cartes du plateau.", 1};

// Lucienne Pacavé
carte c_Lucienne_Pacave = { "Lucienne Pacavé", "S'il y a une carte FISA retournée dans la même ligne ou la même colonne que cette carte, la faction qui a posé cette carte gagne 5 points DDRS.", 1};

// Katrin Salhab
carte c_Katrin_Salhab = { "Katrin Salhab", "Si les cartes Djibril-Aurélien Djembele-Cabeau, Eric Lejeune et Lucienne Pacavé sont retournées, la faction qui a posé cette carte gagne 10 points DDRS. Sinon, retournez toutes les cartes dans la même ligne de cette carte sans appliquer leurs effets.", 1};

// Laurent Prével
carte c_Laurent_Prevel = { "Laurent Prével", "Si Laurent Prével est la dernière carte retournée du plateau, la faction qui a posé cette carte gagne la manche, quel que soit le nombre de points DDRS des deux factions.", 1};

// Liste de toutes les cartes
carte* liste_carte = { &c_FISE, &c_FISA, &c_FC, &c_EcologIIE, &c_lIIEns, &c_Soiree_sans_alcool, &c_Alcool, &c_Cafe, &c_The, &c_Ecocup, &c_Reprographie, &c_Isolation_du_batiment, &c_Parcours_sobriete_numerique, &c_Heures_supplementaires, &c_Kahina_Bouchama, &c_Kevin_Goilard, &c_Massinissa_Merabet, &c_Vitera_Y, &c_Jonas_Senizergues, &c_Fetia_Bannour, &c_Catherine_Dubois, &c_Anne_Laure_Ligozat, &c_Guillaume_Burel, &c_Christophe_Mouilleron, &c_Thomas_Lim, &c_Julien_Forest, &c_Dimitri_Watel, &c_Djibril_Aurelien_Dembele_Cabot, &c_Eric_Lejeune, &c_Lucienne_Pacave, &c_Katrin_Salhab, &c_Laurent_Prevel };


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
void FISE(faction _faction) {
    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+1); 
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures augmente le nombre de DDRS de 2
*/
void FISA(faction _faction, plateau _plateau) {
    int nb_pair=0;
    int i,j;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
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
void FC(faction _faction, plateau _plateau) {
    int drapeau_FC=0;
    int i,j;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if ( (strcmp(get_plateau_carte_nom(_plateau,i,j), "FC") == 0 ) && get_case_etat(get_plateau_case(_plateau,i,j))==1) {
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
void EcologIIE(faction _faction, plateau _plateau) {
    int total = 0;
    int i,j;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "FC") || (get_plateau_carte_nom(_plateau,i,j) == "FISE") || (get_plateau_carte_nom(_plateau,i,j) == "FISA") )) {
                total+=1; 
            }
        }
    }
    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+total) ;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau
@ensures Prend toutes les cartes FISE/FISA/FC retournées, les retire du plateau, 
les mélange et les repose face cachées une par une sur la gauche de la carte la plus en haut à gauche du plateau, 
dans cet ordre et les prochaines cartes à être retournées sont ces cartes là
*/
void lIIEns(faction _faction, plateau _plateau) {
    int i,j;

    carte* liste_carte;
    int* liste_faction;
    int indice=0;

    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "FC") || (get_plateau_carte_nom(_plateau,i,j) == "FISE") || (get_plateau_carte_nom(_plateau,i,j) == "FISA") )) {
                
                liste_carte[indice]= get_case_carte(get_plateau_case(_plateau,i,j));
                liste_faction[indice]=get_case_id_faction(get_plateau_case(_plateau,i,j));
                indice++; //on a ajouté la carte à la liste qui va permettre de reposer les cartes

                set_case_etat( get_plateau_case(_plateau,i,j) , -1 );
            }
        }
    }
    carte tempCarte;
    int tempInt;
    int random;
    int newrandom;
    for (i=0;i<50;i++) {//on mélange la liste 50 fois
        random=rand() % indice;
        newrandom=rand() % indice;

        if (random==newrandom) { //on mélange forcément
            newrandom = (newrandom+1)%indice;
        }

        tempCarte = liste_carte[random];
        tempInt = liste_faction[random];

        liste_carte[random]=liste_carte[newrandom];
        liste_faction[random]=liste_faction[newrandom];

        liste_carte[newrandom]=tempCarte;
        liste_faction[newrandom]=tempInt;
    }
   
    int ligne_debut = get_plateau_carte_premier(_plateau)[0];
    int colonne_debut = get_plateau_carte_premier(_plateau)[1];

    for (i=0; i<indice; i++) {
        set_plateau_case(_plateau,ligne_debut,colonne_debut,liste_carte[i],liste_faction[i],0);
    }

}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction ou le plateau
@ensures Si au moins une carte alcool est retournée, 
supprime toutes les cartes FISE/FISA/FC retournées du plateau-> 
Supprime ensuite la première et la dernière ligne du plateau-> 
Sinon la faction qui a posé cette carte gagne 5 points DDRS
*/
void Soiree_sans_alcool(faction _faction, plateau _plateau) {
    int i,j;
    int drapeau_alcool = 0;
 
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "Alcool" && get_case_etat(get_plateau_case(_plateau, i, j)==1)) {
                drapeau_alcool=1;
                break;
            }
        }
    }

    if (drapeau_alcool) {
        int colonne = get_plateau_carte_premier(_plateau)[1];
        int ligne = get_plateau_carte_premier(_plateau)[0];

        for (j=0;j<TAILLE_PLATEAU;j++) { //suppression de la ligne
            if (get_plateau_case(_plateau,ligne,j)!= NULL){
                set_case_etat( get_plateau_case(_plateau,ligne,j) , -1 );
            }
        }

        for (i=0;i<TAILLE_PLATEAU;i++) { //suppression de la colonne
            if (get_plateau_case(_plateau,i,colonne)!= NULL){
                set_case_etat( get_plateau_case(_plateau,i,colonne) , -1 );
            }
        }

        for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
            for (j=0;j<TAILLE_PLATEAU;j++) {  
                if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "FC") || (get_plateau_carte_nom(_plateau,i,j) == "FISE") || (get_plateau_carte_nom(_plateau,i,j) == "FISA") )) {
                    set_case_etat( get_plateau_case(_plateau,i,j) , -1 );
                }
            }
        }
    }

    

    else {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+5);
    }
    
    
}

/*
@requires faction valide
@assigns le plateau
@ensures Supprimez du plateau toutes les cartes qui touchent cette carte Alcool
*/
void Alcool(faction _faction, plateau _plateau, int ligne, int colonne) {

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
void Cafe(faction _faction, plateau _plateau) {
    int i,j;
    int drapeau_Ecocup = 0;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "Thé") || (get_plateau_carte_nom(_plateau,i,j) == "Alcool")) ) {
                set_case_etat(get_plateau_case(_plateau,i,j),-1); //ATTENTION A CHANGER PAR UNE FONCTION QUI MET LA CASE EN NULL
            }
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( ( strcmp(get_plateau_carte_nom(_plateau,i,j), "Ecocup"))) {
           ) == 0 )     drapeau_Ecocup = 1;
            }
        }
    }

    if (drapeau_Ecocup) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+1);
    }
    else {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)-1);

        if (get_faction_nombre_points_DDRS(_faction)<0) {
            set_faction_nombre_points_DDRS(_faction,0); //pas de points négatifs
        }
    }
    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Supprimez toutes les cartes Café et Alcool retournées sur le plateau-> 
Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS-> Sinon elle perd 1 point DDRS
*/
void The(faction _faction, plateau _plateau) {
    int i,j;
        int drapeau_Ecocup = 0;
        for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
            for (j=0;j<TAILLE_PLATEAU;j++) {  
                if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "Café") || (get_plateau_carte_nom(_plateau,i,j) == "Alcool")) ) {
                    set_case_etat(get_plateau_case(_plateau,i,j),-1); //ATTENTION A CHANGER PAR UNE FONCTION QUI MET LA CASE EN NULL
                }
                if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( ( strcmp(get_plateau_carte_nom(_plateau,i,j), "Ecocup"))) {
           ) == 0 )         drapeau_Ecocup = 1;
                }
            }
        }

        if (drapeau_Ecocup) {
            set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+1);
        }
        else {
            set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)-1);

            if (get_faction_nombre_points_DDRS(_faction)<0) {
            set_faction_nombre_points_DDRS(_faction,0); //pas de points négatifs
            }
        }
        
}

/*
@requires rien
@assigns rien
@ensures sans effet
*/
void Ecocup() {
 
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction adverse
@ensures La faction adverse de celle qui a posé cette carte perd 1 points DDRS pour chaque paire de cartes retournées et identiques sur le plateau
*/
void Reprographie(faction _faction_oppose, plateau _plateau) {
    int i,j; //parcours le plateau

    int k=0; //parcours la liste stockant les cartes retournées

    int nb_de_paire = 0;
    char** liste_carte;
    int indice;

    for (i=0;i<TAILLE_PLATEAU;i++) {  //on stocke les cartes non retournées
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1) {

                while (k<indice) {
                    if (liste_carte[k]== get_plateau_carte_nom(_plateau,i,j)) { //si la carte a déjà été retournée
                        nb_de_paire++;
                        k=indice;//sort de la boucle
                    }
                    k++;
                }

                liste_carte[indice] = get_plateau_carte_nom(_plateau,i,j); //ajoute la carte à la liste
                indice++; 
            }
            
        }
    }

    set_faction_nombre_points_DDRS(_faction_oppose, get_faction_nombre_points_DDRS(_faction_oppose) - nb_de_paire);
    if (get_faction_nombre_points_DDRS(_faction_oppose)<0) {
        set_faction_nombre_points_DDRS(_faction_oppose,0); //pas de points négatifs
    }
}

/*
@requires faction valide
@assigns l'attribut DDRS des factions
@ensures Chaque faction gagne 1 point DDRS par carte non retournée et non supprimée du plateau qu'elle a posée sur le plateau
*/
void Isolation_du_batiment(faction _faction, faction _faction_oppose, plateau _plateau) {
    int nb_faction_1 = 0;
    int nb_faction_2 = 0;
    int i,j;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
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
void Parcours_sobriete_numerique(faction _faction, plateau _plateau) {
    int ligne;
    for (ligne = 0;ligne <TAILLE_PLATEAU; ligne++) {
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
void Heures_supplementaires(faction _faction_oppose, plateau _plateau) {
    int i,j;
    int nb_carte_heures_supp;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 &&  (get_plateau_carte_nom(_plateau,i,j) == "Heures supplémentaires") ) {
                nb_carte_heures_supp+=1; 
            }
        }
    }

    set_faction_nombre_points_DDRS(_faction_oppose,get_faction_nombre_points_DDRS(_faction_oppose) - 3*nb_carte_heures_supp);

    if (get_faction_nombre_points_DDRS(_faction_oppose)<0) {
        set_faction_nombre_points_DDRS(_faction_oppose,0); //pas de points négatifs
    }
}





/*
@requires faction valide
@assigns le plateau
@ensures Supprimez une carte non retournée du plateau choisie au hasard
*/
void Kahina_Bouchama(faction _faction, plateau _plateau) {
    int i,j;
    int* liste_ligne_carte_verso;
    int* liste_colonne_carte_verso;

    int indice = 0;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //on stocke les cartes non retournées
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 0) {
                liste_ligne_carte_verso[indice] = i;
                liste_colonne_carte_verso[indice] = j;
                indice++; 
            }
            
        }
    }

    int random = rand() % indice; //génère l'indice pour trouver la carte au hasard

    int ligne_supp = liste_ligne_carte_verso[random];
    int colonne_supp = liste_colonne_carte_verso[random];

    set_case_etat(get_plateau_case(_plateau,ligne_supp,colonne_supp), -1);
    
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Supprimez une ligne au hasard, la faction qui a posé cette carte gagne 2 points DDRS par carte supprimée ainsi->
*/
void Kevin_Goilard(faction _faction, plateau _plateau) {
    int ligne_debut,ligne_fin,compteur_carte_supp;

    ligne_debut = get_plateau_carte_premier(_plateau)[0];
    ligne_fin = get_plateau_carte_dernier(_plateau)[0];
    int modulo = abs(ligne_fin-ligne_debut);

    int random_ligne = ligne_debut + rand() % modulo;
    int colonne;

    for (colonne = 0; colonne <TAILLE_PLATEAU; colonne++ ) {
        if (get_plateau_case(_plateau,random_ligne,colonne) != NULL){
            set_case_etat(get_plateau_case(_plateau,random_ligne,colonne), -1);
            compteur_carte_supp++;
        }
    }



    set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+2*compteur_carte_supp);
    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau et/ou l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte réactive l'effet de la dernière carte retournée avant Massinissa Merabet, en faisant comme elle l'avait posée elle-même, même si ce n'est pas le cas
*/
void Massinissa_Merabet(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns l'attribut DDRS d'une faction
@ensures La faction qui a le moins de points DDRS gagne 3 points DDRS
*/
void Vitera_Y(faction _faction, faction _faction_oppose, plateau _plateau) {
    if (get_faction_nombre_points_DDRS(_faction) > get_faction_nombre_points_DDRS(_faction_oppose)) {
        set_faction_nombre_points_DDRS(_faction_oppose,get_faction_nombre_points_DDRS(_faction_oppose)+3);
    }

    if (get_faction_nombre_points_DDRS(_faction) < get_faction_nombre_points_DDRS(_faction_oppose)) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+3);
    }
    //ne fais rien dans le cas où les deux factions ont le même nombre de points
}






/*
@requires faction valide
@assigns le plateau
@ensures Supprimez toutes les cartes Heures supplémentaires retournées du plateau
*/
void Jonas_Senizergues(faction _faction, plateau _plateau) {
    int i,j;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "Heures supplémentaires") {
                set_case_etat(get_plateau_case(_plateau,i,j), -1);
            }
        }
    }
    
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, 
supprimez toutes les cartes de la ligne et de la colonne où est posée cette carte (y compris celle-ci)-> 
Sinon la faction qui a posé cette carte gagne 1 point DDRS par carte Catherine Dubois, 
Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest et Dimitri Watel retournée sur le plateau
*/
void Fetia_Bannour(faction _faction, plateau _plateau, int ligne, int colonne) {
    int i,j;
    int drapeau_heures_supp = 0;
    int total_carte_spe = 0;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "Heures supplémentaires" && get_case_etat(get_plateau_case(_plateau, i, j)==1)) {
                drapeau_heures_supp=1;
            }
            if ( get_case_etat(get_plateau_case(_plateau, i, j))==1 && (( strcmp(get_plateau_carte_nom(_plateau,i,j), "Catherine Dubois") == 0 ) || -strcmp(get_plateau_carte_nom(_plateau,i,j), "Dimitri Watel") == 0)  || (( strcmp(get_plateau_carte_nom(_plateau,i,j), "Julien Forest") == 0 ) || (( strcmp(get_plateau_carte_nom(_plateau,i,j), "Thomas Lim") == 0) || (( strcmp(get_plateau_carte_nom(_plateau,i,j), "Anne-Laure Ligozat") == 0) || (strcmp(get_plateau_carte_nom(_plateau,i,j), "Guillaume Burel") == 0 ) || ( strcmp(get_plateau_carte_nom(_plateau,i,j), "Christophe Mouilleron") == 0 ))) {
                total_carte_spe++;
            }
        }
    }

    if (drapeau_heures_supp) {
        for (j=0;j<TAILLE_PLATEAU;j++) { //suppression de la ligne
            if (get_plateau_case(_plateau,ligne,j)!= NULL){
                set_case_etat( get_plateau_case(_plateau,ligne,j) , -1 );
            }
        }

        for (i=0;i<TAILLE_PLATEAU;i++) { //suppression de la ligne
            if (get_plateau_case(_plateau,i,colonne)!= NULL){
                set_case_etat( get_plateau_case(_plateau,i,colonne) , -1 );
            }
        }
    }

    else {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+total_carte_spe);
    }
    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau
@ensures Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte
*/
void Catherine_Dubois(faction _faction, plateau _plateau, int ligne, int colonne) {
    
//carte la plus à gauche
    int ligneg = get_plateau_carte_gauche(_plateau,ligne,colonne)[0];
    int colonneg = get_plateau_carte_gauche(_plateau,ligne,colonne)[1];
    set_case_etat( get_plateau_case(_plateau,ligneg,colonneg) , -1 );
    set_case_etat( get_plateau_case(_plateau,ligneg,colonneg) , -1 );
//carte la plus à droite
    int ligned = get_plateau_carte_droite(_plateau,ligne,colonne)[0];
    int colonned = get_plateau_carte_droite(_plateau,ligne,colonne)[1];
    set_case_etat( get_plateau_case(_plateau,ligned,colonned) , -1 );
    set_case_etat( get_plateau_case(_plateau,ligned,colonned) , -1 );
//carte la plus en haut
    int ligneh = get_plateau_carte_haut(_plateau,ligne,colonne)[0];
    int colonneh = get_plateau_carte_haut(_plateau,ligne,colonne)[1];
    set_case_etat( get_plateau_case(_plateau,ligneh,colonneh) , -1 );
    set_case_etat( get_plateau_case(_plateau,ligneh,colonneh) , -1 );
//carte la plus en bas
    int ligneb = get_plateau_carte_bas(_plateau,ligne,colonne)[0];
    int colonneb = get_plateau_carte_bas(_plateau,ligne,colonne)[1];
    set_case_etat( get_plateau_case(_plateau,ligneb,colonneb) , -1 );
    set_case_etat( get_plateau_case(_plateau,ligneb,colonneb) , -1 );
    
}

/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Pour chaque carte EcologIIE, Ecocup, Isolation du bâtiment et parcours Sobriété numérique retournée, 
la faction qui a posé cette carte gagne 3 points DDRS et la dernière carte non retournée du plateau est supprimée
*/
void Anne_Laure_Ligozat(faction _faction, plateau _plateau) {
    int nb_carte_retournee = 0;
    int i,j;

    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1 && ( (get_plateau_carte_nom(_plateau,i,j) == "EcologIIE") || (get_plateau_carte_nom(_plateau,i,j) == "Ecocup") || (get_plateau_carte_nom(_plateau,i,j) == "Isolation du bâtiment") || (get_plateau_carte_nom(_plateau,i,j) == "Isolation du bâtiment") )) {
                nb_carte_retournee+=1; 
            }
        }
    }
    set_faction_nombre_points_DDRS(_faction, get_faction_nombre_points_DDRS(_faction) + 3*nb_carte_retournee);

    for (i=TAILLE_PLATEAU;i>0;i--) {  //on décrémente car on part de la fin du plateau
        for (j=TAILLE_PLATEAU;j>0;j--) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 0 ) {

                set_case_etat(get_plateau_case(_plateau,i,j),-1);
                return; //arrêt total de la fonction

            }
        }
    }
    
}






/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures Si la faction adverse de celle qui a posé cette carte a plus de points DDRS, la seconde lui vole 3 points DDRS->
*/
void Guillaume_Burel(faction _faction, faction _faction_oppose, plateau _plateau) {

    if (get_faction_nombre_points_DDRS(_faction_oppose) > get_faction_nombre_points_DDRS(_faction) ) {

        

        if (get_faction_nombre_points_DDRS(_faction_oppose)<3) {
            set_faction_nombre_points_DDRS(_faction, get_faction_nombre_points_DDRS(_faction) + get_faction_nombre_points_DDRS(_faction_oppose));
            set_faction_nombre_points_DDRS(_faction_oppose,0); 
        }

        else {
            set_faction_nombre_points_DDRS(_faction_oppose, get_faction_nombre_points_DDRS(_faction_oppose) - 3);
            set_faction_nombre_points_DDRS(_faction, get_faction_nombre_points_DDRS(_faction) + 3);
        }

    }
}

/*
@requires faction valide
@assigns le plateau
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes retournées du plateau sauf les cartes Christophe Mouilleron et Heures supplémentaires
*/
void Christophe_Mouilleron(faction _faction, plateau _plateau) {
    int i,j;
    int drapeau_heures_supp = 0;

    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "Heures supplémentaires" && get_case_etat(get_plateau_case(_plateau, i, j)==1)) {
                    drapeau_heures_supp=1;
            }
        }
    }
    if (drapeau_heures_supp) {
        
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
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
void Thomas_Lim(faction _faction, faction _faction_oppose, plateau _plateau) {
    int Julien_Forest_present = 0;
    int i,j;

    for (i=0;i<TAILLE_PLATEAU;i++) {  //recherche de Julien
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "Julien Forest" && get_case_etat(get_plateau_case(_plateau, i, j)==1 )) {
                Julien_Forest_present = 1;
            }
        }
    }

    int nb_FISE = 0;
    
        
    for (i=0;i<TAILLE_PLATEAU;i++) {  //compte le nb de FISE
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "FISE" && get_case_etat(get_plateau_case(_plateau, i, j)==1)) {
                nb_FISE+=1;
            }
        }
    }

    if (Julien_Forest_present) {
        set_faction_nombre_points_DDRS(_faction_oppose,get_faction_nombre_points_DDRS(_faction_oppose)-nb_FISE);
        if (get_faction_nombre_points_DDRS(_faction_oppose)<0) {
            set_faction_nombre_points_DDRS(_faction_oppose,0);
        }
    }

    else { 
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+3*nb_FISE);
        
    }
    
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures La faction qui a posé cette carte gagne 6 points DDRS par carte FISE retournée sur le plateau si au moins une carte Café est retournée sur le plateau
*/
void Julien_Forest(faction _faction, plateau _plateau) {
    int nb_FISE = 0;
    int i,j;
    int drapeau_cafe = 0;

    for (i=0;i<TAILLE_PLATEAU;i++) {  
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "Café") {
                drapeau_cafe=1;
            }
        }
    }

    if (drapeau_cafe) { 
        for (i=0;i<TAILLE_PLATEAU;i++) { 
            for (j=0;j<TAILLE_PLATEAU;j++) {  
                if (get_plateau_carte_nom(_plateau,i,j) == "FISE") {
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
void Dimitri_Watel(faction _faction, plateau _plateau) {
    int nb_FISA_FC = 0;
    int i,j;
    int drapeau_the = 0;

    for (i=0;i<TAILLE_PLATEAU;i++) {  
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_plateau_carte_nom(_plateau,i,j) == "Thé") {
                drapeau_the=1;
            }
        }
    }

    if (drapeau_the) { 
        for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
            for (j=0;j<TAILLE_PLATEAU;j++) {  
                if (get_plateau_carte_nom(_plateau,i,j) == "FISA" || get_plateau_carte_nom(_plateau,i,j) == "FC" ) {
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
void Djibril_Aurelien_Dembele_Cabot(faction _faction, plateau _plateau, int ligne) {
    int nb_retournee =0;
    int j;
    for (j=0;j<TAILLE_PLATEAU;j++) { //optimisation possible avec getter border du "plateau" effectif
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
void Eric_Lejeune(faction _faction, plateau _plateau) {
    
    int i,j;
    carte* liste_carte; //liste total
    int* liste_faction;
    int* memo_indice; //liste qui va servir à supprimer les cartes dans le cas ou le drapeau est nulle
    int indice=0;

    for (i=0;i<TAILLE_PLATEAU;i++) {  //création de la liste des cartes retournées
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1) {
                
                liste_carte[indice]= get_case_carte(get_plateau_case(_plateau,i,j));
                liste_faction[indice]=get_case_id_faction(get_plateau_case(_plateau,i,j));
                indice++; //on a ajouté la carte à la liste qui va permettre de reposer les cartes

                set_case_etat( get_plateau_case(_plateau,i,j) , -1 );
            }
        }
    }

    carte* liste_carte_5; //liste réduite à 5
    int* liste_faction_5;

    int random;
    int newrandom;

    for (i=0;i<5;i++) {//on prend 5 cartes au hasard
        random=rand() % indice;
        while (liste_carte[random]==NULL) {
            random = rand() % indice;
        }
        liste_carte_5[i]=liste_carte[random];
        liste_faction_5[i]=liste_faction[random];
        memo_indice[i]=random;

        liste_carte[random] = NULL;
        liste_faction[random] = NULL;
    }

    int drapeau_spe = 0 ; //on va vérifier si une des cartes mentionnées est présente

    for (i=0;i<5;i++){ 
      if( (strcmp(get_carte_nom(liste_carte_5[i]), "Catherine Dubois") == 0 ) || (strcmp( get_carte_nom(liste_carte_5[i]), "Anne-Laure Ligozat") == 0 ) || (  strcmp(get_carte_nom(liste_carte_5[i]), "Guillaume Burel")  == 0 ) || (strcmp(get_carte_nom(liste_carte_5[i], "Christophe Mouilleron")) == 0 ) || (strcmp(get_carte_nom(liste_carte_5[i], "Thomas Lim")) == 0) || (strcmp(get_carte_nom(liste_carte_5[i], "Julien Forest")) == 0) || (strcmp(get_carte_nom(liste_carte_5[i], "Dimitri Watel" )) == 0)) {
            drapeau_spe=1;
            break;
        }
    } 


    if (drapeau_spe) {
        carte tempCarte;
        int tempInt;
    
        for (i=0;i<50;i++) {//on mélange la liste 50 fois
            random=rand() % indice;
            newrandom=rand() % indice;

            if (random==newrandom) { //on mélange forcément
                newrandom = (newrandom+1)%indice;
            }

            tempCarte = liste_carte_5[random];
            tempInt = liste_faction_5[random];

            liste_carte_5[random]=liste_carte_5[newrandom];
            liste_faction_5[random]=liste_faction_5[newrandom];

            liste_carte_5[newrandom]=tempCarte;
            liste_faction_5[newrandom]=tempInt;
        
    
            int ligne_debut = get_plateau_carte_premier(_plateau)[0];
            int colonne_debut = get_plateau_carte_premier(_plateau)[1];

            for (i=0; i<indice; i++) {
                set_plateau_case(_plateau,ligne_debut,colonne_debut-i,liste_carte[i],liste_faction[i],0);
            }
        }
    }
    else {//on supprime les cartes du plateau 
        int l=0; //indice de parcours de memo_indice
        int compteur=0; //compte l'occurence d'une carte retournée, que l'on va comparer à l'élement de memo_indice
        
        for (i=0;i<TAILLE_PLATEAU;i++) {  
            for (j=0;j<TAILLE_PLATEAU;j++) {  
                if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1) {

                    if (compteur==memo_indice[l] && memo_indice[l]!=NULL ){
                        set_case_etat(get_plateau_case(_plateau,i,j), -1);
                        l++;
                    }
                    compteur++;
                }
        }
    }

    }


}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures S'il y a une carte FISA retournée dans la même ligne ou la même colonne que cette carte, la faction qui a posé cette carte gagne 5 points DDRS
*/
void Lucienne_Pacave(faction _faction, plateau _plateau, int ligne, int colonne) {
    int drapeau_FISA = 0;
    int i;

   
    while (drapeau_FISA = 0) {

//parcours de la ligne
    for (i=0;i<TAILLE_PLATEAU;i++) {
        if (get_plateau_carte_nom(_plateau,i,colonne)== "FISA") {
            drapeau_FISA = 1;
        }
    }
//parcours de la colonne
    for (i=0;i<TAILLE_PLATEAU;i++) {
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
void Katrin_Salhab(faction _faction, plateau _plateau, int ligne, int colonne) {
    int i,j;
    int drapeau_Djibril = 0;
    int drapeau_Eric = 0;
    int drapeau_Lucienne = 0;

    for(i=0;i<TAILLE_PLATEAU;i++){
        for(j=0;j<TAILLE_PLATEAU;j++){

            if ( strcmp(get_plateau_carte_nom(_plateau,i,j), "Djibril-Aurélien Djembele-Cabeau") == 0 ) {
            drapeau_Djibril = 1;
            }
            if ( strcmp(get_plateau_carte_nom(_plateau,i,j), "Eric Lejeune") == 0 ) {
            drapeau_Eric = 1;
            }
            if ( strcmp(get_plateau_carte_nom(_plateau,i,j), "Lucienne Pacavé") == 0 ) {
            drapeau_Lucienne = 1;
            }
        }
        }


    if (drapeau_Djibril && drapeau_Lucienne && drapeau_Eric) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+10);
    }

    else {
        //retourne les cartes sur la meme ligne
        for(j=0;j<TAILLE_PLATEAU;j++) {
            if (get_plateau_case(_plateau,ligne,j) != NULL) {
                set_case_etat( get_plateau_case(_plateau,ligne,j) , 1 );
            }
        }
        //pareil sur la colonne
        for(j=0;j<TAILLE_PLATEAU;j++) {
            if (get_plateau_case(_plateau,j,colonne) != NULL) {
                set_case_etat(get_plateau_case(_plateau,j,colonne),1);
            }
        }
    }
}

/*
@requires factions valides
@assigns les points DDRS de la faction
@ensures Si Laurent Prével est la dernière carte retournée du plateau, la faction qui a posé cette carte gagne la manche, quel que soit le nombre de points DDRS des deux factions
*/
void Laurent_Prevel(faction _faction, faction _faction_oppose, plateau _plateau, int ligne, int colonne) {

    if ( (ligne == get_plateau_carte_dernier(_plateau)[0]) && (colonne == get_plateau_carte_dernier(_plateau)[1] )) {
        set_faction_nombre_points_DDRS( _faction, max( get_faction_nombre_points_DDRS(_faction) , get_faction_nombre_points_DDRS(_faction_oppose) ) + 100  );
    }
    
}