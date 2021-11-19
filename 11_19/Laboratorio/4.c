/*


ES4 - Scrivere un sottoprogramma translate che riceve in ingresso
una matrice di valori interi, detta m1, dichiarate nel chiamate con
10 colonne, due parametri interi tr_x e tr_y, e qualsiasi altro
parametro ritenuto strettamente necessario.
Il sottoprogramma restituisce al chiamante, mediante una matrice m2
dichiarata nel chiamante di dimensioni pari ad m1 ed anch'essa
passata dal chiamante per indirizzo, i valori della matrice in
ingresso traslati a destra di tr_x posizioni e in basso di tr_y. Gli
elementi che nella traslazione verso destra "escono" dalla matrice
vengono reinseriti da sinistra, mentre gli elementi che "escono" dal
basso della matrice vengono reinseriti dalla cima.
Scrivere un programma che dichiara due matrici matr1 e matr2 di
10x10 elementi. Il programma chiede prima all'utente quante righe e
quante colonne di matr1 vuole popolare (si assuma che l'utente
inserisca correttamente i valori) e poi i valori. In seguito, il
programma invoca il sottoprogramma sopra realizzato specificando per
i due parametri della traslazione i valori 1 e 2 e salvando i
risultati in matr2, e visualizza il risultato.
Esempio:
Se l'utente specifica le dimensioni 3x3 ed i dati:
174 
832 
984
Il programma visualizzerà il risultato 
283
498 
417

*/

#include <stdio.h>
#define N 10

void translate(int[][N], int, int, int, int, int[][N]);

int main(){
	int matr1[N][N], matr2[N][N];
	int i, j;
	int row, col;

	printf("Numero righe: ");
	scanf("%d", &row);
	printf("Numero colonne: ");
	scanf("%d", &col);

	printf("Inserire valori\n");
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			scanf("%d", &matr1[i][j]);

	translate(matr1, row, col, 1, 2, matr2);

	printf("\n");

	for(i=0; i<row; i++){
		for(j=0; j<col; j++)
			printf("%d ", matr2[i][j]);
		printf("\n");
	}

	return 0;
}


void translate(int m1[][N], int row, int col, int tr_x, int tr_y, int m2[][N]){
	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			m2[(i+tr_y)%row][(j+tr_x)%col] = m1[i][j];
		}
	}
}