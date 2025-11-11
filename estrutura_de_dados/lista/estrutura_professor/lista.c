//arquivo onde tem as funções com as lógicas

#include <main.c>
#include <lista_simples.h>

void nova_lista_simples (Lista_simples* ls)
{
    ls->primeiro=NULL;
}

static Ptr_de_no_de_lista_simples novo_no_de_lista_simples
       (Elemento_de_lista_simples i, Ptr_de_no_de_lista_simples p)
{
    Ptr_de_no_de_lista_simples novo = (Ptr_de_no_de_lista_simples)malloc(sizeof(Struct_do_no_de_lista_simples));

    novo->informacao=i;
    novo->proximo   =p;

    return novo;
}

void insira_no_inicio_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i)
{
    l->primeiro=novo_no_de_lista_simples (i,l->primeiro);
}

void insira_no_final_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i)
{
    if (l->primeiro==NULL)
        l->primeiro=novo_no_de_lista_simples (i,NULL);
    else
    {
        Ptr_de_no_de_lista_simples atual = l->primeiro;

        while (atual->proximo!=NULL)
            atual=atual->proximo;

        atual->proximo = novo_no_de_lista_simples (i,NULL);
    }
}

boolean remova_do_inicio_da_lista_simples (Lista_simples* l)
{
    if (l->primeiro==NULL) return false;

    Ptr_de_no_de_lista_simples a_remover = l->primeiro;
    l->primeiro = l->primeiro->proximo;
    free(a_remover->informacao);
    free(a_remover);
    return true;
}

boolean remova_do_final_da_lista_simples (Lista_simples* l)
{
    if (l->primeiro==NULL) return false;

    if (l->primeiro->proximo==NULL)
    {
        free(l->primeiro->informacao);
        free(l->primeiro);
        l->primeiro=NULL;
        return true;
    }

    Ptr_de_no_de_lista_simples atual = l->primeiro;

    while (atual->proximo->proximo!=NULL)
        atual=atual->proximo;

    Ptr_de_no_de_lista_simples a_remover = atual->proximo;
    atual->proximo=NULL;
    free(a_remover->informacao);
    free(a_remover);
    return true;
}

unsigned int quantos_elementos (Lista_simples l)
{
    // criar um contador
    unsigned int contador = 0;
    
    // 1. Crie um "dedo" (ponteiro temporário)
    // 2. Comece pelo começo
    Ptr_de_no_de_lista_simples atual = l.primeiro;

    // 4. Crie um loop (enquanto não chegamos ao fim)
    while (atual != NULL)
    {
        // 5. Dentro do loop
        
        // Conte o nó atual
        contador++;
        
        // Avance para o próximo nó
        atual = atual->proximo;
    }

    // 7. Retorne o resultado
    return contador;
}

void imprimir_todos_itens_da_lista(Lista_simples l)
{
    //criar um ponetiro temporário
    Ptr_de_no_de_lista_simples atual = l.primeiro;

    while(atual != NULL)
    {
        printf("%d\n", *((int*)(atual->informacao)));

        //o avanço
        atual = atual->proximo;
    }

}

void free_lista_simples (Lista_simples* l)
{
    
}
