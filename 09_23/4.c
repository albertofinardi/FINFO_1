/*
Scrivere un programma in C che chiede all'utente due numeri interi.
Il programma calcola e visualizza la media dei valori acquisti. Si
noti che la media è un valore reale.
*/

#include <stdio.h>

int main(){
	int a,b;
	float media;

	scanf("%d %d", &a, &b);

	media = a+b/2.0; /*2.0 sennò divisione tra interi da intero*/

	printf("%f", media);

	return 0;
}