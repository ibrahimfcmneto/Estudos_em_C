#include <stdio.h>

int main()
{
    int numero = 10;
    int *ponteiro;
    
    ponteiro = &numero;//guarda o endereco de memoria do numero;
    //esse ponteiro eh o endereco escrito no envelope

    printf("o que esta dentro do ponteiro eh: %d\n", *ponteiro);//printa 10
    printf("o endereco de memoria que o ponteiro esta guardando eh: %p", ponteiro);//printa 10

    
    

    return 0;
}