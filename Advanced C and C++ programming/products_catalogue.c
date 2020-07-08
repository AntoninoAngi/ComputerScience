#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *cod_prod, *nom_prod, *cat;
    float prezzo;
    int disp, giorno, mese, anno;
} Prodotto;

typedef enum {ord_nome, ord_ric, ord_prezzo_asc, ord_prezzo_disc, ricerca_nome, ricerca_codice, aggiorn, stampa_suvideo_catalogo, stampa_sufile_catalogo, stampa_prod_per_categoria} Comando_e;

int LeggiComando (char lett[30]);

void azione (int com, Prodotto *archivio, int num);
void ordinaNome (int num, Prodotto *archivio);
void ordinaCodice (int num, Prodotto *archivio);
void ordinaPrezzo (int num, Prodotto *archivio, int t);
void stampaCatalogo (int num, Prodotto *archivio, int t);
int ricercaLin (int num, Prodotto *archivio);
int ricercaDic (int num, Prodotto *archivio, int l, int k);
void aggiornamento (int num, Prodotto *archivio);
int stampaProdotto (Prodotto *archivio, int l);

int main(){
    int n, i;
    char str_tmp[25+1], lettura[30];
    Prodotto *archivio;
    FILE *fp;
    fp = fopen("catalogo.txt", "r");
    
    if (fp == NULL){
        fprintf(stderr, "Errore nell'apertura del file\n");
        exit (1);
    }
    fscanf(fp, "%d", &n);
    
    archivio = (Prodotto*)malloc(n*sizeof(Prodotto));
    //oppure archivio = malloc (n*sizeof(Prodotto));
    //oppure archivio = malloc (n*(sizeof *archivio)); che è davvero buona
    if (archivio == NULL) exit (2);
    
    
for(i = 0; i < n; i++){
    fscanf(fp, "%s", str_tmp);
    archivio[i].cod_prod = malloc(strlen(str_tmp)*sizeof(char));
    if (archivio[i].cod_prod == NULL) exit (3);
    strcpy(archivio[i].cod_prod, str_tmp);
    fscanf(fp, "%s", str_tmp);
    archivio[i].nom_prod = malloc(strlen(str_tmp)*sizeof(char));
    if (archivio[i].nom_prod == NULL) exit (4);
    strcpy(archivio[i].nom_prod, str_tmp);
    fscanf(fp, "%s", str_tmp);
    archivio[i].cat = malloc(strlen(str_tmp)*sizeof(char));
    if (archivio[i].cat == NULL) exit (5);
    strcpy(archivio[i].cat, str_tmp);
    fscanf(fp, "%f", &archivio[i].prezzo);
    fscanf(fp, "%d", &archivio[i].disp);
    fscanf(fp, "%d/%d/%d\n", &archivio[i].giorno, &archivio[i].mese, &archivio[i].anno);
}
    fclose(fp);
    
    printf("Inserisci comando da effettuare, scegli tra:\nord_nome\nord_codice\nord_prezzo_asc\nord_prezzo_disc\nricerca_nome\nricerca_codice\naggiornamento\nstampa_suvideo_catalogo\nstampa_sufile_catalogo\nstampa_prod_per_categoria:\n\n");
    scanf("%s", lettura);
    
    azione(LeggiComando(lettura), archivio, n);
    
    for (i = 0; i < n; i++){
        free(archivio[i].cod_prod);
        free(archivio[i].nom_prod);
        free(archivio[i].cat);
    }
    free (archivio);
    
    return 0;
}

int LeggiComando(char lett[30]){
    Comando_e comando;
    
    if (strcmp ("ord_nome", lett) == 0){
        comando = 0;
    }
    else if (strcmp("ord_codice", lett) == 0){
        comando = 1;
    }
    else if (strcmp("ord_prezzo_asc", lett) == 0){
        comando = 2;
    }
    else if (strcmp("ord_prezzo_disc", lett) == 0){
        comando = 3;
    }
    else if (strcmp("ricerca_nome", lett) == 0){
        comando = 4;
    }
    else if (strcmp("ricerca_codice", lett) == 0){
        comando = 5;
    }
    else if (strcmp("aggiornamento", lett) == 0){
        comando = 6;
    }
    else if (strcmp("stampa_suvideo_catalogo", lett) == 0){
        comando = 7;
    }
    else if (strcmp("stampa_sufile_catalogo", lett) == 0){
        comando = 8;
    }
    else if (strcmp("stampa_prod_per_categoria", lett) == 0) {
        comando = 9;
    }
    else { printf("Comando non valido\n");
        exit (6);
    }
    return comando;
}
void azione (int com, Prodotto *archivio, int num){
    int t = 0, k;
    switch (com){
        case 0: ordinaNome(num, archivio);
            break;
        case 1: ordinaCodice(num, archivio);
            break;
        case 2:{
            t = 0; ordinaPrezzo(num, archivio, t);
        }
            break;
        case 3:{
            t = 1; ordinaPrezzo(num, archivio, t);
        }
            break;
        case 4: ricercaLin(num, archivio);
            break;
        case 5: {
            ordinaCodice(num, archivio);
            printf("Inserire codice da cercare con le 6 cifre: ");
            scanf ("%d", &k);
            ricercaDic(num, archivio, t, k);
        }
            break;
        case 6: aggiornamento(num, archivio);
            break;
        case 7:{
            t = 4; stampaCatalogo(num, archivio, t);
        }
            break;
        case 8:{
            t = 5; stampaCatalogo(num, archivio, t);
        }
            break;
        case 9:{
            t = 6; stampaCatalogo(num, archivio, t);
        }
            break;
    }
}
void ordinaNome (int num, Prodotto *archivio){
    int i = 0, min, j;
    Prodotto temp;
    for (i = 0; i < num; i++){
        min = i;
        for (j = i+1; j < num; j++){
            if (strcmp (archivio[j].nom_prod, archivio[min].nom_prod) < 0){
                min = j;
            }
        }
        temp = archivio[i];
        archivio[i] = archivio[min];
        archivio[min] = temp;
    }
    return;
}

void ordinaCodice (int num, Prodotto *archivio){
    int i = 0, min, j;
    Prodotto temp;
    for (i = 0; i < num; i++){
        min = i;
        for (j = i+1; j < num; j++){
            if (strcmp(archivio[j].cod_prod,archivio[min].cod_prod) < 0){
                min = j;
            }
        }
        
        temp = archivio[i];
        archivio[i] = archivio[min];
        archivio[min] = temp;
    }
    return;
}
void ordinaPrezzo (int num, Prodotto *archivio, int t){
    int i = 0, min, j;
    Prodotto temp;
    for (i = 0; i < num; i++){
        min = i;
        if (t == 0) {
            for (j = i+1; j < num; j++){
            if (archivio[j].prezzo < archivio[min].prezzo){
            min = j;
            }
        }
            temp = archivio[i];
            archivio[i] = archivio[min];
            archivio[min] = temp;
        }
        else {
            for (j = i+1; j < num; j++){
                if (archivio[j].prezzo > archivio[min].prezzo){
                    min = j;
                }
            }
            temp = archivio[i];
            archivio[i] = archivio[min];
            archivio[min] = temp;
        }
    }
    return;
}
void stampaCatalogo (int num, Prodotto *archivio, int t){
    int i;
    FILE *fpout;
    fpout = fopen("out.txt", "w");
    for (i = 0; i < num; i++){
        if (t == 4){
                printf("%s %s %s %.2f %d %d/%d/%d\n", archivio[i].cod_prod, archivio[i].nom_prod, archivio[i].cat, archivio[i].prezzo, archivio[i].disp, archivio[i].giorno, archivio[i].mese, archivio[i].anno);
        }
        else if (t == 5) {
            fprintf(fpout, "%s %s %s %.2f %d %d/%d/%d\n", archivio[i].nom_prod, archivio[i].nom_prod, archivio[i].cat, archivio[i].prezzo, archivio[i].disp, archivio[i].giorno, archivio[i].mese, archivio[i].anno);
            }
    }
        if (t == 6){
            int min, j;
            Prodotto temp;
            for (i = 0; i < num; i++){
                min = i;
                for (j = i+1; j < num; j++){
                    if (strcmp (archivio[j].cat, archivio[min].cat) < 0){
                        min = j;
                    }
                }
                temp = archivio[i];
                archivio[i] = archivio[min];
                archivio[min] = temp;
        }
            for(i = 0; i < num; i++){
                printf("%s %s %s %.2f %d %d/%d/%d\n", archivio[i].cod_prod, archivio[i].nom_prod, archivio[i].cat, archivio[i].prezzo, archivio[i].disp, archivio[i].giorno, archivio[i].mese, archivio[i].anno);
            }
        }
        fclose (fpout);
    return;
}
int ricercaLin (int num, Prodotto *archivio){
    int i, trovato = -1;
    char str[25+1];
        printf("Inserire prodotto da cercare: ");
        scanf("%s", str);
        str[0] = toupper(str[0]);
        for (i = 0; i < num; i++){
            if (strstr(archivio[i].nom_prod, str)){
                printf("%s %s %s %.2f %d %d/%d/%d\n", archivio[i].cod_prod, archivio[i].nom_prod, archivio[i].cat, archivio[i].prezzo, archivio[i].disp, archivio[i].giorno, archivio[i].mese, archivio[i].anno);
                trovato = i;
            }
        }
        if (trovato == -1){
            printf("Nessun risultato trovato\n"); exit(0);
        }
    return trovato;
}
int stampaProdotto (Prodotto *archivio, int l){
    printf("%s %s %s %.2f %d %d/%d/%d\n", archivio[l].cod_prod, archivio[l].nom_prod, archivio[l].cat, archivio[l].prezzo, archivio[l].disp, archivio[l].giorno, archivio[l].mese, archivio[l].anno);
    return 0;
}
int ricercaDic (int num, Prodotto *archivio, int l, int k){
    int val, c;
    
    sscanf(archivio[l].cod_prod,"%*c%*c%*c%d", &val);
    
    if ((num-l) == 0)
        if (val == k)
            return stampaProdotto(archivio, l);
        else
            return -1;
    c = (l+num)/2;
    sscanf(archivio[c].cod_prod,"%*c%*c%*c%d", &val);
    if (val >= k)
        return (ricercaDic(c, archivio, l, k));
    else
        return (ricercaDic(c+1, archivio, num,k));
}

void aggiornamento (int num, Prodotto *archivio){
    int j;
    j = ricercaLin(num, archivio);
    printf("Quanto vuoi che diventino le unità disponibili di questo prodotto? ");
    scanf("%d", &archivio[j].disp);
    printf("%s %s %s %.2f %d %d/%d/%d\n", archivio[j].cod_prod, archivio[j].nom_prod, archivio[j].cat, archivio[j].prezzo, archivio[j].disp, archivio[j].giorno, archivio[j].mese, archivio[j].anno);
    return;
}
