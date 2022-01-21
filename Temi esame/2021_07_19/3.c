#define OFFSET 1
#define ERR -1
#include <stdio.h>
#include <stdlib.h>

void cercabassi(float arr[], int dim, float **m, int *dim_m);

int main(){
	int dim_arr, dim_m, i;
	float *arr, *m;

	do {
		scanf("%d", &dim_arr);
	} while(dim_arr <= 0);

	arr = malloc(sizeof(float)*dim_arr);
	
	if(arr){
		for(i=0; i<dim_arr; i++)
			scanf("%f", &arr[i]);

		cercabassi(arr, dim_arr, &m, &dim_m);
		if(dim_m != ERR){
			for(i=0; i<dim_m; i++)
				printf("%f ", m[i]);
			free(m);
			printf("\n");
		}

		free(arr);
	}
	return 0;
}

void cercabassi(float arr[], int dim, float **m, int *dim_m){
	int i, dim_m_loc;
	if(dim > 2){
		for(i=OFFSET, dim_m_loc=0; i<dim-OFFSET; i++)
			if(arr[i-OFFSET] > arr[i] && arr[i+OFFSET] > arr[i])
				dim_m_loc++;
		*m = malloc(sizeof(float)*dim_m_loc);
		dim_m_loc = 0;
		if(*m){
			for(i=OFFSET, dim_m_loc=0; i<dim-OFFSET; i++)
				if(arr[i-OFFSET] > arr[i] && arr[i+OFFSET] > arr[i]){
					(*m)[dim_m_loc] = arr[i];
					dim_m_loc++;
				}
		*dim_m = dim_m_loc;
		}else {
			printf("Errore allocazione\n");
			*dim_m = ERR;
		}
	}else{
		*dim_m = ERR;
		printf("Errore: array troppo piccolo\n");
	}
}