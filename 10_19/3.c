/*
Scrivere un sottoprogramma che chiede all'utente un numero intero
non negativo; se il valore acquisito non è valido il sottoprogramma
visualizza un apposito messaggio di errore e ripete la richiesta.
Una volta acquisito un valore valido, il sottoprogramma restituisce
il numero al chiamate.
Scrivere un programma che acquisisce due numeri positivi mediante
l'apposito sottoprogramma definito sopra e li stampa a video.
Estendere il programma dell'esercizio precedente sul calcolo del
coefficiente binominale, in modo tale da effettuare un'acquisizione
di due valori positivi.
*/

#include <stdio.h>

int input();
int fattoriale(int);
int coeffb(int, int);

int main(){
	int a, b, res;
	a = input();
	b = input();
	res = coeffb(a, b);
	printf("%d\n", res);
	return 0;
}

int input(){
	int n;
	scanf("%d", &n);
	while(n<0){
		printf("Non valido");
		scanf("%d", &n);
	}
	return n;
}

int fattoriale(int n){
	int fatt, i;
	for(i=2, fatt = 1; i<=n; i++){
		fatt *= i;
	}
	return fatt;
}

int coeffb(int n, int k){
	return fattoriale(n)/(fattoriale(k)*fattoriale(n-k));
}
