#include <stdio.h>
#include <stdlib.h>
#define R 4
#define C 3

//programma per ordinare valori in ordine crescente dentro una matrice sia tra righe che colonne

int main(){
    int m[R][C] = {{1,3,2}, {6,3,0}, {8,9,5}, {4,3,9}}, i, j, q, tmp;
    
    for (i = 0; i < R; i++){ // solo per ordinare tra righe
        for (j = 0; j < C-1; j++){
            for (q = 0; q < C-j-1; q++){
                if (m[i][q] > m[i][q+1]){
                    tmp = m[i][q];
                    m[i][q] = m[i][q+1];
                    m[i][q+1] = tmp;
                }
            }
        }
    }
    
    printf("La nuova matrice ordinata solo per le righe sarà:\n");
    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    
    
    for (i = 0; i < C; i++){  // per ordinare tra righe e colonne
        for (j = 0; j < R-1; j++){
            for (q = 0; q < R-j-1; q++){
                if (m[q][i] > m[q+1][i]){
                    tmp = m[q][i];
                    m[q][i] = m[q+1][i];
                    m[q+1][i] = tmp;
                }
            }
        }
    }
    
    
    printf("La nuova matrice ordinata sia per righe che per colonne sarà:\n");
    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
