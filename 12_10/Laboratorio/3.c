/*

Considerando la struttura dati ed i sottoprogrammi contenuti nei file lista.c e lista.h, implementare un sottoprogramma che riceve come parametri una lista dinamica di interi l1 ed un array di interi sel. Assumendo che sel contenga solo valori 0 e 1 e che sia di dimensione pari a l1, il sottoprogramma costruisce e restituisce una nuova lista l2 che contiene solo gli elementi di l1 che si trovano nella lista in una posizione corrispondente agli 1 del vettore sel.
Esempio: se il sottoprogramma riceve in ingresso
l1 = 3 -> 5 -> 8 -> 9 -> 12
vet = [0, 1, 0, 1, 1]
dovrà ritornare la lista
l2 = 5 -> 9 -> 12
Scrivere un programma che chiede all'utente una sequenza di lunghezza indefinita di numeri interi chiesta all'utente e terminata dal valore 0 (che non fa parte della sequenza) per popolare una lista dinamica. In seguito il programma chiede all'utente un array di valori interi 0 e 1 di lunghezza pari a quella della lista (array da allocare dinamicamente!). Il programma invoca il sottoprogramma sopra definito, visualizza la lista restituita e libera tutta la memoria allocata. Gestire opportunamente tutti gli eventuali errori.

*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define TERMINATION 0

nodo_t* filter(nodo_t*, int[]);

int main(int argc, char *argv[]){
	nodo_t *h, *tmp, *l2;
	
	int *arr;
	int n, dim, i;
	
	arr = NULL;
	tmp = h = NULL;

	scanf("%d", &n);
	while(n != TERMINATION){
		h = inserisciInCoda(h, n);
		scanf("%d", &n);
	}

	for(dim=0, tmp=h; tmp; tmp = tmp->next){
		dim++;
	}

	printf("Inserire valori array\n");

	arr = malloc(sizeof(int)*dim);
	if(arr){
		for(i=0; i<dim; i++){
			scanf("%d", &n);
			while(n != 0 && n != 1){
				printf("Valore non valido (valori validi: 0, 1)\n");
				scanf("%d", &n);
			}
			arr[i] = n;
		}
		l2 = filter(h, arr);
		visualizza(l2);
		free(arr);
	}else{
		printf("Errore allocazione memoria\n");
	}

	distruggiLista(h);
	distruggiLista(l2);

	return 0;
}


nodo_t* filter(nodo_t *l1, int sel[]){
	int dim, i;
	nodo_t *tmp, *l2;

	l2 = tmp = NULL;

	for(dim=0, tmp=l1; tmp; tmp = tmp->next){
		dim++;
	}
	for(i=0, tmp=l1; i<dim && tmp; tmp = tmp->next, i++){
		if(sel[i]){
			l2 = inserisciInCoda(l2, tmp->num);
		}
	}

	return l2;

}