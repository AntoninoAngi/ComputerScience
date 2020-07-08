#include <stdio.h>
#include <stdlib.h>

void Convertire_base (int a, int b);

int main(){
    int a, b;
    
    printf("Inserisci un valore: ");
    scanf("%d", &a);
    printf("Inserisci la base cui vuoi convertire quel valore (>= 2): ");
    scanf("%d", &b);

    if (b < 2){
        printf("Base non valida\n");
        exit (0);
    }
    
    Convertire_base(a, b);
    printf("\n");
    return 0;
}

void Convertire_base (int a, int b){
        if ((a/b) != 0)
        Convertire_base((a/b), b);
    
        printf("%d", (a % b));
        return;
}