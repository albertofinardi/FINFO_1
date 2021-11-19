/*
Scrivere un programma in C che acquisisce una stringa di al più 30
caratteri, la copia al rovescio in un secondo array e visualizza il
risultato.
*/

#include <stdio.h>
#define DIM 30

int main(){
	int i, len;
	char str1[DIM+1], str2[DIM+1];

	scanf("%s", str1);
	for(len=0; str1[len]!='\0'; len++);

	for(i=0; str1[i] != '\0'; i++)
		str2[len-i-1] = str1[i];

	str2[len] = '\0';

	printf("%s\n", str2);

	return 0;
}