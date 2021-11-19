/*
Scrivere un programma in C che acquisisce una stringa s1 di massimo
50 caratteri e ne costruisce una nuova s2 copiando il contenuto di
s1 e sostituendo le vocali con il carattere *. Infine il programma
visualizza s2. Esempio: s1="straniero" -> s2="str*n**r*".
*/

#include <stdio.h>
#define DIM 50

int main(){

	char s1[DIM+1], s2[DIM+1];
	int i;

	scanf("%s", s1);

	for(i=0; s1[i]!='\0'; i++){
		if(s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='o' || s1[i]=='u')
			s2[i] = '*';
		else
			s2[i] = s1[i];
	}
	s2[i] = '\0';

	printf("%s", s2);

	return 0;
}