#include <stdio.h>
#include <stdlib.h>

int main() {
    int lato, riga, cont;
    printf("Inserire un numero dispari per il lato del triangolo: ");
    scanf("%d", &lato);
    riga = 0;
    cont = 0;
    while (riga < (lato +1)/2){
        printf("*");
        while (cont < (lato -2)){
            printf("*\n");
            cont++;
        }
        riga++;
    }
    return 0;
}
