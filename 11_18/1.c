/*
Scrivere un programma che esegue due volte le seguenti elaborazioni.
Il programma chiede all'utente il numero di valori interi da
acquisire. Il programma alloca dinamicamente un array della
dimensione specificata e lo popola con i valori acquisiti da
tastiera. In seguito il programma visualizza la sequenza di valori
acquisiti al rovescio e libera la memoria allocata dinamicamente.
Visualizzare un errore nel caso si verifichi un errore di
allocazione della memoria.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int dim, i, *p;

	scanf("%d", &dim);
	p = malloc(dim*sizeof(int)); /*tipo restituito da malloc è void* (non definito) -> durante l'assegnamento viene eseguito cast*/

	if(p){
		for(i=0; i<dim; i++){
			scanf("%d", p+i); /*oppure &p[i]*/
		}
		for(i=dim-1; i>=0; i--){
			printf("%d\n", *(p+i)); /*oppure p[i]*/
		}

		free(p); /* p punta ad una cella random ora */
	}else
		printf("Errore allocazione\n");

	return 0;
}