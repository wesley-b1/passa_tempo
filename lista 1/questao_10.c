#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int x[4];
	//int p;
	// p = x+1;
	printf("%d :: %d",x+1, x);
	
	//para valores de x, quando é igual a 4092, declarados como 'char'
	//para x+1 = 4093
	//para x+2 = 4094
	//para x+3 = 4095
	//para valores de x, quando é igual a 4092, declarados como 'int'
	//para x+1 = 4094
	//para x+2 = 4096
	//para x+3 = 4098
	//para valores de x, quando é igual a 4092, declarados como 'float'
	//para x+1 = 4096
	//para x+2 = 4100
	//para x+3 = 4104
	//para valores de x, quando é igual a 4092, declarados como 'double'
	//para x+1 = 4100
	//para x+2 = 4108
	//para x+3 = 4116
	return 0;
}
