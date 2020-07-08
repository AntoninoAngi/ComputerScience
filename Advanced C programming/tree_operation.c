#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXS 11 /* 10 + 1 per '\0' */

// Definizione delle strutture dati usate
typedef struct nodo* Link;

struct nodo {
    char val[MAXS];
    Link left;
    Link right;
};

// Prototipi delle funzioni di utilità
Link new_nodo(char *val);
Link leggi_nodo(FILE *in);
Link leggi_albero(char *filename);
void libera_albero(Link root);
void display_albero(Link root);

// Prototipi delle funzioni da implementare
int distanza(Link n, char *k1, char *k2);
int dist (Link n, Link b, char *k1, char *k2, int trovato);
int contaCompleti(Link n, int L1, int L2);
int contaCompleti2(Link n, int L1, int L2, int l);

int main(int argc, char **argv) {
    int l1, l2, d;
    char c1[MAXS], c2[MAXS];
    
    Link root;
    root = leggi_albero(argv[1]);
    display_albero(root);
    
    // invocazione delle funzioni richieste
    printf("Inserisci livello L1: ");
    scanf("%d", &l1);
    printf("Inserisci livello L2: ");
    scanf("%d", &l2);
    
    printf("Il numero di nodi con due figli tra il livello L1: %d e il livello L2: %d è: %d\n", l1, l2, contaCompleti(root, l1, l2));
    
    d = distanza(root, c1, c2);
    
    printf("Il numero di archi tra %s e %s è: %d", c1, c2, d);
    
    libera_albero(root);
    printf("\n");
    return 0;
}

// Implementazione delle funzioni di utilità

Link new_nodo(char *val) {
    Link n = malloc(1*sizeof(*n));
    strcpy (n->val,val);
    n->left = NULL;
    n->right = NULL;
    return n;
};

void display_albero(Link root) {
    if (root == NULL) return;
    printf("nodo %s\n", root->val);
    display_albero(root->left);
    display_albero(root->right);
}

void libera_albero(Link root) {
    if (root == NULL) return;
    libera_albero(root->left);
    libera_albero(root->right);
    free(root);
}

Link leggi_albero(char *filename) {
    FILE *in;
    in = fopen(filename, "r");
    Link root = leggi_nodo(in);
    fclose(in);
    return root;
}

Link leggi_nodo(FILE *in) {
    char val[MAXS];
    int l, r;
    if (fscanf(in, "%s %d %d", val, &l, &r) != 3) return NULL;
    Link n = new_nodo(val);
    if (l!=0) n->left = leggi_nodo(in);
    if (r!=0) n->right = leggi_nodo(in);
    return n;
}


// Implementazione delle funzioni da aggiungere
int distanza(Link n, char *k1, char *k2) {
    Link p = n;
    int count1 = 0, count2 = 0, t = 0, l = 0;
    
    printf("Inserisci primo nodo: ");
    scanf("%s", k1);
    printf("Inserisci secondo nodo: ");
    scanf("%s", k2);
    
    if (strcmp (p->val, k1) > 0)
        while (p != NULL && strcmp(p->val, k1) != 0){
            p = p->left;
            count1++;
            t--;
        }
    else {
        t = 0;
        while (p != NULL && strcmp(p->val, k1) != 0){
            p = p->right;
            count1++;
            t++;
        }
    }
    if (p == NULL){
        printf("Nodo non trovato\n");
        exit (1);
    }
    p = n;
    if (strcmp(p->val, k2) > 0)
        while (p != NULL && strcmp(p->val, k2) != 0){
            p = p->left;
            l--;
            count2++;
        }
    else {
        while (p != NULL && strcmp(p->val, k2) != 0){
            l++;
            p = p->right;
            count2++;
        }
    }
    if (p ==  NULL){
        printf("Valore non trovato\n");
        exit(2);
    }
    if ((t < 0 && l > 0) || (t < 0 && l > 0)){
        return (count1+count2);
    }
    else
        return (abs(count2-count1));
    
}

int dist (Link n, Link b, char *k1, char *k2, int trovato){
    Link p = n, q;
    int count1 = 0, count2 = 0, t = 0, l = 0, d = 0, m = -1;
    
    if (strcmp (p->val, k1) > 0)
        while (p != NULL && strcmp(p->val, k1) != 0){
            m++; q = p;
            if (p ->left != NULL && p->right != NULL && trovato != 1 && m > 0)
                d += dist(p, q, p->val, k1, trovato);
            p = p->left;
            count1++;
            t--;
            if (strcmp(p->val, k1) == 0)
                trovato = 1;
        }
    else {
        t = 0; m= -1;
        while (p != NULL && strcmp(p->val, k1) != 0){
            m++; q = p;
            if (p ->left != NULL && p->right != NULL && trovato != 1 && m > 0)
                d += dist(p, q, p->val, k1, trovato);
            p = p->right;
            count1++;
            t++;
            if (strcmp(p->val, k1) == 0)
                trovato = 1;
        }
    }
    if (p == NULL){
        printf("Nodo non trovato\n");
        exit (1);
    }
    p = n; trovato = 0; m = -1;
    if (strcmp(p->val, k2) > 0)
        while (p != NULL && strcmp(p->val, k2) != 0){
            m++; q = p;
            if (q ->left != NULL && p->right != NULL && trovato != 1 && m > 0)
                d += dist(p, q, p->val, k2, trovato);
            q = q->left;
            l--;
            count2++;
            if (strcmp(p->val, k2) == 0)
                trovato = 1;
        }
    else {
        m = -1;
        while (p != NULL && strcmp(p->val, k2) != 0){
            m++; q = p;
            if (p ->left != NULL && p->right != NULL && trovato != 1 && m > 0)
                d += dist(p, q,  p->val, k2, trovato);
            l++;
            p = p->right;
            count2++;
            if (strcmp(p->val, k2) == 0)
                trovato = 1;
        }
    }
    if (p ==  NULL){
        printf("Valore non trovato\n");
        exit(2);
    }
    if ((t < 0 && l > 0) || (t < 0 && l > 0)){
        return (count1+count2);
    }
    else
        return (abs(count2-count1));
}

int contaCompleti(Link n, int L1, int L2) {
    int c = 0, l = 0;
    
    c = contaCompleti2(n, L1, L2, l);
    
    return c;
}

int contaCompleti2(Link n, int L1, int L2, int l){
    int c = 0;
    
    if (n == NULL) return 0;
    if (l >= L1 && l <= L2){
        if (n->left != NULL && n->right != NULL){ //controllo che esistano i figli di n
            c++;
        }
    }
    l++;
    //riapplico la funzione sul figlio sx e sul figlio dx
    c += contaCompleti2(n->left, L1, L2, l);
    c += contaCompleti2(n->right, L1, L2, l);
    
    return c;
}

