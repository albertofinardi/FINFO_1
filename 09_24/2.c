/*
Scrivere un programma in C chiede all'utente un numero intero e ne
visualizza il suo valore assoluto.
*/
#include <stdio.h>

int main(){

	int numero;

	scanf("%d", &numero);
	
	if(numero<0)
		numero = -numero;
	

	printf("%d\n", numero);

	return 0;
}