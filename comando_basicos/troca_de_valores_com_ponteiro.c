#include <stdio.h>

void troca_de_valores(int* n_inteiro, float*n_decimal, char* c_caractere )
{
    *n_inteiro = 666;
    *n_decimal = 666.66;
    *c_caractere = 'k';
}


int main()
{
    int inteiro = 10;
    float decimal = 20.5;
    char caractere = 'a';

    printf("Os valores antes sao:\n%d\n %f\n %c\n", inteiro, decimal, caractere);

    troca_de_valores(&inteiro, &decimal, &caractere);

    printf("Os valores depois sao: \n%d\n %f\n %c\n", inteiro, decimal, caractere);



    return 0;
}
