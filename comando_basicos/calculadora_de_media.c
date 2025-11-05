/*
Escreva um programa que pergunte ao usuário quantas notas ele
quer digitar. O programa deve então ler todas essas notas,
guardá-las em um vetor alocado dinamicamente, calcular a média e exibi-la.
*/

#include <stdio.h>
#include <stdlib.h>

void media_notas(int * notas, int qtd_notas)
{
    int soma = 0;
    int media;
    for(int i=0; i<qtd_notas; i++)
    {
        soma = soma + *(notas + i);
    }
    media = soma/qtd_notas;

    printf("A media das notas eh: %d", media);
}

int main()
{
    int *notas;
    int qtd_notas;

    printf("Quantidade de notas: ");
    scanf("%d", &qtd_notas);

    notas = malloc(qtd_notas * sizeof(int)); //pede a memoria

    if(notas == NULL)
    {
        printf("Erro, quantidade de memoria");
        return 1;
    }

    for (int i=0; i<qtd_notas; i++)
    {
        printf("Nota: ");
        scanf("%d", &notas[i]);
    }

    media_notas(notas, qtd_notas);

    free(notas);


    return 0;
}