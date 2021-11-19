/*Scrivere un programma in C che acquisisce un numero maggiore di 1;
nel caso il valore inserito sia sbagliato, il programma stampa un
apposito messaggio di errore e richiede l'inserimento di un nuovo
valore. Il programma stabilisce se il numero è primo o meno e
visualizza un apposito messaggio con il risultato (1:"primo" o
0:"non primo").*/


#include <stdio.h>

int main(){

	int n, primo, i;

	scanf("%d", &n);

	/*Numero primo = maggiore di 1*/
	while(n < 2){
		printf("Non valido\n");
		scanf("%d", &n);
	}

	/*Numero primo = non divisibile per nessun numero tranne 1 e se stesso*/
	i = 2;
	primo = 1; /*1 = true*/
	while(i*i<=n && primo){		/* i<radice(n) -> ottimizzi; primo -> se trovi divisore esci (flag);*/
		primo = (n%i == 0); 	/*PUOI FARLO PERCHE' C'E' FLAG, SENNO' CON IF --- (n%i == 0) = !(n%i), quindi (n%i != 0) = n%i*/
		/*if(!(n%i))
			primo = 0;*/
		i++;
	}

	printf("%d\n", primo);


	return 0;
}