#include <stdio.h>

float atualiza_preco(float *preco, float valor_atualizado)
{
    *preco = valor_atualizado;
}


int main()
{
    float preco = 42.50;
    float *p_preco;
    float novo_valor;

    p_preco = &preco;
    //ou seja tudo que eu fizer no *p_preco vai alterar o preco;

    printf("Preço original: %.2f\n", preco);
    //------------------------------------------------
    printf("Novo valor: ");
    scanf("%f", &novo_valor);

    atualiza_preco(p_preco, novo_valor);
    //-------------------------------------------------
    printf("Preco atualizado: %.2f", preco);



    return 0;
}