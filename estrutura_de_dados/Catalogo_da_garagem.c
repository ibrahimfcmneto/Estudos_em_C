#include <stdio.h>

struct Carro {
    char modelo[50];
    int ano;
    float preco;
};

struct Carro *criarCarro()
{
    struct Carro *novo_carro = (struct Carro *)malloc(sizeof(struct Carro));

    if(novo_carro == NULL)
    {
        printf("Erro ao alocar memoria");
        return NULL;
    }

    printf("Preco: ");
    scanf("%f", &novo_carro->preco);

    printf("Ano: ");
    scanf("%d", &novo_carro->ano);

    getchar();
    printf("Modelo: ");
    fgets(novo_carro->modelo, 50, stdin);

    return novo_carro;

}

void mostrar_carro(struct Carro *carros)
{
    printf("\n--------CARRO---------\n");
    printf("Modelo: %s\n", carros->modelo);
    printf("Ano: %d\n", carros->ano);
    printf("Preco: %.2f\n", carros->preco);
}

int main()
{

    struct Carro *carros;

    carros = criarCarro();

    if (carros != NULL)
    {
        mostrar_carro(carros);

        free(carros);
    }

    return 0;
}