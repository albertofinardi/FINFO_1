#include <stdio.h>
#include <stdlib.h>
#define MAX 15

void analizza(char[], char*, int*);

int main(int argc, char *argv[]){
	FILE *fp;
	char c, str[MAX+1];
	int n;
	if(argc == 2){
		fp = fopen(argv[1], "r");
		if(fp){
			fscanf(fp, "%s", str);
			while(!feof(fp)){
				analizza(str, &c, &n);
				printf("%s %c %d\n", str, c, n);
				fscanf(fp, "%s", str);
			}
			fclose(fp);
		}else
			printf("Errore apertura file\n");
	}else
		printf("Errore argomenti\n");
	return 0;
}

void analizza(char str[], char *c, int *n){
	int n_loc, i;
	char min;
	if(str[0] != '\0'){
		for(i=1, min=str[0]; str[i] != '\0'; i++)
			if(str[i] < min)
				min = str[i];
		for(i=0, n_loc = 0; str[i] != '\0'; i++)
			if(str[i] == min)
				n_loc++;

		*c = min;
		*n = n_loc;

	}else
		printf("Stringa vuota\n");
}