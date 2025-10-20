#include <stdio.h>

typedef struct 
{
 int id; // identificador único do aluno
 char nome[50]; // nome do aluno
 int idade; // idade do aluno
} Aluno;

typedef struct 
{
 int id; // identificador único do professor
 char nome[50]; // nome do professor
} Professor;

typedef struct 
{
 int idAluno; // id do aluno
 float nota1; // primeira nota
 float nota2; // segunda nota
 float nota3; // terceira nota
} Nota;

typedef struct 
{
 int id; // identificador único da turma
 int idProfessor; // id do professor responsável (não é struct)
 char disciplina[50]; // nome da disciplina da turma
 int alunosTurma[50]; // vetor com os IDs dos alunos
 int qtdAlunos; // quantidade de alunos na turma
 Nota notas[50]; // vetor de notas (ligadas aos alunos)
 int qtdNotas; // quantidade de registros de notas
} Turma;

void media_notas_turma(Turma lista_turmas[], int qtd_turmas, int id_turma)
{

    float somaDasMedias = 0.0;

    for(int i=0; i<qtd_turmas; i++)
    {
        if(lista_turmas[i].id == id_turma)
        {
            for(int c=0; c<lista_turmas[i].qtdNotas; c++)
            {
                float nota_aluno = (nota_aluno + lista_turmas[i].notas[c].nota1 + lista_turmas[i].notas[c].nota2 + lista_turmas[i].notas[c].nota3);
                float media_das_notas = media_das_notas + nota_aluno;
            }
            float mediaDaTurma = somaDasMedias / lista_turmas[i].qtdNotas;

            printf("A media das notas da turma de %s eh %.2f", lista_turmas[i].disciplina, media_notas_turma);
        }
    }
}

int main()
{
    Turma turmas[1000];
    int qtd_turmas;
    int id_turma;

    media_notas_turma(turmas, qtd_turmas, id_turma);

    return 0;
}