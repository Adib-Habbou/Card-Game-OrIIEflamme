#include "../headers/interface.h"

int coefgrille;
int x_plateau;
int y_plateau;

void ClearTextBas(fenetre _fenetre){
    AddRect(_fenetre, HAUTEUR/coefgrille, LARGEUR, 0, HAUTEUR - HAUTEUR/coefgrille, COLOR_DEFAULT);
    Refresh(_fenetre);
}

void UpdateTextBas(fenetre _fenetre,char*msg, int sizefont){
    if(sizefont == 0)
        sizefont = 28;
    ClearTextBas(_fenetre);
    //UpdateText(_fenetre, 1, msg, LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, sizefont, 1, NULL, COLOR_DEFAULT);
    AddTextAuto(_fenetre, msg, LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, CENTRED, NULL, COLORWHITE);
    Refresh(_fenetre);
}

void AddCarte(fenetre _fenetre, int ligne, int colonne, SDL_Color color){
    int h = (HAUTEUR/coefgrille)*0.75;
    int w = (LARGEUR/coefgrille)*0.5;
    AddRect(_fenetre, h, w, (LARGEUR/coefgrille) * (ligne+1 - x_plateau) + (LARGEUR/coefgrille)/2 - w/2,  (HAUTEUR/coefgrille) * (colonne+1 - y_plateau) + (HAUTEUR/coefgrille)/2 - h/2, color);
}

void affiche_partie_plateau(fenetre _fenetre, plateau _plateau){
    ClearAll(_fenetre);
    if(x_plateau > TAILLE_PLATEAU - TAILLE_PLATEAU_MAX){
        x_plateau = TAILLE_PLATEAU - TAILLE_PLATEAU_MAX;
    }
    if(y_plateau > TAILLE_PLATEAU - TAILLE_PLATEAU_MAX){
        y_plateau = TAILLE_PLATEAU - TAILLE_PLATEAU_MAX;
    }
    if(x_plateau < 0){
        x_plateau = 0;
    }
    if(y_plateau < 0){
        y_plateau = 0;
    }
    //printf("affiche plateau x= %i et y = %i\n", x_plateau, y_plateau);
    AddGrille(_fenetre, TAILLE_PLATEAU_MAX, COLOR_DEFAULT);
    for(int i = x_plateau; i < TAILLE_PLATEAU_MAX + x_plateau; i++){
        for(int j = y_plateau; j < TAILLE_PLATEAU_MAX + y_plateau; j++){
            //printf("%i, %i\n", i, j);
            if(get_case_carte(get_plateau_case(_plateau,i,j)) != NULL){
                //printf("carte trouvé\n");
                if(get_case_etat(get_plateau_case(_plateau, i, j)) == 0){ 
                    //printf("carte trouvé\n");
                    AddCarte(_fenetre, i, j, COLOR_DEFAULT);
                }else{
                    AddCarte(_fenetre, i, j, COLORGREEN);
                }
            }
        }
    }
    AddText(_fenetre, "Oriieflamme",HAUTEUR/coefgrille,LARGEUR/4, LARGEUR/2, CENTRED, DEFAULT_FONTSIZE, 1,"Fonts/MySoul-Regular.ttf", COLORWHITE);
    Refresh(_fenetre);
}

void affiche_plateau(fenetre _fenetre, plateau _plateau){
    coefgrille = TAILLE_PLATEAU_MAX+2;
    x_plateau = TAILLE_PLATEAU/2 - TAILLE_PLATEAU_MAX/2;
    y_plateau = TAILLE_PLATEAU/2 - TAILLE_PLATEAU_MAX/2;
    affiche_partie_plateau(_fenetre, _plateau);
}

void affiche_plateau_sur_position(fenetre _fenetre, plateau _plateau, int* position){
    ClearAll(_fenetre);
    x_plateau = position[0] - TAILLE_PLATEAU_MAX/2;
    y_plateau = position[1] - TAILLE_PLATEAU_MAX/2;
    affiche_partie_plateau(_fenetre, _plateau);
}


int GestionnaireEventEnter(fenetre _fenetre, plateau _plateau){    
    SDL_bool program_launched = SDL_TRUE;
    while(program_launched){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_RETURN2){
                        return 0;
                    }else if(event.key.keysym.sym == SDLK_z){
                        y_plateau--;
                        affiche_partie_plateau(_fenetre, _plateau);
                        return 1;
                    }else if(event.key.keysym.sym == SDLK_d){
                        x_plateau++;
                        affiche_partie_plateau(_fenetre,_plateau);
                        return 1;
                    }else if(event.key.keysym.sym == SDLK_q){
                        x_plateau--;
                        affiche_partie_plateau(_fenetre,_plateau);
                        return 1;
                    }else if(event.key.keysym.sym == SDLK_s){
                        y_plateau++;
                        affiche_partie_plateau(_fenetre,_plateau);
                        return 1;
                    }else if(event.key.keysym.sym == SDLK_ESCAPE){
                        program_launched = SDL_FALSE;
                    }else{
                        //AddTextAuto(_fenetre, "Aurevoir", LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, CENTRED, NULL, COLORWHITE);
                    }
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
    return 0;
}

void affiche_main(fenetre _fenetre, faction _faction, plateau _plateau){
    // on vérifie que la pile n'est pas vide
    if( get_faction_main(_faction)==NULL ){
        printf("La main est vide.\n");
        return;
    }
    do{
    pile buffer_main = get_faction_main(_faction);
    int taille = taille_pile(buffer_main);
    for(int i = 0; i < taille; i++){
        AddRect(_fenetre, HAUTEUR/coefgrille, LARGEUR/(taille+1), i * (LARGEUR/taille), HAUTEUR-(HAUTEUR/coefgrille), COLORALICEBLUE);
        //AddText(_fenetre, get_carte_nom(pile_sommet(buffer_main)),HAUTEUR/coefgrille,(LARGEUR/taille), i * (LARGEUR/taille), HAUTEUR-(HAUTEUR/coefgrille), 11, LEFTUP, NULL, COLORBLACK);
        AddTextAuto(_fenetre, get_carte_nom(pile_sommet(buffer_main)), i * (LARGEUR/taille), HAUTEUR-(HAUTEUR/coefgrille), 11, LEFTUP, NULL, COLORBLACK);
        depile(&buffer_main);
    }
    Refresh(_fenetre);
    }while(GestionnaireEventEnter(_fenetre, _plateau));
}

int GestionnaireEventLeftRight(SDL_Keycode code,fenetre _fenetre){
    switch (code)
    {
        case SDLK_LEFT:
            printf("Appuyer sur left\n");
            ClearTextBas(_fenetre);
            return 1;
            break;

        case SDLK_RIGHT:
            printf("Appuyer sur right\n");
            ClearTextBas(_fenetre);
            return 2;
            break;
        default:
            printf("Appuyer sur autre chose\n");
            //UpdateTextBas(_fenetre, "Utiliser les fléches directionnelles", DEFAULT_FONTSIZE);
            return 0;
            break;
    }
}

void AffichageDecision(fenetre _fenetre, char* question, char* decision1, char* decision2){
    AddRect(_fenetre, HAUTEUR/coefgrille, LARGEUR, 0, HAUTEUR - HAUTEUR/coefgrille, COLOR_DEFAULT);
    AddTextAuto(_fenetre, question, LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, CENTRED, NULL, COLORWHITE);
    AddTextAuto(_fenetre, decision1, 10, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, 0, NULL, COLORWHITE);
    AddTextAuto(_fenetre, decision2, LARGEUR-50, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, CENTRED, NULL, COLORWHITE);
    AddImage(_fenetre, "image/arrowleft.bmp", LARGEUR/10, HAUTEUR - HAUTEUR/coefgrille-5);
    AddImage(_fenetre, "image/arrowright.bmp", LARGEUR - 2*LARGEUR/10, HAUTEUR - HAUTEUR/coefgrille-5);
    Refresh(_fenetre);
}

int decision(fenetre _fenetre) {
    AffichageDecision(_fenetre, "Voulez-vous remelanger votre main ?", "NON", "OUI");
    return (GestionnaireEvent(_fenetre, GestionnaireEventLeftRight) - 1);
}

int GestionnaireEventNumero(SDL_Keycode code,fenetre _fenetre){
    if(code == SDLK_1 || code == SDLK_KP_1){
        printf("Appuyer sur 1\n");
        ClearTextBas(_fenetre);
        return 1;
    }else if(code == SDLK_2 || code == SDLK_KP_2){
        printf("Appuyer sur 2\n");
        ClearTextBas(_fenetre);
        return 2;
    }else if(code == SDLK_3 || code == SDLK_KP_3){
        printf("Appuyer sur 3\n");
        ClearTextBas(_fenetre);
        return 3;
    }else if(code == SDLK_4 || code == SDLK_KP_4){
        printf("Appuyer sur 4\n");
        ClearTextBas(_fenetre);
        return 4;
    }else if(code == SDLK_5 || code == SDLK_KP_5){
        printf("Appuyer sur 5\n");
        ClearTextBas(_fenetre);
        return 5;
    }else if(code == SDLK_6 || code == SDLK_KP_6){
        printf("Appuyer sur 6\n");
        ClearTextBas(_fenetre);
        return 6;
    }else if(code == SDLK_7 || code == SDLK_KP_7){
        printf("Appuyer sur 7\n");
        ClearTextBas(_fenetre);
        return 7;
    }else if(code == SDLK_8 || code == SDLK_KP_8){
        printf("Appuyer sur 8\n");
        ClearTextBas(_fenetre);
        return 8;
    }else{
        printf("appuyer sur la mauvaise touche\n");
        return 0;
    }
}

carte carte_choisie(fenetre _fenetre, faction _faction){
    int index = GestionnaireEvent(_fenetre, GestionnaireEventNumero);
    if(index == -1){
        perror("EXIT\n");
        exit(0);
    }
    pile buffer_main = get_faction_main(_faction);
    pile newmain = pile_vide();
    carte _cartechoisie;
    int taille = taille_pile(buffer_main);
    for(int i = 1; i <= taille; i++){
        if(i == index){
            _cartechoisie = pile_sommet(buffer_main);
        }else{
            empile(&newmain, pile_sommet(buffer_main));
        }
        depile(&buffer_main);
    }
    set_faction_main(_faction, newmain);
    AddTextAuto(_fenetre, get_carte_nom(_cartechoisie), LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, 1, NULL, COLORWHITE);
    return _cartechoisie;
}

int mem_pile(wpile _wpile, int* _element){
    while (!wpile_est_vide(_wpile))
    {
        int* position = wdepile(&_wpile);
        if(_element[0] == position[0] && _element[1] == position[1]){
            return 1;
        }
    }
    return 0;
}

void affiche_list(listD l){
    for(int i = 0; i < taille_listD(l); i++){
        int* pos = (int*) get(l, i);
        printf("[%i, %i] -> ", pos[0], pos[1]);
    }
    printf("NULL\n");
}

int* carte_positon(fenetre _fenetre, plateau _plateau){
    AddTextAuto(_fenetre,"Ou souhaitez-vous poser votre carte ?", LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, 1, NULL, COLORWHITE);
    if(get_case_carte(get_plateau_case(_plateau, TAILLE_PLATEAU/2, TAILLE_PLATEAU/2)) == NULL){
        //printf("carte NULL\n");
        int* position = (int*) malloc(2*sizeof(int));
        position[0] = TAILLE_PLATEAU/2;
        position[1] = TAILLE_PLATEAU/2;
        return position;
    }else{
        wpile buffer_a_voir = wpile_vide();
        wpile buffer_vu = wpile_vide();
        listD position_disponible = listD_vide();
        int pos0[2] = { TAILLE_PLATEAU/2 , TAILLE_PLATEAU/2};
        int pos1[2] = { TAILLE_PLATEAU/2 + 1, TAILLE_PLATEAU/2 };
        int pos2[2] = { TAILLE_PLATEAU/2 , TAILLE_PLATEAU/2 + 1};
        int pos3[2] = { TAILLE_PLATEAU/2 - 1, TAILLE_PLATEAU/2};
        int pos4[2] = { TAILLE_PLATEAU/2 , TAILLE_PLATEAU/2 - 1};
        wempile_multiple(&buffer_a_voir, 4, pos1, pos2, pos3, pos4);
        wempile(&buffer_vu, pos0);
        while (!wpile_est_vide(buffer_a_voir))
        {
            int* newpos = (int*) wdepile(&buffer_a_voir);
            int* pos = (int*) malloc(2*sizeof(int));
            pos[0] = newpos[0];
            pos[1] = newpos[1];
            //printf("position à voir x= %i et y = %i\n", pos[0], pos[1]);
            if(get_case_carte(get_plateau_case(_plateau, pos[0], pos[1])) != NULL){
                //printf("carte trouvé ");
                if(!mem_pile(buffer_vu, pos)){
                    //printf("inconnue ajoute à la pile des vus");
                    wempile(&buffer_vu, pos);
                    int* pos1 = (int*) malloc(2*sizeof(int));
                    int* pos2 = (int*) malloc(2*sizeof(int));
                    int* pos3 = (int*) malloc(2*sizeof(int));
                    int* pos4 = (int*) malloc(2*sizeof(int));
                    pos1[0] = newpos[0] + 1;
                    pos1[1] = newpos[1];
                    pos2[0] = newpos[0];
                    pos2[1] = newpos[1] + 1;
                    pos3[0] = newpos[0] - 1;
                    pos3[1] = newpos[1];
                    pos4[0] = newpos[0];
                    pos4[1] = newpos[1] - 1;
                    wempile_multiple(&buffer_a_voir, 4, pos1, pos2, pos3, pos4);
                }
                //printf("\n");
            }else{
                //printf("aucune carte\n");
                if(!mem_pile(buffer_vu, pos)){
                    wempile(&buffer_vu, pos);
                    add_list(&position_disponible, pos);
                    //affiche_list(position_disponible);
                }
            }
        }
        //printf("taille positions dispo : %i\n", taille_listD(position_disponible));
        if(taille_listD(position_disponible) <= 0){
            printf("pas de position disponible\n");
            exit(1);
        }
        int index = 0;
        int* actual_pos = (int*) get(position_disponible, index);
        affiche_plateau_sur_position(_fenetre, _plateau, actual_pos);
        AddCarte(_fenetre, actual_pos[0], actual_pos[1], COLORRED);
        AffichageDecision(_fenetre, "Confirmer ?", "NON", "OUI");
        int confirm = GestionnaireEvent(_fenetre, GestionnaireEventLeftRight) - 1;
        int move = GestionnaireEvent(_fenetre, GestionnaireEventLeftRight) - 1;
        while(confirm != 1){
            if(move == 1){
                index--;
                if(index < 0){
                    index = taille_listD(position_disponible)-1;
                }
                //AddCarte(_fenetre, actual_pos[0], actual_pos[1], COLORBLACK);
                actual_pos = (int*) get(position_disponible, index);
                affiche_plateau_sur_position(_fenetre, _plateau, actual_pos);
                AddCarte(_fenetre, actual_pos[0], actual_pos[1], COLORRED);
            }else if(move == 0){
                index++;
                if(index >= taille_listD(position_disponible)){
                    index = 0;
                }
                //AddCarte(_fenetre, actual_pos[0], actual_pos[1], COLORBLACK);
                actual_pos = (int*) get(position_disponible, index);
                affiche_plateau_sur_position(_fenetre, _plateau, actual_pos);
                AddCarte(_fenetre, actual_pos[0], actual_pos[1], COLORRED);
            }
            AffichageDecision(_fenetre, "Confirmer ?", "NON", "OUI");
            confirm = GestionnaireEvent(_fenetre, GestionnaireEventLeftRight) - 1;
            move = GestionnaireEvent(_fenetre, GestionnaireEventLeftRight) - 1;
        }
        return actual_pos;
    }
}

void afficher_effet(fenetre _fenetre, carte _carte, plateau _plateau){
    char* effet = get_carte_description(_carte);
    AddTextAuto(_fenetre,effet, LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, CENTRED, NULL, COLORWHITE);
    Refresh(_fenetre);
    GestionnaireEventEnter(_fenetre, _plateau);
}

void gagnant(fenetre _fenetre, faction* factions, plateau _plateau){
    if (get_faction_nombre_points_DDRS(factions[0]) > get_faction_nombre_points_DDRS(factions[1])) {
        char* nom_gagnant = get_faction_nom(factions[0]);
        AddTextAuto(_fenetre,nom_gagnant, LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, CENTRED, NULL, COLORWHITE);
        Refresh(_fenetre);
        GestionnaireEventEnter(_fenetre, _plateau);
    }
    else {
        char* nom_gagnant = get_faction_nom(factions[1]);
        AddTextAuto(_fenetre,nom_gagnant, LARGEUR/2, HAUTEUR - HAUTEUR/coefgrille, DEFAULT_FONTSIZE, CENTRED, NULL, COLORWHITE);
        Refresh(_fenetre);
        GestionnaireEventEnter(_fenetre, _plateau);
    }
}