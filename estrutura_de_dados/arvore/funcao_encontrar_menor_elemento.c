#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore_binaria_de_busca.h"

Elemento encontra_menor_elemento(Arvore_binaria_de_busca* a)
{
    // 1. Verifique se a árvore está vazia (caso base)
    if (a->raiz == NULL)
    {
        return NULL;
    }

    // 2. Crie um ponteiro "atual" para começar a navegar,
    //    começando pela raiz.
    Ptr_de_no_de_arvore_binaria_de_busca atual = a->raiz;

    // 3. Crie um loop (while) que continue "andando"
    //    para a direção correta (esquerda ou direita?)
    //    O loop deve parar quando você não puder mais andar.
    while (atual->esquerda!=NULL)//se o atual->esquerda for null quer dizer que atual é o menor elemento
    {
        //paço que vai andando para esquerda
        atual = atual->esquerda;
    }

    // 4. Quando o loop parar, 'atual' estará apontando
    //    para o nó que você quer. Retorne a informação dele.
    return atual->informacao;
}