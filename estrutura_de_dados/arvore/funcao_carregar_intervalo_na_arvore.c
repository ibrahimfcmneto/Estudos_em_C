#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include <time.h>
#include "arvore_binaria_de_busca.h"


//inserir todos os elementos que estão no intervalo
//ex: se inicio é 3 e fim é 6, deve inserir 3,4,5,6;
void carregar_intervalo_na_arvore(Arvore_binaria_de_busca* a, int inicio, int fim)
{
    for(int i=inicio; i<=fim; i++)
    {
        //criar um ponteiro temporário
        int* ptr_temp;

        //alocar esse ponteiro na memoria
        ptr_temp = (int*)malloc(sizeof(int));

        //ir colocando os elementos no ponteiro
        *ptr_temp = i;

        //guardar na ávore o elemento
        guarde_na_arvore_binaria_de_busca(a, (Elemento)ptr_temp);

        ptr_temp = NULL;
    }
}