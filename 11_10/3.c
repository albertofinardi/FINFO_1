/*
Scrivere un programma in C che chiede all'utente il contenuto di una
matrice quadrata 5x5 di interi. Il programma calcola e visualizza
gli indici (i, j) ed il valore dei massimi locali della matrice. Un
massimo locale è definito come un elemento della matrice i cui
adiacenti sono tutti minori o uguali ad esso.
*/
#include <stdio.h>
#define DIM 5
#define DIMCMP 3

int main(){
	int m[DIM][DIM], i, j, x, y, ismax;

	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			scanf("%d", &m[i][j]);

	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			for(x=-DIMCMP/2, ismax=1; x<=DIMCPM/2 && ismax; x++){
				for(y=-DIMCMP/2; y<=DIMCMP/2 && ismax; y++){
					if(i+x < DIM && i+x >=0 && j+y<DIM && j+y >=0 && m[i+x][j+y] > m[i][j]){
						ismax = 0;
					}
				}
			}
			if(ismax){
				printf("m[%d][%d] = %d\n", i, j, m[i][j]);
			}
		}
	}

	return 0;
}