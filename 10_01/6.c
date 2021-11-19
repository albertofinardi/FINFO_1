/*
Scrivere un programma in C in grado di calcolare il valore di
polinomi di grado massimo 8. Il programma chiede all'utente il grado
n del polinomio desiderato (un intero compreso tra 0 e 8 inclusi e
nel caso di valore non valido lo richiede). Successivamente, chiede
all'utente i coefficienti (interi) di tutti i monomi che compongono
il polinomio. Infine, chiede all'utente il valore x (un intero) per
cui fornire la soluzione del polinomio, la calcola e la stampa a
video.
*/

#include <stdio.h>
#define MAXG 8

int main(){
	int coef[MAXG+1], grado, x, i, val, potx;

	do
		scanf("%d", &grado);
	while(grado < 0 || grado > MAXG);

	for(i=0; i<=grado; i++){
		printf("Grado %d: ", i);
		scanf("%d", &coef[i]);
	}

	scanf("%d", &x);

	for(i=0, val=0, potx=1; i<=grado; i++){
		val += coef[i]*potx;
		potx *= x;
	}

	printf("%d\n", val);

	return 0;
}