#include <stdio.h>

void calcularQuadrado(int valor, int *resultado)
{
    *resultado = valor * valor;
}

int main()
{
    int numero = 5;
    int valor_final;

    calcularQuadrado(numero, &valor_final);
    printf("O resultado é %d", valor_final);
    
    return 0;
}