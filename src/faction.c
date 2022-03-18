/* définition de la structure des factions */
typedef struct faction {
    char nom;
    int nombre_points_DDRS;
    liste main; /* type liste défini dans structure.h */
    pile pioche; /* type pile défini dans structure.h */
} faction;
