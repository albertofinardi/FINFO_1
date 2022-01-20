/*
Scrivere un sottoprogramma che riceve come parametro una stringa che rappresenta un numero intero positivo in base 8 (cioè composta soltanto dai caratteri dallo ‘0’ al ‘7’). Il sottoprogramma calcola e restituisce il valore intero rappresentate lo stesso numero in base 10. Nel caso la stringa contenga un carattere non valido, il sottoprogramma restituisce il valore -1.
Esempio 1: Se il sottoprogramma riceve in ingresso la stringa “24” restituisce il valore 20 (infatti 2 x 81 + 4 x 80 = 20). Esempio 2: Se il sottoprogramma riceve in ingresso la stringa “95” restituisce il valore -1 (infatti ‘9’ non è un carattere tra ‘0’ e ‘7’). Stessa cosa se il sottoprogramma riceve in ingresso la stringa “h5”
*/
#define BASE 8
#define ERR -1
#include <string.h>

int conversione(char[]);


int conversione(char str[]){
	int len, i, cifra, potenza, n, valid;
	len = strlen(str);
	n = 0;
	
	for(i=len-1, valid=1, potenza=1; i>=0 && valid; i--){
		cifra = (int)(str[i]-'0');
		valid = cifra >= 0 && cifra <= BASE-1;
		
		if(valid){
			n += cifra*potenza;
			potenza *= BASE;
		}

	}

	if(!valid)
		return ERR;

	return n;
}