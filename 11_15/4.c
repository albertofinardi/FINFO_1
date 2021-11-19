/*
Scrivere un programma apre in lettura un file di testo il cui nome,
di al massimo 30 caratteri è chiesto all'utente. Il programma legge
la sequenza di valori interi salvati nel file (la cui lunghezza non
è nota a priori) e la visualizza.
*/


/*spazio finale post ultimo numero è essenziale -> senza l'ultimo numero non viene visualizzato perchè feof = 1*/
/*si può omettere solo se si utilizza la seconda versione di while*/


/*SCANF -> scarto tutti gli spazi, leggo la prima informazione valida, mi fermo al primo spazio */

#include <stdio.h>
#define STRLEN 30

int main(){
	FILE *fp;
	char fn[STRLEN+1];
	int curr;

	scanf("%s", fn);
	fp = fopen(fn, "r");

	if(fp){
		/*
		//LA SECONDA VERSIONE VA BENE SOLAMENTE SE INT
		fscanf(fp, "%d", &curr);

		while(!feof(fp)){
			printf("%d", curr);
			fscanf(fp, "%d", &curr);
		}*/

		while(fscanf(fd, "%d", &curr)>0){	/*non != 0 perchè eof = -1 -> restituisce numero input validi*/
			printf("%d ", curr);
		}


		printf("\n");
		fclose(fp);
	}else
		printf("Errore apertura file\n");


	return 0;
}