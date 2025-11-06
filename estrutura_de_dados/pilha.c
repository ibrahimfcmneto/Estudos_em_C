#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dado;
    struct lista *prox;
}celula;


void push(int item);
void imprimir();
void pop();

celula *top = NULL;


int main()
{
    int n, opcao;
    do
    {
         printf("Escolha uma opcao\n1) Empilhar\n 2) Desempilhar\n 3) Imprimir\n 0) Sair");
         printf("\nOpcao escolhida: ");
         scanf("%d", &opcao);
         switch(opcao)
         {
            case 1:
                printf("Entre com um valor a ser empilhado");
                scanf("%d", &n);
                push(n);
                break;

            case 2:
                pop();
                break;

            case 3:
                imprimir();
                break;
         }
    } while (opcao != 0);
    

    return 0;
}

void push(int item)
{
    printf("-----EMPILHANDO-----");

    celula *novo = malloc(sizeof(celula));

    if(novo == NULL)
    {
        printf("Erro ao alocar memoria!");
        return;
    }

    novo->dado = item;
    novo->prox = top;
    top = novo;
    printf("\nValor %d empilhado", novo->dado);
    printf("-----------------------\n");
}
