/*
Estrutura fila FIFO "first in first out"
*/

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct
{
    No *prim;
    No *fim;
    int tam;
}Fila;

void criar_fila(Fila *p)
{
    p->prim = NULL;
    p->fim = NULL;
    p->tam = NULL;
}

void inserir_na_fila(Fila *fila, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if(novo) {
        novo->valor = num;
        novo->proximo = NULL;
        if(fila->prim == NULL)//caso a fila esteja vazia, ou seja primeiro elemento
        {
            fila->prim = novo;
            fila->fim = novo;
        }
        else{//caso não seja o primeiro elemento
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

void remover_da_fila(Fila *fila)
{
    No *remover = NULL;

    if(fila->prim){ //caso seja o primeiro elemento da fila
        remover = fila->prim;
        fila->prim = remover->proximo;
        fila->tam--;
    }
    else
    {
        printf("Fila vazia");
    }
    return remover;
}

void imprimir(Fila *fila)
{
    No *aux = fila->prim;
    while(aux)
    {
        printf("%d", aux->valor);
        aux = aux->proximo;
    }
    printf("Fim");
}