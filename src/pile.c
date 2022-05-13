
#include "../headers/pile.h"

struct maillon {
    element sommet; // la valeur du premier maillon représente le sommet de la wpile
    struct maillon *suivant;
};


wpile wpile_vide() {
    return NULL;
}

int wpile_est_vide(wpile wpile) {
    return wpile == NULL;
}

element wpile_sommet(wpile wpile) {
    return wpile->sommet;
}

wpile wpile_suivant(wpile wpile) {
    return wpile->suivant;
}

void wempile(wpile* _wpile, element _element) {
    wpile res = malloc(sizeof(wpile));

    res->sommet = _element;
    res->suivant = *_wpile;
    *_wpile = res;
}

void wempile_multiple(wpile* _wpile,int nb, ...){
    va_list args;
    va_start(args, nb);
    for(int i = 0; i < nb; i++){
        wempile(_wpile, (element) va_arg(args, element));
    }
    va_end(args);
}

element wdepile(wpile* _wpile) {
    if (wpile_est_vide(*_wpile)) {
        exit(1);
    }
    element e = (*_wpile)->sommet;
    *_wpile = (*_wpile)->suivant;
    return e;
}

int taille_wpile(wpile wpile) {
    int taille = 0;
    while(!wpile_est_vide(wpile)) {
        taille += 1;
        wpile = wpile_suivant(wpile);
    }
    return taille;
}

void affiche_wpile(wpile _wpile){
    while (!wpile_est_vide(_wpile))
    {
        printf("[%p]->", wdepile(&_wpile));
    }
    printf("NULL\n");
}

int mem_wpile(wpile _wpile, element _element){
    while (!wpile_est_vide(_wpile))
    {
        if(_element == wdepile(&_wpile)){
            return 1;
        }
    }
    return 0;
}