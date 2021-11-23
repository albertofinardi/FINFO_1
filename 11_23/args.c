#include <stdio.h>
#include <stdlib.h>

/*
int main(int argc, char *argv[]){
	 //argc = numero argomenti (compreso nome eseguibile)
	 //argv[] = argomenti (compreso nome eseguibile, argv[0] == ./eseguibile) 
	
	int i;
	for(i=0; i<argc; i++)
		printf("%s\n", argv[i]);

	 //utilizzare specificando argomenti dopo nome eseguibile 
	 //argomenti sono sempre delle stringhe, se utilizzi numeri vanno convertiti

	return 0;
}
*/

/* programma che riceve due numeri interi dariga di comando e visualizza risultato */
int main(int argc, char *argv[]){
	int n1, n2;

	if(argc == 3) /*due numeri + eseguibile*/
	{
		n1 = atoi(argv[1]); /* atoi converte stringhe di soli numeri in numeri -> importare stdlib.h*/
		n2 = atoi(argv[2]);
		printf("%d + %d = %d\n", n1, n2, n1+n2);
	}else
		printf("Argomenti errati\n");
}