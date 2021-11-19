/*
Il cifrario di Cesare è uno dei più antichi algoritmi crittografici
di cui si abbia traccia storica. È un cifrario a sostituzione
monoalfabetica in cui ogni lettera del testo in chiaro è sostituita
nel testo cifrato dalla lettera che si trova un certo numero di
posizioni dopo nell'alfabeto. Cesare utilizzava uno spostamento di 3
posizioni:
Cifratura: A->D, B->E, ..., X->A, Y->B, Z->C
Decifratura: D->A, E->B, ...,
Scrivere un sottoprogramma cifra() che riceve come parametro un
carattere minuscolo dell'alfabeto inglese e restituisce il carattere
minuscolo cifrato. Scrivere un sottoprogramma decifra() che riceve
come parametro un carattere minuscolo dell'alfabeto inglese già
cifrato e restituisce il corrispondente carattere minuscolo non
cifrato.
Scrivere un sottoprogramma verificalettera() che riceve come
parametro un carattere e restituisce 1 se tale carattere è una
lettera dell'alfabeto minuscolo, altrimenti 0.
Scrivere un programma che acquisisce una stringa di testo di al
massimo 20 caratteri, che si assume contenga soltanto lettere
minuscole dell'alfabeto, cifre ed altri segni di interpunzione e non
lettere maiuscole. Mediante l'ausilio dei sottoprogrammi sopra
definiti, il programma cifra il messaggio salvandolo in un secondo
array e lo stampa a video; in seguito, il programma decifra il
messaggio cifrato, lo stampa a video e verifica che effettivamente è
uguale al messaggio originale, visualizzando l'esito del confronto.
*/

#include <stdio.h>
#include <string.h>

#define MAXSTR 20
#define SHIFT 3

#define PRIMA_LETTERA 'a'
#define ULTIMA_LETTERA 'z'

char cifra(char);
char decifra(char);
int verificalettera(char);

int main(){
	int i, len;
	char str[MAXSTR+1];
	char cifrato[MAXSTR+1];
	char decifrato[MAXSTR+1];

	scanf("%s", str);

	len = strlen(str);

	for(i=0; i<len; i++){
		cifrato[i] = cifra(str[i]);
	}
	cifrato[i] = '\0';

	printf("%s\n", cifrato);

	for(i=0; i<len; i++){
		decifrato[i] = decifra(cifrato[i]);
	}
	decifrato[i] = '\0';

	printf("%s\n", decifrato); 

	if(!strcmp(str, decifrato))
		printf("Decifrato correttamente\n");
	else
		printf("Errore\n");

	return 0;
}

char cifra(char ch){
	char res;
	if(verificalettera(ch))
		res = (ch - PRIMA_LETTERA + SHIFT) % (ULTIMA_LETTERA - PRIMA_LETTERA + 1) + PRIMA_LETTERA;
	else
		res = ch;
	return res;
}

char decifra(char ch){
	char res;
	if(verificalettera(ch))
		res = (ch - PRIMA_LETTERA - SHIFT) % (ULTIMA_LETTERA - PRIMA_LETTERA + 1) + PRIMA_LETTERA;
	else
		res = ch;
	return res;
}

int verificalettera(char ch){
	return (ch >= PRIMA_LETTERA && ch <= ULTIMA_LETTERA);
}