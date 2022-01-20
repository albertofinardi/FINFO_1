/*
Un dato sistema informatico richiede che ciascun username sia una stringa composta da almeno N caratteri, di cui almeno NL lettere dell’alfabeto maiuscolo o minuscolo e non contenga alcun carattere speciale appartenente ad una stringa di controllo SYMB (per esempio "%:;-+"). Scrivere un sottoprogramma che riceve come parametri una stringa rappresentante un username, gli interi N ed NL e la stringa SYMB; il sottoprogramma restituisce 1 se la stringa rappresenta un username valida, altrimenti 0.
Esempio: con N=8, NL=5 e SYMB="%:;-+", "Domani.898" è un username valida, mentre "domani:898" e "do.898" non lo sono.

*/
int check_username(char[], int, int, char[]);

int check_username(char username[], int N, int NL, char SYMB[]){
	int i, j, lettere, symb;

	for(i=0, symb=0, lettere=0; username[i] != '\0' && !symb; i++){
		if((username[i] >= 'a' && username[i] <= 'z') || (username[i] >= 'A' && username[i] <= 'Z')){
			lettere++;
		}else{
			for(j=0; SYMB[j] != '\0' && !symb; j++){
				if(SYMB[j] == username[i])
					symb = 1;
			}
		}
	}

	return (!symb && i >= N && lettere >= NL);
}