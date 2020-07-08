#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 4

int main(){
    int mat[R+2][C+2] = {{0},{0}}, i, k, t, min;

    for(i = 0; i < R; i++){
        for(k = 0; k < C; k++){
            printf("Inserisci l'elemento [%d][%d]: ", i, k);
            scanf("%d", &mat[i][k]);
            while (mat[i][k] <= 0){
                printf("Inserisci l'elemento [%d][%d]: ", i, k);
                scanf("%d", &mat[i][k]);
            }
        }
    }
    min = 1;
    for(i = 0; i < R; i++){
        for (k = 0; k < C; k++){
            for (t = 0; t < 2; t++){
                if (mat[i][k-t] <= mat[i][k] && min != 0 && mat[i][k-t] > min){
                    min = mat[i][k-1+t];
                }
                if (mat[i-t][k] <= mat[i][k] && min != 0 && mat[i-t][k] > min){
                    min = mat[i-1+t][k];
                }
                if (mat[i-t][k-t] <= mat[i][k] && min != 0 && mat[i-t][k-t] > min){
                    min = mat[i-1+t][k-1+t];
                }
                if (min != 1){
                    printf("Il minimo nell'intorno di %d è %d\n", mat[i][k] ,min);
                }
            }
        }
    }
    return 0;
}
