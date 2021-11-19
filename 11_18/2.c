/*

Scrivere un sottoprogramma che riceve come parametri un array a1 di
interi e la sua dimensione dim. Il sottoprogramma alloca
dinamicamente un array della stessa dimensione dim, vi copia il
contenuto di a1 e lo restituisce al chiamante. Gestire
opportunamente gli eventuali errori di allocazione della memoria.
Scrivere un programma che dichiara un array da 10 elementi interi e
lo popola con i valori letti da tastiera. Il programma invoca il
sottoprogramma sopra definito e visualizza il suo risultato. Infine
il programma rilascia la memoria allocata dinamicamente. Gestire
opportunamente gli eventuali errori di allocazione della memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int* arraydinamico(int[], int);
/*void arraydinamico(int[], int, int**);*/

int main(){
	int a[DIM], i, *p;

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	p = arraydinamico(a, DIM);
	/*arraydinamico(a, DIM, &p);*/

	if(p){
		for(i=0; i<DIM; i++){
			printf("%d\n", p[i]);
		}

		free(p);
	}else
		printf("Errore allocazione\n");

	return 0;
}


int* arraydinamico(int a1[], int dim){
	int *p, i;
	p = malloc(dim*sizeof(int));
	if(p){
		for(i=0; i<dim; i++){
			p[i] = a1[i];
		}
	}else{
		printf("Errore allocazione\n");
	}
	return p;
}
/*
void arraydinamico(int a1[], int dim, int** p){
	int i;
	*p = malloc(dim*sizeof(int));
	if(*p){
		for(i=0; i<dim; i++){
			(*p)[i] = a1[i];
		}
	}else{
		printf("Errore allocazione\n");
	}
	return p;
}
*/