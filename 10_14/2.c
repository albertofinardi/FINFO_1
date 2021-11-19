/*
Scrivere un programma in C che chiede all'utente una stringa di al
massimo 10 caratteri che rappresenta un numero intero positivo in
base 8 (cioè composta soltanto dai caratteri dallo '0' al '7'). Il
programma calcola e visualizza il valore intero rappresentante lo
stesso numero in base 10. Nel caso la stringa contenga un carattere
non valido, il programma visualizza il valore -1.
Esempio 1: Se l'utente inserisce la stringa "24", il programma
visualizza il valore intero 20 (infatti 2 x 81 + 4 x 80 = 20).
Esempio 2: Se l'utente inserisce la stringa "95", il programma
visualizza il valore intero -1 (infatti '9' non è un carattere tra
'0' e '7'). Stessa cosa se il programma legge la stringa "h5".
*/

#include <stdio.h>
#include <string.h>
#define DIM 10
#define BASE 8
#define ERR -1

int main(){
	char s[DIM+1];
	int i, n, potenza, cifra;
	scanf("%s", s);

	i = strlen(s);

	for(i--, potenza=1, n=0; i>=0 && n != ERR; i--, potenza *= BASE){
		if(s[i]>='0' && s[i]<='7'){
			cifra = s[i]-'0';
			n += cifra*potenza;
		}else{
			n = ERR;
		}
	}

	printf("%d\n", n);

	

	return 0;
}