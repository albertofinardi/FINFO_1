/*
Scrivere un programma che acquisisce una sequenza s1 di al massimo
20 numeri interi positivi terminati da un valore negativo o nullo, o
dal raggiungimento del massimo numero di valori. Il programma
costruisce una nuova sequenza di numeri s2 in un nuovo array
copiando il contenuto di s1 e duplicando ciascun valore pari. Infine
il programma visualizza s2.
Esempio:
Se l'utente inserisce: 1 2 3 4 5 0
Il programma stamperà a video: 1 2 2 3 4 4 5
*/

#include <stdio.h>
#define DIM 20

int main(){
	int s1[DIM], s2[DIM*2], size1, size2, i;

	size1 = 0;
	scanf("%d", &s1[size1]);

	while(s1[size1]>0 && size1 < DIM){
		size1++;
		if(size1<DIM)	/* Non prendere 21esimo valore */
			scanf("%d", &s1[size1]);
	}

	for(i=0, size2=0; i<size1; i++,size2++){ 	/* size2 per forza < DIM*2 */
		if(!(s1[i]%2)){
			s2[size2] = s1[i];
			size2++;
		}
		s2[size2] = s1[i];
		/*size2++;*/
	}

	for(i=0; i<size2; i++;){ 	
		printf("%d\t", s2[i]);
	}

	printf("\n");
	return 0;
}