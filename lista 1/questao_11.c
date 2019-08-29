int main ()
{
    /* declarando 4 variaveis, uma para cada tipo */
    char y[4];
    int x[4];
    float w[4];
    double z[4];
    int i;

    /* utilizando a funcao sizeof para verificar o tamanho
    de cada tipo de variavel */

    printf(" char .......: %d bytes\n", sizeof(char));
    printf(" int.........: %d bytes\n", sizeof(int));
    printf(" float ......: %d bytes\n", sizeof(float));
    printf(" double......: %d bytes\n\n", sizeof(double));
    printf("posicoes do int: \n\n");

    /* O for foi utilizado para percorrer o vetor
    e imprimir o endereço de cada elemento*/

    for( i=0; i<4; i++)
    {
        printf(" Posicao %d", i);
        printf(" esta no endereco: %d \n\n", &x[i]);
    }

    printf("posicoes do char: \n\n");
    for( i=0; i<4; i++)
    {
        printf(" Posicao %d", i);
        printf(" esta no endereco: %d \n\n", &y[i]);
    }

    printf(" Posicoes do float: \n");
     for( i=0; i<4; i++)
    {
        printf(" Posicao %d", i);
        printf(" esta no endereco: %d \n\n", &w[i]);
    }

     printf(" Posicoes do double: \n\n");
     for( i=0; i<4; i++)
    {
        printf(" Posicao %d", i);
        printf(" esta no endereco: %d \n\n", &z[i]);

    }
    return 0;
}
