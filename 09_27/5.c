/*
Scrivere un programma in C che acquisisce tre numeri in virgola
mobile e verifica se la terna può rappresentare le dimensioni dei
lati di un triangolo: devono essere valori positivi; inoltre la
somma di due numeri deve essere maggiore del terzo. Se il controllo
è stato superato con successo, il programma stabilisce che tipo di
triangolo è isoscele, equilatero o scaleno e stampa un apposito
messaggio a video. Altrimenti, il programma deve stampare un
apposito messaggio di errore.
*/

#include <stdio.h>

int main(){

	float a,b,c;

	scanf("%f %f %f", &a, &b, &c);

	if(a > 0 && b > 0 && c > 0){
		if(a+b>c || a+c>b || c+b>a){
			if(a==b && b==c){
				printf("Equilatero\n");
			}else if(a==b || b==c || a==c){	/*prima equilaterò senno equilateri vengono definiti isosceli*/
				printf("Isoscele\n");
			}else{
			printf("Scaleno\n");
			}
		}else{
			printf("Non è un triangolo\n");
		}
	}else{
		printc("Errore\n");
	}

	return 0;
}