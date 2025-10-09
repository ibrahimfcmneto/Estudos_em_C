#include <stdio.h>

void trocarValores(int *x1, int *y1)
{
    int variavel;
    variavel = *x1;
    *x1 = *y1;
    *y1 = variavel;
}

int main()
{
    int x = 10;
    int y = 20;

    printf("Antes da troca: x = %d, y = %d\n", x, y);

    trocarValores(&x, &y);

    printf("Depois da troca: x = %d, y = %d\n", x, y);

    return 0;
}