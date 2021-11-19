/*
Si vuole realizzare un programma per la gestione di un archivio di
CD musicali (al massimo 100). Ogni CD è caratterizzato da un titolo
ed un autore (entrambe stringhe di al massimo 30 caratteri), un anno
di pubblicazione, il numero di tracce, la durata complessiva (in
termini di ore, minuti, secondi); inoltre si vuole memorizzare anche
il prezzo del cd (un valore float). Definire un tipo di dato per
rappresentare l'archivio di CD. In seguito scrivere un programma che
chiede all'utente prima il numero di CD da inserire e poi i dati di
ciascun CD (assumendo che l'utente inserisca correttamente i dati).
Il programma visualizza i dati del cd di durata massima; se sono
presenti più cd di stessa durata massima il programma visualizzerà i
dati del primo di essi. 

-- VARIANTE: il programma visualizza i dati di
tutti i CD di durata massima, se ne sono stati trovati più di uno.

Il programma chiede in seguito il nome di un autore e visualizza i
titoli di tutti i CD pubblicati da questo. 

-- Infine il programma
visualizza l'autore che ha pubblicato più CD (se più di con lo
stesso numero massimo di CD, si visualizzi il primo).
*/


#include <stdio.h>
#include <string.h>
#define MAXSTR 30
#define MAXCD 100

#define MINTOSEC 60
#define HTOSEC 3600


typedef struct {
	int ore, minuti, secondi;
	//int timestamp;
} tempo_t;

typedef struct {
	char titolo[MAXSTR+1], autore[MAXSTR+1];
	int n_tracce, pubblicazione;
	float prezzo;
	tempo_t durata;
} CD_t;

typedef struct {
	int dim;
	CD_t cd[MAXCD];
} archivio_t;

int main(){
	archivio_t archivio;
	char autore[MAXSTR+1];
	int i, max_i;

	int d_max, d_cor;

	int conto_autore, max_conto, j;

	do {
		scanf("%d", &archivio.dim);
	} while(archivio.dim <= 0 || archivio.dim > MAXCD);

	for(i=0; i<archivio.dim; i++){
		printf("Titolo: ");
		scanf(" %[^\n]", archivio.cd[i].titolo);
		printf("Autore: ");
		scanf(" %[^\n]", archivio.cd[i].autore);
		printf("Numero tracce: ");
		scanf("%d", &archivio.cd[i].n_tracce);
		printf("Pubblicazione: ");
		scanf("%d", &archivio.cd[i].pubblicazione);
		printf("Prezzo: ");
		scanf("%f", &archivio.cd[i].prezzo);
		printf("Ore, minuti, secondi: ");
		scanf("%d %d %d", &archivio.cd[i].durata.ore, &archivio.cd[i].durata.minuti, &archivio.cd[i].durata.secondi);
		//archivio.cd[i].durata.timestamp = archivio.cd[i].durata.secondi + archivio.cd[i].durata.minuti*MINTOSEC + archivio.cd[i].durata.ore*HTOSEC;
	}

	d_max = archivio.cd[0].durata.secondi + archivio.cd[0].durata.minuti*MINTOSEC + archivio.cd[0].durata.ore*HTOSEC;

	for(i=1, max_i = 0; i<archivio.dim; i++){
		d_cor = archivio.cd[i].durata.secondi + archivio.cd[i].durata.minuti*MINTOSEC + archivio.cd[i].durata.ore*HTOSEC;
		if(d_cor > d_max){
			d_max = d_cor;
			max_i = i;
		}
	}

	printf("\n--DURATA MASSIMA--\n\nTitolo: %s \nAutore: %s \nNumero tracce:%d \nPubblicazione: %d \nPrezzo: %f \nOre, minuti, secondi: %d %d %d\n\n", archivio.cd[max_i].titolo, archivio.cd[max_i].autore, archivio.cd[max_i].n_tracce, archivio.cd[max_i].pubblicazione, archivio.cd[max_i].prezzo, archivio.cd[max_i].durata.ore, archivio.cd[max_i].durata.minuti, archivio.cd[max_i].durata.secondi);

	scanf(" %[^\n]", autore);

	for(i=0; i<archivio.dim; i++){
		if(!strcmp(autore, archivio.cd[i].autore)){
			printf("%d)\tTitolo: %s\n", i+1, archivio.cd[i].titolo);
		}
	}

	for(i=0, max_conto = 0; i<archivio.dim; i++){
		for(j=i, conto_autore=0; j<archivio.dim; j++){
			if(!strcmp(archivio.cd[j].autore, archivio.cd[i].autore)){
				conto_autore++;
			}
		}
		if(conto_autore>max_conto){
			max_conto = conto_autore;
			strcpy(autore, archivio.cd[i].autore);
		}
	}


	printf("%s\n", autore);

	return 0;
}