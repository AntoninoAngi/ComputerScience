#include <stdio.h>
#include <stdlib.h>

int main(){
    int nr, nc, i, k;
    printf("Inserisci un valore minore o uguale a 10 per le righe:\n");
    scanf("%d", &nr);
    if(nr > 10){
        printf("Valori delle righe non consentito\n");
        return 1;
    }
    else {
        printf("Inserisci un valore minore o uguale a 10 per le colonne:\n");
        scanf("%d", &nc);
    }
    if(nc > 10){
        printf("Valori delle colonne non consentito\n");
        return 2;
    }
    int mat[nr][nc];
    
    printf("Inserisci una matrice:\n");
    for(i = 0; i < nr; i++){
        for(k = 0; k < nc; k++){
            printf("Inserici l'elemento [%d][%d]: ", i, k);
            scanf("%d", &mat[i][k]);
        }
    }
    
    printf("La matrice trasposta è:\n"); //con nr = nc e nc = nr
    for(i = 0; i < nc; i++){
        for(k = 0; k < nr; k++){
            printf("%d\t", mat[k][i]);
        }
        printf("\n");
    }
    
    
    return 0;
}