#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include <time.h>
#include "arvore_binaria_de_busca.h"

//tirar os elemento da árvore e colocá-los em um vetor destino
void descarregador_de_arvore(Arvore_binaria_de_busca* a, int* vetor_destino)
{
    int qtd_elementos = quantas_info_tem_na_arvore_binaria_de_busca(a);

    if(qtd_elementos == 0)
    {
        printf("árvore vazia");
        return;
    }

    //alocar memoria para o vetor de destino com a quantidade
    //de elementos que tem na árvore
    vetor_destino = (int*)malloc(qtd_elementos * sizeof(int));

    //criar uma ponteiro temporário para passar da árvore para o vetor
    int* ptr_temporario;

    while(qtd_elementos != 0)
    {
    //remover o elemento da árvore e colocar no ponteiro
    remova_da_arvore_binaria_de_busca(a, &ptr_temporario);

    //

    }


}