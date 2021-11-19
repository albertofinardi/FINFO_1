/*

Scrivere un sottoprogramma che riceve come parametri due array di
interi di egual dimensione, e qualsiasi altro parametro ritenuto
strettamente necessario. Il sottoprogramma verifica se, pur di fare
uno scorrimento circolare del secondo array, i due array siano
identici. Nello scorrimento circolare, la cifra che si trova in
ultima posizione diventa quella in prima posizione dopo lo
scorrimento. In caso affermativo il sottoprogramma restituisce
quante posizioni deve essere fatto scorrere il secondo array verso
destra. In caso negativo, restituisce -1.
Scrivere un programma che acquisisce i dati per popolare due array
monodimensionali di 10 interi ciascuno. Il programma invoca il
sottoprogramma sopra definito e visualizza il risultato.
Esempio:
se il sottoprogramma riceve i seguenti due array:
a = [0 2 4 8 2 1 7 8 2 9]
b = [1 7 4 8 2 7 2 6 1 6]
Il sottoprogramma restituisce -1
se il sottoprogramma riceve i seguenti due array:
a = [5 4 9 8 3 0 1 9 3 4]
b = [9 3 4 5 4 9 8 3 0 1]
Il sottoprogramma restituisce 7
*/

#include <stdio.h>
#define MAX 10

#define EXIT -1

int compare(int[], int[], int);

int main(){
	int a[MAX], b[MAX];
	int i;

	for(i=0; i<MAX; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<MAX; i++){
		scanf("%d", &b[i]);
	}

	printf("%d\n", compare(a, b, MAX));
	return 0;
}

int compare(int a[], int b[], int dim){
	int i, j, ok, found;

	for(i=0, found=0; i<dim && !found; i++){
		for(j=0, ok=1; j<dim && ok; j++){
			if(a[j] != b[(i+j)%dim])
				ok = 0;
		}
		if(ok)
			found=1;
	}

	if(found)
		i--;
	else
		i = -1;

	return i;
	

}