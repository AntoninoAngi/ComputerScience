#include "stdio.h"

int
main (void){
    char carattere;
    float C, F, gradi;
    printf("Inserisci F o C\n");
    scanf("%c", &carattere);
    if (carattere == 'F'){
        printf("Inserisci un valore per la temperatura\n");
        scanf("%f", &gradi);
        C = (gradi-32)*5/9;
        printf("La temperatura corrispondente a %.2f gradi Fahrenheit è %.1f gradi Celsius\n", gradi, C);
    } else {
        if (carattere == 'C'){
            printf("Inserisci un valore per la temperatura\n");
            scanf("%f", &gradi);
            F = (gradi*9/5)+32;
            printf("La temperatura corrispondente a %.2f gradi Celsius è %.1f gradi Fahrenheit\n", gradi, F);}
        else
        printf("Input non accettata\n");
    }
    return 0;
}