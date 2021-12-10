/*


Scrivere un sottoprogramma che riceve come parametri due interi n e
b, con b sicuramente compreso tra 1 e 9 estremi inclusi. Il
sottoprogramma visualizza tutti i numeri, in ordine crescente, che
possono essere generati in base b su n cifre.
Per esempio se il sottoprogramma riceve in ingresso i valori n=3 e
b=2, stampa a video "000, 001, 010, 011, 100, 101, 110, 111".
Scrivere un programma che chiede all'utente due valori interi n e b
ed invoca il sottoprogramma sopra definito.
NOTA: nel caso si realizzi un sottoprogramma ricorsivo è possibile
passare anche ulteriori parametri ritenuti necessari.


*/

void _conta_ric(int, int, int, int[]);
void conta_ric(int, int);


void conta_ric(int n, int b){
	int *m;
	m = malloc(sizeof(int) * n);
	if(m){
		_conta_ric(n, b, 0, m);
		free(m);
	}else{
		printf("Errore allocazione\n");
	}
}

void _conta_ric(int n, int b, int pos, int m[]){
	int i;
	
	if(pos == n){
		for(i = 0; i<n; i++)
			printf("%d ", m[i]);
	}

	else {
		for(i=0; i<b; i++){
			m[pos] = i;
			_conta_ric(n, b, pos+1, m);
		}
	}

}