/*
Scrivere un programma in C che chiede all'utente 5 valori interi non
negativi e ne disegna l'istogramma a barre verticali orientate
dall'alto al basso come mostrato nel seguente esempio.
Se l'utente inserisce i valori: 1 4 5 2 1, il programma visualizzerà
il seguente output:
1	4	5	2	1 
*	*	*	*	* 
	*	*	*
	*	* 
	*	* 
		*
*/

#include <stdio.h>
#define DIM 5

int main(){
	int m[DIM], i, j, max;

	for(i=0; i<DIM; i++)
		do
			scanf("%d", &m[i]);
		while(m[i]<0);

	for(i=1, max=m[0]; i<DIM; i++){
		if(max < m[i])
			max = m[i];
	}

	for(i=0; i<DIM; i++)
		printf("%d\t", m[i]);
	printf("\n");

	for(i=0; i<max; i++){
		for(j=0; j<DIM; j++){
			if(m[j]>i)
				printf("*\t");
			else
				printf(" \t");
		}
		printf("\n");
	}

	return 0;
}