/*
Scrivere un programma che apre in scrittura un file binario
"ciao.bin". Il programma chiede all'utente quanti valori vuole
acquisire da tastiera, e poi procede con l'acquisizione da tastiera
della serie di numeri ed il loro salvataggio nel file.
*/

#include <stdio.h>
#define FN "ciao.bin"

int main(){
	FILE *fp;
	int quanti, n, i;

	fp = fopen(FN, "wb");
	if(fp){
		scanf("%d", &quanti);
		for(i=0; i<quanti; i++){
			scanf("%d", &n);
			fwrite(&n, sizeof(int), 1, fp);
		}
		fclose(fp);
	}else
		printf("Errore apertura file\n");
	return 0;
}