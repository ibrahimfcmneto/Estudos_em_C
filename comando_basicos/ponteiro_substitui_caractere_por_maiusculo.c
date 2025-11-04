/* 
Implemente uma função que recebe um ponteiro para uma string e substitua todos
os caracteres minúsculos por maiúsculos (sem usar funções prontas como strupr).
• A função deve alterar a string no próprio espaço de memória.
• No main, leia uma frase do usuário, chame a função e mostre a string modificada
*/

#include <stdio.h>

void paraMaiusculo(char *str)
{
    while (*str != '\0')
    {
        if(*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }
}

int main()
{
    char frase[100];

    printf("Digite uma frase: ");
    // tutorial fgets:
    //   - Guarde em: frase
    //   - Tamanho máximo: 100 (o tamanho do array)
    //   - Fonte: stdin (o teclado)
    fgets(frase, 100, stdin);
    printf("Frase normal: %s", frase);

    paraMaiusculo(frase);

    printf("Frase em maiúsculo: %s", frase);

    return 0;
}