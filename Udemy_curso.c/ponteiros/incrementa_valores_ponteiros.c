#include <stdio.h>

void incrementa(int* valor)
{
    (*valor)++; //está adicionando 1 un 
}

int main()
{
    int contador = 10;

    printf("Contador vale: %d\n", contador);

    incrementa(&contador);

    printf("Contador depois de incrementar vale: %d", contador);

    return 0;
}