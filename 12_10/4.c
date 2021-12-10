/*

Una stringa costituisce un pangramma se ogni lettera dell’alfabeto compare almeno una volta. Si scriva un sottoprogramma che ricevuta in ingresso una stringa restituisce 1 se la stringa è un pangramma, 0 altrimenti. La stringa può contenere caratteri maiuscoli, minuscoli e spazi; non importa se il carattere compare come maiuscola o minuscola. Si considerino stringhe di senso compiuto in inglese, in modo tale da non aver il problema delle lettere j, k, w, x, e y, che quindi devono comparire anch’esse.
Esempio:
Ingresso: A quick brown fox jumps over the lazy dog Valore restituito: 1
Ingresso: There is no easy way out of a problem Valore restituito: 0

*/

int pangramma(char[]);

int main(){
	return 0;
}

int pangramma(char str[]){
	int i, n, presente, pangr;
	char lettera_no_offset;
	
	for(n=0, pangr = 1; n <= 'z' - 'a' && pangr; n++){
		lettera_no_offset = (char)(n);
		for(i=0, presente = 0; str[i] != '\0' && !presente; i++){
			if(str[i] == lettera_no_offset + 'a' || str[i] ==lettera_no_offset + 'A'){
				presente = 1;
			}
		}
		if(!presente){
			pangr = 0;
		}
	}

	return pangr;
}