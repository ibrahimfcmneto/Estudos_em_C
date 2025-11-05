/*
criar um programa que cadastra uma turma de alunos.
O número de alunos não é fixo; o usuário irá decidi-lo
no início do programa.
*/

#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int ra;
    float nota;
    char nome[50];
};

void mostrar_alunos(struct Aluno *turma, int qtd_alunos)
{
    for(int i=0; i<qtd_alunos; i++) //está pegando os dados dos alunos da turma
    {
        printf("nome: %s\n", turma[i].nome);
        printf("RA: %d\n", turma[i].ra);
        printf("Nota: %f\n", turma[i].nota); 
    }
}


int main()
{
    struct Aluno *turma;
    int numero_alunos;

    printf("Numero de alunos: ");
    scanf("%d", &numero_alunos);

    turma = malloc(numero_alunos * sizeof(struct Aluno));

    if (turma == NULL)//se não tiver memoria suficiente
    {
        printf("Erro ao alocar memoria");
        return 1;
    }

    for(int i=0; i<numero_alunos; i++) //está pegando os dados dos alunos da turma
    {
        printf("RA: ");
        scanf("%d", &turma[i].ra);
        printf("Nota: ");
        scanf("%f", &turma[i].nota);
        getchar();
        printf("nome: ");
        fgets(turma[i].nome ,50, stdin);
        printf("-------------------------------\n");
    }

    mostrar_alunos(turma, numero_alunos);

    free(turma);

    return 0;
}