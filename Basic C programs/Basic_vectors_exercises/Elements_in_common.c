#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 5
//programma per controllare quanti stessi elementi ci sono in v1 e v2
int main(){
    int v1[N] = {0}, v2[M] = {0}, i, t, cont;
    printf("Inserisci un valore per il primo vettore: ");
    scanf("%d", &v1[0]);
    for (i = 1; i <= N-1; i++){
        printf("Inserisci un valore per il primo vettore: ");
        scanf("%d", &v1[i]);
        for (t = 1; t <= i; t++){
            while (v1[i] == v1[i-t]){
                printf("Valore non accettato. Inserisci un altro valore: ");
                scanf("%d", &v1[i]);
            }
        }
    }
    printf("Inserisci un valore per il secondo vettore: ");
    scanf("%d", &v2[0]);
    for (i = 1; i <= M-1; i++){
        printf("Inserisci un valore per il secondo vettore: ");
        scanf("%d", &v2[i]);
        for (t = 1; t <= i; t++){
            while (v2[i] == v2[i-t]){
                printf("Valore non accettato. Inserisci un altro valore: ");
                scanf("%d", &v2[i]);
            }
        }
    }
    cont = 0;
    for (i = 0; i < N; i++){        //controlla il v1
        for (t = 0; t < M; t++){    //controlla il v2
            if (v1[i] == v2[i+t]){
                cont++;
            }
        }
    }
    printf("Compaiono %d elementi di v1 in v2\n", cont);
    return 0;
}