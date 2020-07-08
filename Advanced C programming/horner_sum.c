#include <stdio.h>
#include <stdlib.h>


float valutaHorner (float P[11], float x);


int main(){
    int n, a, b, m, i;
    float coeff[11] = {0}, result, h, med, sup, inf;
    
    printf("Inserisci il grado del polinomio (n <= 10): ");
    scanf("%d", &n);
    
    if (n > 0){
        printf("Inserisci coefficienti reali\n");
        for (i = n; i >= 0; i--){
            printf("Coefficiente di grado %d: ", i);
            scanf("%f", &coeff[i]);
        }
        printf("Inserisci estremi di integrazione (separati da uno spazio): ");
        scanf("%d %d", &a, &b);
        printf("Inserisci numero sottointervalli: ");
        scanf("%d", &m);
    }
    else if (n == 0){
            printf("Inserisci estremi di integrazione (separati da uno spazio): ");
            scanf("%d %d", &a, &b);
            result = (float)(b - a);
            printf("Il valore dell'integrale è: %.2f\n", result);
            return 0;
    }
    else { printf("Grado del polinomio non valido\n");
        return 1; }
    h = (b-a)/(float)m;
    inf = 0; i = 1; result = 0;
    while (i <= m){
        sup = i*h;
        med = (sup+inf)/(float)2;
        result += valutaHorner(coeff, med);
        inf = sup;
        i++;
    }
    printf("Il valore dell'integrale è %.2f\n", result*h);
    
    return 0;
}

float valutaHorner (float P[11], float x){
    int i, cont = 0;
    float ris = 0;
    
    for (i = 11; i > 0; i--){
        if (P[i] != 0){
            cont++;
        }
    }
    
    ris = P[cont]*x;
    for (i = cont-1; i > 0; i--){
        ris = (ris + P[i])*x;
    }
    ris+= P[i];
    
    return ris;
}