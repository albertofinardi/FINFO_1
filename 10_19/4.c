/*

In matematica, la congettura di Goldbach è uno dei più vecchi
problemi irrisolti nella teoria dei numeri. Essa afferma che ogni
numero pari maggiore di 2 può essere scritto come somma di due
numeri primi (che possono essere anche uguali).
Scrivere un sottoprogramma che riceve un numero intero positivo
maggiore di 1 e restituisce 1 se il numero è primo, 0 altrimenti.
Scrivere un programma che chiede all'utente un numero n maggiore di
2 e pari (nel caso richiede il numero) e calcola e visualizza tutte
le possibili coppie di numeri primi la cui somma è uguale ad n.

*/

#include <stdio.h>

int primo(int);
int input();

int main(){
	int n, i;
	n = input();

	for(i=2; i<=n/2; i++){
		if(primo(i) && primo(n-i))
			printf("%d + %d\n", i, n-i);
	}
	return 0;
}


int input(){
	int n;
	scanf("%d", &n);
	while(n<=2 && n%2){
		printf("Non valido");
		scanf("%d", &n);
	}
	return n;
}

int primo(int n){
	int p, i;

	for(i=2, p=1; i*i<=n && p; i++){
		if(!(n%i))
			p=0;
	}

	return p;
}