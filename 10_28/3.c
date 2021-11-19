/*

Scrivere un sottoprogramma che riceve come parametri un array di
interi e la sua dimensione. Il sottoprogramma calcola la somma dei
valori dell'array e restituisce il risultato.
Scrivere un programma che chiede all'utente 10 valori da memorizzare
in un array e mediante l'ausilio della funzione sopra definita
calcola la somma dei valori della prima metà dell'array e quella
della seconda metà. Infine il programma valuta se la prima somma è
maggiore visualizzando un apposito messaggio a video.

*/

#include <stdio.h>
#define DIM 10

int somma(int[], int);

int main(){
	int i, a[DIM], sum1, sum2;

	for(i=0; i<DIM; i++)
		scanf("%d", &a[i]);

	sum1 = somma(a, DIM/2);
	sum2 = somma(&a[DIM/2], DIM/2);

	if(sum1>sum2)
		printf("Sum1 > Sum2\n");
	else
		printf("Sum2 > Sum1\n");
	
	return 0;
}

int somma(int a[], int dim){
	int i, sum;
	for(i=1, sum=a[0]; i<dim; i++)
		sum += a[i];

	return sum;
}