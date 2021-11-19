/*
Scrivere un programma in C che acquisisce due stringhe di al più 30
caratteri e verifica se sono uguali visualizzando un apposito
messaggio con il responso (1: uguali, 0: diverse).
*/

#include <stdio.h>

#define DIM 30

int main(){

	char s1[DIM+1], s2[DIM+1];
	int i, uguali;

	scanf("%s %s", s1, s2);

	for(i=0; s1[i] != '\0' && s2[i] != '\0' && s1[i]==s2[i]; i++);

	uguali = s1[i] == '\0' && s2[i] == '\0';


	if(uguali)
		printf("Uguali\n");
	else
		printf("Diverse\n");

	return 0;
}