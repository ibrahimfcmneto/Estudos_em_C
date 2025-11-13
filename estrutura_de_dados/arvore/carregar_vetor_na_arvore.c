#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include <time.h>
#include "arvore_binaria_de_busca.h"

//Pegar os elementos que estão em um vetor e ir colocando em uma árvore

carregar_vetor_na_arvore(Arvore_binaria_de_busca* a, int* vetor, int tamanho)
{
    for (int i=0; i<tamanho; i++)
    {
        //criar um ponteiro temporário
        int* novo_elemento_alocado;

        //alocar um lote de memoria
        novo_elemento_alocado = (int*)malloc(sizeof(int));

        //colocar o numero do vetor dentro do lote
        *novo_elemento_alocado = vetor[i];

        //entregar o ponteiro para a árvore;
        guarde_na_arvore_binaria_de_busca(a, (Elemento)novo_elemento_alocado);

        novo_elemento_alocado == NULL;
    }
}