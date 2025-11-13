#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include <time.h>
#include "arvore_binaria_de_busca.h"

//A regra é: escorregar para esquerda, voltar para o centro e depois ir para direita

static void percorrer_arvore(Ptr_de_no_de_arvore_binaria_de_busca plataforma_atual)
{
    //caso a árvore não tenha nada, retorne
    if(plataforma_atual == NULL)
    {
        return;
    }

    //REGRA 1: escorregar pra esquerda
    percorrer_arvore(plataforma_atual->esquerda);

    //REGRA 2: fazer o trabalho que é printar
    printf("%d ", *(int*)(plataforma_atual->informacao));

    //REGRA 3: escorregar para a direita
    percorrer_arvore(plataforma_atual->direita);
}

//int qtd_de_elementos = 0;

int soma_todos_elementos = 0;

static void qtd_elementos_e_soma_total(Ptr_de_no_de_arvore_binaria_de_busca plataforma_atual)
{
    //condição caso a plataforma atual seja NULL
    if(plataforma_atual == NULL)
    {
        return;
    }

    //regra 1: ir para esquerda
    qtd_elementos_e_soma_total(plataforma_atual->esquerda);

    //regra 2
    //depois de ver que o que está à esquerda da plataforma atual é NULL
    //aumentar o contador e colocar ele na soma
    //qtd_de_elementos++;//aumenta a qtd_de_elementos
    soma_todos_elementos = soma_todos_elementos + *(int*)(plataforma_atual->informacao);//soma o elemento

    //regra 3
    //depois de ter ido para esquerda, visto que era NULL, voltadopara a plataforma central
    //ir para o elemento da direita
    qtd_elementos_e_soma_total(plataforma_atual->direita);
}