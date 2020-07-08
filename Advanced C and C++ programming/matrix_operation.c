#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 20

void StampaSpirale (int num_riga, int num_col, int matr[num_riga][num_col]);

int main(){
    char nome_file[N+1];
    int righe, colonne, i, j;
    FILE *fp;
    printf("Inserisci nome file: ");
    scanf("%s", nome_file);
    
    fp = fopen(nome_file, "r");
    if (fp == NULL){
        fprintf(stderr,"Errore nell'apertura del file\n");
        exit (1);
    }
    
    fscanf(fp, "%d", &righe);
    colonne = righe;
    int matrice[righe][colonne];
    
    for (i = 0; i < righe; i++){
        for (j = 0; j < colonne; j++){
            fscanf(fp, "%d", &matrice[i][j]);
        }
    }
     fclose(fp);
    
    StampaSpirale(righe, colonne, matrice);
    
    
    return 0;
}

void StampaSpirale (int num_riga, int num_col, int matr[num_riga][num_col]){
    int r = 0, c = 0, i;
    
    printf("Forma a spirale: ");
    
    while (r < num_riga && c < num_col){
        for (i = r; i < num_col; i++){
            printf("%d ", matr[c][i]);
        }
    
        r++;
    
        for (i = c+1; i < num_riga; i++){
            printf("%d ", matr[i][num_col-1]);
        }
        num_col--;
    
        if (r < num_riga){
            for (i = num_col-1; i >= c; i--){
                printf("%d ", matr[num_riga-1][i]);
            }
            num_riga--;
        }
        for (i = num_riga-1; i >= r; i--){
            printf("%d ", matr[i][c]);
        }
        c++;
    }
    printf("\n");
    
    return;
}

