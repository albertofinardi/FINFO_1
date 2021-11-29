#include <stdio.h>

int main(){
	int i, n, f;

	scanf("%d", &n);
	for(i=2, f=1; i<n; i++)
		f *= i;

	printf("%d\n", f);
	return 0;
}

/* 

bug a riga 7 -> da < a <=

*/