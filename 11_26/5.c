/*
Scrivere un sottoprogramma che riceve in ingresso una lista per la gestione dei numeri interi ed un valore intero dir. Il sottoprogramma effettua una rotazione a sinistra (se dir vale 0) o a destra (se dir vale 1) del contenuto della lista, restituendola modificata al chiamante. Nella rotazione a sinistra, il primo valore viene posto in fondo alla lista, nello scorrimento a destra, l’ultimo valore della lista viene messo davanti a tutti gli altri.
Nel caso in cui la lista è vuota o contiene un solo elemento, il sottoprogramma restituisce la lista ricevuta in ingresso. Si suggerisce di sviluppare due sottoprogrammi separati, uno che esegua la rotazione a sinistra, uno che esegua quella a destra. Non causare memory leakage: situazione in cui ci sono nodi non più accessibili senza aver effettivamente rilasciato la memoria.

Si considerino già disponibili e non da sviluppare i sottoprogrammi seguenti:

/* inserisce in testa alla lista 
elem_t * push(elem_t *, int );
/* inserisce in coda alla lista 
elem_t * append(elem_t *, int );
/* inserisce un elemento nella lista in ordine crescente 
elem_t * insert_inc(elem_t *, int);
/* inserisce un elemento nella lista in ordine decrescente 
elem_t * insert_dec(elem_t *, int );
/* elimina dalla lista il primo elemento 
elem_t * pop ( elem_t * ) ;
/* elimina dalla lista tutti gli elementi con il valore indicato 
elem_t * delete(elem_t *, int);
/* restituisce il riferimento all ’elemento nella lista che ha il valore indicato , se esiste , NULL altrimenti 
elem_t * exists(elem_t *, int);
/* restituisce il numero di elementi nella lista 
int length(elem_t *);

*/

typedef struct nodo_{
	int n;
	struct nodo_ *next;
} nodo_t;

nodo_t* rotazione(nodo_t *h, int dir){
	if(!(h == NULL || lenght(h) == 1)){
		if(dir == 0)
			return rotazioneSinistra(h);
		if(dir == 1)
			return rotazioneDestra(h);
	}
	else
		return h;
}

nodo_t* rotazioneSinistra(nodo_t *h){
	nodo_t *tmp;
	
	tmp = h->next;
	if(tmp){
		h = pop(h);
		h = append(tmp);
	}else
		printf("Errore allocazione memoria\n");
}

nodo_t* rotazioneDestra(nodo_t *h){
	nodo_t *tmp;

	tmp = h;
	while((tmp->next)->next){
		tmp = tmp->next;
	}

	h = push(h, tmp->n);

	free(tmp->next);
	tmp->next = NULL;
	return h;
}