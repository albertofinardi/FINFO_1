/*
Scrivere un sottoprogramma che riceve come parametri un array di
interi a e la sua dimensione dim. Il sottoprogramma copia in un
secondo array b i numeri pari contenuti in a; si noti che b deve
essere allocato dinamicamente delle dimensioni strettamente
necessarie per contenere i numeri pari. Infine il sottoprogramma
trasmette al chiamante b e la sua dimensione. Gestire opportunamente
gli eventuali errori di allocazione della memoria trasmettendo una
dimensione dell'array allocato pari a -1.
Scrivere un programma che chiede all'utente 10 valori interi da
salvare in un array. Il programma invoca il sottoprogramma sopra
definito e ne visualizza il risultato. Infine il programma libera la
memoria allocata. Gestire opportunamente gli eventuali errori di
allocazione della memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void arraypari(int[], int, int**, int*);

int main(){
	int a[DIM], i;
	int *b, dim_b;


	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	arraypari(a, DIM, &b, &dim_b);

	if(b){
		for(i=0; i<dim_b; i++){
			printf("%d\n", b[i]);
		}
		free(b);
	}else{
		printf("Errore allocazione\n");
	}

	return 0;
}

void arraypari(int a[], int dim_a, int** b, int* dim_b){
	int i, j;
	for(i=0, *dim_b = 0; i<dim_a; i++){
		if(!(a[i]%2)){
			(*dim_b)++;
		}
	}

	if(*dim_b)
		*b = malloc((*dim_b) * sizeof(int));
	else
		*b = NULL;

	if(*b){
		for(i=0, *dim_b=0; i<dim_a; i++){
			if(!(a[i]%2)){
				(*b)[*dim_b] = a[i];
				(*dim_b)++;
			}
		}
	}else{
		printf("Errore allocazione\n");
		*dim_b = -1;
	}

}