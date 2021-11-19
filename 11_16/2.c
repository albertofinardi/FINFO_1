/*


Scrivere un programma che apre un file di testo il cui nome è
TEST.txt contenente un sequenza di lunghezza indefinita (0 o più) di
numeri interi. Il programma calcola e stampa a video il valore
massimo e quante volte tale valore si è presentato nel file.

*/

#include <stdio.h>
#define FN "TEST.txt"

int main(){
	int n, max, count;
	FILE *fp;


	fp = fopen(FN, "r");

	if(fp){
		fscanf(fp, "%d", &n);
		if(!feof(fp)){
			max = n;
			count = 1;
			while(!feof(fp)){
				fscanf(fp, "%d", &n);
				if(n == max){
					count++;
				}else if(n > max){
					max = n;
					count = 1;
				}
			}
			printf("Valore massimo %d ripetuto %d volta/e\n", max, count);
		}
		fclose(fp);
	}else
		printf("Errore apertura\n");

	return 0;
}