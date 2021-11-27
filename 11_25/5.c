/*
Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
lezione, scrivere un sottoprogramma che riceve una lista dinamica di
numeri l1 e da questa costruisce una nuova lista l2 come segue: gli
elementi di l1 vengono presi a coppie e viene inserito prima il
secondo elemento della coppia e poi il primo. Nel caso la lista l1
contenga un numero dispari di elementi, l'ultimo elemento viene
semplicemente copiato alla fine di l2. Esempio:
l1 = 1 2 3 4 5 6 7
l2 = 2 1 4 3 6 5 7
*/

nodo_t* swapCoppie(nodo_t*);


nodo_t* swapCoppie(nodo_t *l1){
	nodo_t *prec, *curr, *l2;
	l2 = NULL;

	if(l1){
		prec = l1;
		curr = l1->next;
		while(curr){
			l2 = inserisciInCoda(l2, curr);
			l2 = inserisciInCoda(l2, prec);

			prec = curr->next;
			if(prec){
				curr = prec->next;
			}else{
				curr = NULL;
			}
		}

		if(!curr && prec){
			l2 = inserisciInCoda(l2, prec);
		}
	}

	return l2;
}