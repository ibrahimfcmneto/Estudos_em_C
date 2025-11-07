#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node *prox; //ponteiro para o nó de baixo;
}celula;

//ponteiro que vai sempre apontar para o topo da pilha, por isso começar NULL;
celula *top = NULL;

//declarando as funções para compilar certo;
void push(int dado);
void pop();
void imprimir();


int main()
{
    int n, opcao;
    
    do
    {
        printf("\n---Escolha uma das opcoes:---");
        printf("\n1) Adicionar dado");
        printf("\n2) Remover dado");
        printf("\n3) Imprimir dados");
        printf("\n999) Sair do programa");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("Digite um numero inteiro: ");
                scanf("%d", &n);
                push(n);//chama a função para colocar na pilha
                break;

            case 2:
                pop();
                break;

            case 3:
                imprimir();
                break;
            
            case 999:
                printf("Fim do programa!");
                return;
            
            default:
                printf("Opcao invalida!");
        }

    }
    while (opcao != 999);

    return 0;
}

void push(int valor)
{
    //alocar memoria para entrar o dado
    celula *novo = malloc(sizeof(celula));//aloca um espaço na memoria do tamanho da celula

    //checagem se tem espaço na memória
    if(novo == NULL)
    {
        printf("Erro ao alocar memória");
        return;
    }

    //alocar o dado
    novo->dado = valor;
    //prox do novo nó aponta para o antigo
    novo->prox = top;
    //mover a ancora, agora o top global é o novo
    top = novo;
}

void pop()
{
    if(top == NULL)//se no top não tem nada quer dizer que está vazia
    {
        printf("Erro ao alocar memoria");
        return;
    }
    //caso a pilha não esteja vazia
    //criar um vetor temporário
    celula *temp = top;

    //guardar o dado que vai ser removido
    int dadoRemovido = temp->dado;

    //mover a ancora do topo para baixo
    top = top->prox;

    //iberar a memória do nó que foi removido
    free(temp);

    //retornar o dado removido
    return dadoRemovido;
}

void imprimir()
{
    printf("imprimir");
}