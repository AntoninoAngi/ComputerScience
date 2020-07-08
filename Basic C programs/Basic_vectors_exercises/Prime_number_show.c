#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(){
    int v[N], i;
    for (i = 0; i < N; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &v[i]);
    }
    printf("Elementi messi in posizione pari: ");
    for (i = 0; i < N; i++){
        if (i % 2 == 0){
            printf("%d ", v[i]);
        }
    }
    printf("\n");
    
    printf("Elementi messi in posizione dispari: ");
    for (i = 0; i < N; i++){
        if (i % 2 != 0){
            printf("%d ", v[i]);
        }
    }
    printf("\n");
    return 0;
}
