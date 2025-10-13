#include <stdio.h>

int main()
{

    int valores[5];

    for (int i = 0; i<5; i++)
    {
        printf("Informe o %d valor: ", (i+1));
        scanf("%d", &valores[i]); //usuário vai adicionar um valor na posição "i";
    }

    printf("Os valores informados foram:\n");
    for(int j=0; j<5; j++)
    {
        printf("%d valor eh: %d\n", j+1, valores[j]);
    }

    //acessar os endereços de memória da array
    printf("endereço de memória da posição 0: %p\n", &valores[0]);//endereço de memória da posição 0;
    printf("endereço de memória da posição 1: %p", &valores[1]);//endereço de memória da posição 1;


    return 0;
}