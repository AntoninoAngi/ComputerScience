#include <stdio.h>
#include <stdlib.h>

void cover (int S[][10], int n, int k);
int comb_sempl(int pos, int S[][10], int *sol, int n, int k, int start, int count, int U[]);
int check (int U[], int n, int *sol, int pos, int S[][10]);

int main(){
    int i = 1, n, k, j;
    
    printf("Inserisci numero di sottoinsiemi: ");
    scanf("%d", &n);
    
    int S[n][10];
    
    for (i = 0; i < n; i++){
        for (k = 0; k < 10; k++){
            S[i][k] = 0;
        }
    }
    printf("Quanti sottoinsiemi vuoi considerare per formare quello di partenza? ");
    scanf("%d", &k);
    
   for (i = 0; i < n; i++){
        j = 0;
        printf("Inserisci sottoinsieme %d-esimo (inserire 0 per terminare acquisizione):\n", i);
        do{
            scanf("%d", &S[i][j]);
            j++;
        }while (j < 10 && S[i][j-1] != 0);
    }
    
    cover(S, n, k);
    
    return 0;
}

void cover (int S[][10], int n, int k){
    int count, *sol, U[9] = {1,2,3,4,5,6,7,8,9}, i;
    sol = malloc(k*sizeof(int));
    
    for (i = 0; i < k; i++)
        sol[i] = -1;
    
    count += comb_sempl(0, S, sol, n, k, 0, 0, U);
    free (sol);
    return;
}

int comb_sempl(int pos, int S[][10], int *sol, int n, int k, int start, int count, int U[]){
    int i;
    if (pos >= k){
        if (check(U, n, sol, pos, S) == 1){
            for (i = 0; i < k; i++)
                printf("%d ", sol[i]);
            printf("\n");
            return count+1;
        }
    }
    for (i = start; i < n; i++){
        sol[pos] = i;
        count = comb_sempl(pos+1, S, sol, n, k, i+1, count, U);
    }
    return count;
}

int check (int U[], int n, int *sol, int pos, int S[][10]){
    int i, count = 0, j, w = 0, v[10];
    
    for (i = 0; i < 10; i++)
        v[i] = 0;
    
    for (i = 0; i < pos; i++){
        w = 0;
        for (j = 0; j < 9; j++){
            if (S[sol[i]][w] == 0) break;
            if (S[sol[i]][w] == U[j]){
                v[U[j]]++;
                w++;
            }
        }
    }
    
    for (i = 1; i <= 9; i++){
        if (v[i] == 1)
            count++;
        if (v[i] == 0)
            return 0;
    }
    if (count == 9){
        return 1;
    }
    else return 0;
}