/*

Definire un nuovo tipo di dato per lista dinamica chiamata
nodo_compatto_t e contenente, oltre al puntatore next, due campi
chiamati n e volte; il primo campo indica l'effettivo valore
memorizzato nel nodo mentre il secondo quante volte compare quel
valore.
Scrivere un sottoprogramma che riceve come parametro una classica
lista dinamica di interi e costruisce la corrispondente lista
compatta.
Se per esempio la lista in ingresso è: 4 2 3 2 2 4, la lista
compatta sarà: (4,2) (2, 3) (3, 1). Infatti il valore 4 compare due
volte nella lista di partenza, il valore 2 tre volte e il valore 3
una volta.
*/

typedef struct nodo_compatto_{
	int num, volte;
	struct nodo_compatto_ *next;
} nodo_compatto_t;

nodo_compatto_t* nodoToNodoCompatto(nodo_t*);

nodo_compatto_t* nodoToNodoCompatto(nodo_t *h){
	nodo_compatto_t *h_comp, *curr, *tmp, *prec;
	int presente;
	h_comp = NULL;


	while(h){
		for(curr = h_comp, presente = 0; curr && !presente; curr = curr->next){
			if(cur->num == h->num){
				presente = 1;
				curr->volte += 1;
			}
		}

		if(!presente){
			/*Aggiungi in coda*/
			tmp = malloc(sizeof(nodo_compatto_t));
			if(tmp){
				tmp->num = h->num;
				tmp->volte = 1;
				tmp->next = NULL;

				if(h_comp){
					for(prec = h_comp; prec && prec->next; prec = prec->next);
					prec->next = tmp;
				}else{
					h_comp = tmp;
				}

			}else{
				printf("Errore allocazione memoria\n");
				/*Distruggi lista*/
			}
		}

		h = h->next;
	}


	return h_comp;
}