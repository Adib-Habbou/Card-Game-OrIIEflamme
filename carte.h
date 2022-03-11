#ifndef CARTE_H  /* pour éviter des inclusions multiples */
#define CARTE_H

/* définition de la structure des cartes */
typedef struct carte {
    char nom;
    char description;
    int nombre_occurrences;
} carte;

#endif
