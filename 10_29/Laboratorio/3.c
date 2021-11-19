/*
ES3 - Definire un tipo di dato parola_t che rappresenta una parola nella lingua italiana e la sua traduzione inglese (due stringhe ciascuna di al massimo 30 caratteri). Scrivere un programma che chiede all'utente 10 parole italiane e la loro traduzione in inglese. Il programma esegue le seguenti elaborazioni:
* Il programma cerca e stampa a video quei termini italiani che sono presenti anche nella lingua inglese (anche se con un altro significato). * Il programma cerca e stampa a video quei termini italiani che hanno più traduzioni in inglese.
Come esempio
scope brooms
scopo scope
case houses
scatola case
goal goal
ciao hello
ciao hi
ballo ball
palla ball
ciao bye
Per il primo
scope brooms * scopo scope
case houses * scatola case
Per il secondo punto il programma stamperà a video: ciao hello
ciao hi
ciao bye
*/

#include <stdio.h>
#include <string.h>

#define DIM 10
#define STRDIM 30

typedef struct{
	char ita[STRDIM+1], eng[STRDIM+1];
} parola_t;

void acquisisci(parola_t[], int);
void cmp(parola_t[], int);
void multi(parola_t[], int);

int main(){
	parola_t dizionario[DIM];
	acquisisci(dizionario, DIM);
	cmp(dizionario, DIM);
	multi(dizionario, DIM);
	return 0;
}

void acquisisci(parola_t dizionario[], int dim){
	int i;
	for(i=0; i<dim; i++){
		scanf("%s %s", dizionario[i].ita, dizionario[i].eng);
	}
}

void cmp(parola_t dizionario[], int dim){
	int i, j;
	printf("\n\n1\n");
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			if(!strcmp(dizionario[i].ita, dizionario[j].eng))
				printf("%s %s * %s %s\n", dizionario[i].ita, dizionario[i].eng, dizionario[j].ita, dizionario[j].eng);
		}
	}
}

void multi(parola_t dizionario[], int dim){
	int i, j;
	printf("\n\n2\n");
	for(i=0; i<dim; i++){
		/* TODO */
	}
}