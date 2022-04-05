#include "../headers/plateau.h"

#include <stddef.h>

/* implémentation du type case */
struct Case {
    carte carte; // carte posée sur la case en question
    int id_faction; // 0 ou 1 qui détermine la faction qui a posée la carte
    int etat; // 0 si la carte est face cachée ou 1 si elle est face visible ou -1 si la carte est retiré
};

/* implémentation du type plateau */
struct plateau {
    Case** tab; // matrice de cases de taille 1000 x 1000
};

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie la carte posé sur la case */
carte get_case_carte(Case _case) {
    return _case.carte;
}

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie l'état de la carte posé sur la case */
int get_case_etat(Case _case) {
    return _case.etat;
}

/*  @requires   une case valide et un entier
    @assigns    case
    @ensures    modifie l'état de la carte posé sur la case */
void set_case_etat(Case _case, int etat) {
    if (etat == -1) {
        _case.carte = NULL;
        _case.id_faction = NULL;
        _case.etat = NULL;
    }
    _case.etat = etat;
}

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie la case de coordonées ligne, colonne sur le plateau */
Case get_plateau_case(plateau plateau, int ligne, int colonne) {
    return plateau->tab[ligne][colonne];
}

/*  @requires   un plateau valide
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus en haut à gauche du plateau */
int* get_plateau_carte_premier(plateau plateau) {
    int ligne = 0;
    int colonne = 0;
    while(plateau->tab[ligne][colonne].carte != NULL) {
        if (colonne < 1000) {
             colonne += 1;
        }
        else {
            colonne = 0;
            ligne += 1;
        }
    }
    return (ligne, colonne);
}

/*  @requires   un plateau valide
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus à gauche  */
int* get_plateau_carte_gauche(plateau plateau, int ligne, int colonne) {
    int ligne_bis = ligne;
    while(plateau->tab[ligne_bis][colonne].carte != NULL) {
        if (ligne_bis == 0) {
            affiche("Pas de carte à gauche");
            exit(1);
        }
        ligne_bis -= 1;
    }
    return (ligne_bis, colonne);
}

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus à droite  */
int* get_plateau_carte_droite(plateau plateau, int ligne, int colonne) {
    int ligne_bis = ligne;
    while(plateau->tab[ligne_bis][colonne].carte != NULL) {
        if (ligne_bis == 1000) {
            affiche("Pas de carte à droite");
            exit(1);
        }
        ligne_bis += 1;
    }
    return (ligne_bis, colonne);
}


/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus en haut  */
int* get_plateau_carte_haut(plateau plateau, int ligne, int colonne) {
    int colonne_bis = colonne;
    while(plateau->tab[ligne][colonne_bis].carte != NULL) {
        if (colonne_bis == 0) {
            affiche("Pas de carte en haut");
            exit(1);
        }
        colonne_bis -= 1;
    }
    return (ligne, colonne_bis);
}

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus en bas  */
int* get_plateau_carte_bas(plateau plateau, int ligne, int colonne) {
    int colonne_bis = colonne;
    while(plateau->tab[ligne][colonne_bis].carte != NULL) {
        if (colonne_bis == 1000) {
            affiche("Pas de carte en bas");
            exit(1);
        }
        colonne_bis += 1;
    }
    return (ligne, colonne_bis);
}

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie la faction qui a posé la carte présente sur la case */
faction get_case_faction(Case _case) {
    faction* factions = liste_faction();
    return factions[_case.id_faction];
}

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie le nom de la carte dans la case */
char* get_plateau_carte_nom(plateau plateau, int ligne, int colonne) {
    return get_carte_nom(plateau->tab[ligne][colonne].carte);
}

plateau init_plateau(){
    plateau _plateau;
    _plateau->tab = (Case**) malloc(TAILLE_PLATEAU * sizeof(Case*));
    for(int i = 0; i < TAILLE_PLATEAU; i++){
        _plateau->tab[i] = (Case*) malloc(TAILLE_PLATEAU * sizeof(Case));
    }
    return _plateau;
}

void libere_plateau(plateau _plateau){
    for(int i = 0; i < TAILLE_PLATEAU; i++){
        free(_plateau->tab[i]);
    }
    free(_plateau->tab);
}

int init_manche(plateau _plateau){
    //tire carte
    // 1 si fin 0 sinon
}

faction* liste_faction(){
    faction factions[NOMBRE_JOUEURS];
    for(int i = 0; i < NOMBRE_JOUEURS; i++){
        faction faction;
        set_faction_nom(faction, "Joueur "+i);
        set_faction_nombre_points_DDRS(faction, 0);
        factions[i] = faction;
    }
    return factions;
}

void poser(plateau _plateau, carte _carte, int* _position){
    _plateau->tab[_position[0]][_position[1]].carte = _carte;
    _plateau->tab[_position[0]][_position[1]].id_faction = _position[2];
    _plateau->tab[_position[0]][_position[1]].etat = 0;
}

carte retourner(plateau _plateau, faction* _factions){
    Case _case;
    for(int i = 0; i < TAILLE_PLATEAU; i++){
        for(int j = 0; j < TAILLE_PLATEAU; j++){
            if(i != j){
                if(_plateau->tab[i][j].etat != 0){
                    _case = _plateau->tab[i][j];
                    goto cartetrouve;
                }
                if(_plateau->tab[j][i].etat != 0){
                    _case = _plateau->tab[j][i];
                    goto cartetrouve;
                }
            }else{
                if(_plateau->tab[j][j].etat != 0){
                    _case = _plateau->tab[j][j];
                    goto cartetrouve;
                }
            }
        }
    }

cartetrouve:
    if(get_carte_nom(_case.carte) == "FISE"){
        FISE(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "FISA"){
        FISA(_factions[_case.id_faction], _plateau);
    }else if(get_carte_nom(_case.carte) == "FC"){
        FC(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "EcologIIE"){
        EcologIIE(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "lIIEns"){
        lIIEns(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Soirée sans alcool"){
        Soiree_sans_alcool(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Alcool"){
        Alcool(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Café"){
        Cafe(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Thé"){
        The(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Ecocup"){
        Ecocup(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Reprographie"){
        Reprographie(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Isolation du bâtiment"){
        Isolation_du_batiment(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Parcours sobriété numérique"){
        Parcours_sobriete_numerique(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Heures supplémentaires"){
        Heures_supplementaires(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Kahina Bouchama"){
        Kahina_Bouchama(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Kevin Goilard"){
        Kevin_Goilard(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Vitéra Y"){
        Massinissa_Merabet(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Jonas Senizergues"){
        Jonas_Senizergues(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Fetia Bannour"){
        Fetia_Bannour(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Catherine Dubois"){
        Catherine_Dubois(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Anne-Laure Ligozat"){
        Anne_Laure_Ligozat(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Guillaume Burel"){
        Guillaume_Burel(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Christophe Mouilleron"){
        Christophe_Mouilleron(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Thomas Lim"){
        Thomas_Lim(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Julien Forest"){
        Julien_Forest(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Dimitri Watel"){
        Dimitri_Watel(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Djibril-Aurélien Dembele-Cabot"){
        Djibril_Aurelien_Dembele_Cabot(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Eric Lejeune"){
        Eric_Lejeune(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Lucienne Pacavé"){
        Lucienne_Pacave(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Katrin Salhab"){
        Katrin_Salhab(_factions[_case.id_faction]);
    }else if(get_carte_nom(_case.carte) == "Laurent Prével"){
        Laurent_Prevel(_factions[_case.id_faction]);
    }
}