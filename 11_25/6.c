/*

Utilizzando la definizione di tipo lista e i sottoprogrammi visti a
lezione, scrivere un sottoprogramma che riceve come parametro una
lista l1 contenente una serie di numeri interi e due puntatori a
lista lp e ln passati per indirizzo e che non puntano ad alcun
indirizzo valido. Il sottoprogramma costruisce due nuove liste,
assegnandole a lp e ln, la prima contenente i soli elementi positivi
di l1 e la seconda i restanti elementi neutri o negativi. La
funzione restituisce entrambe le liste al chiamante.

*/

void splitListe(nodo_t*, nodo_t**, nodo_t**);



void splitListe(nodo_t *l1, nodo_t **lp, nodo_t **ln){
	*lp = NULL;
	*ln = NULL;

	while(l1){
		if(l1->num <= 0)
			*ln = inserisciInCoda(*ln, l1->num);
		else
			*lp = inserisciInCoda(*lp, l1->num);
		l1 = l1->next;
	}

}