/*
Scrivere un programma che chiede all'utente tre numeri interi e,
mediante l'utilizzo di un puntatore, identifica e visualizza il
valore massimo.
Estendere il programma in modo tale che chieda 10 valori da salvare
in un array ed in seguito calcoli e visualizzi il valore massimo.
*/

#include <stdio.h>
#define MAX 10

int main(){
	/*int a, b, c, *max;*/

	int array[MAX], i, *max_array;

	for(i=0; i<MAX; i++)
		scanf("%d", &array[i]);

	max_array = &array[0];

	for(i=1; i<MAX; i++){
		if(*max_array < array[i])
			max_array = &array[i];
	}

	printf("%d\n", *max_array);

	/*scanf("%d %d %d", &a, &b, &c);

	if(a>b)
		max = &a;
	else
		max = &b;

	if(*max < c)
		max = &c;

	printf("%d\n", *max);*/

	return 0;
}
