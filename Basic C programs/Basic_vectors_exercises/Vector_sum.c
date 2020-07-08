#include <stdio.h>
#include <stdlib.h>
#define DIM 5


int main(){
    float v1[DIM], v2[DIM], v3[DIM];
    int i;
    for (i = 0; i < DIM; i++){
        printf("Inserisci un valore per il primo vettore: ");
        scanf("%f", &v1[i]);
    }
    for (i = 0; i < DIM; i++){
        printf("Inserisci un valore per il secondo vettore: ");
        scanf("%f", &v2[i]);
    }
    for (i = 0; i < DIM; i++){
        v3[i] = v1[i] + v2[i];
        printf("%.2f ", v3[i]);
    }
    printf("\n");
    
    return 0;
}
