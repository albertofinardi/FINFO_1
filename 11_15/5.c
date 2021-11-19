/*
Scrivere un programma in C che chiede all'utente un valore intero e
lo stampa a video. Si utilizzino i sottoprogrammi fprintf e fscanf
sugli stream stdin e stdout.
*/

#include <stdio.h>

int main(){
	int i;

	fscanf(stdin, "%d", &i);

	fprintf(stdout, "%d\n", i);

	/*
	
	Sono la stessa cosa, scanf e printf invocano fscanf e fprintf con stdin e stdout

	Stdin e stdout sono i buffer

	Per scrivere errori si usa stderr (se vuoi approfondisci)

	scanf("%d", &i);
	printf("%d\n", i);
	
	*/ 

	return 0;
}


/*
Nel terminal "./5 < prova.txt" significa che lo fscanf prende input da quel file al posto che tastiera -> dice al sistema operativo di utilizzare file al posto che tastiera
Se usi "./5 > prova2.txt" fprintf reindirizza -> in questo caso prova2.txt al posto del terminal

Non funziona se utilizzi stderr


I comandi di prima (< e >) funzionano anche con scanf e printf classici
*/