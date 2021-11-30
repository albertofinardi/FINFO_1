/*
Scrivereunsottoprogrammadimmianagrammichericeveiningressounastringacontenenteunvocaboloevisualizzailnumerodivo- caboli presenti nel file di testo dizionario.txt che sono anagrammi della stringa in ingresso, restituendo il numero di tali vocaboli. I vocaboli presenti nel dizionario sono di al più 25 caratteri, uno per riga. Nel caso in cui ci siano problemi di accesso al file, il sottoprogramma restituisce -1. Per esempio, se il sottoprogramma riceve in ingresso la stringa mira il sottoprogramma visualizza
armi
mari
rami
rima
e restituisce 4.
Si ipotizzi di avere a disposizione il sottoprogramma anagramma che restituisce 1 se le due stringhe ricevute in ingresso solo una l’anagramma dell’altra, 0 altrimenti.
      int anagramma(char s1[], char s2[]);
(1punto) Adattareilsottoprogrammadimmianagrammie/oilsottoprogrammaanagrammainmodotalechepossafunzionareanchenelmo- mento in cui il programma riceve in ingresso un valore intero e il file dizionario.txt contiene una sequenza di numeri (uno per riga) che potrebbero essere l’anagramma del numero ricevuto in ingresso (il numero 9307 è l’anagramma del numero 3790 ...). Nel caso in cui si modifica il sottoprogramma anagramma, indicare il nuovo prototipo e descrivere cosa fa funzionalmente il sottoprogramma (cosa fa, non come lo fa).
*/
#include <stdio.h>
#include <stdlib.h>
#define FN "dizionario.txt"
#define DIM 25
#define ERR -1

int dimmianagrammi(char[]);
int anagramma(char s1[], char s2[]);
int anagramma2(int n, char s2[]);

int anagramma2(int n, char s2[]){
	/*Conversione n a char[] (di nome str)*/
	return anagramma(str, s2);
}


int dimmianagrammi(char str[]){
	FILE *fp;
	char filestr[DIM+1];
	int anagrammi;
	
	fp = fopen(FN, "r");

	if(fp){
		anagrammi = 0;
		fscanf(fp, "%s", filestr);
		while(!feof(fp)){
			if(anagramma(str, filestr)){
				anagrammi++;
				printf("%s\n", filestr);
			}
			fscanf(fp, "%s", filestr);
		}
		fclose(fp);
	}else{
		printf("Errore apertura file\n");
		anagrammi = -1;
	}
	return anagrammi;
}

int dimmianagrammi2(int n){
	FILE *fp;
	char filestr[DIM+1];
	int anagrammi;
	
	fp = fopen(FN, "r");

	if(fp){
		anagrammi = 0;
		fscanf(fp, "%s", filestr);
		while(!feof(fp)){
			if(anagramma2(n, filestr)){
				anagrammi++;
				printf("%s\n", filestr);
			}
			fscanf(fp, "%s", filestr);
		}
		fclose(fp);
	}else{
		printf("Errore apertura file\n");
		anagrammi = -1;
	}
	return anagrammi;
}