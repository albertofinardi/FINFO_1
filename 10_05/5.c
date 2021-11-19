/*
Scrivere un programma in C che calcola il prodotto tra due polinomi
di grado massimo 8. Il programma chiede prima il grado (e nel caso
di valore non valido lo richiede) ed i coefficienti di ciascuno dei
due polinomi (i coefficienti sono valori interi). In seguito esegue
il prodotto polinomiale e visualizza i coefficienti del polinomio
risultato.
*/
#include <stdio.h>
#define DIM 8

int main(){
	int pol1[DIM+1], pol2[DIM+1], ris[DIM*2+1], grado1, grado2, grado3, i, j;

	do
		scanf("%d", &grado1);
	while(grado1>DIM || grado1<0)

	do
		scanf("%d", &grado2);
	while(grado2>DIM || grado2<0)

	for(i=0; i<=grado1; i++)
		scanf("%d", &pol1[i]);

	for(i=0; i<=grado2; i++)
		scanf("%d", &pol2[i]);

	grado3 = grado1+grado2;

	for(i=0; i<=grado3; i++)
		ris[i] = 0;

	for(i=0; i<=grado1; i++){
		for(j=0; j<=grado2; j++)
			ris[i+j] += m1[i] * m2[j];
	}

	for(i=0; i<=grado3; i++)
		printf("%d", ris[i]);

	return 0;

}