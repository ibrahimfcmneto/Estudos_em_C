/*Implemente uma função que crie uma cópia de uma fila, passada como parâmetro de
entrada. A função não deve alterar a fila de entrada e deve ter o seguinte protótipo:
TFila* copia (TFila* p).
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"   // Seu .h da fila
#include "basics.h" // Seu .h do boolean

//lógica pensada:
//criar uma fila auxiliar e uma fila copia(a que vai ser retornada)
//jogar os elementos da fila orignal para a fila auxiliar
//depois pegar os dados da auxiliar e ir colocando de volta na original e na copia
//e depois limpar a auxiliar

Fila* copia (Fila* p)
{
    //alocar a estrutura da copia
    Fila* f_copia = (Fila*) malloc(sizeof(Fila));
    if (f_copia == NULL) return NULL;

    //alocar a estrutura auxiliar
    Fila f_aux;

    //Inicializar as filas
    nova_fila(f_copia, p->capacidade);
    nova_fila(&f_aux, p->capacidade);

    ElementoDeFila elem_original;

    while(!fila_vazia(*p))
    {
    recupere_da_fila(*p, &elem_original);

    remova_elemento_da_fila(p);
    
    //copia profunda
    int* val_original = (int*)elem_original;
    int* val_novo = (int*) malloc(sizeof(int));
    if (val_novo == NULL)
    {
        return NULL;
    }

    *val_novo = *val_original;

    guarde_na_fila(f_copia, (ElementoDeFila)val_novo);//guarda o novo na copia
    guarde_na_fila(&f_aux, elem_original);// Guarda o original na aux;
}

    //devolver os elementos para a orginal e para a copia
    while(!fila_vazia(f_aux))
    {
        recupere_da_fila(f_aux, &elem_original);

        remova_elemento_da_fila(&f_aux);

        guarde_na_fila(p, elem_original);
    }

    free_fila(&f_aux);

    return f_copia;
}