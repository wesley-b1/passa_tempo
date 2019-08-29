#include <stdio.h>
#include <stdlib.h>
int main()
{
	int TAM, i, j;
    float *p, aux;
    
    printf("Informe o número de elementos: ");
    scanf("%d", &TAM);
    
    p = malloc(TAM*sizeof(float));
    
    for(i=0; i<TAM; i++){
        printf("Elemento [%d]:", i);
        scanf("%f", &p[i]);
    }
      // coloca em ordem crescente (1,2,3,4,5...)  
  for( i = 0; i < TAM; i++ )
  {// sempre 1 elemento na frente
    for( j = i + 1; j < TAM; j++ ) 
    {
            if(p[i]>p[j]){
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    system("cls");
   printf("VETOR ORDENADO\n");
    for(i=0; i<TAM; i++){
		 printf("Elemento [%d]: ",i);
        printf("%f, ", p[i]);
        printf("\n");
    }
    free(p);
    return 0;
}
