/*

Scrivere un sottoprogramma minmaxstr che riceve in ingresso una stringa e trasmette al chiamante due caratteri,il minimo e il massimo nell’ordinamento alfabetico tra quelli contenuti nella stringa. Per esempio, se la stringa in ingresso è “esempio”, il minimo ed il massimo sono rispettivamente e ed s. La stringa contenga tutti e soli caratteri alfabetici minuscoli.
Rivedere il sottoprogramma minmaxstr in modo tale che i caratteri possano essere sia maiuscoli, sia minuscoli, e facendo in modo che il sottoprogramma trasmetta comunque quelli minuscoli. In tal caso, se la stringa in ingresso è “Architetto”, il minimo ed il massimo sono rispettivamente a ed t.
Scrivere un programma che acquisisce da riga di comando una stringa e chiama il sottoprogramma minmaxstr. 
*/

void minmaxstr(char str[], char *min, char *max){
	int i;
	char c;
	if(str[0] != '\0'){
		c = converti(str[0]);
		for(i=1, *min = c, *max = c; str[i] != '\0'; i++){
			c = converti(str[i]);
			if(c < *min)
				*min = c;
			if(c > *max)
				*max = c;
		}
	}
	else
		printf("Stringa vuota\n");
}

char converti(char c){
	if(c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	return c;
}