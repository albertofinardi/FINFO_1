/*
Scrivere un programma in C che chiede all'utente di inserire 5
numeri interi e li salva in un array. Il programma inverte di ordine
i numeri nell'array e poi li visualizza.

*/

#include <stdio.h>
#define DIM 5

int main(){
	int array[DIM];
	int i, tmp;

	for(i=0; i<DIM; i++){
		scanf("%d", &array[i]);
	}

	for(i=0; i<DIM/2; i++){
		tmp = array[i];
		array[i] = array[DIM-1-i];
		array[DIM-1-i] = tmp;
	}

	for(i=0; i<DIM; i++){
		printf("%d\n", &array[i]);
	}

	return 0;
}