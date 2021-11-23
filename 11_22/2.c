/*

Dopo aver definito un nuovo tipo di dato per memorizzare una lista
dinamica di valori interi, realizzare i seguenti sottoprogrammi
nelle versioni sia iterativa che ricorsiva.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi e ne visualizza il contenuto.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi e ne restituisce la lunghezza.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi ed un intero. Il sottoprogramma restituisce 1 se
il numero è presente nella lista altrimenti 0.
* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi ed un intero. Il sottoprogramma restituisce il
puntatore al primo nodo della lista avente valore pari al numero
ricevuto come parametro; se il numero non è presente restituisce
NULL.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi ed un intero. Il sottoprogramma inserisce in
testa il numero ricevuto come parametro e restituisce la nuova testa
della lista.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi ed un intero. Il sottoprogramma inserisce in coda
il numero ricevuto come parametro e restituisce la testa della
lista.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi. Il sottoprogramma cancella dalla lista il primo
nodo, se presente, e restituisce la nuova testa della lista.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi. Il sottoprogramma cancella dalla lista l'ultimo
nodo, se presente, e restituisce la nuova testa della lista.
* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica di interi ed un intero. Il sottoprogramma cancella dalla
lista la prima istanza del numero intero ricevuto come parametro, se
presente, e restituisce la testa della lista.
-* Scrivere un sottoprogramma che riceve una testa di una lista
dinamica e cancella tutti gli elementi presenti.

Supponendo di avere a disposizione una struttura dati per liste
dinamiche e una serie di funzioni standard di manipolazione delle
liste (come quelle definite sopra), scrivere un programma che
acquisisce da tastiera due sequenze di lunghezza indefinita di
numeri interi ciascuna terminata da uno 0 (che non fa parte della
sequenza); ciascuna sequenza va memorizzata in una lista. Il
programma calcola l'intersezione delle due sequenze rimuovendo
eventuali duplicati, salvando il risultato in una terza lista e
visualizzandolo. Il programma libera tutta la memoria allocata prima
di terminare.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_ {
	int n;
	struct nodo_ *next;
} nodo_t;

void visualizza(nodo_t*);

int lunghezza(nodo_t*);
int lunghezza_ric(nodo_t*);

nodo_t* inserisciTesta(nodo_t*, int);

int presente(nodo_t*, int);
int presente_ric(nodo_t*, int);

nodo_t* inserisciCoda(nodo_t*, int);
nodo_t* inserisciCoda_ric(nodo_t*, int);

nodo_t* cancellaTesta(nodo_t*);

nodo_t* cancella(nodo_t*);

nodo_t* cancellaValore(nodo_t*, int);
nodo_t* cancellaValore_ric(nodo_t*, int);

nodo_t* cancellaTutti(nodo_t*, int);

int main(){

	nodo_t *h1, *h2, *h3, *curr;
	int n;

	h1 = NULL;
	h2 = NULL;
	h3 = NULL;

	scanf("%d" &n);
	while(n!=0){
		h1 = inserisciCoda(h1, n);
		scanf("%d", &n);
	}

	while(n!=0){
		h2 = inserisciCoda(h2, n);
		scanf("%d", &n);
	}
	for(curr = h1; curr; curr = curr->next){
		if(!presente(h3, curr->n) && presente(h2, curr->n)){
			h3 = inserisciCoda(h3, curr->n);
		}
	}

	visualizza(h3);

	h1 = cancella(h1);
	h2 = cancella(h2);
	h3 = cancella(h3);

	return 0;
}

void visualizza(nodo_t* h){
	/* puntatori semplici son passati per valore, per indirizzo con doppio puntatore */
	for( ; h; h = h->next){
		printf("%d\n", h->n);
	}
	/*
	while(h){
		printf("%d\n", h->n);
		h = h->next;
	}
	*/
}

int lunghezza(nodo_t *h){
	int len;
	len = 0;
	while(h){
		len++;
		h = h->next;
	}
}

int lunghezza_ric(nodo_t *h){
	if(h == NULL){
		return 0;
	}
	return 1+lunghezza_ric(h->next);
}

nodo_t* inserisciTesta(nodo_t *h, int  n){
	nodo_t *tmp;

	tmp = malloc(sizeof(nodo_t));

	if(tmp){

		tmp->n = n;
		tmp->next = h;
		h = tmp;
	
	}else
		printf("Errore allocazione\n");
	

	return h;
}

int presente(nodo_t *h, int n){
	for( ; h && h->n != n; h = h->next);
	
	return h != NULL;
/*
	while(h && h->n != n){
		
		h = h->next;
	}

	return h != NULL;*/
}

int presente_ric(nodo_t *h, int n){
	
	if(!h || h->n == n) /* non invertibili -> valutazione a corto circuito */
		return h != NULL;

	return presente_ric(h->next, n);
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

nodo_t* inserisciCoda_ric(nodo_t *h, int n){
	nodo_t *tmp;
	if(!h)
		/* lista vuota */
		return inserisciTesta(h, n);

	h->next = inserisciCoda_ric(h->next, n);
	return h;
}

nodo_t* cancella(nodo_t *h){
	nodo_t *tmp;
	while(h){
		tmp = h;
		h = h->next;
		free(tmp);
	}
	return h; /* sarà sicuramente NULL */
}

nodo_t* cancellaTesta(nodo_t *h){
	nodo_t *tmp;

	tmp = h;
	h = h->next
	free(tmp);

	return h;
}

nodo_t* cancellaValore(nodo_t *h, int n){
	nodo_t *curr, *prec;

	curr = h;
	prec = NULL;

	while(curr && curr->n != n){
		prec = curr;
		curr = curr->next;
	}
	if(curr){
		if(prec)
			prec->next = curr->next;
		else
			h = curr->next;
		free(curr);
	}

	return h;
}

nodo_t* cancellaTutti(nodo_t *h, int n){
	nodo_t *curr, *prec, *canc;

	curr = h;
	prec = NULL;

	while(curr){
		if(curr->n == n){
			canc = curr;
			curr = curr->next;
			if(!prec)
				h = curr;
			else
				prec->next = curr;

			free(canc);
		} else {
			prec = curr;
			curr = curr->next;
		}
	}

	return h;
}

nodo_t* cancellaValore_ric(nodo_t *h, int n){
	nodo_t *tmp;
	if(!h)
		return NULL;

	if(h->n == n){
		tmp = h;
		h = h->next;
		free(tmp);
		return h;
	}

	h->next = cancellaValore_ric(h->next, n);
	return h;
}
