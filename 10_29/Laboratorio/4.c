/*
ES4 - Scrivere un programma che chiede all'utente la dimensione m di due matrici quadrate di interi A e B (un valore intero compreso tra 1 e 10 e nel caso non sia valido va richiesto) e poi i dati per popolare le due matrici.

Per ogni valore n compreso tra 2 e m (estremi inclusi), il programma calcola e stampa le coordinate (i,j) dell'angolo in alto a sinistra di tutte le sottomatrici quadrate nxn di A e B che soddisfano entrambe le seguenti condizioni:
- hanno la stessa posizione (i,j) in entrambe le matrici A e B
- la sottomatrice definita su A e la sottomatrice definita su B sono
uguali (contengono gli
Esempio:
Date le matrici
stessi elementi, posizione per posizione)
A: 53718 39271 39756 45713 86299
B: 03701 09270 39751 45710 10091
L'output del programma sarà
N=2
(0, 1) (1, 1) (1, 2) (2, 0) (2, 1) (2, 2)
N=3 (1, 1)
N=4
Nessuna sottomatrice soddisfa le condizioni
N=5
Nessuna sottomatrice soddisfa le condizioni
*/

#include <stdio.h>

#define MIN 1
#define MAX 10

int main(){
	int A[MAX][MAX], B[MAX][MAX];
	int m, i, j, n, x, y, eq, sol;

	do{
		scanf("%d", &m);
	}while(m < MIN || m > MAX);

	for(i=0; i<m; i++)
		for(j=0; j<m; j++)
			scanf("%d", &A[i][j]);

	for(i=0; i<m; i++)
		for(j=0; j<m; j++)
			scanf("%d", &B[i][j]);

	do{
		scanf("%d", &n);
	}while(n < 2 || n > MAX);

	for(i=0, sol=0; i<m-n; i++)
		for(j=0; j<m-n; j++){
			for(x=0, eq=1; x<n && eq; x++)
				for(y=0; y<n && eq; y++)
					if(A[i+x][j+y] != B[i+x][j+y])
						eq = 0;
					else
						sol++;
			if(eq){
				printf("(%d, %d) ", i, j);
			}
		}
	if(!sol)
		printf("Nessuna soluzione");
	printf("\n");
					
		

	return 0;
}