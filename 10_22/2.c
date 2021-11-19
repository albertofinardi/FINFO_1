/*
Definiamo baricentro di un array di h elementi, l'elemento in
posizione i tale per cui:
v[0] + v[1] + ... + v[i] = v[i + 1] + v[i + 2] + ... + v[h - 1]
Scrivere un programma in C che chiede all'utente i dati di un array
di interi di 10 valori, calcola e visualizza l'indice dell'elemento
che fa da baricentro agli elementi dell'array, o -1 se questo non
esiste.
Se dovessero esserci più baricentri, il programma visualizza quello
più a sinistra.
Esempio 1:
se il vettore contiene i valori: 1 0 5 10 4 4 2 6 0 0
il programma visualizza il valore 3 (infatti la somma dei primi 4
elementi è uguale a 16 come quella degli ultimi 6 elementi).
Esempio 2:
se il vettore contiene i valori: 1 0 5 10 4 4 2 7 0 0
il programma visualizza il valore -1, non essendoci alcun
baricentro.

*/

#include <stdio.h>
#define MAX 10

/*
int main(){

	int n[MAX], i, j, sumL, sumR, notfound;

	for(i=0; i<MAX; i++){
		scanf("%d", &n[i]);
	}

	for(i=0, sumL=0, notfound = 1; i<MAX && notfound; i++){
		sumL += n[i];
		for(j=i+1, sumR=0; j<MAX; j++){
			sumR += n[j];
		}
		if(sumL == sumR){
			printf("%d\n", i);
			notfound = 0;
		}
	}

	if(notfound){
		printf("-1\n");
	}

	return 0;
}
*/




int main(){

	int n[MAX], i, baricentro, sumL, tot;

	for(i=0; i<MAX; i++){
		scanf("%d", &n[i]);
	}

	for(i=0, tot=0; i<MAX; i++){
		tot += n[i];
	}

	for(i=0, baricentro=-1, sumL = 0, exit=1; i<MAX && baricentro==-1; i++){
		sumL += n[i];
		if(sumL == tot - sumL){
			baricentro = i;
		}
	}

	print("%d\n", baricentro);

	return 0;
}






