/*
Scrivere un programma in C che chiede all'utente di inserire i dati
interi di un array bidimensionale quadrato di dimensione 4x4 e
visualizza 1 se si tratta di una matrice identità, altrimenti 0.
*/
#include <stdio.h>
#define DIM 4

int main(){
	int matx[DIM][DIM], i, j, ident;

	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			scanf("%d", &matx[i][j]);
		}
	}

	for(i=0, ident=1; i<DIM && ident; i++){
		for(j=0; j<DIM && ident; j++){
			if((i==j && matx[i][j] != 1) || (i!=j && matx[i][j] != 0))
					ident = 0;
		}
	}
	printf("%d\n", ident);

	return 0;
}