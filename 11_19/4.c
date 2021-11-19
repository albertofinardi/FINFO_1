/*

Scrivere una funzione ricorsiva che riceve come parametro un numero
intero positivo o nullo e ne visualizza le cifre al contrario (da
destra verso sinistra). Per esempio se la funzione riceve il numero
123456 visualizzerà il messaggio 654321. Scrivere un programma che
chiede all'utente un intero ed invoca la funzione sopra definita.

*/

#include <stdio.h>
#define BASE 10

void inverti(int);

int main(){
	int n;
	scanf("%d", &n);
	inverti(n);
	return 0;
}


void inverti(int n){
	int cifra, _n;
	if(n<1){
		printf("\n");
		return;
	}

	_n = n/BASE;
	cifra = n - (_n)*BASE;
	printf("%d", cifra);

	return inverti(_n);
}
