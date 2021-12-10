/*

Definireuntipodidatoopportunoperglielementidellalista.
(6pti) Scrivereunsottoprogrammachericevecomeparametrounalistadinumeriintericodici.Ilsottoprogrammacreaerestituisceunanuovalista mancanti contenente tutti i valori interi non presenti in codici compresi tra il valore minimo ed il valore massimo di codici, ordinati in ordine crescente.
Per esempio, se la lista codici contiene i valori
      2 -> 5 -> -1-> -4 -> 3 -|
il sottoprogramma crea e restituisce la seguente lista mancanti:
      -3 -> -2 -> 0 -> 1 -> 4 -|
Se la lista codici contiene i valori
      0 -> -5 -> -1-> -4 -> -3 -> -2 -|
il sottoprogramma crea e restituisce una lista vuota.

*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
Ho usato la libreria fatta in classe che comprende già la struttura, quindi non è necessario dichiararla 
typedef struct nodo_ {
	int num;
	struct nodo_ *next;
} nodo_t;
*/

nodo_t* mancanti(nodo_t*);


int main(){
	/* Main non richiesto, per debugging */
	nodo_t *codici_h, *mancanti_h;

	codici_h = mancanti_h = NULL;
	
	codici_h = inserisciInCoda(codici_h, 2);
	codici_h = inserisciInCoda(codici_h, 5);
	codici_h = inserisciInCoda(codici_h, -1);
	codici_h = inserisciInCoda(codici_h, -4);
	codici_h = inserisciInCoda(codici_h, 3);

	visualizza(codici_h);


	mancanti_h = mancanti(codici_h);

	visualizza(mancanti_h);
	

	return 0;
}


nodo_t* mancanti(nodo_t *codici){
	int min, max, i, presente;
	nodo_t *tmp, *mancanti_h;
	
	mancanti_h = NULL;
	
	if(codici){
		for(min = max = codici->num, tmp = codici; tmp; tmp = tmp->next){
			if(tmp->num < min)
				min = tmp->num;
			if(tmp->num > max)
				max = tmp->num;
		}

		for(i=min; i<=max; i++){
			for(tmp = codici, presente=0; tmp && !presente; tmp = tmp->next){
				if(tmp->num == i)
					presente = 1;
			}
			if(!presente){
				/* Ho usato la libreria fatta in classe, per cui cambia nome ma è la stessa funzione */
				//mancanti_h = insert_inc(mancanti_h, i);
				mancanti_h = inserisciInOrdine(mancanti_h, i);
			}
		}

	}

	return mancanti_h;
}