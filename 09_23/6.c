/*
Scrivere un programma in C che chiede all'utente un carattere
dell'alfabeto minuscolo (assumiamo che l'utente non inserisca un
carattere non valido). Il programma calcola e visualizza il
corrispondente carattere maiuscolo.
*/

#include <stdio.h>

int main(){
	char a;
	char A;

	scanf("%c", &a);

	A = a - ('a'-'A'); /*utilizza tabella ASCII per cast char a int*/
	printf("%c\n", A);

	return 0;
}