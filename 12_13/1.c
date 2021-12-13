/*

Scrivere un programma per il calcolo di statistiche sui caratteri presenti in un file di testo il cui nome è specificato come argomento da riga di comando. 
Il programma considera tutti i caratteri ad eccezione degli spazi e fornisce in uscita le seguenti statistiche:
- il numero di righe presenti nel file (ogni riga è al più di 100 caratteri) 
- il numero totale di caratteri (esclusi quelli di spaziatura)
- il numero massimo e medio di caratteri di riga
- la riga più lunga presente nel file
Dato il file con il seguente testo:
Prova di contenuto di file
per avere un esempio.
Non e' importante quello che c'e' scritto
presente.
il programma visualizza:
4
84
35 21
Non e' importante quello che c'e' scritto


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void stats(char[]);

int main(int argc, char *argv[]){
	if(argc == 2){
		stats(argv[1]);
	}else
		printf("Errore argomenti\n");
	return 0;
}

void stats(char str[]){
	FILE *fp;
	int righe, tot, max, mean, max_tmp;
	char maxstr[MAX+1], tmp[MAX+1];

	int i;
	
	fp = fopen(str, "r");
	
	if(fp){
		righe = tot = max = max_tmp = mean = 0;
		
		fgets(tmp, MAX+1, fp);
		while(!feof(fp)){
			
			righe++;

			for(i=0, max_tmp = 0; tmp[i] != '\0' && tmp[i] != '\n'; i++){
				if(tmp[i] != ' '){
					tot++;
					max_tmp++;
				}

			}

			if(max_tmp > max){
				max = max_tmp;
				strcpy(maxstr, tmp);
			}


			fgets(tmp, MAX+1, fp);
		}

		if(righe != 0){
			mean = tot/righe;
			printf("%d\n%d\n%d %d\n%s\n", righe, tot, max, mean, maxstr);
		}else
			printf("File vuoto\n");

		fclose(fp);
		
	}else
		printf("Errore apertura file\n");
}