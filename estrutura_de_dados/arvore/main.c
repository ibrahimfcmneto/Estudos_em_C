#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_de_busca.h"

/*
comparar x com y, retornando um número negativo,
caso x seja menor que y, retornando 0, caso x seja
igual a y, e retornando um número positivo, caso
x seja maior que y
*/
int compara_ints (int* x, int* y)
{
    if (*x <*y) return -666;
    if (*x==*y) return 0;
    return 666;
}
void printa_int (int* x)
{
    printf("%d",*x);
}
/*
typedef struct
{
    unsigned int dia, mes, ano;
}
Data;

int compara_datas (Data* x, Data* y)
{
    if (x->ano<y->ano) return -666;
    if (x->ano>y->ano) return  666;

    if (x->mes<y->mes) return -666;
    if (x->mes>y->mes) return  666;

    if (x->dia<y->dia) return -666;
    if (x->dia>y->dia) return  666;

    return 0;
}
void printa_data (Data* d)
{
    printf("%d/%d/%d",d->dia,d->mes,d->ano);
}
*/
int main()
{
    Arvore_binaria_de_busca arv;
    nova_arvore_binaria_de_busca(&arv,&compara_ints,&printa_int);
    
    int*  i;

    i=(int*)malloc(sizeof(int));
    *i=2;
    guarde_na_arvore_binaria_de_busca (&arv,(Elemento)i);
    i=NULL;

    i=(int*)malloc(sizeof(int));
    *i=3;
    guarde_na_arvore_binaria_de_busca (&arv,(Elemento)i);
    i=NULL;

    i=(int*)malloc(sizeof(int));
    *i=1;
    guarde_na_arvore_binaria_de_busca (&arv,(Elemento)i);
    i=NULL;

    free_arvore_binaria_de_busca(&arv);

    /*
    Arvore_binaria_de_busca arv;
    nova_arvore_binaria_de_busca(&arv,&compara_datas,&printa_data);
    
    Data*  i;

    i=(Data*)malloc(sizeof(Data));
    i->dia=2;
    i->mes=11;
    i->ano=2024;
    guarde_na_arvore_binaria_de_busca (&arv,(Elemento)i);
    i=NULL;

    i=(Data*)malloc(sizeof(Data));
    i->dia=21;
    i->mes=8;
    i->ano=2024;
    guarde_na_arvore_binaria_de_busca (&arv,(Elemento)i);
    i=NULL;

    i=(Data*)malloc(sizeof(Data));
    i->dia=3;
    i->mes=5;
    i->ano=2024;
    guarde_na_arvore_binaria_de_busca (&arv,(Elemento)i);
    i=NULL;

    free_arvore_binaria_de_busca(&arv);
    */

    return 0;
}
