#include <stdio.h>

int main()
{
    int var = 15;
    int *ptr;

    ptr = &var; //ptr está recebendo o endereço de memoria de var;

    printf("conteúdo de var: %d\n", var);
    printf("endereco de memoria de var: %p\n", &var);
    //*ptr vai apontar para o conteúdo dentro de ptr
    printf("conteúdo apontado por ptr: %d\n", *ptr);
    printf("endereco de memoria apontado por ptr: %p\n", ptr);
    printf("Endereco de memoria de ptr: %p\n", &ptr);

    //-----------------------------------------------------------------
    printf("--------------------------------------------\n");
    *ptr = 73;//está mudando o que tem dentro do var;
    //porque o ptr está apontando para o endereço de memoria de var;
    //com isso quando tem o *ptr, altera o que tem dentro de var;

    printf("conteúdo de var: %d\n", var);
    printf("endereco de memoria de var: %p\n", &var);
    //*ptr vai apontar para o conteúdo dentro de ptr
    printf("conteúdo apontado por ptr: %d\n", *ptr);
    printf("endereco de memoria apontado por ptr: %p\n", ptr);
    printf("Endereco de memoria de ptr: %p\n", &ptr);

    //ponteiros:
    //*ptr: o apontador por, conteúdo do endereco da variável que ptr aponta
    //ptr: o endereco da variável;
    //&ptr: endereco do ponteiro;

    return 0;
}