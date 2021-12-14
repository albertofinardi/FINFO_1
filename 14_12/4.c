/*
ab(acg)be()a(xx)f(a) -> ab(#)be(#)a(#)f(#)
*/

#define START '('
#define END ')'
#define CANC '#'
#include <stdio.h>
#include <stdlib.h>

typedef struct clist_{
	char c;
	struct clist_ *next;
} clist_t;

clist_t* manipola(clist_t*);
clist_t* cancellaInTesta(clist_t*);
clist_t* inserisciInTesta(clist_t*, char);

int main(){
	clist_t *h;

	return 0;
}

clist_t* manipola(clist_t *h){
	clist_t *curr;
	for(curr=h; curr; curr = curr->next){
		if(curr->c == START){
			while(curr->next->c != END)
				curr->next = cancellaInTesta(curr->next);
			curr->next = inserisciInTesta(curr->next, CANC);
			curr = curr->next->next;
		}
	}

	return h;
}
clist_t* cancellaInTesta(clist_t *h){
	clist_t *tmp;
	if(h){
		tmp = h;
		h = h->next;
		free(tmp);
	}
	return h;
}

clist_t* inserisciInTesta(clist_t *h, char c){
	clist_t *tmp;
	tmp = malloc(sizeof(clist_t));
	if(tmp){
		tmp->c = c;
		tmp->next = h;
		h = tmp;
	}else
		printf("Errore allocazione memoria\n");

	return h;
}