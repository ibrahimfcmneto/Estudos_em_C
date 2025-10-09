#include <stdio.h>
#include <string.h> // Usado para strcpy nos nomes dos produtos

// Definições das structs (como no enunciado acima)
typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    int id;
    int produtoId;
    int quantidade;
} Venda;

//retornar o id do livro que foi emprestado mais vezes

int produtoMaisVendido(Venda lista_vendas[], int qtd_vendas,
                       Produto lista_produtos[], int qtd_produtos)
{
    int qtd_vendida[qtd_produtos];

    //inicializando a contagem
    for (int i=0; i<qtd_produtos; i++)
    {
        qtd_vendida[i] = 0;
    }

    for(int j=0; j<qtd_vendas; j++)
    {
        for(int i=0; i<qtd_produtos; i++)
        {
            if(lista_vendas[j].produtoId == lista_produtos[i].id)
            {
                //está somando o quanto vendeu cada produto
                qtd_vendida[i]++;
                break;
            }
        }
    }

    int id_produto_mais_vendido;
    int maior_qtd_vendida = 0;

    for(int i=0; i<qtd_produtos; i++)
    {
        if(i == 0)
        {
            id_produto_mais_vendido = lista_produtos[i].id;
            maior_qtd_vendida = qtd_vendida[i];
        }
        else if(qtd_vendida[i] > maior_qtd_vendida)
        {
            id_produto_mais_vendido = lista_produtos[i].id;
            maior_qtd_vendida = qtd_vendida[i];
        }
    }

    return id_produto_mais_vendido;
}


int main() {
    // --- LISTA DE PRODUTOS DA LOJA ---
    Produto produtos_da_loja[4];
    int total_produtos = 4;

    // (O strcpy é usado para colocar texto em vetores de char)
    produtos_da_loja[0].id = 101; strcpy(produtos_da_loja[0].nome, "Smartphone XPTO"); produtos_da_loja[0].preco = 1999.90;
    produtos_da_loja[1].id = 202; strcpy(produtos_da_loja[1].nome, "Notebook Pro");   produtos_da_loja[1].preco = 4500.00;
    produtos_da_loja[2].id = 303; strcpy(produtos_da_loja[2].nome, "Fone Bluetooth"); produtos_da_loja[2].preco = 249.50;
    produtos_da_loja[3].id = 404; strcpy(produtos_da_loja[3].nome, "Smartwatch 2");  produtos_da_loja[3].preco = 899.00;


    // --- LISTA DE VENDAS REALIZADAS ---
    Venda vendas_realizadas[] = {
        {1001, 303, 1}, // Venda de 1 Fone Bluetooth (ID 303)
        {1002, 101, 1}, // Venda de 1 Smartphone XPTO (ID 101)
        {1003, 202, 1}, // Venda de 1 Notebook Pro (ID 202)
        {1004, 303, 2}, // Venda de 2 Fones Bluetooth (ID 303)
        {1005, 101, 2}, // Venda de 2 Smartphones XPTO (ID 101)
        {1006, 101, 1}  // Venda de 1 Smartphone XPTO (ID 101)
    };
    int total_vendas = 6;

    /*
     * Contagem de aparições por produto (o que sua função deve calcular):
     * - Smartphone (ID 101): Aparece em 3 vendas. -> VENCEDOR
     * - Notebook (ID 202): Aparece em 1 venda.
     * - Fone (ID 303): Aparece em 2 vendas.
     * - Smartwatch (ID 404): Aparece em 0 vendas.
    */

    printf("--- Iniciando teste da funcao 'produtoMaisVendido' ---\n");
    int id_vencedor = produtoMaisVendido(vendas_realizadas, total_vendas, produtos_da_loja, total_produtos);

    printf("\n---------------------------------------------\n");
    printf("Resultado da sua funcao: O produto mais vendido tem ID %d\n", id_vencedor);
    printf("Resultado esperado: O produto mais vendido tem ID 101\n");
    printf("---------------------------------------------\n\n");

    if (id_vencedor == 101) {
        printf(">>> SUCESSO! O resultado esta correto. Voce dominou a logica!\n");
    } else {
        printf(">>> FALHA! O resultado esta incorreto. Revise seu codigo.\n");
    }

    return 0;
}