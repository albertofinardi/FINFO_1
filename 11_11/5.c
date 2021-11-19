#include <stdio.h>
#define MAX 10

//int massimo(int*, int);

void maxmin(int[], int, int*, int*);

int main(){
	int m[MAX];
	int i, max, min;

	for(i=0; i<MAX; i++)
		scanf("%d", &m[i]);

	//max = massimo(m, dim);
	maxmin(m, dim, &max, &min);

	printf("%d %d\n", max, min);

	return 0;
}

/*
int massimo(int *a, int dim){
	int maxAltri;
	if(dim == 1)
		return *a;
	maxAltri = massimo(a+1, dim-1);
	if(*a > maxAltri)
		return *a;
	return maxAltri;
}
*/

void maxmin(int m[], int dim, int *max, int *min){
	int maxAltri, minAltri;
	
	if(dim == 1){
		*max = a[0];
		*min = a[0];
	}
	
	maxmin(&a[1], dim-1, &maxAltri, &minAltri);
	
	if(maxAltri > a[0])
		*max = maxAltri;
	else
		*max = a[0];


	if(minAltri > a[0])
		*min = minAltri;
	else
		*min = a[0];
}