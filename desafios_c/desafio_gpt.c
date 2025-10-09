#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    char cargo[50];
    double salario;
} Funcionario;

void exibir_funcionario(Funcionario pessoa)
{
    printf("%d\n", pessoa.id);
    printf("%s\n", pessoa.nome);
    printf("%s\n", pessoa.cargo);
    printf("%2.lf\n", pessoa.salario);
}

int main()
{
    Funcionario pessoa1 = {1, "Diego", "Programador", 1500};

    exibir_funcionario(pessoa1);

    return 0;
}