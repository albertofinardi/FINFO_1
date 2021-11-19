/*
Scrivere un programma in C che chiede all'utente un numero intero
positivo e nel caso questo non sia valido stampa un messaggio
dell'errore e continua a richiederlo. Il programma verifica se il
numero è composto da sole cifre pari (0, 2, 4, 6, 8) e visualizza un
messaggio con il responso del test (1: vero, 0: falso).
*/

#include <stdio.h>
#define BASE 10

int main(){
	int a, cif, res;

	scanf("%d", &a);
	while(a<=0){
		printf("Errore\n");
		scanf("%d", &a);
	}

	res = 1;

	while(a>0 && res){
		cif = a%BASE;
		a = a/BASE;
		if(cif%2){
			res = 0;
		}
	}

	printf("%d\n", res);
	return 0;
}