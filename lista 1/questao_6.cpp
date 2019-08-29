#include <stdio.h>
#include <stdlib.h>



int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;
  //sim, o que era esperado que fosse mostrado, de fato, foi mostrado
  //na seguinte ordem ...
  printf("contador/valor/valor/endereco/endereco");
  for(i = 0 ; i <= 4 ; i++){
    printf("\ni = %d ",i);//valor do contador
    printf("vet[%d] = %.1f ",i, vet[i]);// contador e o valor do respectivo vetor
    printf("*(f + %d) = %.1f ",i, *(f+i));//contador e valor do vetor
    printf("&vet[%d] = %X ",i, &vet[i]);//contador e valor da memória do vetor
    printf("(f + %d) = %X ",i, f+i);//contador e valor da memória do vetor
  }
}


