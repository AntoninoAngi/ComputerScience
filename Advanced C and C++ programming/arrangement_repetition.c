#include <stdio.h>
#include <stdlib.h>

int disp_rip (int pos, int *val, int *sol, int n, int count, int cont_min, int cont_0, int *v1, int *v2);
int check (int v[], int n, int *sol, int *cont_min, int cont_0, int *v1);
void stampa (int n, int *v1);

int main(){
    int n, i, *sol, cont_0 = 0, *v1;
    
    printf("Inserisci numero (pari) di frecce: ");
    scanf("%d", &n);
    if (n % 2 != 0){
        printf("Il numero di frecce non è valido\n");
        exit (0);
    }
    int v[n], v2[n];
    
    sol = malloc(n*sizeof(int));
    
    for (i = 0; i < n; i++)
        sol[i] = 0;
    
    printf("Inserisci sequenza di frecce 0 (punta a dx), 1 (punta a sx):\n");
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++)
        v2[i] = v[i];
    
    v1 = malloc(n*sizeof(int));
    
    for (i = 0; i < n; i++)
        v1[i] = 0;
    
    for (i = 0; i < n; i++){
        if (v[i] == 0)
            cont_0 ++;
        else cont_0--;
    }
    
    disp_rip(0, v, sol, n, 0, n+1, cont_0, v1, v2);
    
    stampa(n, v1);
    
    free(sol);
    free(v1);
    
    return 0;
}
int disp_rip (int pos, int *val, int *sol, int n, int count, int cont_min, int cont_0, int *v1, int *v2){
    int i, c;
    
    if (pos >= n){
        for (i = 0; i < n; i++)
            val[i] = v2[i];
        c = check(val, n, sol, &cont_min, cont_0, v1);
        if (c == 1 && (cont_min == 1 || cont_min == 0))
            stampa(n,v1);
        return count+1;
    }

    for (i = 0; i < n; i++){
        sol[pos] = val[i];
        disp_rip(pos+1, val, sol, n, count, cont_min, cont_0, v1, v2);
    }
    return count;
}

int check (int v[], int n, int *sol, int *cont_min, int cont_0, int *v1){
    int i, x = 0, j = 0, t = 0, cont = 0;
    
    for (i = 0; i < n; i++){
        if (sol[i] == 1){ //per cambiare il senso della freccia
            cont++; //per controllare poi che ci siano i minori cambiamenti
            if (v[i] == 0){
                v[i] = 1;
                cont_0--; //per controllare che gli zeri e gli uni siano nella stessa quantità
                cont_0--;
            }
            else{
                v[i] = 0;
                cont_0++;
                cont_0++;
            }
        }
    }
        if (cont_0 != 0) //se non sono nella stessa quantità esce
            return 0;
        else {
            while (t < n){ //controllo che gli zeri e gli uni siano bilanciati
                for (i = j; i < n; i++){
                    if (v[i] == 0)
                        x++;
                    else break;
                }
                t = i;
                for (j = i; j < n; j++){
                    if (v[j] == 1)
                        x--;
                        else break;
                }
                t = j;
        }
    }
    if (x == 0){
        if (*cont_min > cont){
            *cont_min = cont;
            for (i = 0; i < n; i++)
                v1[i] = v[i];
        }
        return 1;
    }
    else return 0;
}

void stampa (int n, int *v1){
    int i;
    printf("Una soluzione valida è: ");
    for (i = 0; i < n; i++)
        printf("%d ", v1[i]);
    printf("\n");
    exit (0);
    return;
}