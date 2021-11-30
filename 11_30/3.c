/*

Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale di interi mat, un intero val e qualsiasi parametro ritenuto strettamente necessario e trasmette al chiamate gli indici di riga e colonna che identificano la posizione del primo elemento (scandendo l’array per righe) che, sommato a tutti i suoi precedenti, dia come risultato un valore > val. Nel caso in cui tal elemento non esista, si trasmettono i valori -1, -1. Esiste unadirettiva#define NCOL 10.

*/

#define NCOL 10
#define ERR -1

void threeshold(int[][NCOL], int, int, int, int*, int*);

void threeshold(int mat[][NCOL], int col, int row, int val, int *i, int *j){
	int sum, li, lj;
	for(li=0, sum=0; li<row && sum <= val; li++){
		for(lj=0; lj<col && sum <= val; lj++){
			sum += mat[li][lj];
		}
	}
	if(sum > val){
		*i = li;
		*j = lj;
	}else{
		*i = *j = ERR;
	}
}