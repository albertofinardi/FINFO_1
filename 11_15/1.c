/*
Scrivere un programma che apre in scrittura un file di testo
"ciao.txt" e vi scrive le cifre da '0' a '9'.
*/

#include <stdio.h> /* CONTIENE SOTTOPROGRAMMI E DEFINIZIONE FILE */
#define FN "ciao.txt"
#define MAX '9'

int main(){
	FILE *fp;
	char i;
	fp = fopen(FN, "w");

	if(fp){
		for(i='0'; i<=MAX; i++)
			fprintf(fp, "%c ", i);
		fclose(fp);	/*NON DIMENTICARTELO*/
	}
	else
		printf("Errore apertura file\n");


	return 0;
}