/*
Scrivere un sottoprogramma che riceve in ingresso un array di valori interi v e qualsiasi altro parametro ritenuto necessario, ed altri due valori interi da e a. Il sottoprogramma verifica se nell’array sono presenti tutti e soli i valori inclusi nell’intervallo [da,a], senza ripetizioni. In caso positivo il sottoprogramma restituisce 1, 0 in caso contrario.
*/

int intervallo(int v[], int dim, int da, int a){
	int i, j, valid, conto;
	for(i=da, valid = 1; i<= a && valid; i++){
		for(j=0, conto=0; j<dim && conto <= 1; j++){
			if(v[j] == i)
				conto++;
		}
		if(conto != 1)
			valid = 0;
	}

	return valid;
}