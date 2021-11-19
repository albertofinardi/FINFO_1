/*
Scrivere un programma in C che calcola il massimo di una sequenza di
50 numeri interi inseriti dall'utente e visualizza il risultato.
*/

#include <stdio.h>
#define NUM 50

int main(){
	int n, max, i;

	scanf("%d", &n);
	max = n;
	i = 1;
	while(i<NUM){
		scanf("%d", &n);
		if(n > max)
			max = n;
		i++;
	}
	printf("Max: %d\n", max);
	return 0;
}