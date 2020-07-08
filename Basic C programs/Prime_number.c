#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(){
    int v[N], i, d, cont;
    for (i = 0; i < N; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &v[i]);
    }
    for (i = 0; i < N; i++){
        for (d = 2; d < v[i]; d++){
            if (v[i] % d == 0 && v[i] % 2 != 0){
                cont++;
                printf("Numero primo trovato in posizione: %d\n", i+1);
                break;
            }
                else
                    if (v[i] == 2){
                        printf("Numeri primo trovato in posizione: %d\n", i+1);
                break;}
        }
    }
    printf("I numeri primi sono: %d", cont);
    return 0;
}
