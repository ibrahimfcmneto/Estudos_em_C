#include <stdio.h>
#include <stdlib.h>
#include "fila.h"   // Seu .h da fila
#include "basics.h" // Seu .h do boolean

void remove_todas_ocorrencias(Fila *f, int x)
{
    int variavel_inteiro;

    //criar um ponteiro temporário
    ElementoDeFila ptr_temporario;

    //vetor auxiliar para armazenar os elementos
    Fila fila_aux;
    nova_fila(&fila_aux, 1000);

    while(!fila_vazia(*f))
    {
        //recuperar elemento do topo e salvar em um ponteiro
        recupere_da_fila(*f, &ptr_temporario);

        //remover o elemento do incio da fila
        remova_elemento_da_fila(f);

        //converter em inteiro
        variavel_inteiro = *(int*)(ptr_temporario);

        //ver se o elemento é o que está procurando
        if(variavel_inteiro == x)
        {
            free(ptr_temporario);
        }
        else
        {
        //caso não seja o elemento procurado, guardar na fila auxiliar
        guarde_na_fila(&fila_aux, ptr_temporario);
        }
    }

    //loop para devolver os elementos
    while(!fila_vazia(fila_aux))
    {
        recupere_da_fila(fila_aux, &ptr_temporario);

        remova_elemento_da_fila(&fila_aux);

        guarde_na_fila(f, ptr_temporario);
    }

    free_fila(ptr_temporario);

}