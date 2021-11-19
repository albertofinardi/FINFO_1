/*
Scrivere un programma in C che chiede all'utente di inserire una
stringa di massimo 100 caratteri. Il programma deve cercare tutte le
sottostringhe  contenute all'interno della stringa e stampa il loro numero.
*/

#include <stdio.h>
#include <string.h>
#define DIM 100

int main(){

	int i, j, dim_str, dim_t, conto;
	char str[DIM+1], t[DIM+1];

	scanf("%[^\n]", str);
	scanf("%[^\n]", t);

	dim_str = strlen(str);
	dim_t = strlen(t);

	for(i=0, conto=0; i <= dim_str - dim_t; i++){
		for(j=0; j<dim_t && str[i+j]==t[j]; j++);
		
		if(j==dim_t)
			conto++;
	}

	printf("%d", conto)

	return 0;
}