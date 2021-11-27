/*

Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
lezione, scrivere un sottoprogramma listaMedie() che riceve in
ingresso una lista l1 di numeri interi. Il sottoprogramma costruisce
una nuova lista l2 in cui ogni elemento è calcolato come la media
tra un valore di l1 ed il suo successivo. L'ultimo elemento della
lista, per cui non esiste un elemento successivo, viene ricopiato
nella nuova lista. Infine il sottoprogramma restituisce la nuova
lista.
Esempio: se l1 = 8 5 16 7 allora la nuova lista sarà: 6 10 11 7

*/

nodo_t* listaMedie(nodo_t*);

nodo_t* listaMedie(nodo_t *l1){
	nodo_t *l2, *prec, *curr;
	
	l2 = NULL;

	if(l1){
		prec = l1;
		curr = l1->next;
		while(curr){
			l2 = inserisciInCoda(l2, (prec->num+curr->num)/2);
			prec = curr;
			curr = curr->next;
		}

		l2 = inserisciInCoda(l2, prec->num);
	}

	return l2;

}