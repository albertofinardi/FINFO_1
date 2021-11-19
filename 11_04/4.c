/*

Scrivere un sottoprogramma che riceve come parametri due array di
caratteri, il primo contenente una stringa ed il secondo vuoto.
Assumendo che la stringa sia composta da una sequenza di parole
separate da spazi, il sottoprogramma inverte di ordine le parole
della stringa e salva il risultato nel secondo array.
Esempio: Se il programma riceve come stringa "ciao come stai", il
sottoprogramma restituisce "stai come ciao".
Scrivere un programma che acquisisce una stringa di al massimo 100
caratteri contenente anche spazi, invoca il sottoprogramma sopra
definito e visualizza il risultato.

*/
#include <stdio.h>
#include <string.h>
#define SEP ' '

void inverti(char[], char[], int);

int main(){
	char a[101], b[101];
	int len;

	scanf("%[^\n]", a);
	len = strlen(a);


	inverti(a, b, len);

	printf("%s\n", b);

	return 0;
}

void inverti(char a[], char b[], int dim){
	
}