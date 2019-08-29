#include <stdio.h>
#include <math.h>

int main(){
	//será 4094 em exadecimal ffe
int i=5, *p;
p = &i;
printf("%x %d %d %d %d", p,*p+2,**&p,3**p,**&p+4);

	
	
	return 0;
}
