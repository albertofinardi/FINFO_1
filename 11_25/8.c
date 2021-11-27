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
/*
typedef struct nodo_compatto{
	int n, volte;
	struct nodo_compatto *next;
} nodo_compatto_t;

nodo_compatto_t* nodoToNodoCompatto(nodo_t*);

nodo_compatto_t* nodoToNodoCompatto(nodo_t *h){
	nodo_compatto_t *h_comp, *tmp;
	h_comp = NULL;

	if(h){
		while(h){

			h = h->next;
		}
	}

	return h_comp;
}
*/