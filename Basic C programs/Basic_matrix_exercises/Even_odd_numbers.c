#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 2

//programma per calcolare il numero di elementi pari di ogni riga e dispari di ogni una colonna e vedere qual è la riga che ha il massimo di elementi pari e la colonna che ha il massimo di elementi dispari
int main(){
    int m[R][C], vr[R] = {0}, vc[C+4] = {0}, i, j, t;

    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            printf("m[%d, %d] = ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    t = 0;
    
    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            if (m[i][j] % 2 == 0){
                vr[t] = m[i][j];
                t++;
            }
        }
    }
    
    t = 0;
    
    for (j = 0; j < C; j++){ //per scandire le colonne e vedere se ci sono numeri dispari e scriverle
        for (i = 0; i < R; i++){
            if (m[i][j] % 2 != 0){
                vc[t] = m[i][j];
                t++;
            }
        }
    }
    printf("I valori pari nelle colonne sono: ");
    for (i = 0; i < R; i++){
        printf("%d\t", vr[i]);
    }
    printf("\n");
    printf("I valori dispari nelle colonne sono: ");
    for (i = 0; i < R; i++){
        printf("%d\t", vc[i]);
    }
    printf("\n");
    
    return 0;
}
