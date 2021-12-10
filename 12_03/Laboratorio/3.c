/*
Definire un tipo di dato per una lista dinamica di parole, dove ciascuna parola è lunga al massimo 20 caratteri. Realizzare i sottoprogrammi standard per la gestione di una lista di parole, in particolare per l'inserimento in coda di un nuovo elemento, la visualizzazione del contenuto della lista, il calcolo della lunghezza della lista e la sua distruzione.
Scrivere un programma che riceve come argomenti i nomi di due file di testo, ciascuno contenente una sequenza di lunghezza indefinita di parole di al massimo 20 caratteri. Il programma carica le due sequenze in due liste dinamiche s1 e s2. In seguito, il sottoprogramma verifica se s1 è sottosequenza di s2 o, viceversa se s2 è sottosequenza di s1, e stampa a video i risultati dei test (1 o 0); si noti che se almeno una delle due liste è vuota l'esito è negativo. Prima di terminare il programma libera tutta la memoria allocata. Visualizzare opportuni messaggi nel caso di errore (es: argomenti mancanti, memoria non allocata correttamente, file non aperto, ...). Si consiglia di suddividere opportunamente il programma in sottoprogrammi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRDIM 20

typedef struct nodo_ {
	char str[STRDIM+1];
	struct nodo_ *next;
} nodo_t;

nodo_t* inserisciInCoda(nodo_t*, char[]);
nodo_t* distruggi(nodo_t*);
void visualizza(nodo_t*);
int lunghezza(nodo_t*);
int sottosequenza(nodo_t*, nodo_t*);

int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	nodo_t *s1, *s2;
	char str[STRDIM+1];
	int sottoseq;

	s1 = s2 = NULL;

	if(argc == 3){
		fp1 = fopen(argv[1], "r");
		if(fp1){
			fp2 = fopen(argv[2], "r");
			if(fp2){
				fscanf(fp1, "%s", str);
				while(!feof(fp1)){
					s1 = inserisciInCoda(s1, str);
					fscanf(fp1, "%s", str);
				}
				fscanf(fp2, "%s", str);
				while(!feof(fp2)){
					s2 = inserisciInCoda(s2, str);
					fscanf(fp2, "%s", str);
				}

				sottoseq = sottosequenza(s1, s2);
				printf("Sottosequenze: %d\n", sottoseq);

				distruggi(s1);
				distruggi(s2);
				fclose(fp2);
			}else
				printf("Errore apertura file\n");
			fclose(fp1);
		}else
			printf("Errore apertura file\n");

	}else
		printf("Argomenti errati\n");

	return 0;
}

nodo_t* inserisciInCoda(nodo_t* lista, char str[]){
  nodo_t *prec;
  nodo_t *tmp;
  int i;
  tmp = malloc(sizeof(nodo_t));
  if(tmp != NULL){
    tmp->next = NULL;
    
    for(i=0; str[i] != '\0'; i++)
    	tmp->str[i] = str[i];
   
   if(lista == NULL)
      lista = tmp;
    else{
      for(prec=lista;prec->next!=NULL;prec=prec->next);
      prec->next = tmp;
    }
  } else
      printf("Memoria esaurita!\n");
  return lista;
}

void visualizza(nodo_t* lista){
  printf("Elementi nella lista: ");
  while(lista != NULL){
    printf("%s ", lista->str);
    lista = lista->next;
  }
  printf("\n");  
}

nodo_t* distruggi(nodo_t* lista){
  nodo_t* tmp;
  while(lista!= NULL){
    tmp = lista;
    lista = lista->next;
    free(tmp);
  }
  return NULL;
}

int lunghezza(nodo_t *lista){
  int i;
  for(i=0; lista; i++, lista = lista->next);
  return i;
}

int sottosequenza(nodo_t *s1, nodo_t *s2){
	int sottoseq;
	nodo_t *tmp, *tmp2;

	/* Da controllare, non funziona se viene modificato testo2.txt

	/*for(tmp = s1, tmp2 = s2, sottoseq = 0; tmp && strcmp(tmp->str,tmp2->str); tmp = tmp->next){}

	if(!strcmp(tmp->str,tmp2->str)){
		for(sottoseq = 1; tmp && tmp2 && sottoseq; tmp=tmp->next, tmp2 = tmp2->next){
			if(strcmp(tmp->str,tmp2->str)){
				sottoseq = 0;
			}
		}
	}

	if(!sottoseq){
		for(tmp = s2, tmp2 = s1, sottoseq = 0; tmp && strcmp(tmp->str,tmp2->str); tmp = tmp->next){}
		if(!strcmp(tmp->str,tmp2->str)){
			for(sottoseq = 1; tmp && tmp2 && sottoseq; tmp=tmp->next, tmp2 = tmp2->next){
				if(strcmp(tmp->str,tmp2->str)){
					sottoseq = 0;
				}
			}
		}
	}*/

	return sottoseq;
}