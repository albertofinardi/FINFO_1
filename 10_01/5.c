/*
Scrivere un programma in C che chiede all'utente una sequenza di 20
numeri interi salvandoli in un array. Il programma salva in un
secondo array tutti e soli i valori distinti della sequenza
acquisita (ovvero omettere i duplicati). Infine il programma
visualizza il contenuto del secondo array e la sua lunghezza.
*/

#include <stdio.h>
#define DIM 20

int main()
{
	int array[DIM], dupl[DIM], i, j, k, trovato;

	for(i=0; i<DIM; i++)
		scanf("%d", &array[i]);

	for(i=0, k=0; i<DIM, i++){
		for(j=0, trovato=0; j<i && !trovato; j++){		/*confronta array con precedenti*/
			if(array[i] == array[j])
				trovato = 1;
		}
		if(!trovato){
			dupl[k] = array[i];
			k++;
		}
	}

	for(i=0; i<k; i++){
		printf("%d ", dupl[i]);
	}
	printf("\n%d\n", k);

	return 0;
}