/*
Scrivere un programma apre in lettura un file di testo "ciao.bin"
che contiene 10 valori interi. Il programma legge i valori e
verifica che siano stati letti tutti correttamente. In caso
affermativo li visualizza altrimenti segnala l'errore.
*/

#include <stdio.h>
#define FN "ciao.bin"
#define DIM 10

int main(){
	FILE *fp;
	int n[DIM], i, quanti;

	fp = fopen(FN, "rb");
	if(fp){
		quanti = fread(n, sizeof(int), DIM, fp); /* fscanf e fread restituiscono numero valori letti */
		if(quanti != DIM){
			printf("Errore\n");
		}else{
			for(i=0; i<DIM; i++)
				printf("%d\n", n[i]);
		}
		
		fclose(fp);
	}else
		printf("Errore apertura file\n");
	
	return 0;
}