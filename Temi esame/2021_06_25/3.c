#include <string.h>
#define MAX_NOME 100
#define MAX_STR 50
#define MAX_NOME_STR 100
#define MAX_DESC_STR 1000

typedef struct {
	char nome[MAX_NOME_STR+1], desc[MAX_DESC_STR+1];
} strumento_t;

typedef struct {
	int id, max_persone, n_str;
	strumento_t strumenti[MAX_STR];
	char nome[MAX_NOME+1];
} lab_t;

int lab_str(lab_t lab[], int dim, char n[], char s[]){
	int i, j, n, exit;
	for(i=0, n=0; i<dim; i++)
		if(!strcmp(lab[i].nome, n))
			for(j=0, exit = 0; j<lab[i].n_str && !exit; j++)
				if(!strcmp(lab[i].strumenti[j].nome, s)){
					exit = 1;
					n++;
				}


	return n;
}