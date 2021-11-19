/*
Scrivere un sottoprogramma ricorsivo che riceve come parametri due
stringhe e verifica se sono uguali o meno. In caso affermativo il
sottoprogramma restituisce 1 altrimenti 0.
Scrivere un programma che chiede all'utente due stringhe di al
massimo 30 caratteri, invoca il sottoprogramma definito e visualizza
il risultato.
*/

#include <stdio.h>
#define MAX 30

int strcmp_ric(char*, char*);

int main(){
	char a[MAX+1], b[MAX+1];
	int cmp;

	scanf("%s", a);
	scanf(" %s", b);

	cmp = strcmp_ric(a,b);

	printf("%d\n", cmp);
	return 0;
}

int strcmp_ric(char *a, char *b){
	if(*a != *b)
		return 0;
	if(*a == '\0' && *b == '\0')
		return 1;
	/*else if(*a == '\0' || *b== '\0')
		return 0;*/
	return strcmp_ric(a+1, b+1);
}