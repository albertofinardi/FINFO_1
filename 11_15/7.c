/*
Scrivere un programma apre in lettura un file di testo "ciao.bin".
Il programma legge la sequenza di valori interi salvati nel file (la
cui lunghezza non è nota a priori) e la visualizza.
*/

#include <stdio.h>
#define FN "ciao.bin"

int main(){
	FILE *fp;
	int n;

	fp = fopen(FN, "rb");
	if(fp){
		fread(&n, sizeof(int), 1, fp);
		while(!feof(fp)){
			printf("%d\n", n);
			fread(&n, sizeof(int), 1, fp);
		}
		fclose(fp);
	}else
		printf("Errore apertura file\n");
	return 0;
}