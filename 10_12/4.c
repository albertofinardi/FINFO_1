/*

Scrivere un programma in C che chiede all'utente i dati di due
matrici di interi, la prima 5x5 e la seconda 2x2. Il programma
calcola e visualizza il numero di volte che la seconda matrice è
contenuta nella prima.

*/

#include <stdio.h>
#define DIM1 5
#define DIM2 2

int main(){

	int a[DIM1][DIM1], b[DIM2][DIM2], i, j, h, k, conto, issub;

	for(i=0; i<DIM1; i++)
		for(j=0; j<DIM1; j++)
			scanf("%d", &a[i][j]);

	printf("Seconda matrice\n");

	for(i=0; i<DIM2; i++)
		for(j=0; j<DIM2; j++)
			scanf("%d", &b[i][j]);

	for(i=0, conto=0; i<=DIM1-DIM2; i++){
		for(j=0; j<=DIM1-DIM2; j++){
			for(h=0, issub=1; h<DIM2 && issub; h++){
				for(k=0; k<DIM2 && issub; k++){
					if(a[i+h][j+k] != b[h][k])
						issub = 0;
				}
				if(issub)
					conto++;
			}
		}
	}	

	printf("%d\n", conto);

	return 0;
}