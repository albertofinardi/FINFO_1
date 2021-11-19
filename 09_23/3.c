/*
Scrivere un programma in C che calcola il peso di una scatola
contenente un numero di oggetti tutti uguali. Il programma chiede
all'utente il peso del singolo oggetto (float) e il loro numero (int); in seguito
esegue il calcolo e visualizza il risultato.
*/

#include <stdio.h>

int main(){
	int oggetti;
	float peso_oggetto, peso_tot;

	scanf("%d %f", &oggetti, &peso_oggetto);

	peso_tot = oggetti*peso_oggetto;
	printf("Peso totale: %f\n", peso_tot);

	return 0;
}