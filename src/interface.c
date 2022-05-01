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
                    if (get_case_etat(get_plateau_case(_plateau,i,j)) == -1) {
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
void affiche_main(faction _faction,int factionid) {
    // on vérifie que la pile n'est pas vide
    if( pile_est_vide(get_faction_main(_faction))){
        printf("La main est vide.\n");
        return;
    }
    // tant que la pile est non vide on affiche le nom de la carte
    printf("Joueur %d\n",factionid);
    pile buffer_main = get_faction_main(_faction); 
    int i = 1;
    while(!pile_est_vide(buffer_main) ) {
       
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
@assigns la main de la faction
@ensures retourne la carte qui va être posée
*/
carte carte_choisie(faction _faction){
    int choix;
    pile mainF = pile_vide(); //la main qui va refresh la main de la faction
    carte resultat = NULL; //la carte que l'on va retourner
    int taille_main = taille_pile(get_faction_main(_faction));

    debut_demande :

        printf("Quelle carte voulez vous poser ? Entrer le numéro de la carte :\n");
        scanf("%d",&choix);

        pile buffer_main = get_faction_main(_faction);
        int indice = 1;

        if ( choix > taille_main || choix < 1) {
            printf("Erreur : vous avez entré une carte qui n'est pas dans la main, veuillez réessayer :\n");
            goto debut_demande;
        }
        
        while( !pile_est_vide(buffer_main) ) {
            if (indice == choix) { //on est bien à l'indice
                resultat = pile_sommet(buffer_main); 
            }
            else{ // sinon on empile dans la main comme ça on ne rajoute pas la carte à poser
                empile(&mainF, pile_sommet(buffer_main));
            }
            buffer_main=pile_suivant(buffer_main);
            indice++;
        }
        

        
        
    set_faction_main(_faction,mainF); //on a bien enlevé la carte et on refresh la main de la faction
    return resultat;
}


/* 
@requires plateau valide
@assigns rien
@ensures retourne le couple (x,y) les coordonnées de la position de la carte que l'on pose et la faction qui a posé la carte
*/
int* carte_positon(plateau _plateau,int _factionid) {
    int* position;

    position = malloc(3*sizeof(int));
    position[2] = _factionid; //on set l'id de la faction qui pose la carte

    //vérification si plateau est vide
    int drapeau_plateau_vide=1;
    int i,j;
    for (i=0;i<TAILLE_PLATEAU;i++) {  //plateau de taille TAILLE_PLATEAU
        for (j=0;j<TAILLE_PLATEAU;j++) {  
            if (get_case_carte(get_plateau_case(_plateau,i,j)) != NULL ) {
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
    
    demande :
        printf("Où souhaitez-vous poser votre carte ?\n");


        printf("Ligne :  ");
        scanf("%d" , &position[0]);

        printf("Colonne  :  ");
        scanf("%d" , &position[1]);



        int ligneUser = position[0];
        int colonneUser = position[1];
        
        
        //vérification de la validité de la position : y a-t-il une carte adjacente ?
        if ( (get_case_etat(get_plateau_case(_plateau,ligneUser,colonneUser)) == -1)&&(
        ( get_case_etat(get_plateau_case(_plateau,ligneUser-1,colonneUser)) != -1 ) ||
        (get_case_etat(get_plateau_case(_plateau,ligneUser,colonneUser-1)) != -1) ||
        (get_case_etat(get_plateau_case(_plateau,ligneUser+1,colonneUser)) != -1) || 
        (get_case_etat(get_plateau_case(_plateau,ligneUser,colonneUser+1)) != -1) )) {
            return position;
        }
        else {
            printf("Position invalide, veuillez placer la carte à côté d'une carte présente sur le plateau\n");
            goto demande;
        } 

    return position;
    
}

/* 
@requires carte valide
@assigns rien
@ensures affiche les effets de la carte
*/
void afficher_effet(carte _carte) {
    char* effet = get_carte_description(_carte);
    char* nom = get_carte_nom(_carte);
    printf("La carte %s a pour effet : %s\n", nom, effet);
}

/* 
@requires liste faction valide
@assigns rien
@ensures retourne la faction gagnante selon les règles
*/
void gagnant(faction* factions) {

    if (get_faction_manches_gagnees(factions[0]) == 2) { 
        char* nom_gagnant = get_faction_nom(factions[0]);
        printf(" Félicitation %s ! Vous avez gagné la partie ! \n",nom_gagnant);
        return;
    }
    if (get_faction_manches_gagnees(factions[1]) == 2) {
        char* nom_gagnant = get_faction_nom(factions[1]);
        printf(" Félicitation %s ! Vous avez gagné la partie ! \n",nom_gagnant);
        return;
    }
    else {
        printf("Il n'y a pas encore de factions avec 2 manches gagnées. \n");
    }

    /*init_manche s'occupe de comptabiliser les manches gagnées APPAREMMENT

    if (get_faction_nombre_points_DDRS(factions[0]) > get_faction_nombre_points_DDRS(factions[1])) { // sinon on comptabilise le gagnant de la manche
        char* nom_gagnant = get_faction_nom(factions[0]);
        printf(" Félicitation %s ! Vous avez gagné la manche ! \n",nom_gagnant);
    }
    else if (get_faction_nombre_points_DDRS(factions[0]) < get_faction_nombre_points_DDRS(factions[1])) {
        char* nom_gagnant = get_faction_nom(factions[1]);
        printf(" Félicitation %s ! Vous avez gagné la manche ! \n",nom_gagnant);
    }
    else {

        int *liste =  get_plateau_carte_premier(_plateau);
        int ligne = liste[0];
        int colonne = liste[1];

        char* nom_gagnant = get_faction_nom(factions[get_case_id_faction(get_plateau_case(_plateau,ligne,colonne))]); //on recupère la faction qui a poser la carte la plus en haut à gauche
        printf("Egalité : Félicitation %s ! Vous avez gagné la manche car vous avez placé la carte la plus en haut à gauche ! \n",nom_gagnant);
    } */
}

/* 
@requires rien
@assigns rien
@ensures affiche string sur l'écran
*/
void affiche(char* string) {
    printf("%s\n",string);
}

