#include <stdio.h>

int main(){
	int a, b, *c, *d, *e;
	a = 2;
	b = 3;

	c = &a;
	b = *c + 4; /* quindi a + 4 -> 2 + 4 */
	d = c; /* quindi copi indirizzo di c in d, quindi d punta a c che punta ad a, quindi d punta ad a */
	*d = 7; /* a = 7 */
	/* 	b = c;  copi indirizzo di c in b -> NON HA SENSO anche per overflow (b 32 bit, c 64) 
		c = a;  NO -> causa crash a riga successiva */
	*c = 5; /* a = 7 */

	/* *e = b;  e non e' inizializzato -> quindi segmentation fault */

	e = &b; /* e punta a b */
	*e = *c; /* copi valore di a (diventato 5) e lo metti in b */

	*d = *c /* riscrivi in a in valore di a */

	scanf("%d", e); /*corretta, e e' un puntatore -> funziona solo se e già inizializzato -> == scanf("%d", &b);*/

	e = NULL; /* e non punta più a nulla */
	if( e!=NULL) /* dato che NULL = puntare a 0 -> == if(e)
		printf("%d", *e); /* funziona (se e punta a variabile), ma non viene eseguito per condizione if */



	return 0;
}