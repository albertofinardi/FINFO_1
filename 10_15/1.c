/*
Si vuole realizzare un programma "interattivo" che permette di
gestire un percorso su uno spazio bidimensionale composto da una
lista di località.
Dichiarare un tipo di dato per rappresentare una località su una
cartina in termini di coordinate x e y (due interi) ed un nome (una
stringa di al max 30 caratteri). Scrivere un programma in grado di
gestire un massimo di 50 località. All'avvio il programma visualizza
un menù con le seguenti funzionalità e chiede all'utente di
selezionarne una:
1 - Inserire in coda una nuova località
2 - Inserire in una specificata posizione una nuova località
3 - Cancellare una località nella lista
4 - Visualizzare l'intero percorso
5 - Visualizzare la lunghezza complessiva dell'itinerario
6 - Visualizza la coppia di località (anche non consecutive nel
percorso) la cui distanza è maggiore di qualsiasi altra coppia.
7 - Uscita
Implementare le funzionalità specificate come segue:
1 - L'inserimento in coda può avvenire solo se c'è ancora spazio
disponibile nella struttura dati, altrimenti viene visualizzato un
messaggio di errore. In caso positivo il programma chiede all'utente
i dati di una località e la aggiunge in fondo al percorso già
memorizzato.
2 - Anche l'inserimento in mezzo può avvenire solo se c'è ancora
spazio disponibile nella struttura dati, altrimenti viene
visualizzato un messaggio di errore. In caso positivo il programma
chiede all'utente prima l'indice in cui inserire la nuova località e
poi i dati della nuova località; il programma sposta in avanti tutte
le località presenti dall'indice specificato in modo tale da creare
spazio per i nuovi dati. Nel caso l'utente inserisca un indice non
valido il programma visualizza un messaggio di errore e non procede
con la richiesta dei dati e l'inserimento.
3 - Il programma chiede all'utente l'indice della località da
cancellare. Se l'indice è valido rimuove i dati relativi altrimenti
visualizza un messaggio di errore.
4 - Il programma stampa a video il percorso inserito dall'utente
5 - Il programma calcola la distanza del percorso. La distanza tra
due località consecutive nell'elenco è calcolata mediante il teorema
di Pitagora. Per il calcolo della radice quadrata utilizzare la
funzione sqrt() presente nella libreria math.h. Si noti che per
compilare il programma quando si una la libreria matematica bisogna
aggiungere alla fine del comando di compilazione l'argomento "-lm".
Quindi si compilerà come "gcc distanze.c -o distante -lm"
6 - Il programma identifica e visualizza la coppia di località
(anche non consecutive nel percorso) la cui distanza è massima. Il
calcolo è eseguibile solo se ci sono almeno due località inserite.
Se ci fossero più coppie a pari distanza massima, il programma ne
stampa una sola (VARIANTE: stampare tutte le coppie).
Se l'utente inserisce un valore sbagliato, il programma visualizza
un messaggio di errore e poi nuovamente il menù.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define STRDIM 30
#define MAX 50

#define INSERISCI 1
#define AGGIUNGI 2
#define CANCELLA 3
#define VISUALIZZA 4
#define LUNGHEZZA 5
#define COPPIAMAX 6
#define USCITA 7

typedef struct {
	int x,y;
	char nome[STRDIM+1];
} localita_t;

typedef struct {
	localita_t loc[MAX];
	int dim;
} percorso_t;


int main(){
	int opt, i, j;
	percorso_t percorso;
	float lunghezza, max;

	percorso.dim = 0;

	do {
		printf("\n\n    _/      _/                             \n   _/_/  _/_/    _/_/    _/_/_/    _/    _/\n  _/  _/  _/  _/_/_/_/  _/    _/  _/    _/ \n _/      _/  _/        _/    _/  _/    _/  \n_/      _/    _/_/_/  _/    _/    _/_/_/   \n");
		printf("\n\n\nMENU\n%d - Inserire in coda una nuova località\n%d - Inserire in una specificata posizione una nuova località\n%d - Cancellare una località nella lista\n%d - Visualizzare l'intero percorso\n%d - Visualizzare la lunghezza complessiva dell'itinerario\n%d - Visualizza la coppia di località (anche non consecutive nel percorso) la cui distanza è maggiore di qualsiasi altra coppia\n%d - Uscita\n\nInserisci scelta: ", INSERISCI, AGGIUNGI, CANCELLA, VISUALIZZA, LUNGHEZZA, COPPIAMAX, USCITA);
		scanf("%d", &opt);

		switch(opt){
			case INSERISCI:
				if(percorso.dim < MAX){
					printf("Località (x, y): ");
					scanf("%d %d", &percorso.loc[percorso.dim].x,  &percorso.loc[percorso.dim].y);
					printf("Nome: ");
					scanf(" %[^\n]", percorso.loc[percorso.dim].nome);
					percorso.dim++;
				}else{
					printf("Spazio esaurito\n");
				}
				break;
			case AGGIUNGI:
				printf("Inserisci indice: ");
				scanf("%d", &i);
				if(i>=0 && i<=percorso.dim){
					for(j=percorso.dim-1; j>=i; j--){
						percorso.loc[j+1] = percorso.loc[j];
					}
					printf("- Inserisci dati -\n");
					printf("Località (x, y): ");
					scanf("%d %d", &percorso.loc[i].x,  &percorso.loc[i].y);
					printf("Nome: ");
					scanf("%[^\n]", percorso.loc[i].nome);
					
					percorso.dim++;
				}else
					printf("Indice non valido\n");
				break;
			case CANCELLA:
				printf("Inserisci indice: ");
				scanf("%d", &i);
				if(i>=0 && i<=percorso.dim){
					for(j=i; j<percorso.dim-1; j++){
						percorso.loc[j] = percorso.loc[j+1];
					}
					percorso.dim--;
				}else
					printf("Indice non valido\n");
				break;
			case VISUALIZZA:
				for(i=0; i<percorso.dim; i++)
					printf("- (%d, %d): %s\n", percorso.loc[i].x, percorso.loc[i].y, percorso.loc[i].nome);
				break;
			case LUNGHEZZA:
				for(i=0, lunghezza = 0; i<percorso.dim-1; i++){
					lunghezza += sqrt((percorso.loc[i].x-percorso.loc[i+1].x)*(percorso.loc[i].x-percorso.loc[i+1].x)+(percorso.loc[i].y-percorso.loc[i+1].y)*(percorso.loc[i].y-percorso.loc[i+1].y));
				}
				printf("Lunghezza: %f\n", lunghezza);
				break;
			case COPPIAMAX:
				/* TODO */
				break;
			case USCITA:
				break;
			default:
				printf("Scelta non valida\n");
		}
	} while (opt != USCITA);

	printf("Arrivederci\n");

	return 0;
}

/* Ricorda -lm compilazione */






















