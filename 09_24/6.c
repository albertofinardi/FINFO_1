/*
Scrivere un programma in C che acquisisce due numeri interi e stampa
a video il maggiore dei due.
*/

#include <stdio.h>

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	
	if(a>b)
		printf("%d\n", a);
	else if(a<b)
		printf("%d\n", b);
	else
		printf("Sono uguali\n");

	return 0;
}