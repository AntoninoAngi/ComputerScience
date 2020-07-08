#include <stdio.h>
#include <stdlib.h>
#define N 20

int operazione(int r, int matrice[N][N], int nr, int nc, int riga, int colonna);

int main(){
    int nr, nc, matr[N][N], i, j, raggio, matr2[N][N];
    FILE *fpin, *fpout;
    fpin = fopen("matr.txt", "r");
    fpout = fopen("sum.txt", "w");
    
    if (fpin == NULL || fpout == NULL){
        printf("Errore nell'apertura file\n");
        exit (1);
    }
    fscanf(fpin, "%d %d", &nr, &nc);
    
    for (i = 0; i < nr; i++){
        for (j = 0; j < nc; j++){
            fscanf(fpin, "%d", &matr[i][j]);
        }
    }
    fclose(fpin);
    
    printf("Introduci valore per il raggio: ");
    scanf("%d", &raggio);
    
    for (i = 0; i < nr; i++){
        for (j = 0; j < nc; j++){
            matr2[i][j] = operazione(raggio, matr, nr, nc, i, j);
        }
    }
    fprintf(fpout, "%d %d\n", nr, nc);
    for (i = 0; i < nr; i++){
        for (j = 0; j < nc; j++){
            fprintf(fpout, "%d ", matr2[i][j]);
        }
        fprintf(fpout, "\n");
    }
    
    fclose(fpout);
    
    return 0;
}

int operazione(int r, int matrice[N][N], int nr, int nc, int riga, int colonna){
    int i, j, somma = 0;
    for (i = riga - r, j = colonna - r; i <= riga + r; i++){
        if (i >= 0 && i < nr){
            somma += matrice[i][j];
        }
    }
    for (j = colonna - r+1, i = riga - r; j <= colonna + r; j++){
        if (j >= 0 && j < nc){
            somma += matrice[i][j];
        }
    }
    for (i = riga - r +1, j = colonna + r; i <= riga+r; i++){
        if (i >= 0 && i < nr){
            somma += matrice[i][j];
        }
    }
    for (j = colonna - r +1, i = riga + r; j > colonna-r; j--){
        if (j >= 0 && j < nc){
            somma += matrice[i][j];
        }
    }
    return somma;
}
