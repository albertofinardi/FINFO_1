/*

Scrivere un sottoprogramma che riceve come parametro una stringa che
rappresenta il nome di un file che contiene una sequenza di
lunghezza indefinita di numeri interi. Il sottoprogramma apre in
lettura il file binario e crea una nuova lista dinamica popolandola
con il contenuto del file. Il sottoprogramma restituisce infine la
testa della nuova lista creata.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
	int num;
	struct nodo_ *next;
} nodo_t;

nodo_t* fileTolist(char[]);
nodo_t* inserisciCoda(nodo_t*, int);


nodo_t* fileTolist(char fn[]){
	int n;
	FILE *fp;
	nodo_t* h;

	fp = fopen(fn, "rb");
	h = NULL;

	if(fp){

		fread(&n, sizeof(int), 1, fp);

		while(!feof(fp)){
			/* Aggiungi nodo alla lista in coda */
			h = aggiungiInCoda(h, n);
			fread(&n, sizeof(int), 1, fp);
		}

		fclose(fp);
	}else{
		printf("Errore apertura file\n");
	}

	return h;
}

nodo_t* inserisciCoda(nodo_t *h, int n){
	nodo_t *prec, *tmp;

	tmp = malloc(sizeof(nodo_t));

	if(tmp){
		tmp->n = n;
		tmp->next = NULL;
		if(h == NULL)
			/*lista vuota */
			h = tmp;
		else{
			for(prec = h; prec->next; prec=prec->next); /*possiamo farlo solamente se la lista non è vuota -> bisogna mettere prima un if */
			prec->next = tmp;
		}
	}else
		printf("Errore allocazione\n");

	return h;
}