/*
ES5 - Si vuole realizzare un programma che permetta di effettuare alcune operazioni geometriche su rettangoli.
Dichiarare un tipo di dato per rappresentare un rettangolo. Un rettangolo è descritto dal vertice inferiore sinistro e da quella del vertice superiore destro (due punti).
Un punto è definito in termini di coordinate x e y (due interi) su uno spazio cartesiano bidimensionale.
Scrivere un programma che esegua le seguenti elaborazioni in sequenza: 1 - Acquisisce da tastiera i dati di due rettangoli, verificandone la correttezza delle coordinate (la prima coordinata è effettivamente in basso a sinistra rispetto alla seconda) e se non valide le richiede.
2 - Calcola e visualizza l'area di ciascun rettangolo.
3 - Verifica se i due rettangoli sono intersecati e visualizza l'esito del test.
3 - Se sono intersecati, costruisce in una nuova variabile il rettangolo intersezione (prestare attenzione a tutte le casistiche legate alla posizione di un rettangolo rispetto all'altro) e ne visualizza le coordinate a schermo.
4 - Se sono intersecati, calcola e visualizza l'intersezione sull'unione, ovvero la frazione (quindi un valore in virgola mobile) tra l'area
dell'intersezione tra i due rettangoli e l'area totale della forma geometrica generata dai due rettangoli sovrapposti.
*/

#include <stdio.h>

#define DIM 2

typedef struct {
	int x, y;
} punto_t;

typedef struct {
	punto_t is, sd;
} rettangolo_t;

void acquisisci(rettangolo_t [], int);
void area(rettangolo_t [], int);
int intersecati(rettangolo_t [], int);

int main(){
	rettangolo_t rettangoli[DIM];

	acquisisci(rettangoli, DIM);

	return 0;
}

void acquisisci(rettangolo_t rettangoli[], int dim){
	int i;
	for(i=0; i<dim; i++){
		do {
			printf("Inferiore sinistro (x,y): ");
			scanf("%d %d", rettangoli[i].is.x, rettangoli[i].is.y);
			printf("Superiore destro (x,y): ");
			scanf("%d %d", rettangoli[i].sd.x, rettangoli[i].sd.y);
		} while(rettangoli[i].is.x > rettangoli[i].sd.x || rettangoli[i].is.y  > rettangoli[i].sd.y);
	}
}

void area(rettangolo_t rettangoli[], int dim){
	int i, area;
	for(i=0; i<dim; i++){
		area = (rettangoli[i].sd.x-rettangoli[i].is.x) * (rettangoli[i].sd.y-rettangoli[i].is.y);
		printf("Area rettangolo %d: %d", i+1, area);
	}
}

void intersecati(rettangolo_t rettangoli[], int dim){
	int i;
	for(i=0; i<dim; i++){
		
	}
}