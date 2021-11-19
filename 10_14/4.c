/*

Scrivere un programma in C che chiede all'utente una stringa di
massimo 50 caratteri che rappresenta il percorso completo di un
file. Il programma salva in una nuova stringa il solo nome del file
specificato nel percorso e lo visualizza.
Esempio: dal path "/home/antonio/ciao.c" il programma stampa a video
"ciao.c"

*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int main(){

	char s[MAX+1];
	int i, len, stay;

	scanf("%s", s);
	len = strlen(s);

	for(i=len-1, stay=1; i>=0 && stay; i--){
		if(s[i]=='/')
			stay = 0;
	}

	for(i=i+2; i<len; i++) /* +2 perchè 1 per togliere '/' e 1 per rimediare a i-- finale */
		printf("%c", s[i]);

	printf("\n");
	return 0;
}