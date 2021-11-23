/*
Programma che riceve da riga di comando nome del file di testo contenente una sequenza di lunghezza indefinita di numeri interi ed
un valore interno n. Il programma legge dal file di testo i valori e stampa a video in ordine inverso solo i valori inferiori ad n. 
Gestire opportunamente gli errori. Se necessario si supponga di avere a disposizione libreria gestione liste dinamiche */

#include <stdlib.h>
#include <stdio.h>

typedef struct nodo_ {
	int n;
	struct nodo_ next;
} nodo_t;


node_t* aggiungiTesta(node_t *h, int n);
void stampaLista(node_t*);
void liberaMemoria(node_t*);

int main(int argc, char *argv[]){
	int n, curr;
	File *fp;
	nodo_t *h;

	h = NULL;

	if(argc == 3){
		n = atoi(argv[2]);
		fp = fopen(argv[1], "r");

		if(fp){
			fscanf(fp, "%d", &curr);

			while(!feof(fp)){
				if(curr < n)
					h = aggiungiTesta(h, curr);
				fscanf(fp, "%d", &curr);
			}

			fclose(fp);

			stampaLista(h);
			liberaMemoria(h);

		}else
			printf("Errore apertura file\n");

	}else
		printf("Errore argomenti\n");
	return 0;
}

node_t* aggiungiTesta(node_t *h, int n){
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

void stampaLista(node_t *h){

	for( ; h; h = h->next)
		printf("%d\n", h->n);

}

void liberaMemoria(node_t *h){
	nodo_t *tmp;
	while(h){
		tmp = h;
		h = h->next;
		free(tmp);
	}
}