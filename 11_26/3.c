/*
Scrivere un sottoprogramma che riceve in ingresso un array di valori interi v e qualsiasi altro parametro ritenuto necessario, ed altri due valori interi da e a. Il sottoprogramma verifica se nell’array sono presenti tutti e soli i valori inclusi nell’intervallo [da,a], senza ripetizioni. In caso positivo il sottoprogramma restituisce 1, 0 in caso contrario.
*/

int intervallo(int v[], int dim, int da, int a){
	int i, valid;
	for(i=0, valid = 1; i<dim && valid; i++){
		if(!(v[1] >= da && v[i] <= a))
			valid = 0;
	}

	return valid;
}