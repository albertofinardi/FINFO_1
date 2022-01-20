/*
Scrivere un programma che riceve come argomento da riga di comando il nome di un file di testo contenente una sequenza di lunghezza indefinita (0 o più) di numeri interi. Il programma visualizza tutti i soli numeri presenti una sola volta nella sequenza. Gestire opportunamente gli eventuali casi di errore relativi all’accesso al file o alla mancanza degli argomenti richiesti visualizzando appositi messaggi a video.
Esempio: se il file contiene il testo: 0 1 2 3 5 4 3 2 5 7 5 4 2 6 7 8 4 4 il programma visualizza 0 1 6 8.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]){
	FILE *fp;
	int n;
	nodo_t *h, *tmp, *prec;

	h = tmp = prec = NULL;

	if(argc == 2){
		fp = fopen(argv[1], "r");
		if(fp){
			fscanf(fp, "%d", &n);
			while(!feof(fp)){
				h = inserisciInCoda(h, n);
				fscanf(fp, "%d", &n);
			}


			for(tmp=h; tmp && tmp->next; tmp = tmp->next){
				if(!esisteElemento(tmp->next, tmp->num) && !esisteElemento(prec, tmp->num))
					printf("%d ", tmp->num);
				
				prec = inserisciInCoda(prec, tmp->num);
			}

			fclose(fp);
			free(tmp);
			free(h);
			free(prec);
			printf("\n");

		}else
			printf("Errore apertura file\n");

	}else
		printf("Errore argomenti\n");
	return 0;
}