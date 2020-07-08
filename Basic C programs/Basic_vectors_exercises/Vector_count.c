#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main(){
    int n, i, x, t;
    char risp;
    printf("Inserisci un valore n minore o uguale a 100: ");
    scanf("%d", &n);
    int v[n];
    if (n > 100){
        return 0;
    } else {
        for (i = 0; i < n; i++){
        printf("Inserisci un valore per il vettore: ");
        scanf("%d", &v[i]);
        }
        do {
            t = 0;
            x = 0;
             printf("Inserisci un valore per x: ");
             scanf("%d", &x);
             for (i = 0; i < n; i++){
                 if ( v[i] == x ){
                     t++;
                 }
             }
             printf("Il valore di x è stato trovato %d volte\n", t);
            
             printf("Vuoi continuare inserendo un altro valore per x (Y, N)? ");
             scanf("%c%*c", &risp);
             }  while ( risp != 'Y' || risp != 'y');
    }
    return 0;
}
