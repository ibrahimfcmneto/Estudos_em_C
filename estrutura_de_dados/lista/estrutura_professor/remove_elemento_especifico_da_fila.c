#include <main.c>
#include <lista_simples.h>

void remove_todas_ocorrencia(TFila *f, int x)
{
    Struct_do_no_de_lista_simples* atual;

    //criar um ponteiro temporário
    int* ptr_temporario;

    //variavel inteira para poder comparar;
    int variavel_int;


    for(int i=0; i<quantos_elementos(*f); i++)
    {
        //guarda a informação no ponteiro
        ptr_temporario = atual->informacao;

        //a variavel inteiro vai receber o valor inteiro
        variavel_int = *((int*)(ptr_temporario));

        //fazer a comparação
        if(variavel_int == x)
        {
            //remove o elemento que não quer
            free(&ptr_temporario);
        }

        //caso não seja o elemento
        //avançar para o próximo
        atual = atual->proximo;
    }
}

//Lógica certa
void remove_todas_ocorrencias(TFila *F, int X)
{
    Tfila* FilaAuxiliar;
    while ( !esta_vazia(fila_original) )
}