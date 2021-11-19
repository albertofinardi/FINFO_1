/*
Il metodo di Euclide per il calcolo del MCD tra due numeri m e n
dice che
MCD(m,n)=m se m=n
MCD(m,n)=MCD(m-n,n) se m>n
MCD(m,n)=MCD(m,n-m) se m<n
Scrivere un sottoprogramma ricorsivo che calcola e restituisce il
MCD di due numeri interi positivi ricevuti come parametro mediante
il metodo di Euclide.
Scrivere un programma che chiede due valori interi positivi (che si
assume vengano inseriti correttamente), ne calcola il MCD mediate il
sottoprogramma sopra realizzato e visualizza il risultato.
*/

#include <stdio.h>

int mcd(int, int);

int main(){
	int m,n, mcdRis;

	scanf("%d %d", &m , &n);
	mcdRis = mcd(m, n);

	printf("%d\n", mcdRis);

	return 0;
}

int mcd(int m, int n){
	if(n==m)
		return m;
	if(m>n)
		return mcd(m-n, n);
	if(m<n)
		return mcd(m, n-m);
}