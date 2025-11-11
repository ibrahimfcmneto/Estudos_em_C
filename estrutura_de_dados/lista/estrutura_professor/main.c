#include <stdio.h>
#include "lista_simples.h"

int main ()
{
    Lista_simples lst;
    nova_lista_simples(&lst);

    int* inteiro=(int*)malloc(sizeof(int));
    *inteiro=5;
    insira_no_inicio_da_lista_simples(&lst,(Elemento_de_lista_simples)inteiro);
    inteiro=NULL;

    int* inteiro=(int*)malloc(sizeof(int));
    *inteiro=3;
    insira_no_inicio_da_lista_simples(&lst,(Elemento_de_lista_simples)inteiro);
    inteiro=NULL;

    return 0;
}