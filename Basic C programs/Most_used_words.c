#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

int main(int argc, char * argv[]) {
    FILE *fp;
    
    char str[N], str1[N], str2[N];
    int t, n;
    if (argc < 2){
        fprintf(stderr, "Errore di sintassi nell'apertura %s\n", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "Errore nell'apertura del file\n");
        exit(2);
    }
    
    while (fscanf(fp, "%s", str) != EOF){
        t = 0;
        n = 1;
        while (fscanf(fp, "%s", str1) != EOF){
            if (strcmp(str, str1) == 0){
                t++;
                if (t > 1){
                        strcpy(str2, str);
                        n++;
                }
                if (n > 1){
                    printf("La parola contenuta più volte nel file %s è %s (%d ripetizioni)\n", argv[1], str2, n);
                    fclose(fp);
                    return 0;
                }
            }
        }
    }
    printf("Nessuna parola doppione trovata\n");
    return 0;
}
