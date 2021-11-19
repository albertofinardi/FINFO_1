/*
Scrivere un programma che apre in scrittura un file di testo il cui
nome, di al massimo 30 caratteri, è chiesto all'utente. In seguito,
il programma chiede all'utente quanti valori interi vuole acquisire
da tastiera, e poi procede con l'acquisizione da tastiera della
serie di numeri ed il loro salvataggio nel file.
*/

#include <stdio.h>
#define DIMSTR 30

int main(){
	FILE *fp;
	char filename[DIMSTR+1];
	int i, max, curr;

	scanf("%s", filename);
	scanf("%d", &max);

	fp = fopen(filename, "w");

	if(fp){
		for(i=0; i<max; i++){
			scanf("%d", &curr);
			fprintf(fp, "%d ", curr);
		}
		fclose(fp);
	}else
		printf("Errore apertura file\n");

	return 0;
}