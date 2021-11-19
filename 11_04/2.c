/*


Scrivere un sottoprogramma che riceve in ingresso un array
bidimensionale di interi mat (dichiarato nel chiamate con NCOL=10),
un intero val e qualsiasi parametro ritenuto strettamente necessario
e trasmette al chiamate gli indici di riga e colonna che
identificano la posizione del primo elemento (scandendo l'array per
righe) che, sommato a tutti i suoi precedenti, dia come risultato un
valore > val. Nel caso in cui tal elemento non esista, si
trasmettono i valori -1, -1.
*/

#include <stdio.h>
#define NCOL 10

#define NROW 10

#define EXIT -1

void indici(int[][NCOL], int, int, int*, int*);

int main(){

	int mat[NROW][CNOL];
	int val, col, row, i, j;

	for(i=0; i<NROW; i++){
		for(j=0; j<NCOL; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	scanf("%d", &val);

	indici(mat, NROW, NCOL, val, &row, &col);

	printf("%d %d\n", row, col);

	return 0;
}

void indici(int mat[][NCOL], int n_row, int n_col, int val, int *row, int *col){
	int i, j, sum, fine;

	for(i=0, sum=0, fine=0; i<n_row && !fine; i++){
		for(j=0; j<n_col && !fine; j++){
			sum += mat[i][j];
			if(sum>val){
				fine = 1;
				*row = i;
				*col = j;
			}
		}
	}
	if(!fine){
		*row = -1;
		*col = -1;
	}
}