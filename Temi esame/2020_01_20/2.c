/*
Scrivere un programma che apre un file di testo il cui nome è ricevuto come argomento da riga di comando e contenente una serie di lunghezza indefinita di numeri interi. Il programma stampa a video tutti quei numeri della sequenza per cui la cifra delle decine (se esiste) è il doppio della cifra delle decine del numero che lo precede. Esempio: Sequenza nel file: 1 43 484 113 521 446 55. Output a video: 484 521 446
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN 10
#define BASE 10

int main(int argc, char *argv[]){
	FILE *fp;
	int n, n_prec, n_cifra, n_prec_cifra, n_copy, n_prec_copy;

	if(argc == 2){
		fp = fopen(argv[1], "r");
		if(fp){
			fscanf(fp, "%d", &n);
			n_prec = 0;
			
			while(!feof(fp)){

				/* se decine doppie */
				if(n && n_prec >= MIN){
					n_copy = n;
					n_prec_copy = n_prec;

					n_copy /= BASE;
					n_prec_copy /= BASE;

					n_cifra = n_copy % BASE;
					n_prec_cifra = n_prec_copy % BASE;

					if(n_cifra == n_prec_cifra*2)
						printf("%d ", n);
				}

				n_prec = n;
				fscanf(fp, "%d", &n);
			}
			printf("\n");
			fclose(fp);
		}else
			printf("Errore apertura file\n");
	}else
		printf("Argomenti mancanti\n");

	return 0;
}