/*

Realizzare un programma in C per la gestione di una serie di
rilevazioni di temperature sui piani di un edificio. Ciascun
rilevazione specifica il numero del piano, l'ora della misura (una
stringa di al massimo 8 caratteri) e la temperatura letta (un numero
intero).
Definire un tipo di dato strutturato per rappresentare ciascuna
rilevazione.
In seguito, scrivere un programma per la gestione delle rilevazioni.
Il programma dovrà chiedere all'utente di specificare il numero di
rilevazioni da inserire (massimo 100 e nel caso l'utente non
inserisca un valore valido il programma lo richiede) e poi inserire
le rilevazioni (si assume che i dati siano inseriti correttamente in
base all'ora). In seguito il programma dovrà chiedere all'utente il
numero di un piano. Il programma visualizzerà gli intervalli di
tempo per cui la temperatura di quel piano è stata inferiore ai 22
gradi. Si noti che è necessario stampare solo l'ora relativa alla
prima e all'ultima rilevazione di ciascun intervallo.
ESEMPIO:
Numero di rilevazioni: 8
Rilevazioni:
1 10:30:00 23
2 10:35:00 21
2 11:00:00 20
1 11:20:00 23
2 11:34:00 21
2 12:30:00 24
1 12:40:00 23
2 14:30:00 21
Piano da analizzare: 2
Risultato:
10:35:00 -> 11:34:00
14:30:00 -> 14:30:00

*/

#include <stdio.h>
#define STRDIM 8
#define MAX 100
#define TEMPMAX 22

typedef struct {
	int piano, temp;
	char str[STRDIM+1];
} rilevazione_t;

int main(){

	rilevazione_t rilevazione[MAX];
	int num, i, piano;

	do{
		scanf("%d", &num);
	}while(num<=0 || num>MAX);

	for(i=0; i<num; i++){
		scanf("%d", &rilevazione[i].piano);
		scanf(" %s", rilevazione[i].str);
		scanf(" %d", &rilevazione[i].temp);
	}

	scanf("%d", &piano);

	for(i=0; i<num; i++){
		if(rilevazione[i].piano == piano){
			if(rilevazione[i].temp < TEMPMAX)
				printf("%s", rilevazione[i].str);	/* così stampa tutte le ore, modificarlo */
		}
	}


	return 0;
}








