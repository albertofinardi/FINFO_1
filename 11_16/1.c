/*

Scrivere un programma che apre un file di testo il cui nome di al
massimo 30 caratteri va chiesto all'utente e che contiene una
sequenza di lunghezza indefinita (0 o più) di numeri interi. Per
ciascun numero letto, il programma stabilisce se è il doppio del
suo precedente; in tal caso stampa a video la coppia di numeri.
Esempio: se il contenuto del file è "1 2 5 2 4 8 5 4 5", il
programma stampa a video:
12 
24 
48

*/

#include <stdio.h>

#define STRDIM 30

int main(){
	FILE *fp;
	char fn[STRDIM+1];
	int n, n_old;

	scanf("%s", fn);

	fp = fopen(fn, "r");

	if(fp){

		fscanf(fp, "%d", &n);

		while(!feof(fp)){
			n_old = n;
			fscanf(fp, "%d", &n);
			if(n_old*2 == n){
				printf("%d %d\n", n_old, n);
			}
		}
		fclose(fp);
		printf("\n");
	} else
		printf("Errore apertura\n");

	return 0;
}