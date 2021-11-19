/*
Scrivere un sottoprogramma che riceve in ingresso un array
bidimensionale di interi (dichiarato con  DIM=5 colonne) e le
dimensioni effettive della sottoparte della matrice utilizzata. Il
sottoprogramma calcola la media dei valori contenuti nella matrice e
trasmette al chiamante le coordinate del valore più vicino alla
media. Se più valori hanno stessa distanza minima selezionare
l'ultimo.
Scrivere un programma che chiede all'utente i dati di una matrice
5x5 di interi, invoca il sottoprogramma sopra definito e visualizza
i risultati.
*/

#include <stdio.h>
#define DIM 2
#define NR 2

void media(int [][DIM], int, int, int*, int*);

int main(){
	int m[NR][DIM];
	int i, j, r, c;

	for(i=0; i<NR; i++)
		for(j=0; j<DIM; j++)
			scanf("%d", &m[i][j]);

	media(m, NR, DIM, &r, &c);

	printf("M(%d, %d)\n", r, c);

	return 0;
	
}


void media(int m[][DIM], int nr, int nc, int *r, int *c){
	int i, j, sum;
	float media, min, diff;
	for(i=1, sum=m[0][0]; i<nr; i++)
		for(j=0; j<nc; j++)
			sum += m[i][j];

	media = sum/(float)(nc*nr);

	min = m[0][0]-media;
	*r = 1; /* coordinate matematica iniziano da 1, non 0 */
	*c = 1; /* coordinate matematica iniziano da 1, non 0 */
	if(min < 0)
		min = -min;

	for(i=1; i<nr; i++)
		for(j=0; j<nc; j++){
			diff = m[i][j] - media;
			if(diff < 0)
				diff = -diff;

			if(diff <= min){
				min = diff;
				*r = i+1; 	/* coordinate matematica iniziano da 1, non 0 */
				*c = j+1; 	/* coordinate matematica iniziano da 1, non 0 */
			}
		}
}