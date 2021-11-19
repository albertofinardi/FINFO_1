/*
Scrivere un programma in C che chieda all'utente di inserire da
tastiera due angoli in formato gradi, primi e secondi (valori interi
positivi o nulli - si assuma che l'utente non inserisca valori
negativi). Il programma deve normalizzare gli angoli inseriti, farne
la somma e stampare a video i due angoli inseriti (in formato
normale) e la loro somma, anch'essa normalizzata.
*/

#include <stdio.h>
#define NORM 360

int main()
{
	int a,b, ris;
	scanf("%d %d", &a, &b);

	a = a%NORM;
	b = b%NORM;

	ris = (a+b)%NORM;

	printf("%d %d %d\n", a, b, ris);

	return 0;
}