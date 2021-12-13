/*

Scrivere un programma che trova e visualizza tutti i vocaboli di un dizionario (file di testo ASCII dizionario.txt) 
in cui tutte le vocali presenti compaiono in ordine lessicografico crescente. Non è necessario che compaiano tutte 
le vocali e la stessa vocale può comparire più volte. Nel file, ogni vocabolo compare su una riga nuova, ed ogni vocabolo è al più lungo 
35 caratteri (e ovviamente contiene almeno una vocale). I caratteri sono tutti minuscoli e non accentati. Per esempio, i vocaboli alta, 
arte vengono visualizzati, il vocabolo idea no.

*/

#include <stdio.h>
#include <stdlib.h>

#define FN "dizionario.txt"
#define MAXSTR 35

int isVocale(char);

int main(){
    FILE *fp;
    char vocabolo[MAXSTR+1], last;
    int i, valido;

    fp = fopen(FN, "r");

    if(fp){
        fscanf(fp, "%s", vocabolo);

        while(!feof(fp)){
            last = 'a';
            for(i=0, valido = 1; vocabolo[i] != '\0' && valido; i++){
                if(isVocale(vocabolo[i]) && vocabolo[i] >= last){
                    last = vocabolo[i];
                }else{
                    valido = 0;
                }
            }
            if(valido){
                printf("%s\n", vocabolo);
            }

            fscanf(fp, "%s", vocabolo);
        }
        fclose(fp);
    }else
        printf("Errore apertura file\n");

    return 0;
}

int isVocale(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}