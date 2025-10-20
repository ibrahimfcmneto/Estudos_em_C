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

void nome_disciplina(Turma Lista_turmas[], int tamanho, int id_turma)
{
    for (int i=0; i<tamanho; i++)
    {
        if(id_turma == Lista_turmas[i].id)
            printf("A turma com id: %d eh: %s", id_turma, Lista_turmas[i].disciplina);
    }
}

int main()
{
    Turma turmas[1000];
    int tamanho_turma;
    int id_turma;

    nome_da_disciplina(turmas, tamanho_turma, id_turma);
    return 0;
}