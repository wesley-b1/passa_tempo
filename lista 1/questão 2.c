#include <stdio.h>
#include <math.h>

int main(){
	
	int i=3,j=5;
	int *p, *q;
	p = &i;
	q = &j;
	
	//if(p==&i){
		printf("p==&i = %d\n",*p==&i);
	//}else{
                printf("p==&i: Falsa\n");
	//}
	
	int subtracao = *p-*q;
	printf("*p - *q = %d\n",subtracao);//valor -2
	
	printf("**&p = %d\n",**&p);//o valor do valor de 'p' é 3
	
	int equacao = 3 - *p/(*q) + 7;
	printf("3 - *p/(*q) + 7 = %d\n",equacao);
	
	return 0;
}
