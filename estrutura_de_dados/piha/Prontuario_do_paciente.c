/*
criar um programa que cadastra um paciente. A criação (alocação)
e o preenchimento devem ser feitos em uma função "fábrica" separada,
e todo acesso aos dados deve usar o operador ->
*/

#include <stdio.h>
#include <stdlib.h>

struct Paciente {
    char nome[100];
    int idade;
    long id_prontuario;
};

struct Paciente* criarPaciente()
{
    struct Paciente *novo = (struct Paciente *)malloc(sizeof(struct Paciente));

    if (novo == NULL)
    {
        printf("Erro, falha ao alocar memoria");
        return NULL;
    }

    printf("id_prontuario: ");
    scanf("%ld", &novo->id_prontuario);

    printf("idade: ");
    scanf("%d", &novo->idade);

    getchar();
    printf("nome: ");
    fgets(novo->nome, 100, stdin);

    return novo;
}

void mostraPaciente(struct Paciente *p)
{
    printf("\n--- Prontuário ---\n");
    printf("Nome: %s", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("ID: %ld\n", p->id_prontuario);
}

int main()
{
    
    struct Paciente *paciente;

    paciente = criarPaciente();

    if (paciente != NULL)
    {
        mostrarPaciente(paciente);

        free(paciente);
    }

    return 0;
}