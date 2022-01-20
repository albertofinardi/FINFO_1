/*
Realizzare un sottoprogramma che riceve in ingresso un array bidimensionale di interi m, le sue dimensioni ed un valore dim. Il sottoprogramma conta e restituisce il numero di sottomatrici quadrate di dimensione dim contenenti soltanto il valore 0. Si noti che le sottomatrici possono anche essere sovrapposte tra di loro. Nel contesto di utilizzo del sottoprogramma, sono presenti le seguenti direttive/istruzioni riportate di seguito.
*/
#define VALORE 0

int sottomatrici(int m[][NC], int row, int col, int dim);

int sottomatrici(int m[][NC], int row, int col, int dim){
	int i, j, a, b, exit, n;
	for(i=0, n=0; i<row-dim; i++){
		for(j=0; j<col-dim; j++){
			/* elemento della matrice */
			for(a = 0, exit = 0; a<dim && !exit; a++){
				for(b = 0; b<dim && !exit; b++){
					if(m[i+a][j+b] != VALORE)
						exit = 1;
					}
			}
			if(!exit){
				n++;
			}
		}
	}
	return n;
}