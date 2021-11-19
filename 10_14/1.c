/*
Scrivere un programma in C che acquisisce una stringa di al massimo
30 caratteri ed un numero n. Il programma estrae il suffisso della
stringa di lunghezza n salvandolo in un nuovo array e visualizza il
risultato. Se n è maggiore della lunghezza della stringa, il
suffisso sarà rappresentato dalla stringa stessa.
*/

#include <stdio.h>
#include <string.h>

#define DIM 30

int main(){
	char s[DIM+1], s2[DIM+1];
	int n, len, i;

	scanf("%s", s);
	scanf("%d", &n);

	len = strlen(s);

	if(n>s){
		for(i=0; i<len; i++)
			printf("%c", s[i]);
	}else{
		for(i=len-1-n; i<len; i++){
			s2[i] = s[i];
		}
		s2[len] = '\0';
		len = strlen(s2);
		for(i=0; i<len; i++)
			printf("%c", s2[i]);
	}

	printf("\n");

	return 0;
}