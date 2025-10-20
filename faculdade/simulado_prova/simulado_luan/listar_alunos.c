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

void Listar_todos_alunos(Aluno lista[], int tamanho)
{
    if (tamanho == 0)
    {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }

    printf("-----LISTA DE ALUNOS CADASTRADOS-----");

    for (int i=0; i<tamanho; i++)
    {
        printf("-------------------------------------\n");
        printf("Aluno [%d]\n", i+1);
        printf("Nome: %s\n", lista[i].nome);
        printf("ID: %d\n", lista[i].id);
        printf("Idade: %d\n", lista[i].idade);
    }
}

void professor_diciplina(int id, Turma turma_lista[], int qtd_turma)
{
    for(int c=0; c<qtd_turma; c++)
    {
        if(id == turma_lista[c].idProfessor)
        {
            printf("%s", turma_lista[c].disciplina);
        }
    }
}

int main()
{

    int idProfessor;
    Turma turmas[10000];
    int qtdTurma;

    professor_diciplina(idProfessor, turmas, qtdTurma);


    Aluno alunos[10000];
    int qtdAlunos = 0;
     
    Listar_todos_alunos(alunos, qtdAlunos);

    return 0;
}