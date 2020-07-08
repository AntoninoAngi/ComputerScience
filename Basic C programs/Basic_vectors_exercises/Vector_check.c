#include <stdio.h>
#include <stdlib.h>
#define N 200

int main(){
    int v[N], i, t, l, j, cont, tmp;
    t = 0;
    printf("Inserisci un valore: ");
    scanf ("%d", &v[0]);
    i = 0;
    do {
        i++;
        printf("Inserisci un valore: ");
        scanf("%d", &v[i]);
        t++;
    } while (v[i] >= 0 && i < 200);
    cont = 0;
    for (i = 0; i < t; i++){ // per entrare nel vettore
        for (l = 0; l < t; l++){ // per controllare ogni elemento del vettore
            if (v[i] == v[l+1]){ // per vedere se ci sono uguaglianze
                for (j = 0; j < t; j++){ //per modificare tutti i posti
                    tmp = v[l+1];
                    v[l+1] = v[l+2];
                }
            }
            
            cont++;
        }
    }
    for (i = 0; i < cont; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
