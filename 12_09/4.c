/*

Sottoprogramma con parametri stringa e numero compreso tra 1 e 10 (compresi). Assumento che la stringa
sia composta da cifre (caratteri) compresi tra '0' e n-1 il sottoprogramma converte in intero base 10 il valore rappresentato 
dalla stringa in base n e restituisce risultato. Se stringa contiene valore non ammissibile, restiuisce -1

str = '100', n = 2 -> 4
str = '110', n = 3 -> 12

*/
#include <stdio.h>

#define ERR -1
#define MIN 0
#define MAX 10

int stringToInt(char[], int);

int main(){
	/* ... */
	return 0;
}

int stringToInt(char str[], int base){
	int i, str_n, dim;
	int pot, res;
	for(i=0; str[i] != '\0'; i++){
		str_n = (int)(str[i] - '0');
		if(str_n < MIN || str_n > MAX)
			return ERR;
	}

	for(dim = i-1, pot = 1, res=0; dim>=0; dim--){
		str_n = (int)(str[dim] - '0');
		
		res += str_n * pot;
		
		pot *= base;
	}

	return res;
}