#include <stdio.h>

int main()
{
    int variavel1 = 10;
    int variavel2 = 11;

    int *endereco1 = &variavel1;
    int *endereco2 = &variavel2;

    printf("Endereço da variavel1: %p\n", (void*)endereco1);
    printf("Endereço da variavel2: %p\n", (void*)endereco2);

    int *maior_endereco = endereco1;

    if (endereco2 > endereco1)
    {
        maior_endereco = endereco2;
    }

    printf("O maior endereo eh: %p", (void*)maior_endereco);


    return 0;
}