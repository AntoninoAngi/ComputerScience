#include <stdio.h>
#include <stdlib.h>

int Hofstadter (int n);

int main(){
    int n, l, i;
    printf("Inserisci valore di N > 0: ");
    scanf("%d", &n);
    if (n <= 0){
        printf("Valore non valido\n");
        exit (1);
    }

    for (i = 1; i <= n; i++){
        l = Hofstadter(i);
        printf("%d ", l);
    }
    printf("\n");
    return 0;
}

int Hofstadter (int n){
    
    if (n <= 2)
        return 1;
    
    return ((Hofstadter(n - Hofstadter(n-1)) + Hofstadter(n - Hofstadter(n-2))));
}