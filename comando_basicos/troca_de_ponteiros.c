#include <stdio.h>

void troca_valores(int *a, int *b)
{
    int k;
    k = *a; //armazena o valor de x;
    *a = *b; //O x recebe o valor de y;
    *b = k; // O y recebe o valor de x que estava na variável k;

}

int main()
{
    int x = 10;
    int y = 20;
    printf("valor de x antes da troca: %d\n", x);
    printf("valor de y antes da troca: %d\n", y);

    troca_valores(&x, &y);

    printf("valor de x depois da troca:%d\n", x);
    printf("valor de y depois da troca:%d\n", y);

    return 0;
}
