#ifndef SDL_H
#define SDL_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

#define HAUTEUR 600
#define LARGEUR 800
#define INITIALE_CAPACITE_DE_TEXT 5


#define DEFAULT_FONTSIZE 28


#define LEFTUP 0
#define CENTRED 1


#define COLORWHITE ((SDL_Color) {255,255,255,SDL_ALPHA_OPAQUE})
#define COLORALICEBLUE ((SDL_Color) {240,248,255,SDL_ALPHA_OPAQUE})
#define COLORRED ((SDL_Color) {255,0,0,SDL_ALPHA_OPAQUE})
#define COLORGREEN ((SDL_Color) {0,255,0,SDL_ALPHA_OPAQUE})
#define COLORBLUE ((SDL_Color) {0,0,255,SDL_ALPHA_OPAQUE})
#define COLORBLACK ((SDL_Color) {0,0,0,SDL_ALPHA_OPAQUE})

#define COLOR_DEFAULT COLORBLUE

typedef struct text* text;

typedef struct fenetre *fenetre;

void OpenFenetre(char* nom, fenetre _fenetre);

void CloseFenetre(fenetre _fenetre);

void AddGrille(fenetre _fenetre, int taille, SDL_Color color);

void AddRect(fenetre _fenetre, int hauteur, int largeur, int x, int y, SDL_Color color);

void AddText(fenetre _fenetre, char* msg, int hauteur, int largeur, int x, int y, int sizefont, int centred, char* font_path, SDL_Color color);

void AddTextAuto(fenetre _fenetre, char* msg, int x, int y, int sizefont, int centred, char* font_path, SDL_Color color);

//void UpdateText(fenetre _fenetre,int idtext, char*msg, int x, int y, int sizefont, int centred, char* font_path, SDL_Color color);

void Refresh(fenetre _fenetre);

void ClearAll(fenetre _fenetre);

void AddImage(fenetre _fenetre,char* image_path, int x, int y);

int GestionnaireEvent(fenetre _fenetre, int (*f)(SDL_Keycode, fenetre));

void Donothing(fenetre _fenetre);

#endif