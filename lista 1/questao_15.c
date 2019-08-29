#include <stdio.h>
#include <stdlib.h>

 // fun��o para utiliz��o do qsort
int compara(const void * a, const void * b){
	//Quando o conte�do do ponteiro de a for maior que b
    if(*(float*)a > *(float*)b) {
    	//retorna 1
        return 1;
	 //quando o conte�do do ponteiro de a for menor que b
	 
    }else if (*(float*)a <*(float*)b){
    	//retorna -1
        return -1;
        
	//quando o elemento de a for igual ao elemento de b
    }else{
        return 0;
	}
}
int main()
{
	//armazenar� o endere�o de mem�ria do array
    float *p;
	//TAM � a quantidade de elementos e i controla o la�o
    int TAM, i; 
    
	//entrada com o tamanho do array
	printf("Entre com o numero de elementos: "); 
    scanf("%d", &TAM); 
    
    //alocando dinamicamente a mem�ria 
    p = malloc(TAM*sizeof(float)); 
	
	//Leitura dos elementos
    for(i=0; i<TAM; i++){ 
        printf("Elemento[%d]:", i);
        scanf("%f", &p[i]);
    }

	//"chamamento" da fun��o qsort() para realizar o ordenamento
    qsort(p, TAM, sizeof(float), compara);
    //limpa tela
    system("cls");
	printf("VETOR ORDENADO\n");
	//imprimindo os elementos ordenados.
    for(i=0; i<TAM; i++){ 
   		printf("Elemento[%d]:", i);
        printf("%f, ", p[i]);
        printf("\n");
    }
    //libera��o da mem�ria
    free(p);
    return 0;
}
