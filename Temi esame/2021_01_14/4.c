/*
Si vuole realizzare un programma per la gestione di una cineteca.
a) Definirelestrutturedatipermemorizzarelacineteca(tipocineteca_t)chepuòcontenereunmassimodi1000
film diversi. Ciascun film (tipo film_t) è caratterizzato dal titolo (una stringa di al massimo 100 caratteri), un elenco di al massimo 10 attori, l’anno di uscita e la durata in minuti (due interi). Ciascun attore (tipo attore_t) è caratterizzato da nome e cognome (due stringhe di al massimo 50 caratteri ciascuna).
b) Realizzare un sottoprogramma che riceve come parametri una cineteca (cineteca_t) ed un attore (attore_t). Il sottoprogramma conta e restituisce il numero di film nella cineteca interpretati da tale attore.
VARIANTE:
Si vuole realizzare un programma per la gestione di un negozio di dischi.
a) Definire le strutture dati per memorizzare il negozio di dischi (tipo negozio_t) che può contenere un massimo
di 1000 dischi diversi. Ciascun disco (tipo disco_t) è caratterizzato dal titolo (una stringa di al massimo 100 caratteri), un elenco di al massimo 10 cantanti, l'anno di pubblicazione e la durata in minuti (due interi). Ciascun cantante (tipo cantante_t) è caratterizzato da nome e cognome (due stringhe di al massimo 50 caratteri ciascuna).
b) Realizzare un sottoprogramma che riceve come parametri un negozio di dischi (negozio_t) ed un cantante (cantante_t). Il sottoprogramma conta e restituisce il numero di dischi nel negozio registrati dal tale cantante.
*/

#define MAX_FILM 1000
#define MAX_TITOLO 100
#define MAX_ATTORI 10
#define MAX_INFOATTORI 50

typedef struct {
	char nome[MAX_INFOATTORI+1], cognome[MAX_INFOATTORI+1];
} attore_t;

typedef struct {
	char titolo[MAX_TITOLO+1];
	attore_t attori[MAX_ATTORI];
	int anno_uscita, durata, num_attori;
} film_t;

typedef struct {
	film_t film[MAX_FILM];
	int num_film;
} cineteca_t;

int film_interpretati(cineteca_t, attore_t);

int film_interpretati(cineteca_t cineteca, attore_t attore){
	int n_film, i, j, salta;
	for(i=0, n_film = 0; i<cineteca.num_film; i++){
		for(j=0, salta=0; j<cineteca.film[i].num_attori && !salta; j++){
			if(cineteca.film[i].attori[j].nome == attore.nome && cineteca.film[i].attori[j].cognome == attore.cognome){
				n_film++;
				salta = 1; /* se si trova attore in film è inutile controllare gli altri dello stesso film */
			}
		}
	}
	return n_film;
}

/* VARIANTE 

#define MAX_DISCHI 1000
#define MAX_TITOLO 100
#define MAX_CANTANTI 10
#define MAX_INFOCANTANTI 50

typedef struct {
	char nome[MAX_INFOCANTANTI+1], cognome[MAX_INFOCANTANTI+1];
} cantante_t;

typedef struct {
	char titolo[MAX_TITOLO+1];
	cantante_t cantanti[MAX_CANTANTI];
	int anno_uscita, durata, num_cantanti;
} disco_t;

typedef struct {
	disco_t dischi[MAX_DISCHI];
	int num_dischi;
} negozio_t;

int dischi_registrati(negozio_t, cantante_t);

int dischi_registrati(negozio_t negozio, cantante_t cantante){
	int n_dischi, i, j;
	for(i=0, n_dischi = 0; i<negozio.num_dischi; i++){
		for(j=0; j<negozio.dischi[i].num_cantanti; j++){
			if(negozio.dischi[i].cantanti[j].nome == cantante.nome && negozio.dischi[i].cantanti[j].cognome == cantante.cognome)
				n_dischi++;
		}
	}
	return n_dischi;
}

*/