/*
Scrivere un sottoprogramma ricorsivo che riceve come parametri due
stringhe a e b; il sottoprogramma verifica se in b sono presenti
tutti i caratteri presenti in a, nello stesso ordine, più
eventualmente qualche altro carattere. In caso affermativo il
sottoprogramma restituisce 1 altrimenti 0.
Esempio:
Per a="acca" b="baracca" il sottoprogramma restituisce 1.
Per a="acca" b="racchetta" il sottoprogramma restituisce 1.
Per a="acca" b="amaca" il sottoprogramma restituisce 0.
Scrivere un programma che chiede all'utente due stringhe di al più
50 caratteri, invoca il sottoprogramma definito e visualizza il
risultato.
VARIANTE: Scrivere la versione iterativa del sottoprogramma appena
realizzato.
*/

#include <stdio.h>
#define MAX 50

int strcmp_ric(char*, char*);

int main(){
	char a[MAX+1], b[MAX+1];
	int cmp;

	scanf("%s", a);
	scanf(" %s", b);

	cmp = strcmp_ric(a, b);

	printf("%d\n", cmp);

	return 0;
}

int strcmp_ric(char *a, char *b){
	
}