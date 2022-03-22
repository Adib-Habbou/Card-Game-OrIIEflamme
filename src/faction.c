/* importation du module faction */
#include "../headers/faction.h"

/* importation du module structure */
#include "../headers/structure.h"

/* définition de la structure des factions */
struct faction {
    char nom;
    int nombre_points_DDRS;
    pile main; /* type liste défini dans structure.h et structure.c */
    pile pioche; /* type pile défini dans structure.h et structure.c */
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
