#include <stdio.h>
#include <stdlib.h>

 // função para utilizção do qsort
int compara(const void * a, const void * b){
	//Quando o conteúdo do ponteiro de a for maior que b
    if(*(float*)a > *(float*)b) {
    	//retorna 1
        return 1;
	 //quando o conteúdo do ponteiro de a for menor que b
	 
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
	//armazenará o endereço de memória do array
    float *p;
	//TAM é a quantidade de elementos e i controla o laço
    int TAM, i; 
    
	//entrada com o tamanho do array
	printf("Entre com o numero de elementos: "); 
    scanf("%d", &TAM); 
    
    //alocando dinamicamente a memória 
    p = malloc(TAM*sizeof(float)); 
	
	//Leitura dos elementos
    for(i=0; i<TAM; i++){ 
        printf("Elemento[%d]:", i);
        scanf("%f", &p[i]);
    }

	//"chamamento" da função qsort() para realizar o ordenamento
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
    //liberação da memória
    free(p);
    return 0;
}
