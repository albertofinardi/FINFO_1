/*
Scrivere un programma in C che chiede all'utente una serie di numeri
interi terminata dal valore 0 (che non fa parte della sequenza). Il
programma stabilisce se la serie, se non vuota, è monotona crescente
(non strettamente) e visualizza un apposito messaggio di testo.
*/

#include <stdio.h>

int main(){
	int mon, n, prec;

	scanf("%d", &prec);


	mon = 1;
	if(prec != 0){
		scanf("%d", &n);
		while(n!=0 && mon){
			if(prec>n){
				mon = 0;
			}
			prec = n;
			scanf("%d", &n);
		}
		if(mon){
			printf("Monotona crescente\n");
		}else{
			printf("Non monotona crescente\n");
		}
	}else{
		print("Vuota\n");
	}

	return 0;
}