/*
Scrivere un programma che chiede all'utente il nome di due file di
testo (due stringhe di al massimo 30 caratteri ciascuna). Il
programma apre i due file e verifica se il loro contenuto è
identico; in caso affermativo il programma stampa a video 1
altrimenti 0. Segnalare a video eventuali casi di errore.
*/

#include <stdio.h>

#define STRDIM 30

int main(){
	char fn1[STRDIM+1], fn2[STRDIM+1];
	FILE *fp1, *fp2;
	char c1, c2;
	int uguali;

	scanf(" %s", fn1);
	scanf(" %s", fn2);

	fp1 = fopen(fn1, "r");

	if(fp1){
		fp2 = fopen(fn2, "r");
		if(fp2){
			uguali = 1;
			fscanf(fp1, "%c", &c1);
			fscanf(fp2, "%c", &c2);
			while(!feof(fp1) && !feof(fp2) && uguali){
				if(c1 != c2)
					uguali = 0;
				fscanf(fp1, "%c", &c1);
			fscanf(fp2, "%c", &c2);
			}

			if(!feof(fp1) || !feof(fp2)) 	/* se almeno uno non è terminato */
				uguali = 0;


			fclose(fp2);
		}else
			printf("Errore apertura file 2\n");
		
		fclose(fp1);
		printf("%d\n", uguali);
	}else
		printf("Errore apertura file 1\n");

	return 0;
}