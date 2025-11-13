#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include <time.h>
#include "arvore_binaria_de_busca.h"


//tirar os elemento da árvore e colocá-los em um vetor destino
static void descarregar_recursivo(Ptr_de_no_de_arvore_binaria_de_busca no, int* vetor_destino, int* indice_atual)
{

    //verificar se o ponteiro atual é nulo
    if(no == NULL)
    {
        return;
    }

    //passo 1: ir para esquerda
    descarregar_recursivo(no->esquerda, vetor_destino, indice_atual);

    //passo 2: caso o ptr_tual seja NULL, vai entrar na condição e vai retornar
    //dessa forma vai voltar para o elemento central;
    //pegar a informação do elemento central e colocar no vetor
    int valor_da_plataforma = *(int*)(no->informacao);

    //salva o valor no vetor na posição certa
    vetor_destino[*indice_atual] = valor_da_plataforma;

    //avançar o índice
    *indice_atual = *indice_atual + 1;

    //passo 3: depois de ter adicionado o elemento central no vetor,
    //ir para a direita
    descarregar_recursivo(no->direita, vetor_destino, indice_atual);
}

void descarregar_arvore_em_vetor(Arvore_binaria_de_busca* a, int*vetor_destino)
{
    int indice = 0;

    descarregar_recursivo(a->raiz, vetor_destino, &indice);
}