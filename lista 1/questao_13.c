#include <stdio.h>
#include <stdlib.h>

/* declarando a funcao soma para ser chamada na main */

void soma(int x, int y)
{
    /* variavel local para realizar a soma */
    int mais = x+y;

    /* impressao do valor obtido*/
    /*podiamos ter feito a soma no printf, sem precisar da variavel local*/
    printf("o valor da soma eh: %d", mais);

}



/* declaracao da funcao principal*/
int main()
{
    /* variaveis a serem chamadas pela funcao soma */
    int a = 15, b=22;
    /* variavel para a func*/
    void (*somatorio)(int, int);

    /* chamado da func soma na main */
    somatorio = &soma;
    (*somatorio)(a,b);
    return 0;

}
