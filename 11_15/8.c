/*

Scrivere un programma che chiede all'utente 10 valori interi da
salvare in un array. In seguito, il programma apre in scrittura un
file binario "ciao.bin" e vi scrive il contenuto dell'array.

*/
#include <stdio.h>
#define FN "ciao.bin"
#define DIM 10

int main(){
	FILE *fp;
	int n[DIM], i;

	fp = fopen(FN, "wb");
	if(fp){
		for(i=0; i<DIM; i++){
			scanf("%d", &n[i]);
		}
		fwrite(n, sizeof(int), DIM, fp); /*se utilizzi fwrite(n, sizeof(n), 1, fp) il valore restituito dice solamente se array completo o meno, al posto del numero elementi letti*/
		fclose(fp);
	}else
		printf("Errore apertura file\n");
	return 0;
}