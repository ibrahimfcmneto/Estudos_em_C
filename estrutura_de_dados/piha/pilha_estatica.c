#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vetor;      // O ponteiro para o vetor (a "prateleira")
    int capacidade;  // O tamanho MÁXIMO da prateleira
    int topo;        // O índice do *próximo* espaço livre
                     // (Equivalente ao 'qtd_atual' do seu professor)
} Pilha;


// --- Protótipos (O "Cardápio") ---
Pilha* criar_pilha(int capacidade);
void destruir_pilha(Pilha *p);
void push(Pilha *p, int valor); // Push (guarde)
int pop(Pilha *p);             // Pop (remova)
void imprimir(Pilha *p);


int main() {
    
    // 1. Cria uma pilha com capacidade para 5 números
    Pilha *minhaPilha = criar_pilha(5);
    
    if (minhaPilha == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    int n, opcao;
    
    do {
        printf("\n--- PILHA ESTÁTICA DE 'INT' (Base) ---\n");
        printf("1) Empilhar (Push)\n");
        printf("2) Desempilhar (Pop)\n");
        printf("3) Imprimir\n");
        printf("0) Sair e Destruir\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor (int) para empilhar: ");
                scanf("%d", &n);
                push(minhaPilha, n);
                break;
            
            case 2:
                int valorRemovido = pop(minhaPilha);
                if (valorRemovido != -9999) { // (Nosso código de erro)
                    printf(">>> VALOR REMOVIDO: %d\n", valorRemovido);
                }
                break;
            
            case 3:
                imprimir(minhaPilha);
                break;
            
            case 0:
                printf("Destruindo a pilha...\n");
                destruir_pilha(minhaPilha);
                break;
        }
    } while (opcao != 0);

    return 0;
}


// --- TAREFA 1: O "Construtor" (Equivalente a 'nova_pilha') ---
Pilha* criar_pilha(int capacidade) {
    
    // 1. Aloque memória para a ESTRUTURA da Pilha
    //    (A "caixa" que guarda o vetor, a capacidade e o topo)
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    
    // 2. Cheque se 'p' (a caixa) falhou
    if (p == NULL) {
        printf("Erro de alocação da estrutura da Pilha!\n");
        return NULL;
    }
    
    // 3. Aloque memória para o VETOR de inteiros
    p->vetor = (int *)malloc(capacidade * sizeof(int));
    
    // 4. Cheque se o 'p->vetor' (a prateleira) falhou
    if(p->vetor == NULL)
    {
        printf("Erro ao alocar memoria para o vetor interno");
        free(p);
        return NULL;
    }

    
    // 5. Inicialize os valores da pilha
    p->capacidade = capacidade;
    p->topo = 0;
    
    // 6. Retorne o ponteiro para a Pilha pronta
    return p;
}


// --- TAREFA 2: O "Push" (Equivalente a 'guarde_na_pilha') ---
void push(Pilha *p, int valor) {
    
    //verificar se a pilha está cheia
    if(p->topo == p->capacidade)
    {
        printf("Pilha cheia, capacidade: %d", p->capacidade);
        return;
    }

    //adicionar valor ao vetor na posição topo
    p->vetor[p->topo] = valor;

    // 3. Incremente o 'topo' (para apontar para o próximo espaço livre)
    p->topo++;
    
    // 4. Imprima uma mensagem de sucesso
    printf("Valor %d empilhado com sucesso!", valor);
}


// --- TAREFA 3: O "Pop" (Equivalente a 'remova_elemento_da_pilha') ---
int pop(Pilha *p) {
    
    // 1. Verifique se a pilha está VAZIA
    if(p->topo == 0)
    {
        printf("pilha está vazia");
        return -9999;
    }
    
    // 2. Se houver itens, decremente o 'topo' PRIMEIRO
    p->topo--;

    // 3. Retorne o valor que estava no (agora) 'topo'
    return p->vetor[p->topo];

}


// --- TAREFA 4: O "Imprimir" (Não tem no seu professor, mas é essencial) ---
void imprimir(Pilha *p) {
    
    printf("\n--- CONTEÚDO DA PILHA (Base=0) ---\n");
    
    // 1. Cheque se está vazia (if (p->topo == 0) ...)
    if(p->topo == 0)
    {
        printf("Erro, pilha está vazia");
        return;
    }
    
    // 2. Se não estiver vazia, faça um loop 'for'
    for(int i=0; i<p->topo; i++)
    {
        printf("[%d]", p->vetor[i]);
    }
    
    // 3. Imprima onde está o topo
    printf("Próximo indice livre [topo]: %d", p->topo);
}


// --- TAREFA 5: O "Destrutor" (Equivalente a 'free_pilha') ---
void destruir_pilha(Pilha *p) {
    
    // 1. Libere a memória do VETOR (o malloc de dentro)
    free(p->vetor);
    
    // 2. Libere a memória da ESTRUTURA da Pilha (o malloc de fora)
    free(p);
}

int testa_pilha(int *v, int n)
{
    
}