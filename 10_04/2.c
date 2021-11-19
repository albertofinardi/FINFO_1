/*
Scrivere un programma in C che chiede all'utente di inserire i dati
interi di una matrice bidimensionale quadrata di dimensione 5. Il
programma calcola la matrice ruotata di 90 gradi in senso
antiorario, salvandola in una nuova variabile e visualizza il
risultato.
*/

#include <stdio.h>
#define DIM 5

int main(){
	int m[DIM][DIM], i, j, ruotata[DIM][DIM];

	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			scanf("%d", &m[i][j]);

	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			ruotata[DIM-1-j][i]=m[i][j];
		}
	}
	
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++)
			printf("%d\t", &ruotata[i][j]);
		printf("\n");
	}


	return 0;
}
