#include <stdlib.h>
#include "pilha.h"

boolean inverte_pilha(Pilha* p)
{
    if(pilha_vazia(*p)) return false;

    //criar duas pilhas auxiliares
    Pilha p_aux1;
    Pilha p_aux2;


    //aloca memoria para as pilhas
    nova_pilha(&p_aux1, 1000);
    nova_pilha(&p_aux2, 1000);

    //criar um ponteiro auxiliar
    ElementoDePilha ptr_aux;

    while(!pilha_vazia(*p))
    {
        recupere_da_pilha(*p, &ptr_aux);

        remova_elemento_da_pilha(p);

        guarde_na_pilha(&p_aux1, ptr_aux);
    }
    //passar para outa pilha
        while(!pilha_vazia(p_aux1))
    {
        recupere_da_pilha(p_aux1, &ptr_aux);

        remova_elemento_da_pilha(&p_aux1);

        guarde_na_pilha(&p_aux2, ptr_aux);
    }
    //devolver para a pilha original tudo invertido
    while(!pilha_vazia(p_aux2))
    {
        recupere_da_pilha(p_aux2, &ptr_aux);

        remova_elemento_da_pilha(&p_aux2);

        guarde_na_pilha(p, ptr_aux);
    }

    free_pilha(&p_aux1);
    free_pilha(&p_aux2);

    return true;

}