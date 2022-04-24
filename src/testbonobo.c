#include <stdlib.h>
#include <stdio.h>


int main() {
    int* position;

    position = malloc(2*sizeof(int));
    

    printf("Où souhaitez-vous poser votre carte ?\n");


    printf("Ligne :  ");
    scanf("%d" , &position[0]);

    printf("Colonne  :  ");
    scanf("%d" , &position[1]);

    printf("%d, %d n", position[0], position[1] );
    return 0;

}