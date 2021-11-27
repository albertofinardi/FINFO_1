/*

Scrivere un sottoprogramma che riceve come parametri una lista di
interi ed una stringa che rappresenta il nome di un file. Il
sottoprogramma apre in scrittura il file binario il cui nome è stato
ricevuto come parametro e vi salva il contenuto della lista.


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
	int num;
	struct nodo_ *next;
} nodo_t;

void listToFile(nodo_t*, char[]);


void listToFile(nodo_t* h, char fn[]){
	FILE *fp;

	fp = fopen(fn, "wb");

	if(fp){
		while(h){
			fwrite(&(h->num), sizeof(int), 1, fp);
			h = h->next;
		}

		fclose(fp);
	}else
	 printf("Errore apertura file\n");
}

