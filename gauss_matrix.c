/* Riduzione matrice dinamica di n incoglite a matrice triangolare superiore con gauss jordan.
Se passato "show" come argomento da riga di comando, mostra i diversi passaggi di riduzione.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEBUG "show"

int main(int argc, char *argv[]){
    int m,n,i,j,k;
    int c, b;
    double **a, term;
    
    printf("Dimensioni matrice:\nNo. di righe (m)\n");
    scanf("%d",&m);
    while(m<=0){
        printf("Valore non valido\n");
        scanf("%d",&m);
    }
    
    printf("No. di colonne (n)\n");
    scanf("%d",&n);
    while(n<=0){
        printf("Valore non valido\n");
        scanf("%d",&n);
    }

    a = (double**)malloc(m * sizeof(double*));
    for (i = 0; i < m; i++)
        a[i] = (double*)malloc(n * sizeof(double));

    if(a){
        printf("\nElementi matrice:\n");
        /* Input matrice */
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("M[%d][%d]: ", i+1, j+1);
                scanf("%lf",&a[i][j]);
            }
        }

        printf("\nMatrice:\n\n");

        /* Stampa matrice */
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%f\t",a[i][j]);
            }
            printf("\n");
        } 

        /* Eliminazione gauss */
        for(i=0;i<m-1;i++){
            for(k=i+1;k<m;k++){
                term=a[k][i]/a[i][i];
                for(j=0;j<n;j++){
                    a[k][j]=a[k][j]-term*a[i][j];
                }

                if(argc == 2 && !strcmp(argv[1], DEBUG)){
                    printf("\n\nPassaggio\n");
                    for(c=0;c<m;c++){
                        printf("\t");
                        for(b=0;b<n;b++){
                            printf("%f\t",a[c][b]);
                        }
                        printf("\n");
                    } 
                    printf("\n");
                }
            }
        }

        printf("\nTriangolo superiore dopo eliminazione Gauss-Jordan:\n\n");

        /* Stampa matrice */
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%f\t",a[i][j]);
            }
            printf("\n");
        } 

        printf("\n\n");
    }else
        printf("Errore allocazione\n");
    return 0;
     
}
