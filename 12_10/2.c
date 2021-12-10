/*

Scrivereunsottoprogrammacompattaarraychericeveiningressounarraydinumeriinteripositiviequalsiasialtroparametroritenuto strettamente necessario. Il sottoprogramma rimuove dall’array tutti i numeri non primi e restituisce al chiamate il numero di elementi alla fine presenti nell’array.
(2pti) Scrivereunprogrammachechiedeall’utentequantidativorràfornire(alpiù200)efinoaquandol’utentenondàunarispostavalidalorichiede. Acquisiti i valori, il programma chiama il sottoprogramma compattaarray e poi visualizza il contenuto dell’array.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

int compattaarray(int[], int);
int primo(int);

int main(int argc, char *argv[]){
	int arr[MAX];
	int dim, i, dim_primi;

	do{
		scanf("%d", &dim);
	} while(dim <= 0 || dim > MAX);

	for(i=0; i<dim; i++){
		scanf("%d", &arr[i]);
	}

	dim_primi = compattaarray(arr, dim);
	for(i=0; i<dim_primi; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}

int compattaarray(int arr[], int dim){
	int i, primi;
	for(i=0, primi=0; i<dim; i++){
		if(primo(arr[i])){
			arr[primi] = arr[i];
			primi++;
		}
	}
	return primi;
}

int primo(int n){
	int p, i;

	for(i=2, p=1; i*i<=n && p; i++){
		if(!(n%i))
			p=0;
	}

	return p;
}