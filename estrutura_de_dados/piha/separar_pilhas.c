/*
Olhar todos os itens da pilha p.

Se um item (que é um int*) for par, o seu ponteiro deve ser colocado na pilha pares.

Se for ímpar, o seu ponteiro deve ser colocado na pilha impares.

Regra Crucial 1: Ao final, a pilha p deve estar intacta (com todos os seus elementos).

Regra Crucial 2: Os itens em pares e impares devem estar na mesma ordem em que estavam em p.y 
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
// (Eu criei esta 'main' para testar sua função)
int main()
{
    // 1. Criar as 3 Pilhas
    Pilha p, pares, impares;
    nova_pilha (&p, 10); 
    nova_pilha (&pares, 10);
    nova_pilha (&impares, 10);
    
    // 2. Preencher a pilha 'p' (com a "Dança do Malloc")
    printf("Empilhando 6 itens: 10, 21, 30, 41, 50, 61\n");
    int* i1 = (int*)malloc(sizeof(int)); *i1 = 10; guarde_na_pilha(&p, (ElementoDePilha)i1);
    int* i2 = (int*)malloc(sizeof(int)); *i2 = 21; guarde_na_pilha(&p, (ElementoDePilha)i2);
    int* i3 = (int*)malloc(sizeof(int)); *i3 = 30; guarde_na_pilha(&p, (ElementoDePilha)i3);
    int* i4 = (int*)malloc(sizeof(int)); *i4 = 41; guarde_na_pilha(&p, (ElementoDePilha)i4);
    int* i5 = (int*)malloc(sizeof(int)); *i5 = 50; guarde_na_pilha(&p, (ElementoDePilha)i5);
    int* i6 = (int*)malloc(sizeof(int)); *i6 = 61; guarde_na_pilha(&p, (ElementoDePilha)i6);

    printf("\n--- Pilhas ANTES da separação ---\n");
    printf("Pilha P:");    imprimir_pilha_int(&p);
    printf("Pilha Pares:");  imprimir_pilha_int(&pares);
    printf("Pilha Impares:");imprimir_pilha_int(&impares);

    // --- Chamando a SUA função ---
    printf("\n>>> Chamando sua função 'separa_pilhas'...\n");
    separa_pilhas(&p, &pares, &impares);
    printf(">>> Separação concluída.\n");
    
    // --- Verificando os resultados ---
    printf("\n--- Pilhas DEPOIS da separação ---\n");
    printf("Pilha P (deve estar intacta):");    imprimir_pilha_int(&p);
    printf("Pilha Pares (deve ter 10, 30, 50):");  imprimir_pilha_int(&pares);
    printf("Pilha Impares (deve ter 21, 41, 61):");imprimir_pilha_int(&impares);

    // (Limpeza final: O 'main' é o "dono" dos dados (int*),
    // então ele deve libertar tudo. Como os ponteiros foram
    // duplicados em 'pares' e 'impares', só precisamos
    // limpar a pilha 'p' original)
    printf("\nLimpando memória...\n");
    ElementoDePilha temp;
    while(pilha_vazia(p) == false) {
        recupere_da_pilha(p, &temp);
        remova_elemento_da_pilha(&p);
        free(temp); // Libera os 'int*' que alocamos
    }
    free_pilha(&p);
    free_pilha(&pares);
    free_pilha(&impares);
    return 0;
}


// =======================================================
// --- SUA TAREFA: Implementar o Exercício 6 do PDF ---
// =======================================================
void separa_pilhas(Pilha* p, Pilha* pares, Pilha* impares)
{
    // 1. Crie a pilha auxiliar
    Pilha p_aux;
    nova_pilha(&p_aux, 1000); // (Capacidade grande temporária)
    
    ElementoDePilha dado_temp; // O "contêiner" genérico (void*)
    int* dado_int; // O ponteiro específico (int*)

    // --- Loop 1: Esvaziar 'p' e salvar em 'p_aux' (Inverte a ordem) ---
    printf("(Etapa 1: Esvaziando p -> p_aux)...\n");

    while(pilha_vazia(*p) == false)
    {
        //pegar o valor que está no topo e colocar na variavel
        recupere_da_pilha(*p, &dado_temp);
        //remover o valor que estava no topo
        remova_elemento_da_pilha(p);
        //guardar na pilha p_aux;
        guarde_na_pilha(&p_aux, dado_temp);//guarda os elementos da pilha p para a p_aux;
    }

    
    // --- Loop 2: Esvaziar 'p_aux', Restaurar 'p', e Distribuir ---
    printf("(Etapa 2: Esvaziando p_aux -> p, pares, impares)...\n");

    while(pilha_vazia(p_aux) == false)
    {
        //pegar o dado que está no topo e salvar na variavel dado_temp
        recupere_da_pilha(p_aux, &dado_temp);
        //excluir o elemento
        remova_elemento_da_pilha(&p_aux);
        //guardar na pilha p, para restaurá-la
        guarde_na_pilha(p, dado_temp);
        //converter valor para inteiro
        dado_int = (int*)dado_temp;
        //fazer a vericação se é par ou impar e jogar para a respectiva pilha
        if(*dado_int % 2 == 0)
        {
            guarde_na_pilha(pares, dado_temp);
        }
        else
        {
            guarde_na_pilha(impares, dado_temp);
        }
    }
    //limpar a pilha auxiliar
    free_pilha(&p_aux);
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
    if (p.qtd_atual==0) return false; 
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
void imprimir_pilha_int(Pilha* p) {
    Pilha p_aux;
    nova_pilha(&p_aux, 1000); 
    ElementoDePilha dado_temp;
    
    if (pilha_vazia(*p) == true) {
        printf(" (Pilha Vazia)\n");
        return;
    }
    
    printf(" BASE -> ");
    
    while (pilha_vazia(*p) == false) {
        recupere_da_pilha(*p, &dado_temp);
        remova_elemento_da_pilha(p);
        printf("[%d] ", *(int*)dado_temp); 
        guarde_na_pilha(&p_aux, dado_temp);
    }
    printf("<- TOPO\n");
    
    // Restaura P
    while (pilha_vazia(p_aux) == false) {
        recupere_da_pilha(p_aux, &dado_temp);
        remova_elemento_da_pilha(&p_aux);
        guarde_na_pilha(p, dado_temp);
    }
    free_pilha(&p_aux);
}