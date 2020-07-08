#include <stdio.h>
#include <stdlib.h>
#define N 5

//programma che inverte l'ordine di inserimento

int main(){
    int v[N], i;

    for (i = 0; i < N; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &v[i]);
    }
    for (i = N-1; i >= 0 ; i--){
        printf("%d ", v[i]);
    }

    return 0;
}
