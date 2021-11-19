/*
Un dato sistema informatico richiede che ciascun username sia una
stringa composta da almeno N caratteri, di cui almeno NL lettere
dell'alfabeto maiuscolo o minuscolo e non contenga alcun carattere
speciale appartenente ad una stringa di controllo SYMB (per esempio
"%:;-+").
Scrivere un sottoprogramma che riceve come parametri una stringa
rappresentante un username, gli interi N ed NL e la stringa SYMB; il
sottoprogramma restituisce 1 se la stringa rappresenta un username
valida, altrimenti 0.
Esempio: con N=8, NL=5 e SYMB="%:;-+", "Domani.898" è un username
valida, mentre "domani:898" e "do.898" non lo sono.
Scrivere un programma che chiede all'utente una stringa di al
massimo 20 caratteri ed invoca il sottoprogramma sopra definito
specificando i seguenti valori per i parametri: N=8, NL=5 e
SYMB="%:;-+". Il sottoprogramma visualizza il risultato restituito
dal sottoprogramma.

*/

#include <stdio.h>
#include <string.h>
#define MAX 20


#define N 8
#define NL 5
#define SYMB "%:;-+"


int username(char[], int, int, char[]);

int main(){
	char user[MAX+1];
	int valido;

	scanf("%s", user);

	valido = username(user, N, NL, SYMB);

	printf("%d\n", valido);

	return 0;

}


int username(char user[], int N, int NL, char SYMB[]){
	int i, j, dim, sum_nl, symb, ret;
	char current;
	
	dim = strlen(user);

	if(dim>=N){
		for(i=0, symb=0, ret=1, sum_nl = 0; i<dim && !symb; i++){
			current = user[i];
			if((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z'))
				sum_nl++;
			for(j=0; SYMB[j] != '\0' && !symb; j++){
				if(current == SYMB[j])
					symb = 1;
			}

		}
		if(!(sum_nl >= NL) || symb)
			ret = 0;
	}else{
		ret = 0;
	}

	return ret;
}