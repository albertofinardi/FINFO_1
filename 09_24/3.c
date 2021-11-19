/*
Scrivere un programma in C che acquisito un numero intero visualizza
il messaggio "positivo", "negativo" o "nullo" in base al valore.
*/

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	if(n>0)
		printf("Positivo");
	else if(n==0)
		printf("Nullo");
	else
		printf("Negativo");

	printf("\n");

	return 0;
}