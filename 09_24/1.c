/*
Scrivere un programma in C che chiede all'utente di inserire un
numero intero che corrisponde ad un anno e visualizza 1 se l'anno è
bisestile, 0 altrimenti. NOTA: un anno è bisestile se è divisibile
per 4 ma non per 100 o se è divisibile per 400.
*/
#include <stdio.h>

int main(){
	int anno, bisestile;

	scanf("%d", &anno);

	bisestile = (anno%4 == 0 && anno%100 != 0) || anno%400 == 0;
	/* bisestile = (!(anno%4) && anno%100) || !(anno%400); ---> 0=false, numeri diversi da 0=true */
	
	printf("%d\n", bisestile);

	return 0;
}
