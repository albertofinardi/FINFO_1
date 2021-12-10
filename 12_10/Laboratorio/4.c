/*

Considerando la struttura dati ed i sottoprogrammi contenuti nei file lista.c e lista.h, implementare un sottoprogramma che riceve come parametro una lista dinamica di interi l. Il sottoprogramma crea e restituisce una nuova lista contenente soltanto quegli elementi di l strettamente minori di tutti i relativi precedenti in l (il primo elemento se esiste va comunque aggiunto alla nuova lista poiché non ha precedenti).
Esempio: se il sottoprogramma riceve in ingresso
l1 = 8 -> 5 -> 8 -> 2 -> 12 -> 3 -> 2 -> 1
dovrà ritornare la lista
l2 = 8 -> 5 -> 2 -> 1
Scrivere un programma che chiede all'utente una lista di interi terminata dal valore 0, che non fa parte della lista. Il programma invoca il sottoprogramma sopra definito e visualizza il risultato. Gestire opportunamente il rilascio di tutte le risorse allocate.

*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define TERMINATION 0

nodo_t* strettMinori(nodo_t*);

int main(int argc, char *argv[]){
	int n;
	nodo_t *l, *l2;
	l = l2 = NULL;

	scanf("%d", &n);
	while(n != TERMINATION){
		l = inserisciInCoda(l, n);
		scanf("%d", &n);
	}

	l2 = strettMinori(l);

	visualizza(l2);

	distruggiLista(l);
	distruggiLista(l2);

	return 0;
}

nodo_t* strettMinori(nodo_t *l){
	int minore;
	nodo_t *tmp, *l2, *tmp2;
	l2 = tmp = NULL;
	if(l){
		l2 = inserisciInCoda(l2, l->num);
		for(tmp = l->next; tmp; tmp=tmp->next){
			for(minore = 1, tmp2 = l; tmp2 && tmp2 != tmp && minore; tmp2 = tmp2->next){
				if(tmp->num >= tmp2->num)
					minore = 0;
			}
			if(minore)
				l2 = inserisciInCoda(l2, tmp->num);
		}
	}

	return l2;
}