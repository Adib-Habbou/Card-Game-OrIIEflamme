/* importation du module plateau */
#include "../headers/interface.h"



/* 
@requires rien
@assigns rien
@ensures Affiche le plateau de jeu dans son état actuel
*/
void affiche_plateau(plateau _plateau) {
    int i,j;
    char* dot = ".";
    char* card = "X";
    for (i=0;i<TAILLE_PLATEAU;i++) { //on ajoute 1 à la taille pour pouvoir afficher les coordonnées
        
        for (j=0;j<TAILLE_PLATEAU;j++){

            if (i==0) { // on est à la première ligne donc on affiche le quadrillage des colonnes
                printf("%3d",j);
            }
            
            else {
                if (j==0){
                    printf("%3d",i); //quadrillage des lignes
                }
                else {
                    if (get_plateau_case(_plateau,i,j)!=NULL) {
                        printf("%3s",dot);
                    }
                    else{
                        printf("%3s",card);
                    }
                }
            }
            
        }
        printf("\n");

    }
}

/* 
@requires rien
@assigns rien
@ensures Affiche la main actuel de la faction
*/
void affiche_main(faction _faction) {
    // on vérifie que la pile n'est pas vide
    if( get_faction_main(_faction)==NULL ){
        printf("La main est vide.\n");
        return;
    }
    // tant que la pile est non vide on affiche le nom de la carte

    pile buffer_main = get_faction_main(_faction); 
    int i = 1;
    while(buffer_main != NULL ) {
       
        printf("-> %d [ %s ] ", i, get_carte_nom(pile_sommet(buffer_main)) );
        i++;
        buffer_main=pile_suivant(buffer_main);
    }

    // on affiche un saut de ligne par soucis esthétique
    printf("\n");
}


/* 
@requires rien
@assigns rien
@ensures retourne 1 si la faction décide de remélanger sa main, retourne 0 sinon
*/
int decision() {
    int decision;
    printf("Voulez-vous remélanger votre main ? [1]Oui [0]Non\n");
    scanf("%d",&decision);

    //vérification de la cohérence de la réponse de l'utilisateur
    while ((decision!=1) && (decision!=0)) {
        printf("Veuillez entrer 1 pour Oui, 0 pour Non\n");
        printf("Voulez-vous remélanger votre main ? [1]Oui [0]Non\n");
        scanf("%d",&decision);
    }
    return decision;
  
} 

/* 
@requires cartes valides
@assigns rien
@ensures retourne la carte qui va être posée
*/
carte carte_choisie(faction _faction){
    int result;

    debut_demande :

        printf("Quelle carte voulez vous poser ? Entrer le numéro de la carte :\n");
        scanf("%d",&result);

        pile buffer_main = get_faction_main(_faction); 
        int indice = 0;


        while(buffer_main != NULL && indice != result ) {
            buffer_main=pile_suivant(buffer_main);
            indice++;
        }
        if (buffer_main == NULL && indice != result ) {
            printf("Erreur : vous avez entré une carte qui n'est pas dans la main, veuillez réessayer :\n");
            goto debut_demande;
        }

    
    return pile_sommet(buffer_main);
} 

/* 
@requires plateau valide
@assigns rien
@ensures retourne le couple (x,y) les coordonnées de la position de la carte que l'on pose
*/
int* carte_positon(plateau _plateau) {
    int* position = (int*) malloc(2*sizeof(int));
    printf("Où souhaitez-vous poser votre carte ?\n");
    printf("ligne :\n");
    scanf("%d",&position[0]);
    printf("colonne :\n");
    scanf("%d",&position[1]);

    int ligne = position[0];
    int colonne = position[1];

    //vérification si plateau est vide
    int drapeau_plateau_vide=1;
    int i,j;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_etat(get_plateau_case(_plateau,i,j)) == 1) {
                drapeau_plateau_vide=0;  
            }
        }
    }

    //si c'est la première carte, on la place au milieu
    if (drapeau_plateau_vide) {
        position[0]=TAILLE_PLATEAU/2;
        position[1]=TAILLE_PLATEAU/2;
        return position;
    }
    //vérification de la validité de la position : y a-t-il une carte adjacente ?
    else if ( (get_plateau_case(_plateau,ligne-1,colonne) != NULL) || (get_plateau_case(_plateau,ligne,colonne-1) != NULL) || (get_plateau_case(_plateau,ligne+1,colonne) != NULL) || (get_plateau_case(_plateau,ligne,colonne+1) != NULL)) {
        return position;
    }
    else {
        printf("Position invalide, veuillez placer la carte à côté d'une carte présente sur le plateau");
        exit(0);
    }
    free(position);
}

/* 
@requires carte valide
@assigns rien
@ensures affiche les effets de la carte
*/
void afficher_effet(carte _carte) {
    char* effet = get_carte_description(_carte);
    printf("Cette carte a pour effet : %s", effet);
}

/* 
@requires liste faction valide
@assigns rien
@ensures retourne la faction gagnante selon les règles
*/
void gagnant(faction* factions) {
    if (get_faction_nombre_points_DDRS(factions[0]) > get_faction_nombre_points_DDRS(factions[1])) {
        char* nom_gagnant = get_faction_nom(factions[0]);
        printf(" Félicitation %s ! Vous avez gagné la partie ! \n",nom_gagnant);
    }
    else {
        char* nom_gagnant = get_faction_nom(factions[1]);
        printf(" Félicitation %s ! Vous avez gagné la partie ! \n",nom_gagnant);
    }
}

/* 
@requires rien
@assigns rien
@ensures affiche string sur l'écran
*/
void affiche(char* string) {
    printf("%s\n",string);
}

