/*

Si considerino le seguenti strutture dati che permettono di rappresentare un
componente di un mobile Ikea (per esempio: vite, pannello, anta, ...), un magazzino
di componenti e le istruzioni per costruire un mobile (per esempio: cucina,
armadio, ...).
#define MAXS 100
#define MAXC 200
typedef struct {
  int codice;
  char nome[MAXS+1];
  int quantita;
} componente_t;
typedef struct {
  char nome[MAXS+1];
  char indirizzo[MAXS+1];
  componente_t componenti[MAXC];
  int n_componenti;
} magazzino_t;
typedef struct {
  int codice;
  char descrizione[MAXS+1];
  float costo;
  componente_t componenti[MAXC];
  int n_componenti;
} istruzioni_t;
a) Scrivere un sottoprogramma che riceve come parametri un magazzino di componenti MAG, un manuale di istruzioni MAN ed un numero intero X. Il sottoprogramma verifica se è possibile costruire X mobili relativi al manuale MAN ricevuto come parametro e prelevando i componenti dal magazzino MAG; in caso affermativo il sottoprogramma restituisce 1 altrimenti 0.
b) Scrivere un sottoprogramma che riceve come parametri il nome di un file binario ed un magazzino di componenti (passato per indirizzo). Il sottoprogramma legge le informazioni del magazzino contenute nel file e le salva nel parametro passato per indirizzo. Nel caso di errore di accesso al file il sottoprogramma inizializza il magazzino con un numero di componenti pari a zero e visualizza un messaggio di errore.
c) Scrivere un sottoprogramma che riceve come parametri il nome di un file binario ed un manuale di istruzioni (passato per indirizzo). Il sottoprogramma legge le informazioni del manuale contenute nel file e le salva nel parametro passato per indirizzo. Nel caso di errore di accesso al file il sottoprogramma inizializza il manuale con un numero di componenti richiesti pari a zero e visualizza un messaggio di errore.
d) Scrivere un sottoprogramma che riceve come parametri il nome di un file di testo e un magazzino. Il sottoprogramma salva nel file di testo un report con il contenuto del magazzino. Nel caso di errore di accesso al file il sottoprogramma stampa un messaggio di errore.
e) Scrivere un sottoprogramma che riceve come parametri il nome di un file di testo
e un manuale di istruzioni. Il sottoprogramma salva nel file di testo un report con
il contenuto del manuale di istruzioni. Nel caso di errore di accesso al file il
sottoprogramma stampa un messaggio di errore.
d) Scrivere un programma che riceve come argomenti i nomi di due file binari, contenenti rispettivamente i dati di un libretto di istruzioni (una variabile di tipo istruzioni_t) e di un magazzino (una variabile di tipo magazzino_t), un numero N ed i nomi di due file di testo da creare. Mediante l'ausilio dei sottoprogrammi sopra definiti, il programma legge dai file i dati salvandoli in due variabili di tipo istruzioni_t e magazzino_t, verifica se con i mezzi contenuti nel magazzino è possibile è possibile costruire N mobili seguendo le istruzioni fornite e visualizza il risultato a video. Infine, il programma salva in due file di testo il contenuto del magazzino e del manuale di istruzioni.
Come test, forniamo i file istrN.bin, magN.bin, con N=1,2,3. Qui di seguito
mostriamo gli output a video del programma (oltre alla creazione dei due report di
testo che viene omessa).
./ikea istr1.bin mag1.bin 1 istr.txt mag.txt
Output: 1
./ikea istr1.bin mag1.bin 2 istr.txt mag.txt
Output: 0
./ikea istr2.bin mag2.bin 0 istr.txt mag.txt
Output: 1
./ikea istr2.bin mag2.bin 1 istr.txt mag.txt
Output: 0
./ikea istr3.bin mag3.bin 3 istr.txt mag.txt
Output: 1
./ikea istr3.bin mag3.bin 4 istr.txt mag.txt
Output: 0

./ikea istr2.bin mag3.bin 0 istr.txt mag.txt
Output: 0

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 100
#define MAXC 200

typedef struct {
  int codice;
  char nome[MAXS+1];
  int quantita;
} componente_t;

typedef struct {
  char nome[MAXS+1];
  char indirizzo[MAXS+1];
  componente_t componenti[MAXC];
  int n_componenti;
} magazzino_t;

typedef struct {
  int codice;
  char descrizione[MAXS+1];
  float costo;
  componente_t componenti[MAXC];
  int n_componenti;
} istruzioni_t;

int possibileCostruire(magazzino_t*, istruzioni_t*, int);
int qtnComponentiAdatta(magazzino_t*, componente_t*, int);
void leggiFileMagazzino(char[], magazzino_t*);
void leggiFileIstruzioni(char[], istruzioni_t*);
void scriviFileMagazzino(char[], magazzino_t*);
void scriviFileIstruzioni(char[], istruzioni_t*);

int main(int argc, char *argv[]){

	istruzioni_t istruzioni;
	magazzino_t magazzino;
	int costru;
	int x;

	if(argc == 6){
		
		leggiFileIstruzioni(argv[1], &istruzioni);
		leggiFileMagazzino(argv[2], &magazzino);
		

		x = atoi(argv[3]);
		
		costru = possibileCostruire(&magazzino, &istruzioni, x);
		printf("Output: %d\n", costru);

		

		scriviFileIstruzioni(argv[4], &istruzioni);
		scriviFileMagazzino(argv[5], &magazzino);
	}else{
		printf("Errore argomenti\n");
	}
	return 0;
}

/*
a) Scrivere un sottoprogramma che riceve come parametri un magazzino di componenti MAG, un manuale di istruzioni MAN ed un numero intero X. Il sottoprogramma verifica se è possibile costruire X mobili relativi al manuale MAN ricevuto come parametro e prelevando i componenti dal magazzino MAG; in caso affermativo il sottoprogramma restituisce 1 altrimenti 0.
*/


int possibileCostruire(magazzino_t *MAG, istruzioni_t *MAN, int X){
	int i, possibile;

	for(i=0, possibile=1; i<MAN->n_componenti && possibile; i++){
		if(!qtnComponentiAdatta(MAG, &(MAN->componenti[i]), X*MAN->componenti[i].quantita))
			possibile = 0;
	}

	return possibile;
}

int qtnComponentiAdatta(magazzino_t *mag, componente_t *c, int x){
	int i, qtn;
	for(i=0, qtn=0; i<mag->n_componenti && !qtn; i++){
		if(mag->componenti[i].codice == c->codice)
			qtn = mag->componenti[i].quantita;
	}
	return x <= qtn;
}

/*
Scrivere un sottoprogramma che riceve come parametri il nome di un file binario ed un magazzino di componenti (passato per indirizzo). Il sottoprogramma legge le informazioni del magazzino contenute nel file e le salva nel parametro passato per indirizzo. Nel caso di errore di accesso al file il sottoprogramma inizializza il magazzino con un numero di componenti pari a zero e visualizza un messaggio di errore.
*/

void leggiFileMagazzino(char fn[], magazzino_t *mag){
	FILE *fp;
	fp = fopen(fn, "rb");
	if(fp){
		fread(mag, sizeof(magazzino_t), 1, fp);
		fclose(fp);
	}else{
		mag->n_componenti = 0;
		printf("Errore apertura file magazzino\n");
	}
}

/*
Scrivere un sottoprogramma che riceve come parametri il nome di un file binario ed un manuale di istruzioni (passato per indirizzo). Il sottoprogramma legge le informazioni del manuale contenute nel file e le salva nel parametro passato per indirizzo. Nel caso di errore di accesso al file il sottoprogramma inizializza il manuale con un numero di componenti richiesti pari a zero e visualizza un messaggio di errore.
*/

void leggiFileIstruzioni(char fn[], istruzioni_t *istr){
	FILE *fp;
	fp = fopen(fn, "rb");
	if(fp){
		fread(istr, sizeof(istruzioni_t), 1, fp);
		fclose(fp);
	}else{
		istr->n_componenti = 0;
		printf("Errore apertura file istruzioni\n");
	}
}

/*
Scrivere un sottoprogramma che riceve come parametri il nome di un file di testo e un magazzino. Il sottoprogramma salva nel file di testo un report con il contenuto del magazzino. Nel caso di errore di accesso al file il sottoprogramma stampa un messaggio di errore.
*/

void scriviFileMagazzino(char fn[], magazzino_t *mag){
	FILE *fp;
	int i;
	fp = fopen(fn, "w");
	if(fp){
		//fwrite(mag, sizeof(magazzino_t), 1, fp);
		fprintf(fp, "Nome: %s\n", mag->nome);
		fprintf(fp, "Indirizzo: %s\n", mag->indirizzo);
		fprintf(fp, "Componenti:\n");
		for(i=0; i<mag->n_componenti; i++){
			fprintf(fp, "\tN. %d\n", i+1);
			fprintf(fp, "\t\tCodice: %d\n", mag->componenti[i].codice);
			fprintf(fp, "\t\tNome: %s\n", mag->componenti[i].nome);
			fprintf(fp, "\t\tQuantità: %d\n", mag->componenti[i].quantita);
		}
		fclose(fp);
	}else{
		printf("Errore scrittura file magazzino\n");
	}
}


/*
Scrivere un sottoprogramma che riceve come parametri il nome di un file di testo
e un manuale di istruzioni. Il sottoprogramma salva nel file di testo un report con
il contenuto del manuale di istruzioni. Nel caso di errore di accesso al file il
sottoprogramma stampa un messaggio di errore.
*/


void scriviFileIstruzioni(char fn[], istruzioni_t *istr){
	FILE *fp;
	int i;
	fp = fopen(fn, "w");
	if(fp){
		fprintf(fp, "Codice: %D\n", istr->codice);
		fprintf(fp, "Descrizione: %s\n", istr->descrizione);
		fprintf(fp, "Costo: %f\n", istr->costo);
		fprintf(fp, "Componenti:\n");
		for(i=0; i<istr->n_componenti; i++){
			fprintf(fp, "\tN. %d\n", i+1);
			fprintf(fp, "\t\tCodice: %d\n", istr->componenti[i].codice);
			fprintf(fp, "\t\tNome: %s\n", istr->componenti[i].nome);
			fprintf(fp, "\t\tQuantità: %d\n", istr->componenti[i].quantita);
		}
		fclose(fp);
	}else{
		printf("Errore scrittura file istruzioni\n");
	}
}


