/*
Scrivere un programma in C che acquisisce 3 interi. Il programma
verifica se costituiscono una terna pitagorica; in caso affermativo
il programma stampa a video "1" altrimenti "0". NOTA: l'utente può
inserire i tre numeri in qualsiasi ordine; es. "3 4 5" e "5 3 4"
sono entrambe terne pitagoriche.
*/

#include <stdio.h>

int main(){
	int a,b,c;
	int out;
	
	scanf("%d %d %d", &a, &b, &c);

	out = (a*a == b*b + c*c) || (b*b == a*a + c*c) || (c*c == b*b + a*a);

	printf("%d\n", out);
	return 0;
}