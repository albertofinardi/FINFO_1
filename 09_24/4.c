/*
Scrivere un programma in C che chiede all'utente un carattere. Il
programma verifica se il carattere sia una lettera dell'alfabeto. In
caso positivo, se la lettera è minuscola, il programma la converte
nella corrispondente maiuscola, altrimenti la converte nella
corrispondente minuscola, visualizzando infine il risultato. In caso
il carattere non sia una lettera il programma visualizza un apposito
messaggio di errore.
*/

#include <stdio.h>

int main(){
	char c;
	scanf("%c", &c);

	if(c>='a' && c<='z')
		c = c - ('a'-'A');
		printf("%c", c);
	else if(c>='A' && c<='Z')
		c = c + ('a'-'A');
		printf("%c", c);
	else
		printf("Errore");

	printf("\n");

	return 0;
}