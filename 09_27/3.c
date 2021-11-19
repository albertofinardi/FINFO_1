/*


Scrivere un programma in C che realizza le funzionalità base di una
calcolatrice. Il programma chiede all'utente due numeri in virgola
mobile ed un carattere che rappresenta l'operazione che si vuole
eseguire (+ - * /). Il programma esegue l'operazione richiesta e
visualizza il risultato. Nel caso l'utente inserisce un carattere
che non rappresenta alcuna operazione ammissibile, il programma
visualizza un messaggio di errore.

*/

#include <stdio.h>

int main(){

	float a,b, ris;
	char operazione;
	int err;

	scanf("%f %f %c", &a, &b, &operazione);

/*
	if(operazione == '+'){
		ris = a+b;
		printf("%f", ris);
	}else if(operazione == '-'){
		ris = a-b;
		printf("%f", ris);
	}else if(operazione == '*'){
		ris = a*b;
		printf("%f", ris);
	}else if(operazione == '/'){
		ris = a/b;
		printf("%f", ris);
	}else
		printf("Errore");
		*/

/*Non usare switch*/

	err = 0;
	switch(operazione){
		case '+':
			ris = a+b;
			break;
		case '-':
			ris = a-b;
			break;
		case '*':
			ris = a*b;
			break;
		case '/':
			ris = a/b;
			break;
		default:
			err = 1;
	}

	if(!err){
		printf("= %d", ris);
	}else{
		printf("Errore")
	}

	printf("\n");

	return 0;
}