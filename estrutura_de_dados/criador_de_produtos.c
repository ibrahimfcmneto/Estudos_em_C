/*
criar um programa que cadastra um produto.
A criação (alocação e preenchimento) do produto
deve ser feita em uma função separada.
*/

#include <stdio.h>

struct Produto {
    int codigo;
    char nome[100];
    float preco;
};

struct Produto* criar_produtos(int qtd_produtos)
{
    struct Produto* produtos;
    produtos = (struct Produto *)malloc(qtd_produtos * sizeof(struct Produto));

    if(produtos == NULL)
    {
        printf("Erro ao alocar memoria");
        return NULL;
    }

    for (int i=0; i<qtd_produtos; i++)
    {
        printf("\n--- Produto %d ---\n", i + 1);

        printf("Codigo produtos: ");
        scanf("%d", &produtos[i].codigo);

        printf("preco: ");
        scanf("%f", &produtos[i].preco);

        getchar();
        printf("Nome produto: ");
        fgets(produtos[i].nome,100,stdin);
    }

    return produtos;
}

void mostrar_produtos(struct Produto *produtos, int qtd_produtos)
{
    printf("\n--- LISTA DE PRODUTOS ---\n");
    for (int i=0; i<qtd_produtos; i++)
    {
        printf("Nome produto: %s\n", produtos[i].nome);
        printf("Codigo produtos: %d\n", produtos[i].codigo);
        printf("preco: %f\n", produtos[i].preco);
        printf("---------------------------------\n");
    }
}

int main()
{
    struct Produto *produtos = NULL;
    int quantidade_produtos;

    printf("Quantidade de produtos: ");
    scanf("%d", &quantidade_produtos);

    produtos = criar_produtos(quantidade_produtos);

    if(produtos == NULL)
    {
        printf("Erro ao alocar memoria!");
        return 1;
    }

    mostrar_produtos(produtos, quantidade_produtos);

    free(produtos);

    return 0;
}