/* importation du module faction */
#include "../headers/faction.h"

/* définition de la structure des factions */
struct faction {
    char* nom;
    int nombre_points_DDRS;
    int option_remelanger; /* 0 si la faction n'a pas encore remélanger et 1 si la fonction a déjà remélanger */
    int manches_gagnees; /* nombre de manches gagnées par la faction : 0, 1 ou 2 */
    pile main; /* type liste défini dans structure.h et structure.c */
    carte* pioche; /* type pile défini dans structure.h et structure.c */
};

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie le nom de la faction */
char* get_faction_nom(faction _faction) {
    return _faction->nom;
}

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie le nombre de points DDRS de la faction */
int get_faction_nombre_points_DDRS(faction _faction) {
    return _faction->nombre_points_DDRS;
}

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie la main de la faction */
pile get_faction_main(faction _faction) {
    return _faction->main;
}

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie la pioche de la faction */
carte* get_faction_pioche(faction _faction) {
    return _faction->pioche;
}

/*  @requires   une faction valide
    @assigns    faction
    @ensures    renvoie l'option remelanger */
int get_faction_option_remelanger(faction _faction) {
    return _faction->option_remelanger;
}

/*  @requires   une faction valide
    @assigns    faction
    @ensures    renvoie le nombre de manches gagnées */
int get_faction_manches_gagnees(faction _faction) {
    return _faction->manches_gagnees;
}

/*  @requires   une faction valide et un char
    @assigns    faction
    @ensures    modifie nom de la faction */
void set_faction_nom(faction _faction, char* nom) {
    _faction->nom = nom;
}

/*  @requires   une faction valide et un entier positif ou nul
    @assigns    faction
    @ensures    modifie le nombre de points DDRS de la faction */
void set_faction_nombre_points_DDRS(faction _faction, int nombre_points_DDRS) {
    _faction->nombre_points_DDRS = nombre_points_DDRS;
}

/*  @requires   une faction valide et une pile
    @assigns    faction
    @ensures    modifie la main de la faction */
void set_faction_main(faction _faction, pile main) {
    _faction->main = main;
}

/*  @requires   une faction valide et une pile
    @assigns    faction
    @ensures    modifie la pioche de la faction */
void set_faction_pioche(faction _faction, carte* pioche) {
    _faction->pioche = pioche;
}

/*  @requires   une faction valide et un entier valant 0 ou 1
    @assigns    faction
    @ensures    modifie l'option remelanger de la faction */
void set_faction_option_remelanger(faction _faction, int option_remelanger) {
    _faction->option_remelanger = option_remelanger;
}

/*  @requires   une faction valide et un entier valant 0, 1 ou 2
    @assigns    faction
    @ensures    modifie le nombre de manches gagnées de la faction */
void set_faction_manches_gagnees(faction _faction, int manches_gagnees) {
    _faction->manches_gagnees = manches_gagnees;
}

int test_remelanger(faction _faction){
    if(_faction->option_remelanger == 0){
        _faction->option_remelanger = 1;
        return 1;
    }else{
        return 0;
    }
}

void remelanger(faction _faction){
    vider_main(_faction);
    melanger_pioche(_faction);
    repiocher(_faction);
    set_faction_option_remelanger(_faction, 1);
}


void vider_main(faction _faction){
    /*while(!pile_est_vide(_faction->main)){
        depile(&_faction->main);
    }*/
    _faction->main = NULL;
}


void melanger_pioche(faction _faction){
    _faction->pioche = get_liste_carte();
}


void repiocher(faction _faction){
    int* liste_index = (int*) malloc(NOMBRE_TYPES_CARTES*sizeof(int));
    int size_liste_index = NOMBRE_TYPES_CARTES;
    for(int i = 0; i < NOMBRE_TYPES_CARTES; i++){
        liste_index[i] = i;
    }
    for(int i = 0; i < NOMBRE_CARTES_MAIN_INITIAL; i++){
        int index = liste_index[rand()%size_liste_index];
        if(get_carte_nombre_occurrences(_faction->pioche[index]) <= 0){
            i--;
        }else{
            if(get_carte_nombre_occurrences(_faction->pioche[index]) == 1){
                liste_index[index] = liste_index[size_liste_index-1];
                size_liste_index--;
                if(size_liste_index < 0)
                    break;
            }
            empile(&_faction->main, _faction->pioche[index]);
            set_carte_nombre_occurrences(_faction->pioche[index], get_carte_nombre_occurrences(_faction->pioche[index])-1);
        }
    }
}