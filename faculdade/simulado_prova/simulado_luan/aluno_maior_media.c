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

void notas_aluno(Turma lista_turmas[], int qtd_turmas, int id_turma,
Aluno lista_alunos[], int qtd_alunos, int id_aluno)
{
    for(int i=0; i<qtd_turmas; i++)
    {
        if (lista_turmas[i].id == id_turma) //acha a turma
        {
            for(int c=0; c<lista_turmas[i].qtdNotas; c++)
            {
                if (lista_turmas[i].notas[c].idAluno == id_aluno) // acha o aluno dentro da turma
                {
                    printf("Primeira nota: %f", lista_turmas[i].notas[c].nota1);
                    printf("Segunda nota: %f", lista_turmas[i].notas[c].nota2);
                    printf("Terceira nota: %f", lista_turmas[i].notas[c].nota3);
                }
            }
        }
    }
}

int main()
{
    Turma turmas[10000];
    int qtd_turmas;
    int id_turma;
    Aluno alunos[10000];
    int qtd_alunos;
    int id_aluno;

    notas_aluno(turmas, qtd_turmas, id_turma, alunos, qtd_alunos, id_aluno);

    return 0;
}