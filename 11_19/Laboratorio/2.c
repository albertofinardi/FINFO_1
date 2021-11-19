/*


ES2 - Un punto nel piano cartesiano è definito dalla coppia di
coordinate intere x e y: si definisca l'opportuno tipo di dato
point_t.
Data una matrice quadrata NxN di punti, i punti della diagonale,
quelli di ogni riga e quelli di ogni colonna definiscono linee
spezzate (ciascuna di N-1 lati). Si definisce regolare una matrice
dove la lunghezza della spezzata definita dalla diagonale è maggiore
della lunghezza di tutte le spezzate definite dalle righe e dalle
colonne della matrice.
Scrivere un sottoprogramma regolare() che ricevuta in ingresso una
matrice quadrata di punti e qualsiasi parametro ritenuto
strettamente necessario, restituisce 1 se la matrice è regolare, 0
altrimenti.
Si supponga che esista una direttiva
# define N ...
che indica la dimensione utilizzata nella dichiarazione della
matrice quadrata passata al sottoprogramma.
Infine si suggerisce di realizzare un apposito sottoprogramma di
ausilio
float dist(point_t p1, point_t p2)
che calcola e restituisce la distanza euclidea tra due punti.
Scrivere un programma che chiede i dati di una matrice NxN di punti
(con N=3), invoca il programma sopra definito e visualizza il
risultato.


*/

#include <stdio.h>
#include <math.h>

typedef struct{
	int x, y;
 } point_t;

#define NC 3

int regolare(point_t [][NC], int, int);
float dist(point_t, point_t);

int main(){
	int i, j, reg;
	point_t m[N][N];

	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			scanf("%d %d", &m[i][j].x, &m[i][j].y);
	}

	reg = regolare(m, N, N);

	printf("%d\n", reg);

	return 0;
}

float dist(point_t p1, point_t p2){
	return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));

}

int regolare(point_t m[][NC], int col, int row){
	int i, j;
	int d_diag, d_loc;
	int regolare;

	for(i=1, d_diag = 0, regolare = 1; i<row; i++){
		for(j=1; j<col; j++){
			if(i==j){
				d_diag = dist(m[i-1][j-1], m[i][j]);
			}
		}
	}

	for(i=0; i<row && regolare; i++){
		for(j=1, d_loc = 0; j<col && regolare; j++){
			d_loc += dist(m[i][j-1], m[i][j]);
			if(d_loc > d_diag)
				regolare = 0;
		}
	}

	for(i=0; i<col && regolare; i++){
		for(j=1, d_loc = 0; j<row && regolare; j++){
			d_loc += dist(m[i][j-1], m[i][j]);
			if(d_loc > d_diag)
				regolare = 0;
		}
	}
}


/* ricorda -lm in compilazione */







