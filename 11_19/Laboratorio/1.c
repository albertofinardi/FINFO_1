/*


ES1 - Realizzare un sottoprogramma che riceve come parametro una
stringa di testo composta da parole in caratteri minuscoli ciascuna
di lunghezza indefinita e separate da singoli spazi. Il
sottoprogramma modifica la stringa secondo la procedura qui sotto
riportata e poi ne stampa all'utente la nuova versione.
Procedura: ogni parola all'interno della stringa di testo viene
invertita, l'ultima lettera diventa la prima e viceversa.

Esempio
  Input: ciao come stai
  Output: oaic emoc iats

Scrivere un programma che chiede all'utente una stringa di al
massimo 250 caratteri, invoca su di essa il sottoprogramma sopra
definito e stampa a video il risultato.

*/

/* NON FUNZIONA */

#include <stdio.h>

#define SEP ' '
#define STRDIM 250

void invertiparola(char[]);

int main(){
	char str[STRDIM+1];

	scanf("%[^\n]", str);

	invertiparola(str);

	return 0;
}

void invertiparola(char str[]){
	int i, j, fine, inizio;
	char c;
	for(i=0, inizio=0; str[i] != '\0'; i++){
		if(str[i] == SEP){
			fine = i-1;
			
			for(j=inizio; j<(fine-inizio + 1)/2; j++){
				c = str[j];
				str[j] = str[fine-j];
				str[fine-j] = c;
			}

			inizio = i+1;
		}

	}
	printf("%s\n", str);
}