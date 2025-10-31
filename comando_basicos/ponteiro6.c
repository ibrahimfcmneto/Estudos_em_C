#include <stdio.h>


// Struct que representa um produto
struct Produto {
    int id;
    float preco;
}produto;


int main()
{
    /*int x = 10;
    int *p; //criação do ponteiro

    p = &x; //p está guardadndo o endereco de memoria de x;

    printf("%d\n", p); //printa a localização do ponteiro

    printf("%d\n", *p); //printa 10 pois está acessando o que tem dentro de p
    */
    printf("id: ");
    scanf("%d", &produto.id);
    printf("preco: ");
    scanf("%f", &produto.preco);

    printf("O id eh: %d\n", produto.id);
    printf("O preco eh: %f\n", produto.preco);




    return 0;
}