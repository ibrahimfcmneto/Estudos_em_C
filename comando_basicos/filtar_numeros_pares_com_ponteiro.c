#include <stdio.h>

int conta_pares(int*inicio, int*fim)
{
    int qtd_pares = 0;

    for(int *p = inicio; p<fim; p++)
    {
        if((*p) % 2 == 0 )
        {
            qtd_pares++;
        }
    }
    return qtd_pares;

}

int main()
{
    int v[] = {3,5,6,2,4,8};
    int *p = v;
    int qtd = conta_pares(v, v+6);
    printf("A quantidade de pares eh: %d\n", qtd);

    return 0;
}