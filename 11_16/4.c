/*


a) Scrivere una funzione analizzastringa (ed il relativo prototipo)
che riceve come parametro una stringa. La funzione restituisce 1 se
la stringa è lunga più di 5 caratteri e contiene almeno 2 cifre
numeriche ed un carattere che non sia una cifra; in caso negativo la
funzione restituisce 0.
b) Scrivere un programma che apre in lettura un file di testo
testo.txt contenente una serie di lunghezza indefinita di parole
ciascuna lunga al massimo 15 caratteri ed in scrittura un secondo
file risultato.txt. Il programma legge ciascuna parola contenuta in
testo.txt e la scrive in risultato.txt soltanto se l'invocazione
della funzione analizzastringa su di essa porta ad un risultato
positivo (la funzione restituisce 1).
Ad esempio, se il file contiene il seguente testo:
Ciao45 baubau 2345678 esame2020 trallallero1 bimbumbam345 a234
Il programma salverà in risultato.txt il seguente testo:
Ciao45
esame2020
bimbumbam345
 

 */

#include <stdio.h>
#define FN_IN "testo.txt"
#define FN_OUT "risultato.txt"
#define STRDIM 15

int analizzastringa(char[]);

int main(){
	FILE *fp_in, *fp_out;
	char str[STRDIM+1];

	fp_in = fopen(FN_IN, "r");

	if(fp_in){
		fp_out = fopen(FN_OUT, "w");
		if(fp_out){
			fscanf(fp_in, "%s", str);
			while(!feof(fp_in)){
				if(analizzastringa(str)){
					fprintf(fp_out, "%s\n", str);
				}
				fscanf(fp_in, "%s", str);
			}
			fclose(fp_out);
		}else
			printf("Errore apertura %s\n", FN_OUT);
		fclose(fp_in);
	}else
		printf("Errore apertura %s\n", FN_IN);

	return 0;
}

int analizzastringa(char str[]){
	int cifre, i;

	for(i=0, cifre=0; str[i] != '\0'; i++){
		if(str[i] >= '0' && str[i] <= '9')
			cifre++;
	}

	return i > 5 && cifre >= 2 && i > c;
}