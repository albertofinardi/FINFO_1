/*
Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
lezione, scrivere un sottoprogramma che ricevute in ingresso due
liste, ne restituisce una nuova creata alternando gli elementi delle
due liste, e poi mettendo in coda tutti quelli della lista più
lunga. Ad esempio, se le liste in ingresso sono fatte come segue,
1 3 5 7 9 11
2 4 6 8 
la lista creata sarà fatta come segue 
1 2 3 4 5 6 7 8 9 11

*/

/* DA RIVEDERE */

nodo_t* alternaElementi(nodo_t*, nodo_t*);


nodo_t* alternaElementi(nodo_t *l1, nodo_t *l2){
	nodo_t *h;
	h = NULL;

	if(l1 && l2){
		h = l1;
		l1 = l1->next
		for(i=1; l1 && l2; i++){
			if(i%2){
				/*dispari -> aggiungi l2*/
				h = aggiungiInCoda(h, l2->num);
				l2 = l2->next;
			}else{
				/*pari -> aggiungi l1*/
				h = aggiungiInCoda(h, l1->num);
				l1 = l1->next;
			}
		}

		if(!l1 && l2){
			/*l1 finita, l2 no*/
			while(l2){
				h = aggiungiInCoda(h, l2->num);
				l2 = l2->next;
			}
		}else if(l1 && !l2){
			/*l2 finita, l1 no*/
			while(l1){
				h = aggiungiInCoda(h, l1->num);
				l1 = l1->next;
			}
		}

	}else if(l1){
		/* l2 vuota */
		h = l1;
	}else if(l2){
		/* l1 vuota */
		h = l1;
	}

	return h;
}