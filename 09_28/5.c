/*Scrivere un programma in C che visualizza la tabella pitagorica.*/
#include <stdio.h>
#define MAX 10

int main(){

	int i, j, ris;
	i = 1;

	while(i<=MAX){
		j = 1;
		while(j<=MAX){
			ris = j*i;
			printf("%d\t", ris); /*oppure %3d*/
			j++;
		}
		printf("\n");
		i++;
	}

	return 0;
}