/*

Definire le strutture dati per memorizzare le informazioni di una serie di pubblicazioni scientifiche. Ciascuna pubblicazione è caratterizzata da un titolo (una stringa di al massimo 100 caratteri) ed una lista di autori (al massimo 10). Ciascun autore è caratterizzato da nome, cognome, università di affiliazione ed indirizzo email (ciascuna una stringa di al massimo 50 caratteri).
Scrivere un sottoprogramma che riceve come parametri un array di pubblicazioni ed una stringa UNI che indica il nome di un’università e qualsiasi altro parametro ritenuto strettamente necessario. Il sottoprogramma restituisce il numero di pubblicazioni per cui il numero di autori è per almeno la metà affiliato all’università indicata da UNI.

*/
#define MAX_TITOLO 100
#define MAX_AUTORI 10
#define MAX_INFO 50

#define META 2

#include <string.h>
#include <stdio.h>

typedef struct {
	char nome[MAX_INFO], cognome[MAX_INFO], uni[MAX_INFO], email[MAX_INFO];
} autori_t;

typedef struct {
	char titolo[MAX_TITOLO+1];
	autori_t autori[MAX_AUTORI];
	int num_autori;
} pubblicazione_t;

int n_pubblicazioni(pubblicazione_t[], int, char[]);

/*
int main(){
	int i, j;
	pubblicazione_t pubblicazioni[3];
	for(i=0; i<3; i++){
		printf("titolo pubblicazione %d ", i);
		scanf("%s", pubblicazioni[i].titolo);
		do{
			printf("num autori pubblicazione %d ", i);
			scanf("%d", &pubblicazioni[i].num_autori);
		}while(pubblicazioni[i].num_autori > MAX_AUTORI);
		
		for(j=0; j<pubblicazioni[i].num_autori; j++){
			printf("nome pubblicazione %d autore %d ", i, j);
			scanf("%s", pubblicazioni[i].autori[j].nome);
			printf("cognome pubblicazione %d autore %d ", i, j);
			scanf("%s", pubblicazioni[i].autori[j].cognome);
			printf("uni pubblicazione %d autore %d ", i, j);
			scanf("%s", pubblicazioni[i].autori[j].uni);
			printf("email pubblicazione %d autore %d ", i, j);
			scanf("%s", pubblicazioni[i].autori[j].email);
		}
	}

	printf("%d\n", n_pubblicazioni(pubblicazioni, 3, "prova"));
	return 0;
}

*/


int n_pubblicazioni(pubblicazione_t pubblicazioni[], int dim, char UNI[]){
	int i, j, n_pubbl, n_autori;
	for(i=0, n_pubbl = 0; i<dim; i++){
		for(j=0, n_autori = 0; j<pubblicazioni[i].num_autori; j++){
			if(!strcmp(UNI, pubblicazioni[i].autori[j].uni))
				n_autori++;
		}
		if(n_autori >= pubblicazioni[i].num_autori/META)
			n_pubbl++;
	}

	return n_pubbl;
}