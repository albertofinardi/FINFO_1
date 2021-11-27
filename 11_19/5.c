/*


Scrivere un sottoprogramma che riceve in ingresso una stringa e due
doppi puntatori a char. Il sottoprogramma divide la stringa in
esattamente due parti di lunghezza uguale (se il numero di caratteri
è dispari lascia il carattere in eccesso nella seconda sottostringa)
e le salva in due array allocati dinamicamente da restituire al
chiamante tramite i due parametri doppio puntatore a char. I due
array vanno allocati esattamente delle dimensioni strettamente
necessarie per contenere i dati. Infine nel caso di errore di
allocazione della memoria il sottoprogramma dovrà restituire due
NULL (deallocando l'eventuale memoria allocata correttamente).
Scrivere un programma che chiede all'utente una stringa di al
massimo 50 caratteri, invoca il sottoprogramma sopra definito
passandogli la stringa acquisita e visualizza il risultato. Il
sottoprogramma dealloca la memoria prima di terminare.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRDIM 50

void dividi_stringa(char[], char**, char**);

int main(){
	char str[STRDIM+1];
	char *s1, *s2;

	scanf("%s", str);
	dividi_stringa(str, &s1, &s2);
	
	printf("%s %s\n", s1, s2);
	
	free(s1);
	free(s2);
	return 0;
}

void dividi_stringa(char str[], char **s1, char **s2){
	int len, len1, len2, i, j;
	len = strlen(str);
	
	len1 = len/2;
	len2 = len - len1;

	*s1 = malloc((len1+1)*sizeof(char));

	if(*s1){
		*s2 = malloc((len2+1)*sizeof(char));
		if(*s2){
			
			for(i=0; i<len1; i++)
				(*s1)[i] = str[i];
			(*s1)[len1] = '\0';

			for( ; i<len; i++)
				(*s2)[i] = str[i];
			(*s2)[len2] = '\0';

		}else{
			printf("Errore allocazione memoria\n");
			free(*s1);
			*s1 = NULL;
		}
	}else{
		printf("Errore allocazione memoria\n");
		*s2 = NULL;
	}

}