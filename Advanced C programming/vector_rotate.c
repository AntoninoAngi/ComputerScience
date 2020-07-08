#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 35

typedef struct tabella{
    char compresso[N+1], originale[N+1];
} Tabella;


int main(){
    char parola[N+1];
    int s, i, j, cont, t;
    FILE *fp_sorg, *fp_diz, *fp_compr;
    fp_sorg = fopen("sorgente.txt", "r");
    fp_diz = fopen("dizionario.txt", "r");
    fp_compr = fopen("compresso.txt", "w");
    
    if (fp_sorg == NULL || fp_diz == NULL || fp_compr == NULL){
        fprintf(stderr,"Errore nell'apertura file\n");
        exit (1);
    }
    
    fscanf(fp_diz, "%d", &s);
    Tabella sost[s];

    for (i = 0; i < s; i++){
        fscanf(fp_diz, "%s", sost[i].compresso);
        fscanf(fp_diz, "%s", sost[i].originale);
    }
    fclose(fp_diz);
    
    while (fscanf(fp_sorg, "%s", parola) != EOF){
        cont = 0; t = 0;
        for (i = 0; i < s; i++){
            if (strstr(parola, sost[i].originale) != NULL){
                for (j = 0; j < strstr(parola, sost[i].originale) - parola; j++){
                    fprintf(fp_compr, "%c", parola[j]); t++;
                }
                fprintf(fp_compr, "%s" ,sost[i].compresso);
                t += strlen(sost[i].originale);
                if (t != strlen(parola))
                    for (j = t; j < strlen(parola); j++)
                        fprintf(fp_compr, "%c", parola[j]);
                fprintf(fp_compr, " ");
                break;
                }
            else cont++;
        }
        if (cont == s){
            fprintf(fp_compr, "%s ", parola);
        }
    }
    fclose(fp_sorg); fclose(fp_compr);
    return 0;
}
