//arquivo onde tem todas as funções com as lógicas

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
    Ptr_de_no_de_lista_simples atual = l->primeiro;

    //variavel temporária
    Ptr_de_no_de_lista_simples proximo_no;

    while(atual != NULL)
    {
        
        free(atual->informacao);
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    l->primeiro = NULL;
}

boolean busca_inteiro_na_lista(Lista_simples l, int valor_procurado)
{
    Ptr_de_no_de_lista_simples atual = l.primeiro;
    

    boolean achou_valor = false;

    while(atual->informacao != NULL)
    {
        if (*((int*)(atual->informacao)) == valor_procurado)
        {
            achou_valor = true;
            return achou_valor;
        }

        atual = atual->proximo;
    }

    return achou_valor;
}

boolean listas_sao_iguais(Lista_simples l1, Lista_simples l2)
{
    Ptr_de_no_de_lista_simples atual1 = l1.primeiro;
    Ptr_de_no_de_lista_simples atual2 = l2.primeiro;
    
    boolean lista_iguais = true;
    //comparar a quantidade de elementos
    int qtd_elementos_l1 = quantos_elementos(l1);
    int qtd_elementos_l2 = quantos_elementos(l2);

    if(qtd_elementos_l1 != qtd_elementos_l2)
    {
        lista_iguais = false;
        return lista_iguais;
    }

    //comparar elemento por elemento
    while(atual1 != NULL)
    {
        if (*((int*)(atual1->informacao)) != *((int*)(atual2->informacao)))
        {
            lista_iguais = false;
            return lista_iguais;
        }

        //passo para pular para o próximo
        atual1 = atual1->proximo;
        atual2 = atual2->proximo;
    }

    return lista_iguais;

}