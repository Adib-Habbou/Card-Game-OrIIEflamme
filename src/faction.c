/* définition de la structure des factions */
struct faction {
    char nom;
    int nombre_points_DDRS;
    pile main; /* type liste défini dans structure.h */
    pile pioche; /* type pile défini dans structure.h */
};
