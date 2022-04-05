#include "../headers/faction.h"

/* définition de la structure des factions */
struct faction {
    char nom;
    int nombre_points_DDRS;
    pile main; /* type liste défini dans structure.h et structure.c */
    carte* pioche; /* type pile défini dans structure.h et structure.c */
    int option_remelanger; /* 0 si la faction n'a pas encore remélanger et 1 si la fonction a déjà remélanger */
};

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie le nom de la faction */
char get_faction_nom(faction faction) {
    return faction->nom;
}

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie le nombre de points DDRS de la faction */
int get_faction_nombre_points_DDRS(faction faction) {
    return faction->nombre_points_DDRS;
}

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie la main de la faction */
pile get_faction_main(faction faction) {
    return faction->main;
}

/*  @requires   une faction valide
    @assigns    rien
    @ensures    renvoie la pioche de la faction */
pile get_faction_pioche(faction faction) {
    return faction->pioche;
}

/*  @requires   une faction valide et un entier
    @assigns    faction
    @ensures    modifie le nombre de points DDRS de la faction */
void set_faction_nombre_points_DDRS(faction faction, int nombre_points_DDRS) {
    faction->nombre_points_DDRS = nombre_points_DDRS;
}

/*  @requires   une faction valide et une pile
    @assigns    faction
    @ensures    modifie la main de la faction */
void set_faction_main(faction faction, pile main) {
    faction->main = main;
}

/*  @requires   une faction valide et une pile
    @assigns    faction
    @ensures    modifie la pioche de la faction */
void set_faction_pioche(faction faction, pile pioche) {
    faction->pioche = pioche;
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
}


void vider_main(faction _faction){
    while(!pile_est_vide(_faction->main)){
        depile(_faction->main);
    }
}


void melanger_pioche(faction _faction){
    _faction->pioche = get_liste_carte();
}


void repiocher(faction _faction){
    int* liste_index;
    int size_liste_index = NOMBRE_DE_TYPE_DE_CARTE;
    for(int i = 0; i < NOMBRE_DE_TYPE_DE_CARTE; i++){
        liste_index[i] = i;
    }
    for(int i = 0; i < NOMBRE_CARTES_MAIN_INITIAL; i++){
        int index = liste_index[rand()%size_liste_index];
        if(get_carte_nombre_occurrences(_faction->pioche[index]) == 0){
            i--;
        }else{
            if(get_carte_nombre_occurrences(_faction->pioche[index]) == 1){
                liste_index[index] = liste_index[size_liste_index-1];
                size_liste_index--;
                if(size_liste_index < 0)
                    break;
            }
            empile(_faction->main, _faction->pioche[index]);
            set_carte_nombre_occurrences(_faction->pioche[index], get_carte_nombre_occurrences(_faction->pioche[index])-1);
        }
    }
}