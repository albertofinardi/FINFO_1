/*

Definire un nuovo tipo di dato per la gestione di una lista dinamica di interi, list_t. 
Scrivere due sottoprogrammi kcon e knocon che ricevuta in ingresso una lista del tipo definito ed un intero k, 
si comportino come specificato di seguito: 
- kcon: restituisce 1 se la lista contiene almeno due occorrenze consecutive di k, 0 altrimenti
- knocon: restituisce 1 se la lista contiene almeno due occorrenze non consecutive
di k, 0 altrimenti.
Provare a realizzare le versioni sia iterative che ricorsive dei due
sottoprogrammi; per le versioni ricorsive è possibile definire ulteriori
sottoprogrammi ausiliari.
Esempi (tutti con k=5)
Con la lista: 1 -> 5 -> 5 -> 3 -> 2 kcon: 1
knoncon: 0
Con la lista: 1 -> 5 -> 5 -> 5 -> 2 kcon: 1
knoncon: 1
Con la lista: 1 -> 5 -> 3 -> 5 -> 2 kcon: 0
knoncon: 1

*/
#include <stdio.h>

typedef struct list_ {
    int num;
    struct list_ *next;
} list_t;

int kcon(list_t*, int);
int knocon(list_t*, int);

int kcon_ric(list_t*, int);
int knocon_ric(list_t*, int);
int _knocon_ric(list_t*, int);

int main(){

    return 0;
}

int kcon(list_t *h, int k){
    int found;
    found = 0;
    if(h){
        for(; h->next && !found; h = h->next){
            if(h->next->num == k && h->num == k){
                found = 1;
            }
        }
        
    }else
        printf("Lista vuota\n");

    return found;
}

int knocon(list_t *h, int k){
    int occ, prec;
    
    for(occ = 0, prec = 0; h && occ < 2; h = h->next){
        if(!prec && h->num == k){
            occ++;
            prec = 1;
        }else
            prec = 0;
    }
    
    return occ >= 2;
}

int kcon_ric(list_t *h, int k){
    if(!h || !h->next)
        return 0;

    if(h->num == k && h->next->num == k)
        return 1;

    return kcon_ric(h->next, k);
}

int knocon_ric(list_t *h, int k){
    return _knocon_ric(h, k) >= 2;
}

int _knocon_ric(list_t *h, int k){
    /* restituisce numero di k non consecutivi */
    if(!h)
        return 0;
    
    if(h->num == k){
        if(h->next){
            return 1 + _knocon_ric(h->next->next, k);
        }else
            return 1;
    }
    
    return _knocon_ric(h->next, k);
}
