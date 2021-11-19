/*

ES1 - Scrivere un programma che mostra a video il triangolo di Tartaglia di dimensione chiesta all'utente (massimo 10). 
Il programma deve eseguire un controllo di validità sulla dimensione chiesta all'utente e nel caso di valore non valido richiederla. 
Esempio: il triangolo di Tartaglia di dimensione 5 (valore inserito dall'utente) è:
1
11 
121 
1331 
14641

*/

#include <stdio.h>
#define MAX 10

int fattoriale(int);

int main(){
	int n, i, j, coeff;

	do {
		scanf("%d", &n);
	} while (n <= 0 || n > MAX);

	printf("\n\n");

	for(i=0; i<n; i++){
		for(j=0; j<=i; j++){
			coeff = fattoriale(i)/(fattoriale(j)*fattoriale(i-j));
			printf("%d\t", coeff);
		}
		printf("\n");
	}

	return 0;
}

int fattoriale(int n){
	int res, i;

	for(res=1, i=2; i<=n; i++){
		res *= i;
	}
	return res;
}