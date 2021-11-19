/*

Scrivere un sottoprogramma che riceve come parametro un numero
intero non negativo e calcola e restituisce il suo fattoriale.
Scrivere in seguito un sottoprogramma che riceve come parametri due
numeri interi non negativi e calcola il coefficiente binomiale
(utilizzare il sottoprogramma precedentemente definita per calcolare
il fattoriale)
Scrivere un programma che chiede all'utente due numeri interi non
negativi e utilizza il sottoprogramma sopra definito per calcolarne
il coefficiente binomiale mostrando a video il risultato.
*/

#include <stdio.h>

int fattoriale(int); 	/*puoi omettere nome variabile*/
int coeffb(int, int);

int main(){

	int n, k;
	int res;
	do {
		scanf("%d %d", &n, &k);
	} while(n<=0 || k<=0);
	res = coeffb(n, k);

	printf("%d\n", res);

	return 0;
}

int coeffb(int n, int k){
	return fattoriale(n)/(fattoriale(k)*fattoriale(n-k));
}

int fattoriale(int n){
	int i, res;
	for(i=2, res=1; i<=n; i++){
		res *= i;
	}
	return res;
}