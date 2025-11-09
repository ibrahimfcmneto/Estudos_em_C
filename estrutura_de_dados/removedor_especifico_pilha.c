/*
Implementar a função boolean remover_item(Pilha* p, int valor_procurado)

Esta função deve:

Receber a pilha p e um valor_procurado (ex: 20).

Procurar na pilha pelo item com esse valor.

Se o encontrar, deve removê-lo e libertar a sua memória (free).

Importante: Todos os outros itens devem permanecer na pilha, na mesma ordem em que estavam.

Retornar true se encontrou e removeu, ou false se não encontrou.
*/
#include <stdio.h>
#include <stdlib.h>

// --- Início: Código do Professor (basics.h) ---
typedef enum {
    false,
    true
} boolean;
// --- Fim: Código do Professor (basics.h) ---


// --- Início: Código do Professor (pilha.h) ---
typedef void* ElementoDePilha; // A pilha guarda ponteiros genéricos

typedef struct {
    ElementoDePilha* vetor;
    unsigned int capacidade;
    unsigned int qtd_atual; // O "topo"
} Pilha;

boolean nova_pilha (Pilha* p, unsigned int capacidade);
boolean guarde_na_pilha (Pilha* p, ElementoDePilha e);
boolean recupere_da_pilha (Pilha p, ElementoDePilha* e);
boolean remova_elemento_da_pilha (Pilha* p);
boolean pilha_vazia (Pilha p);
boolean free_pilha (Pilha* p);
// --- Fim: Código do Professor (pilha.h) ---


// --- Função Auxiliar (Para nos ajudar a ver a pilha) ---
void imprimir_pilha_int(Pilha* p);


// --- O "Cliente" (main.c) ---
int main()
{
    Pilha pil;
    nova_pilha (&pil, 10); 
    
    // (Lógica do main.c do professor: alocar os dados)
    printf("Empilhando 4 itens: 10, 20, 30, 40\n");
    int* i1 = (int*)malloc(sizeof(int)); *i1 = 10;
    guarde_na_pilha(&pil, (ElementoDePilha)i1);
    
    int* i2 = (int*)malloc(sizeof(int)); *i2 = 20;
    guarde_na_pilha(&pil, (ElementoDePilha)i2);
    
    int* i3 = (int*)malloc(sizeof(int)); *i3 = 30;
    guarde_na_pilha(&pil, (ElementoDePilha)i3);

    int* i4 = (int*)malloc(sizeof(int)); *i4 = 40;
    guarde_na_pilha(&pil, (ElementoDePilha)i4);

    printf("Pilha antes de remover:\n");
    imprimir_pilha_int(&pil); // Pilha: [10] [20] [30] [40]

    // --- Chamando a SUA função ---
    int item_para_remover = 30;
    printf("\n>>> Chamando sua função para remover o item: %d\n", item_para_remover);
    
    boolean sucesso = remover_item(&pil, item_para_remover);
    
    if (sucesso == true) {
        printf(">>> SUCESSO! Item %d foi removido.\n", item_para_remover);
    } else {
        printf(">>> FALHA! Item %d não foi encontrado.\n", item_para_remover);
    }

    printf("\nPilha depois de remover:\n");
    imprimir_pilha_int(&pil); // Pilha deve ser: [10] [20] [40]

    // (Limpeza final)
    ElementoDePilha temp;
    while(pilha_vazia(pil) == false) {
        recupere_da_pilha(pil, &temp);
        remova_elemento_da_pilha(&pil);
        free(temp); // Libera os 'int*' que sobraram
    }
    free_pilha(&pil);
    return 0;
}


// =======================================================
// --- SUA TAREFA: Implementar o Exercício 7 do PDF ---
// =======================================================
boolean remover_item(Pilha* p, int valor_procurado) 
{
    // (Atenção: 'p' é a pilha original)
    // REGRA: Só pode usar os "botões" (funções) da pilha.
    
    // 1. Crie a pilha auxiliar
    Pilha p_aux;
    nova_pilha(&p_aux, 1000); // (Capacidade grande temporária)
    
    boolean achou_item = false;
    ElementoDePilha dado_temp; // O "contêiner" genérico (void*)
    int* dado_int; // O ponteiro específico (int*)

    // --- Loop 1: Esvaziar 'p', procurar, e salvar em 'p_aux' ---
    printf("(Procurando... Loop 1: Esvaziando p -> p_aux)\n");

    //chama essa função para ver se a pilha está vazia
    //esse while é para ir rodadndo até pilha_vazia ser true e sair do loop
    while (pilha_vazia(*p) == false)
    {
        //colocar o dado que vai ser removido na variavel dado_temp
        recupere_da_pilha(*p, &dado_temp); 

        //remover o dado que já foi guardado
        remova_elemento_da_pilha(p);

        //converter dado_temp para inteiro
        //a variavel dado_int está com o dado que foi removido
        dado_int = (int*)dado_temp;

        //verificar se esse dado é o que está procurando
        //se não for o procurado joga para o vetor
        if(*dado_int == valor_procurado && achou_item == false)
        {
            //se entrou nessa condição é porque o dado int é o procurado
            //por isso ele vai ser excluido
            free(dado_int);
            achou_item=true;
        }
        else
        {                           //conversão de tipo de dado: o dado_int passa a ser ElementoDePilha
            guarde_na_pilha(&p_aux, (ElementoDePilha)dado_int);
        }

    }
    
    // --- Loop 2: Restaurar 'p' ---
    printf("(Restaurando pilha original... Loop 2: p_aux -> p)\n");

    while(pilha_vazia(p_aux) == false)
    {
        //guardar o dado que vai ser removido na dado_temp
        recupere_da_pilha(p_aux, &dado_temp);

        //remover o elemento que foi guardado
        remova_elemento_da_pilha(&p_aux);

        //converter dado_temp para inteiro
        dado_int = (int*)dado_temp;

        //guardar o dado de volta no vetor p
        guarde_na_pilha(p, (ElementoDePilha)dado_int);
    }

    //liberar a memoria da pilha auxiliar
    free_pilha(&p_aux);

    //retornar true
    return achou_item; 
}


// --- Início: Código do Professor (pilha.c) ---
// (Copiado aqui para o programa funcionar em um arquivo só)
boolean nova_pilha (Pilha* p, unsigned int capacidade) {
    if (capacidade<=0) return false;
    p->capacidade=capacidade;
    p->vetor=(ElementoDePilha*)malloc(capacidade*sizeof(ElementoDePilha));
    if (p->vetor == NULL) return false; 
    p->qtd_atual=0;
    return true;
}
boolean guarde_na_pilha (Pilha* p, ElementoDePilha e) {
    if (p->qtd_atual==p->capacidade) return false; 
    p->vetor[p->qtd_atual]=e;
    p->qtd_atual++;
    return true;
}
boolean recupere_da_pilha (Pilha p, ElementoDePilha* e) {
    if (p.qtd_atual==0) return false; 
    *e=p.vetor[p.qtd_atual-1]; 
    return true;
}
boolean remova_elemento_da_pilha (Pilha* p) {
    if (p->qtd_atual==0) return false; 
    p->qtd_atual--; 
    p->vetor[p->qtd_atual]=NULL;
    return true;
}
boolean pilha_vazia (Pilha p) {
    return p.qtd_atual==0;
}
boolean free_pilha (Pilha* p) {
    if (p->vetor==NULL) return false;
    free(p->vetor); 
    p->vetor = NULL;
    p->capacidade = 0;
    p->qtd_atual = 0;
    return true;
}
// --- Fim: Código do Professor (pilha.c) ---


// --- Função Auxiliar (Para checar se 'p' ficou intacta) ---
// (Esta função também usa a "Manobra da Pilha Auxiliar")
void imprimir_pilha_int(Pilha* p) {
    Pilha p_aux;
    nova_pilha(&p_aux, 1000); 
    ElementoDePilha dado_temp;
    
    printf("BASE -> ");
    
    // Loop 1: Esvazia P, Imprime, e Salva em P_AUX
    while (pilha_vazia(*p) == false) {
        recupere_da_pilha(*p, &dado_temp);
        remova_elemento_da_pilha(p);
        printf("[%d] ", *(int*)dado_temp); 
        guarde_na_pilha(&p_aux, dado_temp);
    }
    printf("<- TOPO\n");
    
    // Loop 2: Restaura P
    while (pilha_vazia(p_aux) == false) {
        recupere_da_pilha(p_aux, &dado_temp);
        remova_elemento_da_pilha(&p_aux);
        guarde_na_pilha(p, dado_temp);
    }
    free_pilha(&p_aux);
}
