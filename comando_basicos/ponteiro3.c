#include <stdio.h>
#include <string.h>

void encontrarMaiorElemento(int *maior, int tdos_valores[], int tamanho)
{
    
    *maior = tdos_valores[0];

    for (int i=0; i<tamanho; i++)
    {
        if (tdos_valores[i] > *maior)
        {
            *maior = tdos_valores[i];
        }
    }
}

int main()
{
    int valores[14] = {2,3,4,5,6,7,12,35,23,5,234,65,2,34};
    int maior_valor = 0;

    encontrarMaiorElemento(&maior_valor, valores, 14);

    printf("Maior valor: %d", maior_valor);
    
    return 0;
}