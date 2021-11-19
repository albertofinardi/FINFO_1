/*

Scrivere un sottoprogramma che chiede all'utente una stringa e conta
e restituisce quante vocali contiene. Scrivere un programma che
chiede all'utente una stringa di al massimo 30 caratteri che può
contenere anche degli spazi, invoca su di essa il sottoprogramma
sopra definito e visualizza il risultato.

*/

#include <stdio.h>
#define MAX 30

int vocali(char*);

int main(){
	char a[MAX+1];
	int dim;
	
	scanf("%[^\n]", a);

	dim = vocali(a);

	printf("%d\n", dim);

	return 0;
}

int vocali(char *a){
	int n;

	for(n=0; *a != '\0'; a++){
		if(*a == 'a' || *a == 'e' || *a == 'i' || *a == 'o' || *a == 'u' || *a == 'A' || *a == 'E' || *a == 'I' || *a == 'O' || *a == 'U'){
			n++;
		}
	}

	return n;
}