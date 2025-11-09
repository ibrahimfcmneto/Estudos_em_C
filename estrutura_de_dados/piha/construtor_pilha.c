/*
construir o "esqueleto" de um programa de Pilha.
Seu trabalho é implementar as duas funções mais essenciais:
push() (para construir) e imprimir() (para ver o que você construiu).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dado;
    struct Node *prox; // Ponteiro para o nó de baixo
} celula;

celula *top = NULL; //top sempre vai apontar para o topo da pilha, por isso começa NULL

void push(int item);
void imprimir();

int main()
{
    int n;
    do
    {
        printf("valor: ");
        scanf("%d", &n);
        if(n != 999)
        {
            push(n);//chama a função para empilhar o numero digitado;
        }
    }
    while(n != 999);

    imprimir();

    return 0;
}

void push(int valor)
{
    //alocar memoria em uma nova célula
    celula *novo = malloc(sizeof(celula));

    //checagem se tem espaço na memoria
    if(novo == NULL)
    {
        printf("Erro ao alocar memoria!");
        return;
    }
    //preencher o dado com o valor que o usuário digitou
    novo->dado = valor;
    //o prox do novo nó aponta para o antigo topo
    novo->prox = top;
    //move a âncora, o top global agora é o novo nó
    top = novo;
}

void imprimir()
{
    //checagem se a pilha está vazia
    if (top == NULL)
    {
        printf("pilha está vazia");
        return;
    }

    //criar um ponteiro temporário para andar
    //para não mover o top global
    celula *temp = top;

    printf("Topo -> ");

    //fazer um loop para ir imprimindo até ficar null
    while(temp != NULL)
    {
        //imprimir o dado do nó atual
        printf("[%d] -> ", temp->dado);
        //avaçar o tempo para o próximo nó
        temp = temp->prox;
    }

    printf("NULL\n");
}

void pop()
{
    //verificar se a pilha está vazia
    if(top == NULL)
    {
        printf("Pilha esta vazia");
        return;
    }

    //criar um ponteiro temporário para guardar o nó do topo e liberá-lo
    celula *temp = top;

    //guardar o dado que vai ser retornado
    int dadoRemovido = temp->dado;

    //mover a ancora do topo para baixo
    top = top->prox;

    //liberar a memoria do nó que foi removido
    free(temp);

    //retornar o dado guardado
    return dadoRemovido;
}