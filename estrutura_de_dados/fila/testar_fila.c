#include <stdio.h>
#include <stdlib.h>
#include "fila.h"   // Seu .h da fila
#include "basics.h" // Seu .h do boolean

/*
 * Testa se a implementação da fila funciona.
 * Recebe um vetor de inteiros 'v' e seu tamanho 'n'.
 * Retorna 'true' se a fila respeitar o FIFO, 'false' caso contrário.
 */
boolean testa_fila(int *v, int n)
{
    Fila f_teste;
    if (!nova_fila(&f_teste, n)) {
        printf("Erro ao criar fila de teste.\n");
        return false;
    }

    int* i_ptr;
    int i;

    // 1. Enfileirar todos os elementos do vetor 'v'
    for (i = 0; i < n; i++)
    {
        // ... SEU CÓDIGO AQUI ...
        // 1.1. Alocar memória para um int*
        // 1.2. Atribuir o valor: *i_ptr = v[i];
        // 1.3. Guardar na fila
        // 1.4. Tratar se guarde_na_fila falhar (não deve, mas é bom)
    }

    // 2. Desenfileirar e verificar a ordem FIFO
    int j = 0; // Índice para comparar com o vetor original 'v'
    boolean resultado = true; // Começa assumindo que está correto

    while (!fila_vazia(f_teste))
    {
        // ... SEU CÓDIGO AQUI ...
        // 2.1. Recuperar o elemento (recupere_da_fila)
        // 2.2. Remover o elemento (remova_elemento_da_fila)
        
        // 2.3. Comparar o valor: if (*i_ptr != v[j])
        //      Se for diferente, mude 'resultado = false;'
        
        // 2.4. Liberar a memória do int*: free(i_ptr);
        
        // 2.5. Incrementar o índice 'j'
    }

    // 3. Liberar a fila
    free_fila(&f_teste);

    // 4. Retornar o resultado da verificação
    return resultado;
}

// --- Função main() para testar seu exercício ---
int main()
{
    printf("Iniciando teste do EXERCICIO 2...\n");
    
    int vetor_teste[] = {10, 20, 30, 40, 50};
    int n_teste = 5;

    if (testa_fila(vetor_teste, n_teste))
        printf("SUCESSO: A fila funciona corretamente (FIFO)!\n");
    else
        printf("FALHA: A fila NAO funciona corretamente.\n");
    
    // Teste com vetor "errado" (só para ver se a main funciona)
    int vetor_teste2[] = {5, 4, 3};
    n_teste = 3;
    
    if (testa_fila(vetor_teste2, n_teste))
        printf("SUCESSO: A fila funciona corretamente (FIFO)!\n");
    else
        printf("FALHA: A fila NAO funciona corretamente.\n");

    return 0;
}