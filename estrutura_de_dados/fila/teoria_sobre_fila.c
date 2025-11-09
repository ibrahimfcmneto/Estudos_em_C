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