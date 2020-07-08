#include <stdio.h>
#include <stdlib.h>
#define N_ROW 3
#define N_COL 3

int main(){
    int mat1[N_ROW][N_COL], mat2[N_ROW][N_COL], i, k;
    
    printf("Inserisci una prima matrice:\n");
    for(i = 0; i < N_ROW; i++){
        for(k = 0; k < N_COL; k++){
            scanf("%d", &mat1[i][k]);
        }
    }
    printf("Inserisci una seconda matrice:\n");
    for(i = 0; i < N_ROW; i++){
        for(k = 0; k < N_COL; k++){
            scanf("%d", &mat2[i][k]);
        }
    }

    printf("La matrice somma sarà:\n");
    
    for(i = 0; i < N_ROW; i++){
        for(k = 0; k < N_COL; k++){
            printf("%d\t", mat1[i][k]+mat2[i][k]);
        }
        printf("\n");
    }
    
    return 0;
}
