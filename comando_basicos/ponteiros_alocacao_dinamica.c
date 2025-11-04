/*
alocação dinamica de memoria
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numeros;
    int n;

    printf("Quantidade de numeros: ");
    scanf("%d", &n);

    numeros = malloc(n * sizeof(int));

    if (numeros == NULL)
    {
        printf("Erro! Falha ao alocar memoria. \n");
        return 1;
    }

    for(int i=0; i<n; i++)
    {
        printf("%d numero: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("Numeros lidos: \n");
    for(int i=0; i<n; i++)
    {
        printf("Numero %d: valor: %d\n", i+1, numeros[i]);
    }

    free(numeros);

    return 0;
}