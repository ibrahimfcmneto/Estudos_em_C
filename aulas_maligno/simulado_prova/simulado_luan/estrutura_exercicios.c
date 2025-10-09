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

int main()
{
    return 0;
}