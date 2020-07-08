#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5

// programma per elevamento a potenza

int main(){
    int base[N], exp[N], i, power;
    for ( i = 0; i < N; i++){
        printf("Inserisci un valore per la base: ");
        scanf("%d", &base[i]);
    }
    for ( i = 0; i < N; i++){
        printf("Inserisci un valore positivo per l'esponente: ");
        scanf("%d", &exp[i]);
        if (exp[i] < 0){
            printf("Valore non valido. Inserisci un valore valido: ");
        }
    }
    for (i = 0; i < N; i++){
        power = pow(base[i], exp[i]);
        printf("%d ", power);
    }
    printf("\n");
    return 0;
}
