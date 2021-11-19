/*
Realizzare un sottoprogramma che riceve come parametri il puntatore
alla prima cella di una matrice bidimensionale di interi e qualsiasi
altro parametro ritenuto strettamente necessario. Il sottoprogramma
visualizza il contenuto della matrice.
Scrivere un programma che dichiara una matrice di interi 5x5, chiede
all'utente quanti dati si vuole inserire nella matrice (numero di
righe e colonne - che si assume vengano inseriti correttamente
dall'utente) ed i dati per popolare la matrice; il programma invoca
il sottoprogramma sopra definito.
*/

#include <stdio.h>
#define NC 5
#define NR 5

void visualizza(int*, int, int, int);

int main(){

	int row, col;
	int m[NR][NC];
	int i, j;

	scanf("%d %d". &row, &col);
	
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			scanf("%d", &m[i][j]);

	visualizza(&m[0][0], NC, row, col);

	return 0;
}


void visualizza(int *p, int NC, int row, int col){		//p è puntatore semplice --> punta prima cella
	int i, j;
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			printf("%d\t" *(p+i*NC + j));
		printf("\n");

}