#include <stdio.h>

int main()
{
    int n;

    int *p; //aponta para um endereço de memória

    printf("Informe um numero: ");
    scanf("%d", &n);

    //inicializando o ponteiro
    p = &n;


    printf("endereço de memoria  em que o numero esta: %d\n", &n);
    printf("endereço de memoria2 em que o numero esta: %d", p);


    return 0;
}