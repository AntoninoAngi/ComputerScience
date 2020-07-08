#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int main(){
    int v[DIM], vp[DIM], vn[DIM], i, t, l;
    for (i = 0; i < DIM; i++){
        printf("Inserisci un valore per il vettore diverso da zero: ");
        scanf("%d", &v[i]);
         while (v[i] == 0){
                printf("Valore non valido. Inserisci un altro valore: ");
                scanf("%d", &v[i]);
        }
    }
    t = 0;
    l = 0;
    for (i = 0; i < DIM; i++){
        if (v[i] > 0){
            vp[t] = v[i];
            t++;
        }
        else {
            vn[l] = v[i];
            l++;
        }
    }
    printf("Il vettore che contiene numeri positivi è composto da: ");
    for (i = 0; i < t; i++){
        printf("%d ", vp[i]);
    }
    printf("\n");
    printf("Il vettore che contiene numeri negativi è composto da: ");
    for (i = 0; i < l; i++){
        printf("%d ", vn[i]);
    }
    printf("\n");
    
    return 0;
}
