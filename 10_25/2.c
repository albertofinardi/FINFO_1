/*

Scrivere un sottoprogramma che riceve in ingresso due variabili
contenenti due numeri interi e ne scambia il contenuto, rendendo
effettiva la modifica anche nel chiamante. Scrivere un programma che
acquisisce due numeri interi e li scambia mediante il sottoprogramma
sopra definito.

*/

void swap(int*, int*);

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a,&b);

	printf("%d %d \n", a, b);
	return 0;
}

void swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}