/*
Scrivere un programma in C che chiede all'utente una stringa di al
massimo 30 caratteri. Il programma individua la sequenza più lunga
di caratteri consecutivi tutti uguali e ne visualizza la lunghezza
ed il carattere che si ripete.
Nel caso ci siano più di una sequenza a pari lunghezza massima, il
programma visualizza i dati (dimensione e valore ripetuto)
dell'ultima sequenza individuata.
*/

#include <stdio.h>
#include <string.h>

#define MAX 30
#define SHIFT 1

int main(){
	int len, i, max, j;
	char str[MAX+1], ch;

	scanf("%s", str);
	len = strlen(str);

	for(i=0, j=1, max=0; i<len-SHIFT; i++){
		if(str[i] == str[i+SHIFT]){
			j++;
		}else{
			if(j=>max){
				max = j;
				ch = str[i];
			}
			j=0;
		}
	}

	printf("%d %c", max, ch);



	return 0;
}