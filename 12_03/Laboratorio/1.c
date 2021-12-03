/*

Si realizzino i seguenti sottoprogrammi utilizzando la struttura dati e funzioni
fornite nei file lista.c e lista.h.
Scrivere un sottoprogramma estrai() che riceve come parametro una lista dinamica di numeri interi detta l1, e un parametro intero detto dispari. Il sottoprogramma restituisce un puntatore ad una nuova lista l2 contenente gli elementi di l1 in posizione dispari se il parametro dispari vale 1, o gli elementi in posizione pari se il parametro dispari vale 0.
NOTA: con "posizione" si intende l'equivalente dell'indice se stessimo parlando di vettori invece che di liste: il primo elemento della lista ha indice zero (pari), il secondo elemento ha indice 1 (dispari), e così via.
Scrivere un sottoprogramma uguali() che verifica se due liste ricevute come
parametro sono uguali, cioè contengono la stessa sequenza di numeri e restituisce 1
in caso positivo 0 altrimenti.
Scrivere un sottoprogramma stessoContenuto() che verifica se due liste l1 ed l2 ricevute come parametro contengono gli stessi valori, a prescindere dall'ordine; cioè se una lista è una permutazione dell'altra. Il sottoprogramma restituisce 1 in caso positivo 0 altrimenti.
Suggerimento: perché l1 sia permutazione di l2 basta controllare che le due liste abbiano pari lunghezza e che ciascun valore presente in l1 compaia sia in l1 che in l2 lo stesso numero di volte. Si suggerisce inoltre di implementare anche
1) un sottoprogramma di ausilio conta() che riceve come parametri una lista ed un valore intero, e conta e restituisce quante volte il valore intero compare nella lista, ed
2) un sottoprogramma lunghezza() che restituisce la lunghezza di una lista ricevuta come parametro.
Scrivere un sottoprogramma unisci() che riceve come parametri due liste l1 ed l2. Il sottoprogramma crea e restituisce una nuova lista concatenando il contenuto di l1 con quello di l2.
Scrivere un programma che carica dal file di testo "serie.txt" (il cui nome è stato passato come argomento alla chiamata del programma) una serie di lunghezza indefinita di numeri interi e li memorizza in una lista lf. Il programma, invocando i sottoprogrammi sopra definiti,
1) crea una nuova lista lp, contenente i valori in posizione pari della lista lf. 2) crea una nuova lista ld, contenente i valori in posizione dispari della lista lf.
3) verifica se lp è uguale a ld ed in caso negativo se almeno contengono gli stessi numeri sebbene in ordine diverso. Il programma stampa a video gli esiti dei test. 4) genera una nuova lista u in cui appaiono prima tutti gli elementi di lf originariamente in posizione pari e poi gli elementi originariamente in posizione dispari.
5) infine, visualizza (a) la lista di partenza, (b) la lista degli elementi in posizione pari, (c) la lista degli elementi in posizione dispari, (d) la nuova lista con gli elementi riordinati come specificato.
Infine il programma termina deallocando tutta la memoria allocata.

*/

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

nodo_t* estrai(nodo_t*, int);
int uguali(nodo_t*, nodo_t*);
int conta(nodo_t*, int);
int stessoContenuto(nodo_t*, nodo_t*);
nodo_t* unisci(nodo_t*, nodo_t*);

int main(int argc, char const *argv[]){
	FILE *fp;
	nodo_t *lf, *lp, *ld, *u;
	int n;

	lf = lp = ld = u = NULL;

	if(argc == 2){

		fp = fopen(argv[1], "r");
		if(fp){
			fscanf(fp, "%d", &n);
			while(!feof(fp)){
				lf = inserisciInCoda(lf, n);
				fscanf(fp, "%d", &n);
			}
			fclose(fp);

			/* Divisione pari e dispari */
			lp = estrai(lf, 0);
			ld = estrai(lf, 1);

			/*Verifica uguali / stesso contenuto */
			if(uguali(lp, ld))
				printf("Liste uguali\n");
			else if(stessoContenuto(lp, ld))
				printf("Stesso contenuto\n");

			/* Unione prima pari poi dispar i*/
			u = unisci(lp, ld);

			/* Visualizzazione */
			printf("a) ");
			visualizza(lf);
			printf("b) ");
			visualizza(lp);
			printf("c) ");
			visualizza(ld);
			printf("d) ");
			visualizza(u);

			/* Deallocazione memoria */
			distruggi(lf);
			distruggi(lp);
			distruggi(ld);
			distruggi(u);

		}else
			printf("Errore apertura file\n");

	} else
		printf("Argomenti non validi\n");
	
	return 0;
}

nodo_t* estrai(nodo_t *h, int dispari){
	int indice;
	nodo_t *h_estrai;
	h_estrai = NULL;

	indice = 0;
	while(h){
		if(indice%2 && dispari)
				h_estrai = inserisciInCoda(h_estrai, h->num);
		else if(indice%2 == 0 && !dispari)
				h_estrai = inserisciInCoda(h_estrai, h->num);
		
		indice++;
		h = h->next;
	}

	return h_estrai;
}

int uguali(nodo_t *h1, nodo_t *h2){
	int equal;
	equal = 1;
	while(h1 && h2 && equal){

		if(h1->num != h2->num){
			equal = 0;
		}

		h1 = h1->next;
		h2 = h2->next;
	}

	if((!h1 && h2) || (!h2 && h1))
		equal = 0;

	return equal;
}

int conta(nodo_t *h, int n){
	int conta;
	conta = 0;

	while(h){
		conta += h->num == n;
		h = h->next;
	}

	return conta;
}

int stessoContenuto(nodo_t *h1, nodo_t *h2){
	int equal, n;
	equal = 1;

	if(equal && lunghezza(h1) != lunghezza(h2)){
		equal = 0;
	}

	while(equal && h1){
		n = h1->num;
		
		if(conta(h1, n) != conta(h2, n))
			equal = 0;
		
		h1 = h1->next;
	}

	return equal;
}

nodo_t* unisci(nodo_t *h1, nodo_t *h2){
	nodo_t *h;
	h = NULL;

	while(h1){
		h = inserisciInCoda(h, h1->num);
		h1 = h1->next;
	}

	while(h2){
		h = inserisciInCoda(h, h2->num);
		h2 = h2->next;
	}

	return h;
}






