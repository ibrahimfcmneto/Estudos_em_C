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
    // 1. Criar as Pilhas
    Pilha p1, p2, p3;
    nova_pilha (&p1, 10); 
    nova_pilha (&p2, 10);
    nova_pilha (&p3, 10); // (p3 será diferente)
    
    // 2. Preencher as pilhas (com a "Dança do Malloc")
    printf("Preenchendo p1 e p2 (iguais)...\n");
    int* i1 = (int*)malloc(sizeof(int)); *i1 = 10;
    guarde_na_pilha(&p1, (ElementoDePilha)i1);
    int* i2 = (int*)malloc(sizeof(int)); *i2 = 10;
    guarde_na_pilha(&p2, (ElementoDePilha)i2);
    
    int* i3 = (int*)malloc(sizeof(int)); *i3 = 20;
    guarde_na_pilha(&p1, (ElementoDePilha)i3);
    int* i4 = (int*)malloc(sizeof(int)); *i4 = 20;
    guarde_na_pilha(&p2, (ElementoDePilha)i4);
    
    printf("Preenchendo p3 (diferente)...\n");
    int* i5 = (int*)malloc(sizeof(int)); *i5 = 10;
    guarde_na_pilha(&p3, (ElementoDePilha)i5);
    int* i6 = (int*)malloc(sizeof(int)); *i6 = 99; // <--- Valor diferente
    guarde_na_pilha(&p3, (ElementoDePilha)i6);


    // --- Chamando a SUA função ---
    
    // Teste 1: p1 vs p2 (Devem ser iguais)
    printf("\n>>> Teste 1: Comparando P1 e P2 (devem ser iguais)...\n");
    boolean teste1 = sao_iguais(&p1, &p2);
    if (teste1 == true) {
        printf(">>> SUCESSO! 'sao_iguais' disse que P1 e P2 são iguais.\n");
    } else {
        printf(">>> FALHA! 'sao_iguais' disse que P1 e P2 são diferentes.\n");
    }

    // Teste 2: p1 vs p3 (Devem ser diferentes)
    printf("\n>>> Teste 2: Comparando P1 e P3 (devem ser diferentes)...\n");
    boolean teste2 = sao_iguais(&p1, &p3);
    if (teste2 == false) {
        printf(">>> SUCESSO! 'sao_iguais' disse que P1 e P3 são diferentes.\n");
    } else {
        printf(">>> FALHA! 'sao_iguais' disse que P1 e P3 são iguais.\n");
    }
    
    // Teste 3: Checar se as pilhas originais estão intactas
    printf("\n>>> Teste 3: Verificando se P1 foi restaurada...\n");
    imprimir_pilha_int(&p1); // (Deve mostrar 10 e 20)


    // (Limpeza final: O 'main' é o "dono" dos dados (int*),
    // ele deve libertar tudo. p2 e p3 só têm cópias dos
    // ponteiros, então só precisamos limpar 'p1'.)
    
    printf("\nLimpando memória...\n");
    ElementoDePilha temp;
    while(pilha_vazia(p1) == false) {
        recupere_da_pilha(p1, &temp);
        remova_elemento_da_pilha(&p1);
        free(temp); // Libera os 'int*' que alocamos para p1
    }
    while(pilha_vazia(p2) == false) { // (Temos que esvaziar p2 e p3)
        recupere_da_pilha(p2, &temp);
        remova_elemento_da_pilha(&p2);
        free(temp); // Libera os 'int*' que alocamos para p2
    }
    while(pilha_vazia(p3) == false) {
        recupere_da_pilha(p3, &temp);
        remova_elemento_da_pilha(&p3);
        free(temp); // Libera os 'int*' que alocamos para p3
    }
    
    free_pilha(&p1);
    free_pilha(&p2);
    free_pilha(&p3);
    return 0;
}


// =======================================================
// --- SUA TAREFA: Implementar o Exercício 4 do PDF ---
// =======================================================
boolean sao_iguais(Pilha* p1, Pilha* p2)
{
    //criar dois ponteiros auxiliares
    Pilha p_aux1;
    nova_pilha(&p_aux1, 1000);
    Pilha p_aux2;
    nova_pilha(&p_aux2, 1000);

    boolean pilhas_iguais = true;
    ElementoDePilha dado_temp1;
    int* dado_int1;
    ElementoDePilha dado_temp2;
    int* dado_int2;
    
    //fazer os while para comparar se as pilhas são iguais
    while(pilha_vazia(*p1) == false && pilha_vazia(*p2) == false)
    {
        //retirar os elementos do topo de cada pilha
        //nessa função manda a pilha e onde é para guardar o elemento
        recupere_da_pilha(*p1, &dado_temp1);
        recupere_da_pilha(*p2, &dado_temp2);
        //remover os elementos da pilha principal
        remova_elemento_da_pilha(p1);
        remova_elemento_da_pilha(p2);
        //guardar nas pilhas auxiliares
        guarde_na_pilha(&p_aux1, (ElementoDePilha)dado_temp1);
        guarde_na_pilha(&p_aux2, (ElementoDePilha)dado_temp2);
        //convertendo os dados_temp para inteiros
        dado_int1 = (int*)dado_temp1;
        dado_int2 = (int*)dado_temp2;
        //comparando os dois numeros
        if(*dado_int1 != *dado_int2)//caso os numeros seja diferentes
        {
            pilhas_iguais = false;//flag para indicar que as pilhas não são iguais
        }
    }

    //verificar caso elas sejam de tamanhos diferentes
    if(pilha_vazia(*p1) == false || pilha_vazia(*p2) == false)
    {
        pilhas_iguais = false;
    }


    // --- Loop 2: Restaurar p1 ---
    while(pilha_vazia(p_aux1) == false)
    {
        recupere_da_pilha(p_aux1, &dado_temp1);
        remova_elemento_da_pilha(&p_aux1);
        guarde_na_pilha(p1, dado_temp1);
    }
    
    // --- Loop 3: Restaurar p2 ---
    while(pilha_vazia(p_aux2) == false)
    {
        recupere_da_pilha(p_aux2, &dado_temp2);
        remova_elemento_da_pilha(&p_aux2);
        guarde_na_pilha(p2, dado_temp2);
    }

    free_pilha(&p_aux1);
    free_pilha(&p_aux2);

    return pilhas_iguais;
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