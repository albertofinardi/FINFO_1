/*

Definire un tipo di dato intervallo_t per descrivere un intervallo
su un asse temporale in termini di inizio e fine (due numeri
interi).
Scrivere un sottoprogramma che chiede i dati di un intervallo. Se
l'utente specifica un valore di inizio maggiore del valore di fine,
il sottoprogramma inverte i due valori per salvarli correttamente in
una variabile di tipo intervallo_t che restituisce al chiamante.
Scrivere un sottoprogramma che riceve come parametri due intervalli
ed un parametro formale intero, detto "sovrapposti", passato per
indirizzo. Il sottoprogramma verifica se i due intervalli sono
sovrapposti ed in caso affermativo assegna 1 a sovrapposti e calcola
e restituisce l'intervallo sovrapposto; in alternativa assegna 0 a
sovrapposti e restituisce l'intervallo di estremi 0, 0.
Scrivere un sottoprogramma che riceve come parametro un intervallo e
restituisce la sua lunghezza.
Scrivere un sottoprogramma che riceve come parametro un intervallo e
lo stampa a video.
Scrivere un programma che mediante l'ausilio dei tre sottoprogramma
definiti acquisisce due intervalli e valuta se sono sovrapposti; in
caso affermativo visualizza l'intervallo sovrapposto e la sua
lunghezza. In alternativa mostra un messaggio "non sovrapposti".
Esempio: se l'utente inserisce gli intervalli -2 5 e 1 10,
l'intersezione sarà 1 5 ed avrà lunghezza 4.

*/

#include <stdio.h>

typedef struct {
	int inizio, fine;
} intervallo_t;

intervallo_t input();
intervallo_t sovrapposizione(intervallo_t, intervallo_t, int*);
int lunghezza(intervallo_t);
void output(intervallo_t);

int main(){

	intervallo_t i1, i2, sovr;
	int sovrapposti, len;

	i1 = input();
	i2 = input();

	sovr = sovrapposizione(i1, i2, &sovrapposti);

	if(sovrapposti){
		output(sovr);
		len = lunghezza(sovr);
		printf("Lunghezza: %d\n", len);
	}else{
		printf("Non sovrapposti\n");
	}

	return 0;
}

intervallo_t input(){
	intervallo_t intervallo;
	int tmp;
	scanf("%d", &intervallo.inizio);
	scanf("%d", &intervallo.fine);
	if(intervallo.inizio > intervallo.fine){
		tmp = intervallo.inizio;
		intervallo.inizio = intervallo.fine;
		intervallo.fine = tmp;
	}
	return intervallo;
}

intervallo_t sovrapposizione(intervallo_t i1, intervallo_t i2, int *sovrapposti){
	intervallo_t intervallo_sovrapposto;
	if(i1.inizio <= i2.inizio && i1.fine <= i2.fine){
		*sovrapposti = 1;
		intervallo_sovrapposto.inizio = i2.inizio;
		intervallo_sovrapposto.fine = i1.fine;
	}else if(i2.inizio <= i1.inizio && i2.fine <= i1.fine){
		*sovrapposti = 1;
		intervallo_sovrapposto.inizio = i1.inizio;
		intervallo_sovrapposto.fine = i2.fine;
	}else{
		*sovrapposti = 0;
		intervallo_sovrapposto.inizio = 0;
		intervallo_sovrapposto.fine = 0;
	}
	return intervallo_sovrapposto;
}

int lunghezza(intervallo_t i){
	return i.fine - i.inizio;
}

void output(intervallo_t i){
	printf("Inizio: %d, fine: %d\n", i.inizio, i.fine);
}