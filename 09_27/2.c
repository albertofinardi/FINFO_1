/*
Scrivere un programma in C che chiede all'utente due numeri in
virgola mobile che rappresentano i parametri a e b di un'equazione
di primo grado ax+b=0. Il programma calcola e visualizza la
soluzione dell'equazione. Si ricordi che l'equazione può essere
impossibile o indeterminata.
*/

#include <stdio.h>

int main(){
	float a,b, x;

	scanf("%f %f", &a, &b);

	if(a != 0){
		x = -b/a;
		printf("Soluzione: %f", x);
	}else if(b == 0){
		printf("Indeterminata");
	}else{
		printf("Impossibile");
	}

	printf("\n");


	return 0;
}