#include <stdio.h>
#include <stdlib.h>

int compara(float a, float b) {
    return (a - b);
}

void utilizando_qsort(float *p, int TAM, int (*funcaoP)(float, float)) { 
    int i, j;
    float aux;
	// comparando todos os elementos
   for( i = 0; i < TAM; i++ )
  {
    for( j = i + 1; j < TAM; j++ ) // sempre 1 elemento na frente
    {
            if(p[i]>p[j]){
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
}

int main()
{
    int i, TAM;
	float *p;
    printf("Informe um número: ");
    scanf("%d", &TAM);
    
    //declaração do ponteiro para função
    int (*funcaoP)(float, float); 
	
	// inicialização do ponteiro para função
    funcaoP = &compara;

    p = (float*)malloc(TAM * sizeof(float)); 
	
	// verifica se ocorreu sucesso na alocação
    if (p == 0) { 
        printf("Ocorreu um erro!\n");
        exit(0);
    }
    
    printf("\nINFORME OS ELEMENTOS\n");
    for (i = 0; i < TAM; i++) { 
	 printf("Elemento[%d]:", i);
        scanf("%f", &p[i]);
    }
	
	//chamada da função utilizando_qsort
    utilizando_qsort(p, TAM, funcaoP); 
    //limpa tela
    system("cls");
    printf("VETOR ORDENADO\n");
    for (i = 0; i < TAM; i++) { 
        printf("Elemento[%d]:", i);
        printf("%f, ", p[i]);
        printf("\n");
    }

    free(p); //libera memória alocada
    return 0; 
}
