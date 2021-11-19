/*

Realizzare un programma in C per la gestione di una serie di
rilevamenti di temperature sui piani di un edificio. Ciascun
rilevamento specifica il numero del piano, l'ora del rilevamento
(una stringa di al massimo 8 caratteri) e la temperatura letta (un
numero intero).
Definire un tipo di dato strutturato per rappresentare ciascun
rilevamento.
In seguito, scrivere un programma per la gestione dei rilevamenti.
Il programma dovrà chiedere all'utente di specificare il numero di
rilevamenti da inserire (massimo 100 e nel caso l'utente non
inserisca un valore valido il programma lo richiede) e poi inserire
i rilevamenti (si assume che i dati siano inseriti correttamente in
base all'ora). In seguito il programma dovrà chiedere all'utente il
numero di un piano. Il programma visualizzerà gli intervalli di
tempo per cui la temperatura di quel piano è stata inferiore ai 22
gradi. Si noti che è necessario stampare solo l'ora relativa alla
prima e all'ultima rilevazione di ciascun intervallo.
ESEMPIO:
Numero di rilevamenti: 8
Rilevamenti:
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
#define STR 8
#define MAX 100
#define TRESHOLD 22

typedef struct{
	int piano, temp;
	char ora[STR+1];
} ril_t;


int main(){
	int num, piano;
	ril_t rel[MAX];

	do {
		scanf("%d", &num);
	} while(num<=0 || num > MAX);

	for(i=0; i<num; i++){
		scanf("%d", &rel[i].piano);
		scanf("%s", rel[i].ora);
		scanf("%d", &rel[i].temp);
	}

	scanf("%d", &piano);

	/* TODO */

	return 0;
}






