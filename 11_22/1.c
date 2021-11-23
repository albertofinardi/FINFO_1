/*

Dichiarare un nuovo tipo di dato di tipo basato sul modello della
lista concatenata per memorizzare una sequenza di lunghezza
indefinita di numeri interi.
Scrivere un programma che svolge le seguenti elaborazioni:
- chiede all'utente una sequenza di lunghezza indefinita di numeri
interi positivi terminata da un valore non valido e la salva in una
lista utilizzando un inserimento in testa (cioè ogni nuovo numero
viene inserito in testa alla lista)
- visualizza il contenuto della lista
- libera la memoria allocata dinamicamente per la lista.

*/

#include <stdio.h>

typedef struct nodo_{
	int n;
	struct nodo_ *next; /* non usare nodo_t -> non è ancora definito come nome */
} nodo_t;

int main(){
	nodo_t *h, *tmp;
	int n;

	h = NULL;
	scanf("%d", &n);
	
	/*INPUT*/
	while(n>0){
		tmp = malloc(sizeof(nodo_t));
		if(tmp){
			tmp->n = n; 						/* (*tmp).n = n */
			tmp->next = h;
			h = tmp;
		}else
			printf("Errore allocazione\n");
		scanf("%d", &n);
	}

	/*OUTPUT*/
	for(tmp = h; tmp; tmp = tmp->next){
		/* partendo dalla testa, se tmp è valido ( != NULL), si passa a tmp successivo -> non usare ++, dati non sequenziali nell'heap */
		printf("%d\n", tmp->n);
	}

	/*LIBERA MEMORIA*/
	while(h){
		/* finchè head punta a qualcosa, libera memoria un nodo alla volta */
		tmp = h;
		h = h->next;
		free(tmp);
	}



	return 0;
}