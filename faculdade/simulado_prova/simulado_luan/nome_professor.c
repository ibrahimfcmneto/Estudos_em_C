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

void turmas_do_professor(Turma lista_turmas[], int turma_id, int qtd_turmas,
Professor lista_professores[], int qtd_professor)
{
    for (int i=0; i<qtd_turmas; i++)
    {
        if(turma_id == lista_turmas[i].id)
        {
            for(int c=0; c<qtd_professor; c++)
            {
                if(lista_turmas[i].idProfessor == lista_professores[c].id)
                printf("%s", lista_professores[c].nome);
            }
        }
    }
}

int main()
{
    int id_turma;
    Turma turmas[10000];
    int qtd_turmas;
    Professor professores[1000];
    int qtd_professor;
    
    turmas_do_professor(turmas, id_turma, qtd_turmas, professores, qtd_professor);
    return 0;
}