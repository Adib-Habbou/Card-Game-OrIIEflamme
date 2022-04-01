#include "../headers/plateau.h"

#include <stddef.h>

/* implémentation du type case */
struct Case {
    carte carte; // carte posée sur la case en question
    int id_faction; // 0 ou 1 qui détermine la faction qui a posée la carte
    int etat; // 0 si la carte est face cachée ou 1 si elle est face visible
};

/* implémentation du type plateau */
struct plateau {
    Case** tab; // matrice de cases de taille 1000 x 1000
};

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie la carte posé sur la case */
carte get_case_carte(Case case) {
    return case->carte;
}

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie l'état de la carte posé sur la case */
int get_case_etat(Case case) {
    return case->etat;
}

/*  @requires   une case valide et un entier
    @assigns    case
    @ensures    modifie l'état de la carte posé sur la case */
void set_case_etat(Case case, int etat) {
    case->etat = etat;
}

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie la case de coordonées ligne, colonne sur le plateau */
case get_plateau_case(plateau plateau, int ligne, int colonne) {
    return plateau.tab[ligne][colonne];
}

/*  @requires   un plateau valide
    @assigns    rien
    @ensures    renvoie la carte la plus en haut à gauche du plateau */
carte get_plateau_carte_premier(plateau plateau) {
    int ligne = 0;
    int colonne = 0;
    while(plateau.tab[ligne][colonne].carte != NULL) {
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
    @ensures    renvoie la carte la plus en bas à droite du plateau  */
carte get_plateau_carte_dernier(plateau plateau) {
    int ligne = 1000;
    int colonne = 1000;
    while(plateau.tab[ligne][colonne].carte != NULL) {
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

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie la carte la plus à gauche  */
carte get_plateau_carte_gauche(plateau plateau, int ligne, int colonne) {
    int ligne_bis = ligne;
    while(plateau.tab[ligne_bis][colonne].carte != NULL) {
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
    @ensures    renvoie la carte la plus à droite  */
carte get_plateau_carte_droite(plateau plateau, int ligne, int colonne) {
    int ligne_bis = ligne;
    while(plateau.tab[ligne_bis][colonne].carte != NULL) {
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
    @ensures    renvoie la carte la plus en haut  */
carte get_plateau_carte_haut(plateau plateau, int ligne, int colonne) {
    int colonne_bis = colonne;
    while(plateau.tab[ligne][colonne_bis].carte != NULL) {
        if (colonne_bis == 0) {
            affiche("Pas de carte en haut");
            exit(1);
        }
        colonne_bis -= 1;
    }
    return (ligne, colonne_bis);

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie la carte la plus en bas  */
carte get_plateau_carte_bas(plateau plateau, int ligne, int colonne) {
    int colonne_bis = colonne;
    while(plateau.tab[i][y].carte != NULL) {
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
faction get_case_faction(Case case) {
    liste_faction = liste_faction();
    return liste_faction[case->id_faction];
}

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie le nom de la carte dans la case */
char* get_plateau_carte_nom(plateau plateau, int ligne, int colonne) {
    plateau->tab[ligne][colonne]->carte->nom;
}

plateau init_plateau(){
    plateau _plateau;
    _plateau.tab = (Case**) malloc(TAILLE_PLATEAU * sizeof(Case*));
    for(int i = 0; i < TAILLE_PLATEAU; i++){
        _plateau.tab[i] = (Case*) malloc(TAILLE_PLATEAU * sizeof(Case));
    }
    return _plateau;
}

void libere_plateau(plateau _plateau){
    for(int i = 0; i < TAILLE_PLATEAU; i++){
        free(_plateau.tab[i]);
    }
    free(_plateau.tab);
}

int init_manche(plateau _plateau){
    //tire carte
    // 1 si fin 0 sinon
}

faction* liste_faction(){
    faction factions[NOMBRE_JOUEURS];
    for(int i = 0; i < NOMBRE_JOUEURS; i++){
        faction faction;
        faction->nom = "Joueur "+i;
        faction->nombre_points_DDRS = 0;
        factions[i] = faction;
    }
    return factions;
}

void poser(plateau _plateau, carte _carte, int* _position){
    _plateau.tab[_position[0]][_position[1]].carte = _carte;
    _plateau.tab[_position[0]][_position[1]].id_faction = _position[2];
    _plateau.tab[_position[0]][_position[1]].etat = 0;
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
    switch (_case.carte->nom)
    {
        case 'FISE':
            FISE(_factions[_case.id_faction]);
            break;
        case 'FISA':
            FISA(_factions[_case.id_faction], _plateau);
            break;
        case 'FC':
            FC(_factions[_case.id_faction]);
            break;
        case 'EcologIIE':
            EcologIIE(_factions[_case.id_faction]);
            break;
        case 'lIIEns':
            lIIEns(_factions[_case.id_faction]);
            break;
        case 'Soirée sans alcool':
            Soiree_sans_alcool(_factions[_case.id_faction]);
            break;
        case 'Alcool':
            Alcool(_factions[_case.id_faction]);
            break;
        case 'Café':
            Cafe(_factions[_case.id_faction]);
            break;
        case "Thé":
            The(_factions[_case.id_faction]);
            break;
        case "Ecocup":
            Ecocup(_factions[_case.id_faction]);
            break;
        case "Reprographie":
            Reprographie(_factions[_case.id_faction]);
            break;
        case "Isolation du bâtiment":
            Isolation_du_batiment(_factions[_case.id_faction]);
            break;
        case "Parcours sobriété numérique":
            Parcours_sobriete_numerique(_factions[_case.id_faction]);
            break;
        case "Heures supplémentaires":
            Heures_supplementaires(_factions[_case.id_faction]);
            break;
        case "Kahina Bouchama":
            Kahina_Bouchama(_factions[_case.id_faction]);
            break;
        case "Kevin Goilard":
            Kevin_Goilard(_factions[_case.id_faction]);
            break;
        case "Massinissa Merabet":
            Massinissa_Merabet(_factions[_case.id_faction]);
            break;
        case "Vitéra Y":
            Vitera_Y(_factions[_case.id_faction]);
            break;
        case "Jonas Senizergues":
            Jonas_Senizergues(_factions[_case.id_faction]);
            break;
        case "Fetia Bannour":
            Fetia_Bannour(_factions[_case.id_faction]);
            break;
        case "Catherine Dubois":
            Catherine_Dubois(_factions[_case.id_faction]);
            break;
        case "Anne-Laure Ligozat":
            Anne_Laure_Ligozat(_factions[_case.id_faction]);
            break;
        case "Guillaume Burel":
            Guillaume_Burel(_factions[_case.id_faction]);
            break;
        case "Christophe Mouilleron":
            Christophe_Mouilleron(_factions[_case.id_faction]);
            break;
        case "Thomas Lim":
            Thomas_Lim(_factions[_case.id_faction]);
            break;
        case "Julien Forest":
            Julien_Forest(_factions[_case.id_faction]);
            break;
        case "Dimitri Watel":
            Dimitri_Watel(_factions[_case.id_faction]);
            break;
        case "Djibril-Aurélien Dembele-Cabot":
            Djibril_Aurelien_Dembele_Cabot(_factions[_case.id_faction]);
            break;
        case "Eric Lejeune":
            Eric_Lejeune(_factions[_case.id_faction]);
            break;
        case "Lucienne Pacavé":
            Lucienne_Pacave(_factions[_case.id_faction]);
            break;
        case "Katrin Salhab":
            Katrin_Salhab(_factions[_case.id_faction]);
            break;
        case "Laurent Prével":
            Laurent_Prevel(_factions[_case.id_faction]);
            break;
        
        default:
            break;
    }
}