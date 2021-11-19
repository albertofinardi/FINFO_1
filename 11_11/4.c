/*
Scrivere un sottoprogramma ricorsivo che calcola e restituisce l'i-
esimo numero della sequenza di Fibonacci con i intero positivo o
nullo ricevuto come parametro.
Scrivere un programma che chiede all'utente un valore intero
positivo o nullo (che si assume venga inserito correttamente),
invoca il sottoprogramma definito e visualizza il risultato.
*/

#include <stdio.h>

int fibonacci(int n);

int main(){
	int n;

	scanf("%d", &n);
	printf("%d", fibonacci(n));
	return 0;
}

int fibonacci(int n){
	if(n==0 || n==1)
		return n;
	return fibonacci(n-1) + fibonacci(n-2);
}