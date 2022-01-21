#include <stdio.h>
#define ADD_EPICENTRO 2
#define ADD_INTORNO 1
#define RAGGIO 1

#define NC 10
#define NR 10

void eruzione(int m[][NC], int col, int row, int x, int y);

int main(){
	int i, j, x, y, m[NR][NC];

	for(i=0; i<NR; i++)
		for(j=0; j<NC; j++)
			scanf("%d", &m[i][j]);

	for(i=0; i<NR; i++){
		for(j=0; j<NC; j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}

	printf("Riga colonna: ");
	scanf("%d %d", &x, &y);
	
	eruzione(m, NC, NR, x, y);

	for(i=0; i<NR; i++){
		for(j=0; j<NC; j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}

	return 0;

}

void eruzione(int m[][NC], int col, int row, int x, int y){
	int i, j;
	if(x <= col && y <= col){
		for(i=RAGGIO*-1; i<=RAGGIO; i++)
			if(x+i >= 0 && x+i <= col)
				for(j=RAGGIO*-1; j <= RAGGIO; j++)
					if(y+j >= 0 && y+j <= row && m[x+i][j+y] < m[x][y])
						m[i+x][y+j] += ADD_INTORNO;

		m[x][y] += ADD_EPICENTRO;
	}
}