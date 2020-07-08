#include <stdio.h>
#include <stdlib.h>

int main(){
    int v1[10], v2[10], i, diff, pos;
    for (i = 0; i < 10; i++){
        printf("Inserisci un valore per il primo vettore: ");
        scanf("%d", &v1[i]);
    }
    for (i = 0; i < 10; i++){
        printf("Inserisci un valore per il secondo vettore: ");
        scanf("%d", &v2[i]);
    }
    diff = v1[0] - v2[0];
    pos = 0;
    for (i = 0; i < 10; i++){
        if (diff > (v1[i] - v2[i])){
            diff = (v1[i] - v2[i]);
            pos = i;
        }
    }
    printf("La massima differenza tra due elementi corrispondenti si ha tra gli elementi in posizione %d, cioè tra i valori %d e %d\n", pos, v1[pos], v2[pos]);
    return 0;
}
