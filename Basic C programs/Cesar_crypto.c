#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 5

int main(){
    char s[N] = {'m', 'a', 'R', 'c', 'o'}, s1[N];
    int i, chiave, k;
    
    printf("Inserisci il valore per la chiave: ");
    scanf("%d", &chiave);
    for (i = 0; i < N; i++){
        if (isalpha(s[i]) != 0){ //per vedere se è una lettera o un simbolo, se è simbolo non entra
            if (islower(s[i]) != 0){ //per vedere se la lettera è minuscola
                k = 'z' - s[i];
                if (k < chiave){ //k indica quanto il valore per arrivare all'ultima lettera
                    s1[i] = 'a' + (chiave - k) - 1; //per fare in modo che ricominci dalla a
                }
                else {
                    s1[i] = s[i] + chiave;
                }
            }
            else {k = 'Z' - s[i]; //per le lettere maiuscole
                if (k < chiave){
                    s1[i] = 'A' + (chiave - k) - 1;
                }
                else {
                    s1[i] = s[i] + chiave;
                }
            }
        }
        else
            s1[i] = s[i];
    }
    printf("La parola crittografata è: ");
    for (i = 0; i < N; i++){
        printf("%c ", s1[i]);
    }
    printf("\n");
    return 0;
}
