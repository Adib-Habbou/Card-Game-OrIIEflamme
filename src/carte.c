/* importation du module carte */
#include "../headers/carte.h"

/* importation du module faction */
#include "../headers/faction.h"

/* importation du module plateau */
#include "../headers/plateau.h"
#include "../src/plateau.c"

#include "../headers/main.h"

/* définition de la structure des cartes */
struct carte {
    char nom;
    char description;
    int nombre_occurrences;
};

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie le nom de la carte */
char get_carte_nom(carte carte) {
    return carte->nom;
}

/*  @requires   une carte valide
    @assigns    rien
    @ensures    renvoie la description de la carte */
char get_carte_description(carte carte) {
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
void set_carte_nom(carte carte, char nom) {
    carte->nom = nom;
}

/*  @requires   une carte valide et une chaîne de caractères
    @assigns    carte
    @ensures    modifie la description de la carte */
void set_carte_description(carte carte, char description) {
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
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_case_etat(get_tableau_case(_plateau,i,j)) == 1) {
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
    for (i=0;i<1000;i++) {  //plateau de taille 1000
        for (j=0;j<1000;j++) {  
            if (get_plateau_carte_nom(plateau,i,j) == "FC" && get_case_etat(get_plateau_case(_plateau,i,j))==1) {
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
void lIIEns(faction _faction, plateau _plateau) {


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

    
}

/*
@requires faction valide
@assigns le plateau
@ensures Supprimez du plateau toutes les cartes qui touchent cette carte Alcool
*/
void Alcool(faction _faction, plateau _plateau, int ligne, int colonne) {

    
}

/*
@requires faction valide
@assigns l'attribut DDRS de la faction et le plateau
@ensures Supprime toutes les cartes Thé et Alcool retournées sur le plateau-> 
Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS-> Sinon elle perd 1 point DDRS
*/
void Cafe(faction _faction, plateau _plateau) {

    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------


/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Supprimez toutes les cartes Café et Alcool retournées sur le plateau-> 
Si une carte Ecocup est retournée sur le plateau, la faction qui a posé cette carte gagne 1 point DDRS-> Sinon elle perd 1 point DDRS
*/
void The(faction _faction, plateau _plateau) {

    
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
void Reprographie(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns l'attribut DDRS des factions
@ensures Chaque faction gagne 1 point DDRS par carte non retournée et non supprimée du plateau qu'elle a posée sur le plateau
*/
void Isolation_du_batiment(faction _faction, plateau _plateau) {

    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau
@ensures Retournez toutes les cartes non retournées les plus à gauche et à droite de chaque ligne, sans appliquer leur effet
*/
void Parcours_sobriete_numerique(faction _faction, plateau _plateau) {

    
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
void Kahina_Bouchama(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Supprimez une ligne au hasard, la faction qui a posé cette carte gagne 2 points DDRS par carte supprimée ainsi->
*/
void Kevin_Goilard(faction _faction, plateau _plateau) {

    
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
void Vitera_Y(faction _faction, plateau _plateau) {

    
}






/*
@requires faction valide
@assigns le plateau
@ensures Supprimez toutes les cartes Heures supplémentaires retournées du plateau
*/
void Jonas_Senizergues(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns le plateau et l'attribut DDRS de la faction
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, 
supprimez toutes les cartes de la ligne et de la colonne où est posée cette carte (y compris celle-ci)-> 
Sinon la faction qui a posé cette carte gagne 1 point DDRS par carte Catherine Dubois, 
Anne-Laure Ligozat, Guillaume Burel, Christophe Mouilleron, Thomas Lim, Julien Forest et Dimitri Watel retournée sur le plateau
*/
void Fetia_Bannour(faction _faction, plateau _plateau) {

    
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------



/*
@requires faction valide
@assigns le plateau
@ensures Supprimez la première et la dernière cartes de la ligne et de la colonne où est posée cette carte
*/
void Catherine_Dubois(faction _faction, plateau _plateau, int ligne, int colonne) {

    
}

/*
@requires faction valide
@assigns le plateau, l'attribut DDRS de la faction
@ensures Pour chaque carte EcologIIE, Ecocup, Isolation du bâtiment et parcours Sobriété numérique retournée, 
la faction qui a posé cette carte gagne 3 points DDRS et la dernière carte non retournée du plateau est supprimée
*/
void Anne_Laure_Ligozat(faction _faction, plateau _plateau) {

    
}






/*
@requires faction valide
@assigns l'attribut DDRS de la faction
@ensures Si la faction adverse de celle qui a posé cette carte a plus de points DDRS, la seconde lui vole 3 points DDRS->
*/
void Guillaume_Burel(faction _faction, plateau _plateau) {

    
}

/*
@requires faction valide
@assigns le plateau
@ensures Si la carte Heures supplémentaires est retournée sur le plateau, supprimez toutes les cartes retournées du plateau sauf les cartes Christophe Mouilleron et Heures supplémentaires
*/
void Christophe_Mouilleron(faction _faction, plateau _plateau) {

    
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
void Julien_Forest(faction _faction, plateau _plateau) {
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
void Dimitri_Watel(faction _faction, plateau _plateau) {
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
void Djibril_Aurelien_Dembele_Cabot(faction _faction, plateau _plateau, int ligne) {
    int nb_retournee =0;
    int j;
    for (j=0;j<1000;j++) { //optimisation possible avec getter border du "plateau" effectif
        if (_plateau->tab[ligne][j]->etat == 1) {
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
    for (i=0;i<1000;i++) {
        if (_plateau->tab[i][colonne]->carte->nom == "FISA") {
            drapeau_FISA = 1;
        }
    }
//parcours de la colonne
    for (i=0;i<1000;i++) {
        if (_plateau->tab[ligne][i]->carte->nom == "FISA") {
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

    for(i=0;i<1000;i++){
        for(j=0,j<1000;j++){

            if (_plateau->tab[i][j]->carte->nom == "Djibril-Aurélien Djembele-Cabeau") {
            drapeau_Djibril = 1;
            }
            if (_plateau->tab[i][j]->carte->nom == "Eric Lejeune") {
            drapeau_Eric = 1;
            }
            if (_plateau->tab[i][j]->carte->nom == "Lucienne Pacavé") {
            drapeau_Lucienne = 1;
            }
        }
        }
    }

    if (drapeau_Djibril && drapeau_Lucienne && drapeau_Eric) {
        set_faction_nombre_points_DDRS(_faction,get_faction_nombre_points_DDRS(_faction)+10);
    }

    else {
        //retourne les cartes sur la meme ligne
        for(j=0;j<1000;j++) {
            if (_plateau->tab[ligne][j] != NULL) {
            _plateau->tab[ligne][j]->etat = 1;
            }
        }
        //pareil sur la colonne
        for(j=0;j<1000;j++) {
            if (_plateau->tab[j][colonne] != NULL) {
            _plateau->tab[j][colonne]->etat = 1;
            }
        }
    }
}

/*
@requires faction valide
@assigns rien
@ensures Si Laurent Prével est la dernière carte retournée du plateau, la faction qui a posé cette carte gagne la manche, quel que soit le nombre de points DDRS des deux factions
*/
void Laurent_Prevel(faction _faction, plateau _plateau) {

    
}