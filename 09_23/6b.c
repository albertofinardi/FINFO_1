/* 
Calcola lettera successiva 
(considera che con Z devi tornare indietro)
*/

#include <stdio.h>
#define PASSO 1	/* Semanticamente passo > 25 non ha senso (26 lettere) */

int main(){
	char c_in, c_out;

	scanf("%c", &c_in);

	/*Nuova codifica per partire da 0 (0-25 + passo, lo moduli per 26 e aggiungi a per tornare a range giusto)*/
	c_out = (c_in - 'a' + PASSO) % ('z' - 'a' + 1) + 'a';

	printf("%c\n", c_out);

	return 0;
}

/* Funziona solo con passo positivo */