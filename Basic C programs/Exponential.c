#include <stdio.h>
#include <stdlib.h>

int expo (int a, int b);

int main(){
    int base, esponente, x;
    
    printf("Inserisci un valore per la base: ");
    scanf("%d", &base);
    printf("Inserisci un valore per l'esponente: ");
    scanf("%d", &esponente);
    x = expo(base, esponente);
    printf("%d\n", x);
    
    return 0;
}

int expo (int a, int b){
    int r, i;
    r = 1;
    if (a == 0){
        r = 0;
    }
    else while (i < b){
                r = a * r;
                i++;
            }
    return r;
}