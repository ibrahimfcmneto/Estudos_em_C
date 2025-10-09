#include <stdio.h>

#define MEDIA_APROVACAO 7.0
#define NOTA_MINIMA 6.0


typedef struct {
    int id;
    char nome[50];
    float notas[4]; // Um vetor para as 4 notas do ano
} Aluno;

typedef struct {
    char nome_turma[50];
    Aluno lista_alunos[10];
    int num_alunos_cadastrados; // Controla quantos alunos realmente existem na lista
} Turma;

void selecionarAlunosAprovados (Turma* turma_base, Aluno lista_aprvados[], int*contador_aprovados)
{
    printf(turma_base->nome_turma);
}

int main()
{
    selecionarAlunosAprovados();
}