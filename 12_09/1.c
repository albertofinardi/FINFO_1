/*


Scrivere un sottoprogramma ricorsivo che riceve come parametri un
array di interi ordinati in ordine crescente (e la sua dimensione)
ed un numero n. Il sottoprogramma verifica se n è contenuto
nell'array utilizzando il metodo della bisezione. In caso
affermativo restituisce 1 altrimenti 0.
Scrivere un programma che chiede all'utente 10 valori interi, invoca
il sottoprogramma definito e visualizza il risultato.

*/
#include <stdio.h>
#define DIM 10

int bisezione(int[], int, int);

int main(int argc, char *argv[]){
	int m[DIM];
	int n, i, ris;

	for(i=0; i<DIM; i++)
		scanf("%d", &m[i]);

	scanf("%d", &n);

	ris = bisezione(m, DIM, n);
	printf("%d\n", ris);

	return 0;
}

int bisezione(int m[], int dim, int n){
	if(dim == 0)
		return 0;
	if(m[dim/2] == n)
		return 1;
	

	if(m[dim/2] > n){
		/* sinistra */
		return bisezione(m, dim/2, n);
	}
	/* destra */
	return bisezione(&m[dim/2 + 1], dim/2 - 1, n);
}