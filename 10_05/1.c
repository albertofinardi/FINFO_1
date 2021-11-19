/*
Scrivere un programma in C che chiede all'utente una sequenza di 10
numeri interi. Il programma controlla che non vi siano duplicati
all'interno della sequenza data e visualizza l'esito del test (1 se
non ci sono duplicati, 0 altrimenti).
*/

#include <stdio.h>
#define DIM 10

int main(){
	int m[DIM], i, j, nodupl;

	for(i=0; i<DIM; i++){
		scanf("%d", &m[i]);
	}

	for(i=0, nodupl = 1; i<DIM && nodupl; i++){
		for(j=0; j<i && nodupl; j++){
			if(m[i]==m[j])
				nodupl = 0;
		}
	}

	printf("%d\n", nodupl);

	return 0;
}