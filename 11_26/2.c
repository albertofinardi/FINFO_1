/*
In un array bidimensionale di valori interi, si definisce dominante ogni elemento dell’array che è strettamente maggiore di tutti gli elementi dell’array bidimensionale che si trova in basso a destra rispetto all’elemento stesso (si veda la figura), non considerando però tutti gli elementi presenti nell’ul- tima colonna e nell’ultima riga. Si realizzi un sottoprogramma che ricevuto in ingresso un array bidimensionale e qualsiasi altro parametro ritenuto strettamente necessario calcoli e restituisca al chiamante il numero di elementi dominanti presenti. Nel contesto di utilizzo del sottoprogramma, sono presenti le seguenti direttive/istruzioni riportate di seguito.
*/

int dominanti(int m[][NC], int col, int row){
	int i, j, a, b;
	int n_dominanti, dominante;
	for(i=0, n_dominanti=0; i<row; i++){
		for(j=0; j<col; j++){
			/* scorro elemento per elemento della matrice */
			for(a=i+1, dominante = 1; a<row && dominante; a++){
				for(b = j+1; j<col && dominante; j++){
					/* scorro sottomatrice in basso a destra */
					if(m[a][b] > m[i][j])
						/* se trovo elemento maggiore del dominante di riferimento, allora il dominante non è dominante */
						dominante = 0;
				}
			}
			if(dominante)
				/* se non ho trovato nessun numero maggiore del dominante, allora è davvero dominante */
				n_dominanti++;
		}
	}
	return n_dominanti;
}