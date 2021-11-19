/*
Scrivere un programma in C che acquisisce una stringa s1 di massimo
50 caratteri e ne costruisce una nuova s2 copiando il contenuto di
s1 senza le vocali. Infine il programma visualizza s2. Esempio:
s1="straniero" -> s2="strnr".
*/

#include <stdio.h>
#define DIM 50

int main(){
	char s1[DIM+1], s2[DIM+1];
	int i, j;

	scanf("%s", s1);

	for(i=0, j=0; s1[i]!='\0'; i++){
		if(!(s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='o' || s1[i]=='u')){
			s2[j] = s1[i];
			j++;
		}
		
	}
	s2[j]='\0';

	printf("%s\n", s2);

	return 0;

}