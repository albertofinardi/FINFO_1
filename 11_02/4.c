

/*
Definire le strutture dati per rappresentare un concessionario di
automobili. Il concessionario è descritto in termini di un codice
numerico, i dati di un gestore ed una lista di massimo 50
automobili. Il gestore è a sua volta descritto in termini di una
partita IVA, un nome ed un cognome, tre stringhe di al massimo 30
caratteri ciascuna. L'automobile infine è descritta in termini di un
modello (una stringa di al massimo 30 caratteri), una targa (una
stringa di al massimo 7 caratteri) e mese ed anno di
immatricolazione (due interi).
Realizzare un sottoprogramma che riceve come parametro un array di
tipo concessionario, un intero AA che rappresenta un anno, e
qualsiasi altro parametro ritenuto strettamente necessario. Per ogni
concessionario il sottoprogramma stampa a video modello, targa e
mese (in numero) delle auto immatricolate nell'anno AA. Il report
mostrato dovrà avere il seguente formato:
Conc. 0, codice 12345: gestore Paolo Rossi
Immatricolazioni 2015:
* mese 9: Punto, MI80980
* mese 6: Marea, TO12567
Conc. 1, codice 23456: gestore Luca Bianchi
Immatricolazioni 2015:
* mese 2: Panda, VE85980
Conc. 2, codice 23556: gestore Franco Verdi
Immatricolazioni 2015:
NESSUNA
Scrivere un programma che chiede all'utente i dati di 10
concessionari ed invoca la funzione sopra definita per stampare la
reportistica.
*/

#include <stdio.h>
#define GESTORESTR 30

#define AUTOMOD 30
#define AUTOTARGA 7

#define MAXAUTO 50

#define MAXCONCESSIONARI 10

typedef struct{
	char partIVA[GESTORESTR+1], cognome[GESTORESTR+1], nome[GESTORESTR+1];
}gestore_t;

typedef struct{
	char targa[AUTOTARGA+1], modello[AUTOMOD+1];
	int mese, anno;
}auto_t;

typedef struct{
	int id, nauto;
	gestore_t gestore;
	auto_t automobili[MAXAUTO];
}concessionario_t;

void info(concessionario_t[], int, int);


int main(){
	int i, j;
	concessionario_t concessionario[MAXCONCESSIONARI];
	for(i=0; i<MAXCONCESSIONARI; i++){
		printf("-- Concessionario %d --\n", i);
		printf("Codice concessionario: ");
		scanf("%d", &concessionario[i].id);
		printf("-- Gestore --\n");
		printf("Partita Iva: ");
		scanf(" %s", concessionario[i].gestore.partIVA);
		printf("Nome: ");
		scanf(" %s", concessionario[i].gestore.nome);
		printf("Cognome: ");
		scanf(" %s", concessionario[i].gestore.cognome);
		printf("-- Automobili --\n");
		printf("Numero: ");
		scanf(" %d", &concessionario[i].nauto);
		for(j=0; j<concessionario[i].nauto; j++){
			printf("-- Automobile %d --\n", j);
			printf("Targa: ");
			scanf(" %s", concessionario[i].automobili[j].targa);
			printf("Modello: ");
			scanf(" %s", concessionario[i].automobili[j].modello);
			printf("Mese: ");
			scanf(" %d", &concessionario[i].automobili[j].mese);
			printf("Anno: ");
			scanf(" %d", &concessionario[i].automobili[j].anno);
		}
	}
	return 0;
}



void info(concessionario_t concessionario[], int dim_concessionario, int AA){
	int i, j, trovato;
	for(i=0; i<dim_concessionario; i++){
		printf("Conc. %d, codice %d: gestore %s %s\nImmatricolazioni %d:\n", i, concessionario[i].id, concessionario[i].gestore.nome, concessionario[i].gestore.cognome, AA);
		for(j=0, trovato=0; j<concessionario[i].nauto; j++){
			if(concessionario[i].automobili[j].anno == AA){
				printf("* mese %d: %s, %s\n", concessionario[i].automobili[j].mese, concessionario[i].automobili[j].modello, concessionario[i].automobili[j].targa);
				trovato=1;
			}
		}
		if(!trovato){
			printf("NESSUNA\n");
		}
	}

}