#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *vetor;
    int capacidade;
    int topo;
}Pilha;


Pilha* criar_pilha(int capacidade);
void destruir_pilha(Pilha *p);
void push(Pilha *p, char valor);
char pop(Pilha *p);
void imprimir(Pilha *p);


int main()
{
    char palavra[100];
    printf("--INVERSOR DE PALAVRAS--\n");
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);

    Pilha *p = criar_pilha(tamanho);

    if (p == NULL)
    {
        printf("Erro ao alocar memoria");
        return 1;
    }

    printf("Empilhando a palavra\n");

    for (int i=0; i<tamanho; i++)//vai fazer um push para cada letra
    {
        push(p, palavra[i]);
    }

    printf("Desempilhando a palavra\n");
    printf("A palavra ao contrario eh: ");
    for(int i=0; i<tamanho; i++)
    {
        char letra = pop(p);
        if(letra == '\0')
        {
            printf("pilha esta vazia");
            return;
        }
        printf("%c", letra);
    }

    free(p);

    return 0;
}

Pilha* criar_pilha(int capacidade)
{
    //alocar memoria para a pilha
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    //verificar se tem espaço na memoria
    if(p == NULL)
    {
        printf("Erro ao alocar memoria");
        return NULL;
    }
    
    //alocar o vetor char que está dentro da struct
    p->vetor = malloc(capacidade * sizeof(char));
    if(p->vetor == NULL)
    {
        printf("Erro ao alocar memoria para o vetor");
        free(p);
        return NULL;
    }

    p->capacidade = capacidade;
    p->topo = 0;

    return p;
}

//vai colocar cada letra na pilha
void push(Pilha *p, char valor)
{
    //verificar se o vetor está cheio
    if(p->topo == p->capacidade)
    {
        printf("vetor já está cheio");
        return;
    }

    //colocar o valor no vetor
    p->vetor[p->topo] = valor;
    //aumentar o topo
    p->topo++;
}

char pop(Pilha *p)
{
    //checar se tem contúdo dentro da pilha
    if(p->topo == 0)
    {
        return '\0';
    }

    //vai tirando de 1 em 1 do topo
    p->topo--;

    /*p->topo aponta para o próximo espaço livre, por isso primeiro você
    'volta' uma casa do topo para que realmente aponte para o último elemento*/

    //retorna o valor que está no topo
    return p->vetor[p->topo];
}