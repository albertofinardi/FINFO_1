#include <stdio.h>
#define DIM 10

int main(){

	int array[DIM];
	int i;

	for(i=0; i<DIM; i++)
		scanf("%d", &array[i]);

	printf("\n");

	for(i=0; i<DIM; i++){
		if(!(array[i]%2))
			printf("%d\n", array[i]);
	}

	printf("\n");

	for(i=0; i<DIM; i++){
		if(array[i]%2)
			printf("%d\n", array[i]);
	}

	return 0;
}