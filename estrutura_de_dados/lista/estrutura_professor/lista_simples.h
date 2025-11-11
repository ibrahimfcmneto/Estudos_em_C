#ifndef LISTA_SIMPLES
#define LISTA_SIMPLES

#include "basics.h"

typedef void* Elemento_de_lista_simples;

typedef struct Struct_do_no_de_lista_simples  {
    Elemento_de_lista_simples informacao;
    struct Struct_do_no_de_lista_simples* proximo;
} Struct_do_no_de_lista_simples;

typedef Struct_do_no_de_lista_simples* Ptr_de_no_de_lista_simples;

typedef struct
{
    Ptr_de_no_de_lista_simples primeiro;
} Lista_simples;

void nova_lista_simples (Lista_simples* l);
void insira_no_inicio_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i);
void insira_no_final_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i);
void remova_do_inicio_da_lista_simples (Lista_simples* l);
void remova_do_final_da_lista_simples (Lista_simples* l);
unsigned int quantos_elementos (Lista_simples l);
void free_lista_simples (Lista_simples* l);
#endif