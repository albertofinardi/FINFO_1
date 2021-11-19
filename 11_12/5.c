/*
Scrivere un sottoprogramma che, ricevuto in ingresso un array
monodimensionale di interi e qualsiasi parametro ritenuto
strettamente necessario, individua la sottosequenza più lunga di
valori tutti uguali tra di loro e trasmette al chiamante il valore e
la lunghezza.
Nel caso ci fosse più di una sottosequenza di pari lunghezza
massima, il sottoprogramma restituisce la prima
Esempio:
Ingresso = 1 2 8 3 3 7 4 6 6 6 6 3 2 2 8 8 8 8 8 3 3
Uscita: valore = 8, lunghezza = 5
*/

#include <stdio.h>
#define DIM 21

void sottosequenza(int[], int, int*, int*);

int main()
{
	int i, m[DIM], valore, lunghezza;

	for(i=0; i<DIM; i++){
		scanf("%d", &m[i]);
	}

	sottosequenza(m, DIM, &valore, &lunghezza);

	printf("%d %d\n", valore, lunghezza);

	return 0;
}

void sottosequenza(int m[], int dim, int *valore, int *lunghezza){
	int i, v, l;
	*lunghezza = 0;
	for(i=1, v = m[0], l=1; i<dim; i++){
		
		if(m[i] == v)
			l++;
		else{
			v = m[i];
			l = 1;
		}
		
		if(l > *lunghezza){
			*lunghezza = l;
			*valore = v;
		}
	}
}