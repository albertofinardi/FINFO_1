/*
Scrivere un programma in C che chiede all'utente 5 valori interi non
negativi e ne disegna l'istogramma a barre verticali orientate dal
basso verso l'alto come mostrato nel seguente esempio.

		*
	*	* 
	*	* 
	*	*	*
*	*	*	*	* 
1	4	5	2	1 
*/

#include <stdio.h>
#define DIM 5

int main(){
	int m[DIM], i, j, max;

	for(i=0; i<DIM; i++)
		scanf("%d", &m[i]);

	for(i=1, max=m[0]; i<DIM; i++){
		if(max < m[i])
			max = m[i];
	}

	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			if(max - m[j]>i)
				printf(" \t");
			else
				printf("*\t");
		}
		printf("\n");
	}

	for(i=0; i<DIM; i++)
		printf("%d\t", m[i]);
	printf("\n");

	return 0;
}