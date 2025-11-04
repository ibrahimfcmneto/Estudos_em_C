#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 1000

// ------------------ Estruturas ------------------

typedef struct {
    double itens[MAX];
    int topo;
} Pilha;

typedef struct {
    char itens[MAX][50];
    int frente, tras;
} Fila;

// ------------------ Pilha ------------------

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, double valor) {
    p->itens[++p->topo] = valor;
}

double desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }
    return p->itens[p->topo--];
}

double topoPilha(Pilha *p) {
    if (pilhaVazia(p)) return 0;
    return p->itens[p->topo];
}

// ------------------ Fila ------------------

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

int filaVazia(Fila *f) {
    return f->frente > f->tras;
}

void enfileirar(Fila *f, char *valor) {
    strcpy(f->itens[++f->tras], valor);
}

char* desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: fila vazia.\n");
        exit(1);
    }
    return f->itens[f->frente++];
}

// ------------------ Funções auxiliares ------------------

int prioridade(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// ------------------ Etapa 1: Tokenização ------------------

void quebrarExpressao(char *expr, Fila *entrada) {
    char token[50];
    int i = 0, j = 0;

    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            j = 0;
            while (isdigit(expr[i]) || expr[i] == '.') {
                token[j++] = expr[i++];
            }
            token[j] = '\0';
            enfileirar(entrada, token);
            continue;
        }
        else if (ehOperador(expr[i]) || expr[i] == '(' || expr[i] == ')') {
            token[0] = expr[i];
            token[1] = '\0';
            enfileirar(entrada, token);
        }
        else if (!isspace(expr[i])) {
            printf("Erro: caractere inválido '%c'.\n", expr[i]);
            exit(1);
        }
        i++;
    }
}

// ------------------ Etapa 2: Infixa -> Pós-fixa ------------------

void converterPosfixa(Fila *entrada, Fila *saida) {
    Pilha operadores;
    inicializarPilha(&operadores);

    while (!filaVazia(entrada)) {
        char *token = desenfileirar(entrada);

        if (isdigit(token[0])) {
            enfileirar(saida, token);
        } 
        else if (token[0] == '(') {
            empilhar(&operadores, '(');
        } 
        else if (token[0] == ')') {
            while (!pilhaVazia(&operadores) && topoPilha(&operadores) != '(') {
                char temp[2] = {(char)desempilhar(&operadores), '\0'};
                enfileirar(saida, temp);
            }
            desempilhar(&operadores); // remove '('
        } 
        else if (ehOperador(token[0])) {
            while (!pilhaVazia(&operadores) &&
                   prioridade((char)topoPilha(&operadores)) >= prioridade(token[0]) &&
                   (token[0] != '^' || prioridade((char)topoPilha(&operadores)) > prioridade(token[0]))) {
                char temp[2] = {(char)desempilhar(&operadores), '\0'};
                enfileirar(saida, temp);
            }
            empilhar(&operadores, token[0]);
        }
    }

    while (!pilhaVazia(&operadores)) {
        char temp[2] = {(char)desempilhar(&operadores), '\0'};
        enfileirar(saida, temp);
    }
}

// ------------------ Etapa 3: Avaliar Pós-fixa ------------------

double avaliarPosfixa(Fila *posfixa) {
    Pilha valores;
    inicializarPilha(&valores);

    while (!filaVazia(posfixa)) {
        char *token = desenfileirar(posfixa);

        if (isdigit(token[0])) {
            empilhar(&valores, atof(token));
        } else if (ehOperador(token[0])) {
            double b = desempilhar(&valores);
            double a = desempilhar(&valores);
            double res;

            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Erro: divisão por zero.\n");
                        exit(1);
                    }
                    res = a / b;
                    break;
                case '^': res = pow(a, b); break;
                default: res = 0; break;
            }
            empilhar(&valores, res);
        }
    }

    return desempilhar(&valores);
}

// ------------------ Principal -------------------

int main() {
    char expressao[MAX];
    Fila entrada, posfixa;

    inicializarFila(&entrada);
    inicializarFila(&posfixa);

    printf("Digite a expressao: ");
    fgets(expressao, MAX, stdin);
    expressao[strcspn(expressao, "\n")] = 0;

    quebrarExpressao(expressao, &entrada);
    converterPosfixa(&entrada, &posfixa);

    double resultado = avaliarPosfixa(&posfixa);
    printf("Resultado: %.2lf\n", resultado);

    return 0;
}
