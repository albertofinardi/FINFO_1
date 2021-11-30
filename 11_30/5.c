/*

(6punti) Scrivereunsottoprogrammaint2listchericevutoiningressounnumerointerorestituisceunalistaincuiognicifradelnumeroiningresso compare tante volte quanto il suo valore. Nel caso in cui il valore ricevuto in ingresso sia negativo, il sottoprogramma restituisce la lista creata a partire dalla cifre in ordine opposto. Se per esempio il sottoprogramma riceve in ingresso l’intero 3204, il sottoprogramma restituisce la lista seguente:
3→3→3→2→2→4→4→4→4
Se per esempio il sottoprogramma riceve in ingresso l’intero -3204, il sottoprogramma restituisce la lista seguente:
4→4→4→4→2→2→3→3→3
(1punto) Definireuntipodidatoopportunoperlalista.
(1punto) Scrivereunprogrammacheacquisiscedarigadicomandoilvaloreinteroechiamailsottoprogrammaint2list.
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define BASE 10

/*
Per punto 2 del quesito, ma già presente all'interno della libreria
typedef struct nodo_ {
	int num;
	struct nodo_ *next;
} nodo_t; 
*/

nodo_t* int2list(int);

int main(int argc, char const *argv[])
{
	nodo_t *h;
	int n;
	h = NULL;
	if(argc == 2){
		n = atoi(argv[1]);
		h = int2list(n);
		visualizza(h);
	}else{
		printf("Argomenti errati\n");
	}
	return 0;
}


nodo_t* int2list(int n){
	nodo_t *h;
	int cifra, i, neg;

	h = NULL;

	if(n>0){
		neg = 0;
	}else{
		neg = 1;
		n = -n;
	}

	while(n>0){
			cifra = n%BASE;

			for(i=0; i<cifra; i++){
				/*Cifra dalla più a DX a quella più SX -> quindi già ribaltate */
				if(neg)
					h = inserisciInCoda(h, cifra);
				else
					h = inserisciInTesta(h, cifra);
			}


			n = n/BASE;
	}
	return h;
}