#ifndef PLATEAU_H
#define PLATEAU_H

/* importation du module type */
#include "type.h"

#include "carte.h"

/* importation du module faction */
#include "faction.h"

#include <stddef.h>
#include <string.h>


// INTERFACES DES FONCTIONS

/*  @requires   rien
    @assigns    rien
    @ensures    renvoie un nouveau plateau */
plateau init_plateau();

/*  @requires   un plateau valide
    @assigns    plateau
    @ensures    libère la mémoire associée au plateau et à ses deux factions */
void libere_plateau(plateau plateau);

/*  @requires   un plateau valide
    @assigns    rien
    @ensures    renvoie 1 si il initialise une nouvelle manche de jeu
                renvoie 0 si le jeu est terminé */
int init_manche(faction* factions, plateau _plateau);

/*  @requires   rien
    @assigns    rien
    @ensures    initialise la liste avec deux factions en jeu */
faction* liste_faction();

/*  @requires   un plateau, une carte valide et un tableau position = [x, y] contenant les deux coordonnées de la position où on pose la carte
    @assigns    ajoute la carte à la case en position x et y du plateau
    @ensures    pose la carte face cachée sur le plateau */
void poser(plateau plateau, carte carte, int* position);

/*  @requires   un plateau valide et une liste des factions en jeu
    @assigns    change l'état de la carte la plus en haut à gauche du plateau
    @ensures    retourne la carte la plus en haut à gauche face visible et active son effet
                renvoie la carte retournée ou NULL si toutes les cartes du plateau sont déjà face visible */
carte retourner(plateau plateau, faction* liste_faction);


// CONSTANTES ET VARIABLES GLOBALES

/* nombre de lignes et nombres de colonnes d'un plateau */
#define TAILLE_PLATEAU 50

/* nombre de joueurs pour une partie */
#define NOMBRE_JOUEURS 2

/* nombre de manches gagnantes */
#define NOMBRE_MANCHES_GAGNANTES 2

/* nombre des phases d'une manche */
#define NOMBRE_PHASES_MANCHE 2

/* nombre de cartes posées sur le plateau */
#define NOMBRE_CARTES_POSEES 16


// GETTERS ET SETTERS

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie la carte posé sur la case */
carte get_case_carte(Case _case);

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie l'état de la carte posé sur la case */
int get_case_etat(Case _case);

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie la faction qui a posé la carte présente sur la case */
faction get_case_faction(Case _case);

/*  @requires   une case valide et un entier positif ou -1
    @assigns    case
    @ensures    modifie l'état de la carte posé sur la case */
void set_case_etat(Case _case, int etat);

/*  @requires   un plateau valide
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus en haut à gauche du plateau */
int* get_plateau_carte_premier(plateau plateau);

/*  @requires   un plateau valide
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus en bas à droite du plateau  */
int* get_plateau_carte_dernier(plateau plateau);

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie la case de coordonées ligne, colonne sur le plateau */
Case get_plateau_case(plateau plateau, int ligne, int colonne);

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus à gauche  */
int* get_plateau_carte_gauche(plateau plateau, int ligne, int colonne);

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus à droite  */
int* get_plateau_carte_droite(plateau plateau, int ligne, int colonne);

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus en haut  */
int* get_plateau_carte_haut(plateau plateau, int ligne, int colonne);

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie les coodronnées de la carte la plus en bas  */
int* get_plateau_carte_bas(plateau plateau, int ligne, int colonne);

/*  @requires   un plateau valide et deux entiers
    @assigns    rien
    @ensures    renvoie le nom de la carte dans la case */
char* get_plateau_carte_nom(plateau plateau, int ligne, int colonne);

/*  @requires   une case valide
    @assigns    rien
    @ensures    renvoie l'id faction de la case */
int get_case_id_faction(Case _case);

/*  @requires   un plateau valide, deux entiers coordonnées de la case, une carte, l'id faction et l'état 
    @assigns    plateau
    @ensures    modifie la case du plateau */
void set_plateau_case(plateau plateau, int ligne, int colonne, carte carte, int id_faction, int etat);

#endif
