#include <stdio.h>
#define N 5

//programma per dividere in un vettore i numeri primi da quelli dispari

int main(){
    int v[N], i;
    for (i = 0; i < N; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &v[i]);
    }
    printf("Valori pari: ");
    for (i = 0; i < N; i++){
        if (v[i] % 2 == 0){
            printf("%d ", v[i]);
        }
    }
    printf("\n");
    
    printf("Valori dispari: ");
    for (i = 0; i < N; i++){
        if (v[i] % 2 != 0){
            printf("%d ", v[i]);
        }
    }
    printf("\n");

    return 0;
}
