/*
Scrivere un programma in C che chiede all'utente un valore intero
positivo o nullo che rappresenta una durata di tempo in secondi. Il
programma converte e visualizza la durata in termini di: N di
giorni, N di ore, N di minuti, N di secondi. Per esempio, se
l'utente inserisce il valore 76, il programma visualizzerà "0
giorni, 0 ore, 1 minuti, 16 secondi".
*/

#include <stdio.h>
#define ORE 24
#define MINUTI 60
#define SECONDI 60


int main(){
	int durata, g, o, m, s;

	scanf("%d", &durata);

	g = durata/(ORE*MINUTI*SECONDI);
	s = durata % (ORE*MINUTI*SECONDI);

	o = s/(MINUTI*SECONDI);
	s = s%(MINUTI*SECONDI);

	m = s/SECONDI;
	s = s%SECONDI;

	printf("Giorni: %d, ore: %d, minuti: %d, secondi: %d\n", g, o, m, s);


	return 0;
}