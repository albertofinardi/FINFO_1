/*
Definire un nuovo tipo di dato per una lista concatenata che permetta di memorizzare un polinomio; ciascun nodo della lista memorizzerà un monomio in termini di due interi che rappresentano il grado e il coefficiente di un dato monomio.
Scrivere un programma che chiede all'utente i dati di due polinomi. L'acquisizione di ciascun polinomio termina quando l'utente inserisce i dati 0 0 (che non andrà aggiunta alla lista) ed inoltre va prestata attenzione al fatto che una lista non può contenere due monomi con stesso grado; il programma deve prevenire tale inserimento errato nella lista visualizzando anche un apposito messaggio di errore. Si consiglia di organizzare ciascuna lista ordinando i monomi in ordine decrescente del grado.
In seguito il programma esegue il prodotto e la somma tra i due polinomi salvando il risultato in due nuove liste. Attenzione al fatto che il prodotto tra due monomi può generare un monomio di grado già presente nella lista risultato (e quindi ne va soltanto aggiornato il coefficiente) o un nuovo monomio (che va quindi aggiunto alla lista).
Il programma visualizza infine le quattro liste e, prima di terminare, rilascia tutta la memoria allocata.
Si consiglia di strutturare il programma in vari sottoprogrammi.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_ {
	int grado, coeff;
	struct nodo_ *next;
} nodo_t;

int exists(nodo_t*, int);
nodo_t* inserisciInOrdine(nodo_t*, int, int);
nodo_t* somma(nodo_t*, nodo_t*);
nodo_t* prod(nodo_t*, nodo_t*);
void visualizza(nodo_t*);
void distruggi(nodo_t*);

int main(){
	nodo_t *p1, *p2, *h_sum, *h_prod;
	int grado, coeff;

	p1 = p2 = NULL;

	printf("Primo polinomio\nGrado, coefficiente: ");
	scanf("%d %d", &grado, &coeff);
	while(grado != 0 && coeff != 0){
		if(!exists(p1, grado))
			p1 = inserisciInOrdine(p1, grado, coeff);
		else
			printf("Dato già inserito\n");
		
		printf("Grado, coefficiente: ");
		scanf("%d %d", &grado, &coeff);
	}

	printf("Secondo polinomio\nGrado, coefficiente: ");
	scanf("%d %d", &grado, &coeff);
	while(grado != 0 && coeff != 0){
		if(!exists(p1, grado))
			p2 = inserisciInOrdine(p2, grado, coeff);
		else
			printf("Dato già inserito\n");
		
		printf("Grado, coefficiente: ");
		scanf("%d %d", &grado, &coeff);
	}

	h_sum = somma(p1, p2);
	h_prod = prod(p1, p2);

	printf("Somma\n");
	visualizza(h_sum);
	printf("Prodotto\n");
	visualizza(h_prod);

	distruggi(p1);
	distruggi(p2);
	distruggi(h_sum);
	distruggi(h_prod);
	return 0;
}

int exists(nodo_t *h, int grado){
	int not_exist;
	
	for(not_exist = 1; not_exist && h; h=h->next){
		if(h->grado == grado)
			not_exist = 0;
	}

	return not_exist;
}

nodo_t* inserisciInOrdine(nodo_t* lista, int grado, int coeff){
  nodo_t *tmp, *prec, *curr;
  tmp = malloc(sizeof(nodo_t));
  if(tmp){
    tmp->grado = grado;
    tmp->coeff = coeff;
    tmp->next = NULL;
    if(lista && grado < lista->grado){
      for(prec = lista, curr = lista->next; curr && grado < curr->grado; 
                   curr = curr->next, prec = prec->next);
      tmp->next = curr;
      prec->next = tmp;
    } else {
      tmp->next = lista;
      lista = tmp;
    }
  }else
    printf("Memoria esaurita!\n");
  return lista;
}

nodo_t* somma(nodo_t *p1, nodo_t *p2){
	nodo_t *h, *tmp;
	int exit;
	h = NULL;

	while(p1){
		h = inserisciInOrdine(h, p1->grado, p1->coeff);
		p1 = p1->next;
	}

	while(p2){
		if(exists(h, p2->grado)){
			/* esiste il grado, vanno sommati i coefficienti */
			for(tmp = h, exit = 1; tmp && exit; tmp = tmp->next){
				if(tmp->grado == p2->grado){
					tmp->coeff += p2->coeff;
					exit = 0;
				}
			}
		}else{
			/* non esiste il grado, basta aggiungere in ordine */
			h = inserisciInOrdine(h, p2->grado, p2->coeff);
		}
		p2 = p2->next;
	}

	return h;
}

nodo_t* prod(nodo_t *p1, nodo_t *p2){
	nodo_t *h, *tmp;
	int exit, grado;
	h = NULL;

	while(p1){
		while(p2){
			grado = (p2->grado)*(p1->grado);
			if(exists(h, grado)){
				for(tmp=h, exit = 1; exit && tmp; tmp=tmp->next){
					if(tmp->grado == grado){
						tmp->coeff = (p2->coeff)*(p1->coeff);
						exit = 0;
					}
				}
			}else
				h = inserisciInOrdine(h, grado, (p2->coeff)*(p1->coeff));
			
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	return h;
}

void visualizza(nodo_t *h){
	while(h){
		printf("Grado: %d, coefficiente: %d", h->grado, h->coeff);
		h = h->next;
	}
}

void distruggi(nodo_t *h){
  nodo_t* tmp;
  while(h){
    tmp = h;
    h = h->next;
    free(tmp);
  }
}