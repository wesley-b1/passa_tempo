#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int mat[4], *p, x;
	mat[0]=0;
	//p = mat + 1;//é válida e movimenta a memória em um bit de inteiro
	//sp = mat++;//a função incremental não funciona com estes operadores 
	//p = ++mat;//não é válida, pois a função incremental não funciona com estes operadores
	//	x = (*mat)++;//é válida porque incrementa o valor (lixo de memória) em uma unidade
	printf("%d = %d\n", x, *mat);
	
	return 0;
}
