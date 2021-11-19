/*
Definire un nuovo tipo di dato per memorizzare una durata temporale
in termini di numero di giorni, ore, minuti e secondi. Scrivere un
programma che riceve da tastiera i dati sulla durata di una serie di
10 intervalli di tempo. Ciascun intervallo di tempo è della durata
massima di 23 ore, 59 minuti e 59 secondi. Il programma deve
assicurarsi che i dati di ciascun intervallo inserito siano validi.
Successivamente, il programma calcola la somma di tutti gli
intervalli e la stampa a video nel formato: giorni, ore, minuti,
secondi (massimo 23 ore, massimo 59 minuti, massimo 59 secondi.
Nessun limite al numero di giorni).
Esempio: per le seguenti durate di due (e non 10 per brevità)
intervalli di tempo (ore, minuti, secondi):
- 20 50 15
- 7 20 30
il risultato che dovrà essere stampato sarà:
1 giorno/i, 4 ora/e, 10 minuto/i e 45 secondo/i.
VARIANTE: modificare il programma in modo tale che chieda all'utente
il numero di intervalli (massimo 10) di cui misurare la durata
complessiva (e ne caso il valore sia sbagliato lo richiede).
*/

#include <stdio.h>
#define DIM 10
#define MAX_S 60
#define MAX_M 60
#define MAX_O 24

typedef struct{
	int giorni, ore, minuti, secondi;
} durata_t;

int main(){
	durata_t durate[DIM];
	durata_t risultato;
	int i, max;

	do {
		scanf("%d", &max);
	} while(max<0 || max>DIM);

	printf("\n-- Intervalli --\n\n");

	for(i=0; i<max; i++){
		printf("\nIntervallo n. %d\n", i+1);
		do {
			printf("\nOre: ");
			scanf("%d", &durate[i].ore);
		} while(durate[i].ore >= MAX_O - 1 || durate[i].ore < 0);
		do {
			printf("\nMinuti: ");
			scanf("%d", &durate[i].minuti);
		} while(durate[i].minuti >= MAX_M - 1 || durate[i].minuti < 0);
		do {
			printf("\nSecondi: ");
			scanf("%d", &durate[i].secondi);
		} while(durate[i].secondi >= MAX_S - 1 || durate[i].secondi < 0);
	}

	for(i=0, risultato.giorni = 0, risultato.ore = 0, risultato.minuti = 0, risultato.secondi = 0; i<max; i++){
		risultato.secondi += durate[i].secondi;
		risultato.minuti += durate[i].minuti;
		risultato.ore += durate[i].ore;
	}

	risultato.minuti += risultato.secondi/MAX_S;
	risultato.secondi = risultato.secondi%MAX_S;
	
	risultato.ore += risultato.minuti/MAX_M;
	risultato.minuti = risultato.minuti%MAX_M;
	
	risultato.giorni += risultato.ore/MAX_O;
	risultato.ore = risultato.ore%MAX_O;

	printf("%d giorno/i, %d ora/e, %d minuto/i e %d secondo/i\n", risultato.giorni, risultato.ore, risultato.minuti, risultato.secondi);

	return 0;
}