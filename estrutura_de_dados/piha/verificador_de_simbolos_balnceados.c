#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definição simples de boolean (se não tiver seu basics.h) ---
typedef enum { false, true } boolean;

// --- Definição simples de uma Pilha de Char ---
#define MAX_TAM 100

typedef struct {
    char itens[MAX_TAM];
    int topo;
} PilhaChar;

// --- Funções da Pilha (para você usar) ---
void nova_pilha(PilhaChar *p) { p->topo = -1; }
int pilha_vazia(PilhaChar p) { return (p.topo == -1); }
int pilha_cheia(PilhaChar p) { return (p.topo == MAX_TAM - 1); }
int empilhar(PilhaChar *p, char c) {
    if (pilha_cheia(*p)) return 0;
    p->topo++; p->itens[p->topo] = c;
    return 1;
}
int desempilhar(PilhaChar *p, char *c) {
    if (pilha_vazia(*p)) return 0;
    *c = p->itens[p->topo];
    p->topo--;
    return 1;
}
// --- Fim das funções da Pilha ---


/*
 * Função auxiliar para verificar se um par (abertura, fechamento) combina.
 */
boolean combina(char aberto, char fechado) {
    if (aberto == '(' && fechado == ')') return true;
    if (aberto == '[' && fechado == ']') return true;
    if (aberto == '{' && fechado == '}') return true;
    return false;
}


/*
 * Verifica se uma expressão tem símbolos balanceados.
 */
boolean esta_balanceado(char* expressao)
{
    PilhaChar p;
    nova_pilha(&p);
    
    int i = 0;
    char char_atual;
    char char_do_topo;

    //rodar cada elemento da expressão
    while ( (char_atual = expressao[i]) != '\0' )
    {
        // verificar se é um simbolo de abertura
        if (char_atual == '(' || char_atual == '[' || char_atual == '{')
        {
            //verificar se a pilha está cheia
            if(pilha_cheia(p) == true)
            {
                printf("Pilha cheia");
                return false;
            }
            //caso a pilha não esteja cheia, guardar o elemento no char atual
            empilhar(&p, char_atual);
        }

        // caso seja um simbolo de fechamento
        else if (char_atual == ')' || char_atual == ']' || char_atual == '}')
        {
            //verificar se a pilha está vazia
            if(pilha_vazia(p) == true)
            {
                return false;
            }
            //caso a pilha não esteje vazia
            //vai pegar o elemento da pilha p e colocar na char_topo
            desempilhar(&p, &char_do_topo);
            //ver se o par combina usando a função combina
            if (combina(char_do_topo, char_atual) == false)
            {
                return false;
            }
        }   
        i++; // Vai para o próximo caractere
    }
    return pilha_vazia(p);
}


// --- Função main() para testar seu exercício ---
int main()
{
    printf("Iniciando teste do BALANCEAMENTO...\n\n");
    
    char* testes[] = {
        "minha_funcao(a[0])",    // true
        "({[]})",                // true
        "()",                    // true
        "(]",                     // false
        "([)]",                   // false
        "{ ( )",                  // false
        "}",                     // false
        "int x = { (a+b) * (c[i]) };" // true
    };
    
    int num_testes = 8;

    for (int i = 0; i < num_testes; i++) {
        if (esta_balanceado(testes[i]))
            printf("'%s' -> BALANCEADO\n", testes[i]);
        else
            printf("'%s' -> *** ERRO ***\n", testes[i]);
    }

    return 0;
}