/*
Scrivere un programma in C che acquisisce una stringa di al più 30
caratteri e calcola e visualizza la sua lunghezza.
*/

#include <stdio.h>
#define DIM 30

int main(){
	int i;
	char str[DIM+1];

	scanf("%s", str);

	for(i=0, str[i]!='\0'; i++);

	printf("%d\n", i);

	return 0;
}