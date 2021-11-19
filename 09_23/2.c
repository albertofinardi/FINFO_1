/* Scrivere un programma in C che chiede all'utente un valore intero
positivo o nullo che rappresenta l'importo che un cassiere deve
restituire al cliente. Assumendo che l'utente abbia solo banconote
da 5 euro e monete da 1 euro, il programma stabilisce e visualizza
quante banconote da 5 euro deve restituire ed eventualmente quante
monete da 1 euro.
*/

#include <stdio.h>
#define TAGLIO 5

int main(){
	int resto, banconote, monete;

	scanf("%d", &resto);
	banconote = resto/TAGLIO;
	monete = resto%TAGLIO;

	printf("Banconote da %d euro: %d, monete: %d\n", TAGLIO, banconote, monete);

	return 0;
}

/*---- VARIANTE: resto 5 euro, 2 euro e 1 euro ----*/

/*
#include <stdio.h>
#define TAGLIO 5
#define TAGLIO_M 2

int main(){
	int resto, banconote, monete_1, monete_2;

	scanf("%d", &resto);
	banconote = resto/TAGLIO;
	resto = resto%TAGLIO;
	monete_2 = resto/TAGLIO_M;
	monete_1 = resto%TAGLIO_M;

	printf("Banconote da %d euro: %d, monete da %d: %d, monete: %d\n", TAGLIO, banconote, TAGLIO_M, monete_2, monete_1);

	return 0;
}*/