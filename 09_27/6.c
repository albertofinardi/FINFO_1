/*
Si consideri un corso X in cui l'esame è composto da due compitini,
ciascuno valutato in trentesimi. Condizione necessaria per essere
promossi è che entrambi i compitini siano sufficienti e in tal caso
il voto finale è calcolato come media dei due valori. Si noti che il
voto finale è un intero e quindi l'eventuale parte decimale non va
considerata.
Scrivere un programma in C che acquisisce due valori interi che
rappresentano i punteggi ottenuti da uno studente nelle due prove in
itinere; si assuma in prima istanza che l'utente inserisca
correttamente dei valori compresi tra 0 e 30.
Il programma valuta se lo studente è stato promosso o bocciato
visualizzando un apposito messaggio; in caso positivo il programma
deve anche visualizzare il voto ottenuto.
Migliorare poi il programma aggiungendo un controllo di validità dei
dati inseriti, cioè che ciascun punteggio deve essere compreso tra 0
e 30; nel caso almeno uno dei dati sia non consistente, il programma
deve visualizzare un messaggio di errore.

*/


#include <stdio.h>
#define MIN 0
#define MAX 30
#define SUFF 18

int main(){
	int a,b, ris;

	scanf("%d %d", &a, &b);
	
	if(a>=MIN && a<=MAX && b>=MIN && b<=MAX){
		if(a>=SUFF && b>=SUFF){
			ris = (a+b)/2;
			printf("%d\n", ris);
		}else{
			printf("Non sufficiente\n");
		}
	}else{
		printf("Voti non validi\n");
	}

	return 0;
}