/* implémentation du type case */
typedef struct case {
    carte carte; // carte posée sur la case en question
    int id_faction; // 0 ou 1 qui détermine la faction qui a posée la carte
    int etat; // 0 si la carte est face cachée ou 1 si elle est face visible
} case;

typedef struct plateau {
    case tab[1000][1000]; // matrice de cases de taille 1000 x 1000
} plateau;
