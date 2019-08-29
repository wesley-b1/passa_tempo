
#include <stdlib.h>
#include <stdio.h>

void MultiplicacaoMatrizes (int **x, int **y, int **z,
                            int nlinhas, int ncolunas, int ncolunasy)
{
    /* variaveis locais a serem utilizadas */

    int i=0, j=0, k=0;
    int auxiliar;

    for(i; i<nlinhas; i++)
    {
        for(j; j< ncolunasy; j++);
        {

            for(k; k<ncolunas; k++)
            {
                auxiliar=auxiliar + (x[i][k] * y[k][j]);
            }
            z[i][j] = auxiliar;
            auxiliar = 0;
        }
    }

}

int main()
{
    int **a, **b, **c;
    int numerolinhasA = 2, numerocolunasA = 2;
    int numerolinhasB = numerocolunasA, numerocolunasB = numerolinhasA;
    int i,j,k;

    /*alocando memoria dinamica para a matriz*/
    a = (int **)malloc(numerolinhasA*sizeof(int*));
    b = (int **)malloc(numerocolunasA*sizeof(int*));
    c = (int **)malloc(numerolinhasA*sizeof(int*));

    a[0]=(int *)malloc(numerolinhasA*numerocolunasA*sizeof(int));
    b[0]=(int *)malloc(numerolinhasB*numerocolunasB*sizeof(int));
    c[0]=(int *)malloc(numerolinhasA*numerocolunasB*sizeof(int));

    for(i=0; i<numerolinhasA; i++)

    {
        a[i]=(*a + numerocolunasA*i);
    }


    for(i=0; i<numerolinhasA; i++)
    {
        b[i]=(*b+numerocolunasA*i);
    }


    for(i=0; i<numerolinhasA; i++)
    {
        c[i]=(*c +numerocolunasA*i);
    }


    /*inserindo elementos na matriz */

    for(i=0;i<numerolinhasA;i++){
        for(j=0;j<numerocolunasA;j++){
                a[i][j] = 2;
        }

        for(i=0;i<numerolinhasB;i++){
        for(j=0;j<numerocolunasB;j++){
                b[i][j] = 2;

        }
    }
    }
/* chamando a funcao */
    MultiplicacaoMatrizes(a,b,c,numerolinhasA,numerocolunasA,numerocolunasB);

/* impressao da matriz */
    for (i=0; i<numerolinhasA; i++){
        for(j=0;j<numerocolunasB; j++){
             printf ("\nElemento[%d][%d] = %d\n", i, j,c[i][j]);
        }
        printf("\n");
    }



    free(a[0]);
    free(b[0]);
    free(c[0]);

    free(a);
    free(b);
    free(c);

    return 0;
}
