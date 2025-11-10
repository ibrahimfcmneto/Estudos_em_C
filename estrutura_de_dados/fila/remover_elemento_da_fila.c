#include <stdio.h>
#include <stdlib.h>
#include "fila.h"   // Seu .h da fila
#include "basics.h" // Seu .h do boolean

/*
 * Remove todos os elementos da fila 'f' (que contém int*)
 * cujo valor apontado seja igual a 'valor_para_remover'.
 * Libera a memória de cada elemento removido.
 * Retorna 'true' se algo foi removido, 'false' caso contrário.
 */
boolean remover_todos_elementos(Fila* f, int valor_para_remover)
{
    boolean removeu_algo = false;
    
    // 1. Verifique se a fila não está vazia (use fila_vazia)
    if (fila_vazia(*f)) return false;

    //criar uma fila auxiliar com a quantidade de elementos da outra fila
    Fila f_aux;
    nova_fila(&f_aux, f->qtd_atual);

    ElementoDeFila elem_ptr;
    int* valor_ptr;

    while(fila_vazia(*f) == false)
    {
        //pegar o primeiro elemento da fila e guardar no elem_ptr
        recupere_da_fila(*f, &elem_ptr);
        //excluir o elemento que foi pego
        remova_elemento_da_fila(f);
        //tranformar o elemento que foi pego em inteiro
        valor_ptr = (int*)elem_ptr;
        //comparar se o elemento pego é o mesmo que o elemento para remover
        if(*valor_ptr != valor_para_remover)
        {
            //caso o elemento seja diferente, adicionar ele na fila auxiliar
            guarde_na_fila(&f_aux, elem_ptr);
        }
        else
        {
            //caso seja o elemento que é para ser removido, limpar ele da memória
            free(elem_ptr);
            removeu_algo = true;
        }
    }
    //fazer um while para devolver os elementos certos para a fila original
    while(fila_vazia(f_aux) == false)
    {
        //pegar o primeiro elemento da fila auxiliar e guardá-lo na variável
        recupere_da_fila(f_aux, &elem_ptr);
        //excluir o elemento pego
        remova_elemento_da_fila(&f_aux);
        //colocar o elemento de volta na fila original
        guarde_na_fila(f, elem_ptr);
    }
    //limpar a fila auxiliar
    free_fila(&f_aux);

    //retornar se removeu algo
    return removeu_algo;
}

// --- Função main() para testar seu exercício ---
int main()
{
    printf("Iniciando teste do exercicio...\n");
    
    Fila fil;
    nova_fila(&fil, 10);
    
    int* i;

    // Adiciona 10
    i = (int*)malloc(sizeof(int)); *i = 10;
    guarde_na_fila(&fil, (ElementoDeFila)i);

    // Adiciona 20
    i = (int*)malloc(sizeof(int)); *i = 20;
    guarde_na_fila(&fil, (ElementoDeFila)i);

    // Adiciona 30
    i = (int*)malloc(sizeof(int)); *i = 30;
    guarde_na_fila(&fil, (ElementoDeFila)i);

    // Adiciona 20 de novo
    i = (int*)malloc(sizeof(int)); *i = 20;
    guarde_na_fila(&fil, (ElementoDeFila)i);

    // Adiciona 40
    i = (int*)malloc(sizeof(int)); *i = 40;
    guarde_na_fila(&fil, (ElementoDeFila)i);

    printf("Fila original: 10 20 30 20 40\n");

    // Chame sua função
    int valor_remov = 20;
    printf("Removendo todos os %d...\n", valor_remov);
    
    if (remover_todos_elementos(&fil, valor_remov))
        printf("Elementos foram removidos.\n");
    else
        printf("Nenhum elemento foi removido.\n");


    // Imprima a fila resultante (deve ser 10, 30, 40)
    printf("Fila resultante: ");
    while(!fila_vazia(fil))
    {
        recupere_da_fila(fil, (ElementoDeFila*)&i);
        remova_elemento_da_fila(&fil);
        printf("%d ", *i);
        free(i); // Não esqueça de liberar o que sobrou
    }
    printf("\n");
    
    free_fila(&fil);

    return 0;
}