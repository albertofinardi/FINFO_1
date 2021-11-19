/*

Scrivere un sottoprogramma che riceve come parametro una matrice di
interi dichiarata nel chiamante con NC=10 colonne, e le dimensioni
di tale matrice. Il sottoprogramma chiede all'utente i dati per
popolare tale matrice.
Scrivere un sottoprogramma che riceve come parametro una matrice di
interi dichiarata nel chiamante con NC=10 colonne, e le dimensioni
di tale matrice. Il sottoprogramma visualizza sullo schermo il
contenuto della matrice.
Scrivere un programma che dichiara una matrice 10x10 di interi. Il
programma utilizza i due sottoprogrammi sopra definiti per acquisire
i dati dell'intera matrice e la visualizza. In seguito il programma
chiede all'utente le dimensioni di una sottomatrice della matrice
sopra dichiarata (si assuma che l'utente inserisca i due valori
correttamente). Il programma popola e visualizza la sottomatrice
mediante i due sottoprogrammi sopra definiti.
*/

#include <stdio.h>
#define NC 10
#define NR 10

void acquisisci(int [][NC], int, int);
/*void acquisisci(int (*)[NC], int, int);*/
void visualizza(int [][NC], int, int);

int main(){
	int m[NR][NC];
	int sub_nr, sub_nc;

	acquisisci(m, NR, NC);
	visualizza(m, NR, NC);

	scanf("%d %d", &sub_nr, &sub_nc);

	acquisisci(m, sub_nr, sub_nc);
	stampa(m, sub_nr, sub_nc);

	return 0;
}

void acquisisci(int m[][NC], int nr, int nc){ /* formula per accedere a celle -> i*NC + j, senza NC il sottoprogramma non sa come linearizzare la matrice */
	int i, j;
	for(i=0; i<nr; i++){
		for(j=0; j<nc; j++){
			scanf("%d", &m[i][j]);
		}
	}
}

void visualizza(int m[][NC], int nr, int nc){
	int i, j;
	for(i=0; i<nr; i++){
		for(j=0; j<nc; j++){
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}

/* 	DA CONTROLLARE
void acquisisci(int (*p)[NC], int nr, int nc){ 
	int j, i;
	for(i=0; i<nr; i++, p++){
		for(j=0; j<nc; i++){
			scanf("%d", &(*p)[i]);
		}
	}
}
*/