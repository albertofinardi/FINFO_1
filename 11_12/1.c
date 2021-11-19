/*
Scrivere un sottoprogramma ricorsivo che riceve due numeri interi
positivi a e b e calcola risultato e resto della divisione intera a/
b (senza l'utilizzo degli operatori / e %).
Scrivere un programma che acquisisce due valori x e y ed invoca la
funzione sopra definita, visualizzando poi il risultato.
*/

#include <stdio.h>

void divisione(int, int, int*, int*);

int main(){
	int a, b, resto, div;

	scanf("%d", &a);
	scanf("%d", &b);

	divisione(a, b, &resto, &div);

	printf("%d %d\n", div, resto);

	return 0;
}

void divisione(int a, int b, int *resto, int *risultato){
	if(b > a){
		*resto = a;
		*risultato = 0;
	}else{
		divisione(a-b, b, resto, risultato);
		(*risultato)++;
	}
}