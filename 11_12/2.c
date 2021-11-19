/*
Scrivere un sottoprogramma ricorsivo che riceve come parametro una
stringa e ne calcola e restituisce la lunghezza.
Scrivere un programma che chiede all'utente una stringa di al
massimo 30 caratteri, invoca il sottoprogramma definito e visualizza
il risultato.
*/

#include <stdio.h>
#define MAX 30

int lunghezza(char*);

int main(){
	char str[MAX+1], len;

	scanf("%s", str);
	len = lunghezza(str);

	printf("%d\n", len);

	return 0;
}

int lunghezza(char *str){
	if(*str == '\0')
		return 0;
	return 1+lunghezza(str+1);
}