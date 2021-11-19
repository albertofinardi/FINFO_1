/*Definire un tipo di dato struct per rappresentare una frazione in
termini di numeratore e denominatore (due numeri interi).
Scrivere un sottoprogramma che chiede all'utente una frazione valida
(denominatore diverso da zero) e la restituisce al chiamate; nel
caso la condizione non sia soddisfatta il sottoprogramma richiede di
nuovo all'utente di inserire dei valori validi.
Scrivere un sottoprogramma che riceve come parametro una frazione e
la semplifica spostando l'eventuale segno meno al numeratore.
Scrivere un sottoprogramma che riceve come parametri due frazioni,
ne esegue la somma, semplifica il risultato (mediante la funzione
precedentemente definita) e restituisce il risultato.
Scrivere un sottoprogramma che riceve come parametri due frazioni,
ne esegue la moltiplicazione, semplifica il risultato (mediante la
funzione precedentemente definita) e restituisce il risultato.
Scrivere un sottoprogramma che riceve come parametro una frazione e
la stampa a video.
Scrivere un programma che mediante l'ausilio dei sottoprogrammi
sopra definiti, chiede all'utente due frazioni le somma e le
moltiplica e visualizza i due risultati.*/

#include <stdio.h>

typedef struct
{
	int num, den;
} frazione_t;

frazione_t input();
frazione_t semplifica(frazione_t);
frazione_t somma(frazione_t, frazione_t);
frazione_t prodotto(frazione_t, frazione_t);
void stampa(frazione_t);

int main(){
	frazione_t f1, f2;
	f1 = input();
	f2 = input();

	stampa(somma(f1, f2));
	stampa(prodotto(f1, f2));
	return 0;
}

frazione_t input(){
	frazione_t frazione;
	do {
		printf("Numeratore: ");
		scanf("%d", &frazione.num);
		printf("Denominatore: ");
		scanf("%d", &frazione.den);
	} while(frazione.den==0);
	return frazione;
}

frazione_t semplifica(frazione_t frazione){
	int meno, mcd;
	if(frazione.num < 0){
		meno = 1;
		frazione.num = -frazione.num;
	} else{
		meno = 0;
	}

	if(frazione.den < 0){
		meno = !meno;
		frazione.den = -frazione.den;
	}
	if(frazione.num < frazione.den){
		mcd = frazione.num;
	}else{
		mcd = frazione.den;
	}

	while(frazione.num % mcd || frazione.den % mcd){
		mcd --;
	}

	frazione.num /= mcd;
	frazione.den /= mcd;
	if(meno){
		frazione.den = -frazione.den;
	}

	return frazione;
}

frazione_t somma(frazione_t f1, frazione_t f2){
	frazione_t somma;
	somma.num = f1.num*f2.den + f2.num*f1.num;
	somma.den = f1.den*f2.den;
	return semplifica(somma);
}

frazione_t prodotto(frazione_t f1, frazione_t f2){
	frazione_t prodotto;
	prodotto.num = f1.num*f2.num;
	prodotto.den = f1.den*f2.den;
	return semplifica(prodotto);
}

void stampa(frazione_t frazione){
	printf("%d / %d", frazione.num, frazione.den);
}