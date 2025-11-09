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
    Pilha pil;
    nova_pilha (&pil, 10); 
    
    // (Lógica do main.c do professor: alocar os dados)
    printf("Empilhando 5 itens: 10, 20, 30, 20, 40\n");
    int* i1 = (int*)malloc(sizeof(int)); *i1 = 10; guarde_na_pilha(&pil, (ElementoDePilha)i1);
    int* i2 = (int*)malloc(sizeof(int)); *i2 = 20; guarde_na_pilha(&pil, (ElementoDePilha)i2);
    int* i3 = (int*)malloc(sizeof(int)); *i3 = 30; guarde_na_pilha(&pil, (ElementoDePilha)i3);
    int* i4 = (int*)malloc(sizeof(int)); *i4 = 20; guarde_na_pilha(&pil, (ElementoDePilha)i4); // (Item duplicado)
    int* i5 = (int*)malloc(sizeof(int)); *i5 = 40; guarde_na_pilha(&pil, (ElementoDePilha)i5);

    printf("Pilha antes de remover:\n");
    imprimir_pilha_int(&pil); // Pilha: [10] [20] [30] [20] [40]

    // --- Perguntar ao usuário (como pede o PDF) ---
    int item_para_remover;
    printf("\nDigite o elemento que deseja excluir: ");
    scanf("%d", &item_para_remover);
    
    // --- Chamando a SUA função ---
    printf(">>> Chamando sua função para remover o item: %d\n", item_para_remover);
    
    boolean sucesso = remover_item_especifico(&pil, item_para_remover);
    
    // --- Informar o sucesso (como pede o PDF) ---
    if (sucesso == true) {
        printf(">>> SUCESSO! Item %d foi removido.\n", item_para_remover);
    } else {
        printf(">>> FALHA! Item %d não foi encontrado.\n", item_para_remover);
    }

    printf("\nPilha depois de remover:\n");
    imprimir_pilha_int(&pil); // (Deve ter removido a primeira ocorrência do item)

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
boolean remover_item_especifico(Pilha* p, int valor_procurado) 
{
    //criar um ponteiro auxiliar
    Pilha p_aux;
    nova_pilha(&p_aux, 1000);

    ElementoDePilha dado_temp;
    int* p_int;//variavel inteira
    boolean elemento_removido = false;

    while(pilha_vazia(*p) == false)
    {
        //pegar o valor que está no topo da pilha e salvar no p_aux;
        recupere_da_pilha(*p, &dado_temp);
        //excluir esse elemento da pilha original
        remova_elemento_da_pilha(p);
        //tranformar o numero em inteiro
        p_int = (int*)dado_temp;
        //fazer a comparação se é o item não adiciona na pilha auxiliar
        if(*p_int != valor_procurado)
        {
            guarde_na_pilha(&p_aux, dado_temp);//guardado os dados que são os diferentes do procurado
        }
        else
        {
            free(dado_temp);//caso seja o dado procurado, excluir ele
            elemento_removido = true;
        }
    }
    
    //voltar os valores para o ponteiro original sem o valor procurado
    while(pilha_vazia(p_aux) == false)
    {
        //pegar o valor que está no topo da p_aux e salvar no dado_temp
        recupere_da_pilha(p_aux, &dado_temp);
        //excluir o topo da pilha
        remova_elemento_da_pilha(&p_aux);
        //guardar elemento na pilha original
        guarde_na_pilha(&p, dado_temp);
    }
    //limpa a pilha auxiliar
    free_pilha(&p_aux);

    return elemento_removido;
}


// --- Início: Código do Professor (pilha.c) ---
// (Copiado aqui para o programa funcionar em um arquivo só)
boolean nova_pilha (Pilha* p, unsigned int capacidade) {
    if (capacidade<=0) return false;
    p->capacidade=capacidade;
    p->vetor=(ElementoDePilha*)malloc(capacidade*sizeof(ElementoDePilha));
    if (p->vetor == NULL) {
        printf("Falha no malloc do vetor da pilha!\n");
        return false; 
    }
    p->qtd_atual=0;
    return true;
}
boolean guarde_na_pilha (Pilha* p, ElementoDePilha e) {
    if (p->qtd_atual==p->capacidade) {
        printf("Erro: Pilha cheia!\n");
        return false; 
    }
    p->vetor[p->qtd_atual]=e;
    p->qtd_atual++;
    return true;
}
boolean recupere_da_pilha (Pilha p, ElementoDePilha* e) {
    if (p.qtd_atual==0) {
        // (Vamos silenciar este erro para o 'remover_item')
        return false; 
    }
    *e=p->vetor[p.qtd_atual-1]; 
    return true;
}
boolean remova_elemento_da_pilha (Pilha* p) {
    if (p.qtd_atual==0) {
        // (Vamos silenciar este erro para o 'remover_item')
        return false; 
    }
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