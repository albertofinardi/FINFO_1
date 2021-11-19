/*
Scrivere un programma in C che chiede all'utente un numero intero
positivo (assumiamo per brevità che l'utente inserisca correttamente
il valore). Il programma stampa a video le cifre che compongono il
numero al contrario dalla più piccola alla più grande.
Esempio: se l'utente inserisce il valore 23445, il programma stampa
il messaggio "54432".
*/

/*Farla al contrario*/

#include <stdio.h>
#define BASE 2 	/*con base 2 diventa metodo dei resti */
#define BASE2 10

int main(){
	int n, cif;

	int ris, pot10;

	scanf("%d", &n);

	ris = 0;
	pot10 = 1;
	while(n>0){
		cif = n%BASE;
		n = n/BASE;
		ris = ris + pot10*cif;
		pot10 = pot10*BASE2;
	}

	printf("%d\n", ris);
	return 0;

}
