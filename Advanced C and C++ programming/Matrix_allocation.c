#include <stdio.h>
#include <stdlib.h>

int **malloc2dr(int r, int c);
void free2d (int **mat, int r);
void salva_diagonali (int **mat, int r, int c, int **mat_diag, int **mat_anti_diag);

int main(){
    int nr, nc, **mat, i, j, **mat_diag, **mat_anti_diag;
    FILE *fp;
    fp = fopen("matrice.txt", "r");
    if (fp == NULL){
        fprintf(stderr, "Errore nell'apertura del file\n");
        exit (1);
    }
    
    fscanf(fp, "%d", &nr); fscanf(fp, "%d", &nc);
    
    mat = malloc2dr(nr, nc); //ho allocato dinamicamente la matrice
    
    for (i = 0; i < nr; i++){
        for (j = 0; j < nc; j++){
            fscanf(fp, "%d", &mat[i][j]);
        }
    }
    fclose(fp);
    
    mat_diag = malloc ((nr+nc-1)*sizeof(int*));
    if (mat_diag == NULL) exit (2);
    mat_anti_diag = malloc ((nr+nc-1)*sizeof(int*));
    if (mat_anti_diag == NULL) exit (2);
    
    salva_diagonali(mat, nr, nc, mat_diag, mat_anti_diag);
    
    free2d(mat, nr); //libero lo spazio riservato alla matrice
    return 0;
}

int **malloc2dr(int r, int c){
    int **mat, i;
    
    mat = malloc(r * sizeof(int *));
    if (mat == NULL) exit (2);
    for (i = 0; i < c; i++){
        mat[i] = malloc(c * sizeof(int));
        if (mat[i] == NULL) exit (3);
    }
    return mat;
}
void free2d (int **mat, int r){
    int i;
    for (i = 0; i < r; i++){
        free (mat[i]);
    }
    free (mat);
}

void salva_diagonali (int **mat, int r, int c, int **mat_diag, int **mat_anti_diag){
    int i = 0, j = c - 2, t, u = 1, l = j, k = 1, m = 1;
    
    *mat_diag = malloc(m*sizeof(int));
    m++;
    mat_diag[0] = &mat[0][c-1];
    printf("%d ", *mat_diag[k-1]);
    for (t = 0; t < (r+c-3); t++){
        if (t < (c-1)){
            *mat_diag++ = malloc(m*sizeof(int));
            m++;
        }
        while (i < r && j < c && t < (c-1)){
            mat_diag[k] = &mat[i][j];
            printf("%d ", *mat_diag[k]);
            k++; i++; j++;
        }
        i = 0; j = l-1; l--;
        if (t >= (c-1)){
            i = u; j = 0;
            l = m - 1;
            m = c - 1;
            *mat_diag++ = malloc(m*sizeof(int));
            m--; l++;
            while (i < r && j < c){
                mat_diag[k] = &mat[i][j];
                printf("%d ", *mat_diag[k]);
                k++; i++; j++;
            }
            u++;
        }
    }
    *mat_diag = malloc(m*sizeof(int));
    mat_diag[k] = &mat[r-1][0];
    printf("%d ", *mat_diag[k]);
    printf("\n");
    i = 1; j = 0; k = 1; l = i; m = 1; u = 1;
    
    *mat_anti_diag = malloc(m*sizeof(int));
    m++;
    mat_anti_diag[0] = &mat[0][0];
    printf("%d ", *mat_anti_diag[k-1]);
    
    for (t = 0; t < (r+c-3); t++){
        if (t < (c-1)){
            *mat_anti_diag++ = malloc(m*sizeof(int));
            m++;
        }
        while (i >= 0 && j >= 0 && t < (c-1)){
            mat_anti_diag[k] = &mat[i][j];
            printf("%d ", *mat_anti_diag[k]);
            k++; i--; j++;
        }
        i = l+1; j = 0; l++;
        if (t >= (c-1)){
            i = r-1; j = u;
            *mat_anti_diag++ = malloc(m*sizeof(int));
            m--; l++;
            while (i > 0 && j > 0){
                mat_anti_diag[k] = &mat[i][j];
                printf("%d ", *mat_anti_diag[k]);
                k++; i--; j++;
            }
            u++;
        }
    }
    *mat_anti_diag = malloc(m*sizeof(int));
    mat_anti_diag[k] = &mat[r-1][c-1];
    printf("%d\n", *mat_anti_diag[k]);
}