/*

Un intero n>=0 si dice “numero narcisistico di ordine x” se la somma delle potenze x-esime delle sue cifre è uguale al numero stesso n. Esempi di numeri narcisistici sono:
• 153==13 +53 +33 –narcisistaordine3
• 1634==14 +64 +34 +44 –narcisistaordine4
Scrivere un sottoprogramma trovanarcisisti che, ricevuto in ingresso due array di interi numero e tipo di egual dimensione, un intero x e qualsiasi altro parametro ritenuto necessario, analizza ciascun valore contenuto in numero e se è narcisistico di ordine x mette un 1 nel corrispondente elemente dell’array tipo, 0 altrimenti.

*/

#include <stdio.h>
#define BASE 10

void trovanarcisisti(int[], int[], int, int);
int potenza(int, int);
int narcisista(int, int);

int main(int argc, char *argv[]){
	return 0;
}

void trovanarcisisti(int numeri[], int tipo[], int dim, int x){
	int i;
	for(i=0; i<dim; i++){
		tipo[i] = narcisista(numeri[i], x);
	}
}

int potenza(int a, int b){
	if(b == 0 || a == 1)
		return 1;
	return a*potenza(a, b-1);
}

int narcisista(int num, int x){
	int sum, n, cifra;
	
	n = num;
	sum = 0;
	
	while(n > 0){
		cifra = n%BASE;
		sum += potenza(cifra, x);
		n /= BASE;
	}
	return num == sum;
}