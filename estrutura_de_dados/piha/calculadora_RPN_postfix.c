#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definição simples de boolean ---
typedef enum { false, true } boolean;

// --- Definição simples de uma Pilha de INT ---
#define MAX_TAM 100

typedef struct {
    int itens[MAX_TAM];
    int topo;
} PilhaInt;

// --- Funções da Pilha (para você usar) ---
void nova_pilha(PilhaInt *p) { p->topo = -1; }
int pilha_vazia(PilhaInt p) { return (p.topo == -1); }
int pilha_cheia(PilhaInt p) { return (p.topo == MAX_TAM - 1); }
int empilhar(PilhaInt *p, int i) {
    if (pilha_cheia(*p)) return 0;
    p->topo++; p->itens[p->topo] = i;
    return 1;
}
int desempilhar(PilhaInt *p, int *i) {
    if (pilha_vazia(*p)) return 0;
    *i = p->itens[p->topo];
    p->topo--;
    return 1;
}
// --- Fim das funções da Pilha ---

boolean calcular_rpn(char* expressao, int* resultado_final)
{
    PilhaInt p;
    nova_pilha(&p);
    
    int i = 0;
    char char_atual;
    int val1, val2, res;

    while ( (char_atual = expressao[i]) != '\0' )
    {
        // esta condição é caso seja um numero
        //ai está trasformando ele em inteiro e empilhando
        if (char_atual >= '0' && char_atual <= '9')
        {
            //se for um nuero entre 0 e 9, converter ele para inteiro
            //e colocar na variavel valor
            int valor = char_atual - '0';//converte o numero pela tabela ASCII

            //empilhar o valor
            if(empilhar(&p, valor) == false)//caso não consiga empilhar
            {
                return false;
            }
        }
        // 2. É um OPERADOR?
        else if (char_atual == '+' || char_atual == '-' || char_atual == '*' || char_atual == '/')
        {
            if(desempilhar(&p, &val2) == false)
            {
                //caso de erro desempilhar o valor1
                return false;
            }
            if (desempilhar(&p, &val1) == false)
            {
                //caso de erro ao desempilhar o valor 2
                return false;
            }

            //fazer a operação
            switch(char_atual)
            {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/':
                    if (val2 == 0) return false; // Erro: Divisão por zero
                    res = val1 / val2; 
                    break;
            }

            //devolver o resultado para a pilha
            if(empilhar(&p, res) == false)
            {
                //caso de erro ao empilhar
                return false;
            }
        }
        // 3. É um ESPAÇO? (Ignore)
        else if (char_atual == ' ')
        {
            // Não faz nada
        }
        // 4. É um caractere inválido?
        else
        {
            return false; // Expressão malformada
        }
        
        i++; // Próximo caractere
    }

// Tenta desempilhar o resultado final. 
    // Note o uso de &res TEMPORARIAMENTE
    int resultado_temp;
    if(desempilhar(&p, &resultado_temp) == false)
    {
        // Falhou, significa que a pilha estava vazia (ex: string vazia)
        return false;
    }

    // Se desempilhou, a pilha TEM que estar vazia agora.
    // Se não estiver, é porque sobrou coisa (ex: "5 3")
    if (pilha_vazia(p) == false)
    {
        return false; // Erro, expressão malformada
    }

    // Se chegou aqui, deu tudo certo!
    *resultado_final = resultado_temp; // Copia o resultado para o ponteiro da main
    return true; // SUCESSO!
}

// --- Função main() para testar seu exercício ---
int main()
{
    printf("Iniciando teste da CALCULADORA RPN...\n\n");
    
    char* testes[] = {
        "5 3 +",       // 8
        "8 4 /",       // 2
        "9 5 -",       // 4
        "3 4 *",       // 12
        "5 3 2 + *",   // 5 * (3+2) = 25
        "8 2 / 3 +",   // (8/2) + 3 = 7
        "9 5 - 2 +",   // (9-5) + 2 = 6
        "5 3",         // Erro: muitos operandos
        "5 +",         // Erro: poucos operandos
        "8 0 /"        // Erro: divisão por zero
    };
    
    int num_testes = 10;
    int resultado;

    for (int i = 0; i < num_testes; i++) {
        if (calcular_rpn(testes[i], &resultado)) {
            printf("'%s' -> %d\n", testes[i], resultado);
        } else {
            printf("'%s' -> *** ERRO NA EXPRESSAO ***\n", testes[i]);
        }
    }

    return 0;
}