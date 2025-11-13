#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include <time.h>
#include "arvore_binaria_de_busca.h"

unsigned int soma_recursiva(Ptr_de_no_de_arvore_binaria_de_busca no)
{
    // 1. CASO BASE: Se o nó é NULL, ele não soma nada.
    //    A soma de uma árvore vazia é 0.
    if (no == NULL)
    {
        return 0;
    }

    // 2. PASSO RECURSIVO: Se o nó não é NULL...

    // 2a. Pegue o valor DESTE nó (convertendo de void*)
    int valor_atual = *(int*)(no->informacao);

    // 2b. Peça a soma de TUDO à esquerda
    int soma_esquerda = soma_recursiva(no->esquerda);

    // 2c. Peça a soma de TUDO à direita
    int soma_direita = soma_recursiva(no->direita);

    // 3. COMBINE O RESULTADO:
    return valor_atual + soma_esquerda + soma_direita;
}