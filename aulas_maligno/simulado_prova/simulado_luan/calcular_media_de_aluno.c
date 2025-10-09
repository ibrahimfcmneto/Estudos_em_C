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

void medias_notas_alunos(Aluno lista_alunos[], int qtd_alunos, Nota lista_notas[], int qtd_notas, char nome_aluno[])
{
 
    for(int c=0; c<qtd_alunos; c++)
    {
        if (strcmp(lista_alunos[c].nome, nome_aluno) == 0)
        {
            int id_aluno = lista_alunos[c].id;

            for (int i=0; i<qtd_notas; i++)
            {
                if(lista_notas[i].idAluno == id_aluno)
                {
                    printf("Primeira nota: %.2f", lista_notas[i].nota1);
                    printf("Segunda nota: %.2f", lista_notas[i].nota2);
                    printf("Terceira nota: %.2f", lista_notas[i].nota3);
                }
            }
        }
    }
}

int main()
{
    Aluno alunos[1000];
    int qtd_alunos;
    Nota notas[1000];
    int qtd_notas;
    char nome_aluno[50];

    media_notas_aluno(alunos, qtd_alunos, notas, qtd_notas, nome_aluno);

    return 0;
}