#include "../headers/sdl.h"

struct text{
    SDL_Texture* textTexture;
    SDL_Rect* textRect;
};

struct fenetre{
    SDL_Window* window;
    SDL_Renderer* renderer;
    /*text* liste_text;
    int nombre_text;
    int sizemax_liste_text;*/
};

int GRILLECOEF;
SDL_Color current_color;

void SDL_ExitWithError(const char* s){
    SDL_Log("ERROR : %s", s);
    exit(EXIT_FAILURE);
}

void SDL_SetRenderDrawColor2(fenetre _fenetre, SDL_Color color){
    if(current_color.r != color.r ||current_color.g != color.g || current_color.b != color.b  || current_color.a != color.a ){
        if(SDL_SetRenderDrawColor(_fenetre->renderer, color.r, color.g, color.b, color.a) != 0)
            SDL_ExitWithError("Impossible de changer la couleur pour le rendu");
        current_color = color;
    }
}

void freetext(text t){
    free(t->textRect);
    free(t->textTexture);
}

/*void AddTextFenetre(fenetre _fenetre, text t){
    if(_fenetre->nombre_text >= _fenetre->sizemax_liste_text){
        text* listetext = (text*) malloc((_fenetre->nombre_text + 5)*sizeof(text));
        for(int i = 0; i < _fenetre->nombre_text; i++){
            listetext[i] = _fenetre->liste_text[i];
        }
        for(int i = 0; i < _fenetre->nombre_text; i++){
            free(_fenetre->liste_text[i]);
        }
        _fenetre->liste_text = listetext;
        _fenetre->sizemax_liste_text = _fenetre->nombre_text + 5;
    }
    _fenetre->liste_text[_fenetre->nombre_text] = t;
    _fenetre->nombre_text++;
}*/

void OpenFenetre(char* nom, fenetre _fenetre){

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");

    if(TTF_Init() != 0)
        SDL_ExitWithError("Initialisation TTF");

    if(SDL_CreateWindowAndRenderer(LARGEUR, HAUTEUR, 0, &_fenetre->window, &_fenetre->renderer) != 0)
        SDL_ExitWithError("Impossible de créer la fenetre et le rendu");
    
    SDL_SetWindowTitle(_fenetre->window, nom);
    
    /*_fenetre->liste_text = (text*) malloc(INITIALE_CAPACITE_DE_TEXT*sizeof(text));
    _fenetre->nombre_text = 0;
    _fenetre->sizemax_liste_text = INITIALE_CAPACITE_DE_TEXT;*/

    SDL_SetRenderDrawColor2(_fenetre, COLORBLUE);
}

void CloseFenetre(fenetre _fenetre){
    SDL_DestroyRenderer(_fenetre->renderer);
    SDL_DestroyWindow(_fenetre->window);
    TTF_Quit();
    SDL_Quit();
}

void AddRect(fenetre _fenetre, int hauteur, int largeur, int x, int y, SDL_Color color){
    SDL_SetRenderDrawColor2(_fenetre, color);
    SDL_Rect rectangle;
    rectangle.h = hauteur;
    rectangle.w = largeur;
    rectangle.x = x;
    rectangle.y = y;
    if(SDL_RenderFillRect(_fenetre->renderer, &rectangle) != 0)
        SDL_ExitWithError("Impossible de dessiner le rectangle");
}

void AddGrille(fenetre _fenetre, int taille, SDL_Color color){
    SDL_SetRenderDrawColor2(_fenetre, color);
    GRILLECOEF = taille+2;
    for(int i = 1; i < GRILLECOEF; i++){
        if(SDL_RenderDrawLine(_fenetre->renderer,i*(LARGEUR/GRILLECOEF), 0, i*(LARGEUR/GRILLECOEF), HAUTEUR) != 0)
            SDL_ExitWithError("Imposisble de dessiner une ligne");

        if(SDL_RenderDrawLine(_fenetre->renderer, 0, i*(HAUTEUR/GRILLECOEF), LARGEUR, i*(HAUTEUR/GRILLECOEF)) != 0)
            SDL_ExitWithError("Imposisble de dessiner une ligne");
    }
    AddRect(_fenetre, HAUTEUR/GRILLECOEF, LARGEUR, 0, 0, color);
    AddRect(_fenetre, HAUTEUR/GRILLECOEF, LARGEUR, 0, HAUTEUR - HAUTEUR/GRILLECOEF, color);
    AddRect(_fenetre, HAUTEUR, LARGEUR/GRILLECOEF, 0, 0, color);
    AddRect(_fenetre, HAUTEUR, LARGEUR/GRILLECOEF, LARGEUR - LARGEUR/GRILLECOEF, 0, color);
    Refresh(_fenetre);
}

void AddText(fenetre _fenetre, char* msg, int hauteur, int largeur, int x, int y, int sizefont, int centred, char* font_path, SDL_Color color){
    if(font_path == NULL)
        font_path = "Fonts/Roboto-Medium.ttf";
    text t = (text) malloc(sizeof(text));
    TTF_Font* font = TTF_OpenFont(font_path, sizefont);
    SDL_Surface* textSurf = TTF_RenderText_Blended(font, msg, color);
    t->textTexture = SDL_CreateTextureFromSurface(_fenetre->renderer, textSurf);

    SDL_Rect* rect = (SDL_Rect*) malloc(sizeof(SDL_Rect*)); 
    rect->x = x - centred*largeur/2;
    rect->y = y;
    rect->w = largeur;
    rect->h = hauteur;
    t->textRect = rect;
    //AddTextFenetre(_fenetre, t);
    SDL_FreeSurface(textSurf);
    TTF_CloseFont(font);
    SDL_RenderCopy(_fenetre->renderer, t->textTexture, NULL, t->textRect);
}

void AddTextAuto(fenetre _fenetre, char* msg, int x, int y, int sizefont, int centred, char* font_path, SDL_Color color){
        if(font_path == NULL)
        font_path = "Fonts/Roboto-Medium.ttf";
    text t = (text) malloc(sizeof(text));
    TTF_Font* font = TTF_OpenFont(font_path, sizefont);
    SDL_Surface* textSurf = TTF_RenderText_Blended(font, msg, color);
    t->textTexture = SDL_CreateTextureFromSurface(_fenetre->renderer, textSurf);

    SDL_Rect* rect = (SDL_Rect*) malloc(sizeof(SDL_Rect*)); 
    rect->x = x - centred*(textSurf->w)/2;
    rect->y = y;
    rect->w = textSurf->w;
    rect->h = textSurf->h;
    t->textRect = rect;
    //AddTextFenetre(_fenetre, t);
    SDL_FreeSurface(textSurf);
    TTF_CloseFont(font);
    SDL_RenderCopy(_fenetre->renderer, t->textTexture, NULL, t->textRect);
}

/*void UpdateText(fenetre _fenetre,int idtext, char*msg, int x, int y, int sizefont, int centred, char* font_path, SDL_Color color){
    if(font_path == NULL)
        font_path = "Fonts/Roboto-Medium.ttf";
    TTF_Font* font = TTF_OpenFont(font_path, sizefont);
    SDL_Surface* textSurf = TTF_RenderText_Blended(font, msg, color);
    _fenetre->liste_text[idtext]->textTexture = SDL_CreateTextureFromSurface(_fenetre->renderer, textSurf);

    SDL_Rect* rect = (SDL_Rect*) malloc(sizeof(SDL_Rect*)); 
    rect->x = x - centred*(textSurf->w)/2;
    rect->y = y;
    rect->w = textSurf->w;
    rect->h = textSurf->h;
    _fenetre->liste_text[idtext]->textRect = rect;
    SDL_FreeSurface(textSurf);
    TTF_CloseFont(font);
    SDL_RenderCopy(_fenetre->renderer, _fenetre->liste_text[idtext]->textTexture, NULL, _fenetre->liste_text[idtext]->textRect);
}*/

void AddImage(fenetre _fenetre,char* image_path, int x, int y){
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;

    image = SDL_LoadBMP(image_path);

    if(image == NULL)
        SDL_ExitWithError("Impossible de charger l'image");
    
    texture = SDL_CreateTextureFromSurface(_fenetre->renderer, image);
    SDL_FreeSurface(image);

    if(texture == NULL)
        SDL_ExitWithError("Impossible de charger la texture");
    
    SDL_Rect rectangle;

    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0)
        SDL_ExitWithError("Impossible de creer la texture");
    
    rectangle.x = x;
    rectangle.y = y;

    if(SDL_RenderCopy(_fenetre->renderer, texture, NULL, &rectangle) != 0)
        SDL_ExitWithError("Impossible d'afficher la texture");
}

void Refresh(fenetre _fenetre){
    SDL_RenderPresent(_fenetre->renderer);
}

void ClearAll(fenetre _fenetre){
    SDL_SetRenderDrawColor2(_fenetre, COLORBLACK);
    SDL_RenderClear(_fenetre->renderer);
    SDL_SetRenderDrawColor2(_fenetre, COLOR_DEFAULT);
}

int GestionnaireEvent(fenetre _fenetre, int (*f)(SDL_Keycode, fenetre)){
    SDL_bool program_launched = SDL_TRUE;
    while(program_launched){
        SDL_Event event;
        int i;
        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        perror("EXIT\n");
                        exit(0);
                    }
                    i = (*f)(event.key.keysym.sym, _fenetre);
                    if(i != 0)
                        return i;
                    break;
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;
                default:
                    break;
            }
        }
    }
    perror("EXIT\n");
    exit(0);
    return -1;
}