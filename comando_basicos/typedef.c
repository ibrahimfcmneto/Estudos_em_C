#include <stdio.h>

typedef struct{
    char cpf[30];
    char nome[100];
    float altura;
}Pessoa;

int main()
{

    Pessoa pessoa1 = {'466.213.618-07', 'Ibrahim', 1.82};

    printf("\t %s\n %s\n %.2f", pessoa1.cpf, pessoa1.nome, pessoa1.altura);

    return 0;
}