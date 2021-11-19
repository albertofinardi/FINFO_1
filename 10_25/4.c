/*
Scrivere un sottoprogramma che calcola l'area e il perimetro di un
cerchio di un dato raggio. Il sottoprogramma riceve come parametri
un numero in virgola mobile che rappresenta il raggio del cerchio e
altri due parametri, sempre in virgola mobile, in cui verranno
salvati i due risultati richiesti.
Scrivere un programma che chiede all'utente la lunghezza del raggio
del cerchio, calcola mediante la funzione sopra e visualizza il
perimetro e l'area del cerchio. In seguito il programma chiede
all'utente se vuoi continuare o meno (0 per continuare, qualsiasi
altro valore per terminare).
*/

#include <stdio.h>
#define PI 3.14

void areaperimetro(float, float*, float*);

int main(){
	float r, area, per;

	scanf("%f", &r);

	areaperimetro(r, &area, &per);

	printf("%lf %lf\n", area, per);
}

void areaperimetro(float r, float *area, float *perimetro){
	*area = PI*r*r;
	*perimetro = 2*PI*r;
}