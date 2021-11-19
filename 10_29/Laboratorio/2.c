/*
ES2 - Modificare il programma 2021-10-15-codice.c (gestione di un percorso) visto in aula aggiungendovi le seguenti due nuove funzionalità: 
7 - Ricerca di una località dato il nome. La funzionalità chiede all'utente il nome di una località (una stringa di al massimo 30 caratteri) e stampa a video i dati di tutte le località con quel dato nome. Si ricordi che per confrontare le stringhe si può usare la funzione strcmp() contenuta in string.h che riceve come parametri due stringhe e restituisce 0 se sono uguali.
8 - Calcola cornice del percorso. La funzionalità calcola la cornice rettangolare sulla cartina che racchiude tutto il percorso e ne visualizza le coordinate dei due vertici in basso a sinistra ed in alto a destra. Visualizzare un apposito messaggio di errore nel caso il percorso sia vuoto.
Rinumerare opportunamente l'opzione di uscita (che diventerà 9).
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
#define RICERCA 7
#define CORNICE 8
#define USCITA 9

typedef struct {
	int x,y;
	char nome[STRDIM+1];
} localita_t;

typedef struct {
	localita_t loc[MAX];
	int dim;
} percorso_t;

void inserisci_f(percorso_t*, int);
void aggiungi_f(percorso_t*);
void cancella_f(percorso_t*);
void visualizza_f(percorso_t*);
void lunghezza_f(percorso_t*);
/*void coppiamax_f();*/
void ricerca_f();
void cornice_f();


int main(){
	int opt;
	percorso_t percorso;

	percorso.dim = 0;

	do {
		printf("\n\n    _/      _/                             \n   _/_/  _/_/    _/_/    _/_/_/    _/    _/\n  _/  _/  _/  _/_/_/_/  _/    _/  _/    _/ \n _/      _/  _/        _/    _/  _/    _/  \n_/      _/    _/_/_/  _/    _/    _/_/_/   \n");
		printf("\n\n\nMENU\n%d - Inserire in coda una nuova località\n%d - Inserire in una specificata posizione una nuova località\n%d - Cancellare una località nella lista\n%d - Visualizzare l'intero percorso\n%d - Visualizzare la lunghezza complessiva dell'itinerario\n%d - Visualizza la coppia di località (anche non consecutive nel percorso) la cui distanza è maggiore di qualsiasi altra coppia\n%d - Ricerca di una località\n%d - Calcola cornice del percorso\n%d - Uscita\n\nInserisci scelta: ", INSERISCI, AGGIUNGI, CANCELLA, VISUALIZZA, LUNGHEZZA, COPPIAMAX, RICERCA, CORNICE, USCITA);
		scanf("%d", &opt);

		switch(opt){
			case INSERISCI:
				inserisci_f(&percorso, MAX);
				break;
			case AGGIUNGI:
				aggiungi_f(&percorso);
				break;
			case CANCELLA:
				cancella_f(&percorso);
				break;
			case VISUALIZZA:
				visualizza_f(&percorso);
				break;
			case LUNGHEZZA:
				lunghezza_f(&percorso);
				break;
			case COPPIAMAX:
				/* TODO */
				break;
			case RICERCA:
				ricerca_f(&percorso);
				break;
			case CORNICE:
				/* TODO */
				cornice_f(&percorso);
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


void inserisci_f(percorso_t *percorso, int max){
	if(percorso->dim < max){
		printf("Località (x, y): ");
		scanf("%d %d", &percorso->loc[percorso->dim].x,  &percorso->loc[percorso->dim].y);
		printf("Nome: ");
		scanf(" %[^\n]", percorso->loc[percorso->dim].nome);
		percorso->dim++;
	}else{
		printf("Spazio esaurito\n");
	}
}


void aggiungi_f(percorso_t *percorso){
	int i, j;
	printf("Inserisci indice: ");
	scanf("%d", &i);
	if(i>=0 && i<=percorso->dim){
		for(j=percorso->dim-1; j>=i; j--){
				percorso->loc[j+1] = percorso->loc[j];
		}
		printf("- Inserisci dati -\n");
		printf("Località (x, y): ");
		scanf("%d %d", &percorso->loc[i].x,  &percorso->loc[i].y);
		printf("Nome: ");
		scanf(" %[^\n]", percorso->loc[i].nome);
					
		percorso->dim++;
	}else
		printf("Indice non valido\n");
}

void cancella_f(percorso_t *percorso){
	int i, j;
	printf("Inserisci indice: ");
	scanf("%d", &i);
	if(i>=0 && i<=percorso->dim){
		for(j=i; j<percorso->dim-1; j++){
			percorso->loc[j] = percorso->loc[j+1];
		}
			percorso->dim--;
	}else
		printf("Indice non valido\n");
}

void visualizza_f(percorso_t *percorso){
	int i;
	for(i=0; i<percorso->dim; i++)
		printf("- (%d, %d): %s\n", percorso->loc[i].x, percorso->loc[i].y, percorso->loc[i].nome);
}

void lunghezza_f(percorso_t *percorso){
	int i;
	float lunghezza;
	for(i=0, lunghezza = 0; i<percorso->dim-1; i++){
			lunghezza += sqrt((percorso->loc[i].x-percorso->loc[i+1].x)*(percorso->loc[i].x-percorso->loc[i+1].x)+(percorso->loc[i].y-percorso->loc[i+1].y)*(percorso->loc[i].y-percorso->loc[i+1].y));
		}
	printf("Lunghezza: %f\n", lunghezza);
}

void ricerca_f(percorso_t *percorso){
	char nome[STRDIM+1];
	int i;

	printf("Inserire nome: ");
	scanf(" %[^\n]", nome);

	for(i=0; i<percorso->dim; i++){
		if(!strcmp(nome, percorso->loc[i].nome))
			printf("- (%d, %d): %s\n", percorso->loc[i].x, percorso->loc[i].y, percorso->loc[i].nome);
	}
}

void cornice_f(percorso_t *percorso){
	/* TODO */
}

/* Ricorda -lm compilazione */






















