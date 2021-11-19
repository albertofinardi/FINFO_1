/*

ES3 - Si vuole realizzare un programma che verifica se una griglia
di un Sudoku (https://it.wikipedia.org/wiki/Sudoku), anche
parzialmente riempita, sia valida o meno. In breve una griglia di un
Sudoku è una matrice 9x9 di interi e ciascuna posizione può
contenere un valore da 1 a 9 o esser vuota se la griglia non è stata
ancora completata. Una griglia, anche parzialmente, è valida se si
verificano tutte le seguenti condizioni:
* in ciascuna riga della matrice non si presenta alcuna ripetizione
dei numeri validi (da 1 a 9)
* in ciascuna colonna della matrice non si presenta alcuna
ripetizione dei numeri validi (da 1 a 9)
* dividendo la matrice 9x9 in 9 sottomatrici 3x3 non sovrapposte,
ciascuna sottomatrice non contiene alcuna ripetizione dei numeri
validi (da 1 a 9).
Realizzare il programma come segue:
- definire una costante VUOTO contenente il valore 0.
- definire un sottoprogramma "stampa_sudoku" che riceva come argomento una matrice definita con 9 colonne e la stampi a video. Si utilizzi uno spazio per indicare le celle vuote; opzionale: disegnare le righe orizzontali e verticali che contornano l'intera griglia e le 9 sottogriglie come da esempio: +-------+-------+-------+
|9||4|
|85|4|1|
| 4|681|539|
+-------+-------+-------+
|8|49|73|
|7| 6|48|
|41|83|6|
+-------+-------+-------+
|35 |4 |291|
|9 2|1 3| 76|
|1 |6|54|
+-------+-------+-------+
- definire un sottoprogramma "leggi" che riceve come argomento il nome di un file di testo e una matrice di interi dichiarata con 9 colonne. Il sottoprogramma apre il file di testo, contenente 9x9 valori interi, e popola la matrice con i dati letti da file. Il sottoprogramma restituisce 1 se l'operazione è andata a buon fine altrimenti 0. Si noti che si potrebbe verificare un errore di apertura del file o il numero di valori letti potrebbe essere erroneamente minore di 81 o un dato valore potrebbe essere al di fuori dell'intervallo [1,9] o diversa da VUOTO. Il sottoprogramma prima di ritornare stampa a video la causa dell'eventuale errore riscontrato.
- definire un sottoprogramma "verifica_sudoku" che riceva come argomento una matrice di interi dichiarata con 9 colonne e verifichi che il sudoku associato sia valido. Il sottoprogramma restituisce 1 in caso affermativo; in alternativa stampa a video un messaggio per ciascun errore riscontrato (cioè indici di riga o colonna o quadrante che violano le regole) e restituisce 0.
- Scrivere un programma chiede all'utente il nome del file (una stringa di al massimo 50 caratteri). Mediante l'ausilio dei sottoprogrammi sopra definiti, il programma legge la matrice dal file, la stampa a video e verifica se la griglia è valida, stampando a video il responso. Gestire opportunamente gli eventuali errori.

*/

#include <stdio.h>

#define DIM 50
#define VUOTO 0
#define N 9
#define NSUB 3
#define MIN 1
#define MAX 9

int leggi(char[], int[][N], int, int);
int in_range(int);

void stampa_sudoku(int[][N], int, int);

int verifica_sudoku(int[][N], int, int);

int main(){
	char fn[DIM+1];
	int sudoku[N][N];

	scanf("%s", fn);

	if(leggi(fn, sudoku, N, N)){
		stampa_sudoku(sudoku, N, N);
		printf("\n\n\nValidità: %d\n", verifica_sudoku(sudoku, N, N));
	}

	return 0;
}

int leggi(char fn[], int sudoku[][N], int col, int row){
	FILE *fp;
	int n, success, numeri;

	int i, j;

	fp = fopen(fn, "r");
	success = 1;
	numeri = 0;

	if(fp){
		fscanf(fp, "%d", &n);
		i = 0;
		j = 0;
		while(!feof(fp) && success){

			if(j == col){
				j=0;
				i++;
			}

			if(!in_range(n)){
				printf("Fuori range\n");
				success = 0;
			}

			if(j<col && i<row){
				sudoku[i][j] = n;
				j++;
				numeri++;
			}else{
				printf("Quantità eccessiva di dati\n");
				success = 0;
			}

			fscanf(fp, "%d", &n);
		}
		if(numeri < col*row){
			printf("Dati insufficienti\n");
			success = 0;
		}
		fclose(fp);
	}else{
		printf("Errore apertura file\n");
		success = 0;
	}

	return success;

}

int in_range(int n){
	return (n>= MIN && n <= MAX) || n == VUOTO;
}

void stampa_sudoku(int sudoku[][N], int col, int row){

	int i, j, x;

	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			if(sudoku[i][j] == VUOTO)
				printf(" \t");
			else
				printf("%d\t", sudoku[i][j]);
		}
		printf("\n");
	}

}

int verifica_sudoku(int sudoku[][N], int col, int row){
	int valido;
	int i, j, y, x, a, b;
	int inizio_x;
	int inizio_y;
	
	valido = 1;

	for(i=0; i<row && valido; i++){
		for(j=0; j<col && valido; j++){
			for(x=0; x<j && valido; x++){
				if(sudoku[i][j] == sudoku[i][x]){
					valido = 0;
					printf("Dati ripetuti su riga\n");
				}
			}
		}
	}

	for(i=0; i<col && valido; i++){
		for(j=0; j<row && valido; j++){
			for(x=0; x<j && valido; x++){
				if(sudoku[i][j] == sudoku[i][x]){
					valido = 0;
					printf("Dati ripetuti su colonna\n");
				}
			}
		}
	}

	/* TODO - Verifica matrici 3x3 */

	/*for(i=0, inizio_y=0; i<row && valido; i++){
		if(i%NSUB == 1){
			inizio_y = i;
		}
		for(j=0, inizio_x = 0; j<col && valido; j++){
			if(j%NSUB == 1){
				inizio_x = j;
			}
			for(y=inizio_y; y<inizio_y+NSUB && valido; y++){
				for(x=inizio_x; x<inizio_x+NSUB && valido; x++){
					for(a=inizio_y; i<y; a++){
						for(b=inizio_x; b<x; b++){
							if(sudoku[a][b] == sudoku[y][x]){
								valido = 0;
								printf("Cella non valida\n");
							}
						}
					}
				}
			}
		}
	}*/


	return valido;
}