/*
Scrivere un programma in C che chiede all'utente una stringa di al
massimo 15 caratteri contenente soltanto lettere dell'alfabeto
minuscolo (si assuma che l'utente non commetta errori
nell'inserimento).
Il programma identifica e visualizza qual è la prima lettera
nell'ordinamento alfabetico che compare nella stringa e quante volte
vi compare.
Esempio
Se l'utente inserisce "cocci" il programma stampa "c 3"
Se l'utente inserisce "bacco" il programma stampa "a 1"
Se l'utente inserisce "tiene" il programma stampa "e 2"

*/

#include <stdio.h>
#include <string.h>
#define MAX 15

int main(){
	char s[MAX+1], lett;
	int num, i, len;

	scanf("%s", s);

	len = strlen(s);

	for(lett = s[0], i=1; i<len; i++){
		if(s[i]<lett){
			lett = s[i];
			num = 1;
		} else if(s[i] == lett)
			num++;
	}		

	printf("%c %d\n", lett, num);
	return 0;
}