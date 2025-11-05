/*
Escreva um programa que pergunte ao usuário o tamanho máximo do
nome que ele quer digitar (ex: 50) e, em seguida, armazene esse
nome usando alocação dinâmica.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho;
    char *nome;

    printf("Tamanho maximo do nome: ");
    scanf("%d", &tamanho);

    getchar(); // <-- "Come" o '\n' deixado pelo scanf

    nome = malloc((tamanho + 1) * sizeof(char)); //está alocando a memoria com o tamanho do nome

    if (nome == NULL)
    {
        printf("Erro ao alocar memoria");
        return 1;
    }

    printf("Digite o nome: ");
    fgets(nome, tamanho+1, stdin); //está pegando o nome

    printf("%s", nome);

    free(nome);

    return 0;
}