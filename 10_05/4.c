/*
Scrivere un programma in C che chiede i dati di due matrici quadrate
4x4 di interi. Il programma calcola e visualizza il loro prodotto
matriciale.
*/

#include <stdio.h>
#define DIM 4

int main(){
	int m1[DIM][DIM], m2[DIM][DIM], i, j, k, ris[DIM][DIM];

	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			scanf("%d", &m1[i][j]);

	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			scanf("%d", &m2[i][j]);

	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			for(k=0, ris[i][j] = 0; k<DIM; k++)
				ris[i][j] += m1[i][k] * m2[k][j];

	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++)
			printf("%d\t", ris[i][j]);
		printf("\n");
	}

	return 0;
}