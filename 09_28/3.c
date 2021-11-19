/*
Scrivere un programma in C che acquisisce uno alla volta una serie
di caratteri minuscoli appartenenti all'alfabeto inglese (cioè
"carattere INVIO, carattere INVIO"). Per ogni carattere acquisito il
programma visualizza il carattere successivo (o più in generale N
posizioni dopo con N=1); per esempio, se l'utente inserisce una 'b'
il programma visualizza 'c', se inserisce 'z' visualizza 'a'... Il
programma termina quando l'utente inserisce un carattere non
appartenente all'alfabeto inglese senza visualizzare alcun output.
*/

#include <stdio.h>
#define N 1

int main(){

	char c;

	scanf("%c", &c);

	while(c >='a' && c <= 'z'){
		c = (c - 'a' + N) % ('z' - 'a' + 1) + 'a';
		printf("%c\n", c);
		scanf(" %c", &c);	/*Metti spazio sennò scanf salta*/
	}

	return 0;
}