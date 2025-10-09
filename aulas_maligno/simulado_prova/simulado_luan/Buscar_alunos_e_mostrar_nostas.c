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


void mostrar_notas(int id_aluno, int id_turma, Turma lista_turmas[], int qtd_turmas,
Aluno lista_alunos[], int qtd_alunos)
{
    for (int i=0; i<qtd_alunos; i++)
    {
        if(id_aluno == lista_alunos[i].id)
        {
            for (int c=0; i<qtd_turmas; c++)
            {
                if(id_turma == lista_turmas[c].notas[c].idAluno)
                {
                    printf("O aluno: %s, da matéria: %s tem as seguintes notas:\n", lista_alunos[i].nome, lista_turmas[c].disciplina);
                    printf("Primeira nota: %.2f\n", lista_turmas[c].notas[c].nota1);
                    printf("Segunda nota: %.2f\n", lista_turmas[c].notas[c].nota2);
                    printf("Terceira nota: %.2f\n", lista_turmas[c].notas[c].nota3);
                }
            }
        }
    }
}

int main()
{
    int id_aluno;
    int id_turma;
    Turma turmas[1000];
    int qtd_turmas;
    Nota notas[1000];
    int qtd_notas;
    Aluno alunos[1000];
    int qtd_alunos;

    mostrar_notas(id_aluno, id_turma, turmas, qtd_turmas, alunos, qtd_alunos);

    return 0;
}