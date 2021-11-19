/*
Scrivere un programma in C che acquisisce due stringhe di al più 30
caratteri e le concatena in un terzo array e visualizza il
risultato.
*/

#include <stdio.h>
#define DIM 30

int main(){
	int l1, i;
	char s1[DIM+1], s2[DIM+1], s3[DIM*2 + 1];

	scanf("%s %s", s1, s2);

	for(i=0; s1[i]!='\0'; i++){
		s3[i] = s1[i];
	}
	for(l1=i, i=0; s2[i]!='\0'; i++){
		s3[i+l1] = s2[i];
	}
	s3[i+l1] = '\0';

	printf("%s", s3);

	return 0;
}