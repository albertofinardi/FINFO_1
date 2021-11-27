/*

Scrivere un sottoprogramma che riceve come parametri una lista
dinamica di interi ordinata in ordine crescente ed un valore intero.
Il sottoprogramma inserisce il nuovo elemento nella lista
preservando l'ordine crescente e restituisce la testa della lista al
chiamante. Realizzare sia la versione iterativa che ricorsiva del
sottoprogramma.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
	int num;
	struct nodo_ *next;
} nodo_t;

nodo_t* inserisci_crescente(nodo_t*, int);
nodo_t* inserisci_crescente_ric(nodo_t*, int);

int main(){

	return 0;
}

nodo_t* inserisci_crescente(nodo_t *h, int n){
	nodo_t *tmp, *prec, *curr;

	tmp = malloc(sizeof(nodo_t));

	if(tmp){
		tmp->num = n;
		tmp->next = NULL;
		if(h && n> h->num){
			for(prec = h, curr=h->next; curr && n > curr->num; prec = curr, curr = curr->next); /* non invertire le condizioni */
			tmp->next = curr;
			prec->next = tmp;

		}else{
			tmp->next = h;
			h = tmp;

		}
	}else
		printf("Errore allocazione memoria\n");

	return h;
}

nodo_t* inserisci_crescente_ric(nodo_t *h, int n){
	if(!h || n <= h->num){
		return inserisciInTesta(h, n); /* definita nella libreria */
	}

	h->next = inserisci_crescente_ric(h->next, n);
	return h;
}