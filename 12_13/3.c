/*

Scrivere un sottoprogramma rep che riceve in ingresso una stringa s e un intero n (senz'altro non negativo). 
Il sottoprogramma restituisce una nuova stringa ottenuta concatenando n copie di s. Ad esempio, se il sottoprogramma 
riceve in ingresso "esempio" e 3 restituisce la nuova "esempioesempioesempio", se riceve "esempio" e 0 restituisce una stringa vuota. 
Non è consentito l'uso dei sottoprogrammi di libreria quali strcat(), strcpy() e simili.
Scrivere il programma che acquisisce da riga di comando la stringa s e l'intero n,
invoca il sottoprogramma sopra definito e visualizza il risultato.


*/

#include <stdio.h>
#include <stdlib.h>

char* rep(char[], int);

int main(int argc, char *argv[]){
    char *s;
    int n;
    if(argc == 3){
        n = atoi(argv[2]);
        s = rep(argv[1], n);
        if(s) {
            printf("%s\n", s);
            free(s);
        }
    }else
        printf("Errore argomenti\n");

    return 0;
}

char* rep(char s[], int n){
    char *h;
    int len, i, j;

    for(len=0; s[len] != '\0'; len++);
    
    h = malloc(sizeof(char)*(len*n +1));

    if(h){
        for(i=0; i<n; i++){
            for(j=0; j<len; j++){
                h[j + i*len] = s[j];
            }
        }
        s[len*n + 1] = '\0';
    }else
        printf("Errore allocazione memoria\n");
    
    return h;
}