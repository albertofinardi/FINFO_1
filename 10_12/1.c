/*

Definire un tipo di dato strutturato in C per rappresentare una
frazione in termini di numeratore e denominatore (due numeri
interi). Scrivere un programma in C che acquisisce due frazioni ed
esegue la somma. Il programma deve in seguito semplificare il
risultato dell'operazione rappresentando l'eventuale segno meno nel
numeratore.

*/


#include <stdio.h>

typedef struct {
	int n, d;
} frazione_t; /* definizione struct non occupa memoria */

/*
struct frazione2_t{
	int n, d;
};*/


int main(){

	/*struct frazione2_t a,b,somma;*/

	/*struct {
		int n, d;
	} a,b,somma;*/

	frazione_t a,b,somma;
	int meno, mcd;

	do {
	scanf("%d %d", &a.n, &a.d);
	}while(a.d == 0);

	do{
		scanf("%d %d", &b.n, &b.d);
	}while(b.d == 0);

	somma.n = a.n*b.d + b.n*a.d;
	somma.d = a.d*b.d;

	if(somma.n >= 0){
		meno=0;
	}else{
		meno = 1;
		somma.n *= -1;	/* valore assoluto */
	}

	if(somma.d<0){
		somma.d *= -1;
		meno = !meno;	/* se denominatore negativo, il segno diventa opposto */
	}

	if(somma.n>somma.d){
		mcd = somma.d
	}else{
		mcd = somma.n;
	}

	while(somma.n % mcd || somma.d % mcd)
		mcd --;

	somma.n /= mcd;
	somma.d /= mcd;

	if(meno)
		somma.n *= -1;

	printf("%d %d\n", somma.n, somma.d);


	return 0;
}