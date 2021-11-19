/*
Scrivere un programma apre in lettura un file "ciao.txt". Il
programma legge la sequenza di caratteri salvati nel file (la cui
lunghezza non è nota a priori) e la visualizza.
*/

#include <stdio.h>
#define FN "ciao.txt"

int main(){
	FILE *fp;
	char c;

	fp = fopen(FN, "r");

	if(fp){
		fscanf(fp, "%c", &c);

		while(!feof(fp)){
			printf("%c ", c);
			fscanf(fp, "%c", &c);	/*se file finito, in c non viene salvato nulla di nuovo (ultimo valore valido rimane)*/
		}

		printf("\n");
		fclose(fp);
	} else
		printf("Errore apertura file\n");

	return 0;
}

	/* STRUTTURA LETTURA FILE E' SEMPRE QUESTA */