#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int mat[4], *p, x;
	mat[0]=0;
	//p = mat + 1;//� v�lida e movimenta a mem�ria em um bit de inteiro
	//sp = mat++;//a fun��o incremental n�o funciona com estes operadores 
	//p = ++mat;//n�o � v�lida, pois a fun��o incremental n�o funciona com estes operadores
	//	x = (*mat)++;//� v�lida porque incrementa o valor (lixo de mem�ria) em uma unidade
	printf("%d = %d\n", x, *mat);
	
	return 0;
}
