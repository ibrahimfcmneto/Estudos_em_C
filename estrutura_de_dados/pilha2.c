#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dado;
    struct lista *prox;
} celula;

// --- "Âncora" global ---
celula *top = NULL; 

// --- Protótipos ---
void push(int item);
void pop();
void imprimir();

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Verificação da funcao push");

    printf("Valor no topo: %d\n", top->dado);
    printf("Valor do segundo: %d\n", top->prox->dado);
    printf("Valor terceiro: %d\n", top->prox->prox->dado);

    return 0;
}

// --- Sua função push (Corrigida) ---
void push(int item)
{
    printf("-----EMPILHANDO-----\n");
    celula *novo = (celula *)malloc(sizeof(celula));
    
    // Checagem do malloc
    if (novo == NULL) {
        printf("ERRO: Falha ao alocar memória!\n");
        return; 
    }
    
    novo->dado = item;
    novo->prox = top; // O "engate"
    top = novo;       // O "movimento" da âncora
    printf("Valor %d empilhado\n", novo->dado);
    printf("-----------------------\n");
}


void pop()
{

}
void imprimir()
{
    printf("-----conteudo da pilha------");

    if (top == NULL)
    {
        printf("Pilha vazia");
        return;
    }

    celula *temp = top;

    printf("TOPO-> ");

    while (temp != NULL)
    {
        printf("[%d] -> ", temp->dado);

        temp = temp->prox;
    }

    printf("NULL\n");
}