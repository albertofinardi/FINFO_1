/*

Definire un tipo di dato strutturato per rappresentare una frazione
in termini di numeratore e denominatore (due numeri interi).
Scrivere un sottoprogramma che riceve come parametro passato per
indirizzo una frazione e la visualizza sullo schermo.
Scrivere un sottoprogramma che riceve come parametro passato per
indirizzo una variabile frazione, chiede all'utente numeratore e
denominatore (verificando la correttezza di quest'ultimo e nel caso
richiedendone il valore) e salva i due valori nella variabile
ricevuta come parametro.
Scrivere un sottoprogramma che riceve come parametro passato per
indirizzo una frazione e la semplifica.
Scrivere un programma che chiede mediante i sottoprogrammi sopra
definiti chiede all'utente una frazione, la semplifica e mostra il
risultato a video.
*/

#include <stdio.h>

typedef struct{
	int n, d;
} frac_t;

void visualizza(frac_t*);
void acquisisci(frac_t*);
void semplifica(frac_t*);

int main(){
	frac_t f;
	acquisisci(&f);
	semplifica(&f);
	visualizza(&f);
	return 0;
}

void visualizza(frac_t *f){
	printf("%d/%d\n", f->n, f->d); /* puoi srivere anche (*f).n, (*f).d*/
}

void acquisisci(frac_t *f){
	scanf("%d", &f->n);
	do {
		scanf("%d", &f->d);
	} while (f->d == 0);
}

void semplifica(frac_t *f){
	int meno, mcd;
	if(f->n < 0){
		meno = 1;
		f->n = -f->n;
	} else{
		meno = 0;
	}

	if(f->d < 0){
		meno = !meno;
		f->d = -f->d;
	}

	if(f->n < f->d){
		mcd = f->n;
	}else{
		mcd = f->d;
	}

	while(f->n % mcd || f->d % mcd){
		mcd --;
	}

	f->n /= mcd;
	f->d /= mcd;
	if(meno){
		f->d = -f->d;
	}

}