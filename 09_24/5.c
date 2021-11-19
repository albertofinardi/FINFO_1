/*
Scrivere un programma che acquisisce un intero che rappresenta un
voto e stampa «grav. insuff.» se il voto è minore 10, «insuff.» se
il voto è compreso tra 10 e 17 estremi inclusi, «suff.» se è
compreso tra 18 e 24 estremi inclusi, «ottimo» se maggiore di 24.
Estendere il programma in modo tale che verifichi che il numero
inserito rappresenti un voto valido (un intero tra 0 e 30 estremi
inclusi); in caso affermativo procede con l'analisi altrimenti
visualizza un messaggio di errore.
*/

#include <stdio.>

int main(){
	int voto;

	scanf("%d", &voto);

	if(voto>=0 && voto<=30){
		if(voto>24)
			printf("Ottimo");
		else if(voto>=18)
			printf("Suff.");
		else if(voto>=10)
			printf("Insuff.");
		else
			printf("Grav. insuff.");
	}

	printf("\n");

	return 0;
}