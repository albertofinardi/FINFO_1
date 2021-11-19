/*
Definire un tipo di dato in C per rappresentare una matrice
bidimensionale di valori in virgola mobile di dimensioni massime
5x5; la struttura dati dovrà memorizzare le dimensioni effettive
della matrice ed i dati. Scrivere un programma in C che acquisisce
due matrici, chiedendo prima le dimensioni (e richiedendole nel caso
non siano valide) e poi i valori. Il programma calcola, se
possibile, il prodotto matriciale visualizzando il risultato; in
alternativa visualizza un messaggio di errore.
*/

#include <stdio.h>
#define DIM 5

typedef struct {
	float m[DIM][DIM];
	int righe, colonne;
} matrice;

int main(){

	matrice a,b, prod;
	int i, j, k;

	do {
		scanf("%d", &a.righe);
	}while(a.righe <= 0 || a.righe > DIM);

	do {
		scanf("%d", &a.colonne);
	}while(a.colonne <= 0 || a.colonne > DIM);


	do {
		scanf("%d", &b.righe);
	}while(b.righe <= 0 || b.righe > DIM);

	do {
		scanf("%d", &b.colonne);
	}while(b.colonne <= 0 || b.colonne > DIM);

	for(i=0; i<a.righe; i++)
		for(j=0; j<a.colonne; j++)
			scanf("%f", &a.m[i][j]);

	for(i=0; i<b.righe; i++)
		for(j=0; j<b.colonne; j++)
			scanf("%f", &b.m[i][j]);

	/* con a==b e matrici sottodimensionate confronti anche dati non validi*/

	if(a.colonne == b.righe){
		prod.righe = a.righe;
		prod.colonne = b.colonne;

		for(i=0; i<prod.righe; i++)
			for(j=0; j<prod.colonne; j++)
				for(k=0, prod.m[i][j] = 0; k<a.colonne; k++)
					prod.m[i][j] += a.m[i][k]*b.m[k][j];

		for(i=0; i<prod.righe; i++){
			for(j=0; j<prod.colonne; j++)
				printf("%f\t", prod.m[i][j]);
			printf("\n");
		}


	}else{
		printf("Prodotto matriciale impossibile\n");
	}



	return 0;
}