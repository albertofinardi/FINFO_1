/*
Scrivere un programma in C che chiede all'utente di inserire due
sequenze di 10 numeri interi ciascuna. Il programma controlla che la
seconda sequenza sia una permutazione della prima e stampa a video
l'esito del test (1: permutazioni, 0: altrimenti).
*/

#include <stdio.h>
#define DIM 10

int main(){

	int m1[DIM], m2[DIM], i, j, qtn_m1, qtn_m2, perm;

	for(i=0; i<DIM; i++)
		scanf("%d", &m1[i]);

	for(i=0; i<DIM; i++)
		scanf("%d", &m2[i]);

	for(i=0, perm=1; i<DIM && perm; i++){
		qtn_m1 = 0;
		qtn_m2 = 0;
		for(j=0; j<DIM; j++){
			if(m1[i]==m1[j])
				qtn_m1++;
			if(m1[i]==m2[j])
				qtn_m2++;
		}
		if(qtn_m1 != qtn_m2)
			perm = 0;
	}

	printf("%d\n", perm);

	return 0;
}