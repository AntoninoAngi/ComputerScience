#include <stdio.h>
#include <stdlib.h>


int main(){
    int lato, i, s, k;
    printf("Inserisci il valore per il lato del quadrato: ");
    scanf("%d", &lato);
    
    for (i = 0; i < lato; i++){
        printf("*");
    }
        printf("\n");
    for (k = 0; k < (lato - 2); k++){
        printf("*");
        for (s = 0; s < (lato - 2); s++){
            printf(" ");
        }
        printf("*\n");
    }
    for (i = 0; i < lato; i++){
        printf("*");}
    printf("\n");
return 0;
}
