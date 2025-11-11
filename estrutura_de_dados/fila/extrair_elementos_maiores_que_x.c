/*
A nova fila (f_copia) deve conter cópias profundas (deep copy)
dos elementos que passam no filtro. Ou seja, você deve alocar
(malloc) um novo int* para cada elemento da nova fila.
A fila original f_orig NÃO PODE ser alterada. Ao final da função,
ela deve estar em seu estado original (mesmos elementos, mesma ordem).
A função deve retornar um ponteiro Fila* para a nova fila. Em caso de erro,
deve retornar NULL.
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"   // Seu .h da fila
#include "basics.h" // Seu .h do boolean

boolean extrair_maiores_que(Fila* f_orig, int valor_limite)
{
    boolean maiores_retirados = false;
    //criar uma fila auxiliar
    Fila f_aux;
    //iniciar fila
    nova_fila(&f_aux, f_orig->qtd_atual);
    //criar elementod de fila
    ElementoDeFila elem_fila;
    //criar um ponteiro inteiro
    int* elem_int;

    //criar um while para rodar até a fila esvaziar
    while(!fila_vazia(*f_orig))
    {
        recupere_da_fila(*f_orig, &elem_fila);

        remova_elemento_da_fila(f_orig);

        elem_int = (int*)elem_fila;

        if(*elem_int <= valor_limite)
        {
            //se o elemento for menor ou igual, adiciona ele na fila auxiliar para ele voltar
            guarde_na_fila(&f_aux, elem_fila);
        }
        else
        {
            free(elem_fila);//caso seja maior, limpar ele;
            maiores_retirados = true;
        }
    }
    //while para voltar os elementos ao original
    while(!fila_vazia(f_aux))
    {
        recupere_da_fila(f_aux, &elem_fila);

        remova_elemento_da_fila(&f_aux);

        guarde_na_fila(f_orig, elem_fila);
    }

    //limpar a fila auxiliar
    free_fila(&f_aux);

    return maiores_retirados;
}


// --- Funções auxiliares de teste (copiadas de exercícios anteriores) ---
void enfileirar_int(Fila* f, int valor) {
    int* i = (int*)malloc(sizeof(int));
    *i = valor;
    guarde_na_fila(f, (ElementoDeFila)i);
}

void liberar_elementos_fila(Fila* f) {
    while (!fila_vazia(*f)) {
        ElementoDeFila elem;
        recupere_da_fila(*f, &elem);
        remova_elemento_da_fila(f);
        free(elem);
    }
    free_fila(f);
}

// --- Função main() para testar seu simulado ---
int main()
{
    printf("Iniciando SIMULADO DE PROVA...\n");

    Fila fila_A;
    nova_fila(&fila_A, 10);
    
    // Fila A: [10, 50, 20, 70, 30]
    enfileirar_int(&fila_A, 10);
    enfileirar_int(&fila_A, 50);
    enfileirar_int(&fila_A, 20);
    enfileirar_int(&fila_A, 70);
    enfileirar_int(&fila_A, 30);

    printf("Fila A original: [10, 50, 20, 70, 30]\n");
    int limite = 40;
    printf("Chamando extrair_maiores_que() com limite %d...\n", limite);

    // Chama sua função
    Fila* fila_B = extrair_maiores_que(&fila_A, limite);

    if (fila_B == NULL) {
        printf("ERRO: Funcao 'extrair_maiores_que' retornou NULL.\n");
        liberar_elementos_fila(&fila_A);
        return 1;
    }

    printf("\n--- VERIFICACAO ---\n");

    // Teste 1: A fila A foi restaurada? (Deve ser 10 50 20 70 30)
    printf("Teste de Restauracao (Fila A): ");
    while (!fila_vazia(fila_A)) {
        int* val;
        recupere_da_fila(fila_A, (ElementoDeFila*)&val);
        remova_elemento_da_fila(&fila_A);
        printf("%d ", *val);
        free(val); // Libera o int* de A
    }
    printf("\n");

    // Teste 2: A fila B (cópia) tem os elementos corretos? (Deve ser 50 70)
    printf("Teste de Filtro (Fila B): ");
    while (!fila_vazia(*fila_B)) {
        int* val;
        recupere_da_fila(*fila_B, (ElementoDeFila*)&val);
        remova_elemento_da_fila(fila_B);
        printf("%d ", *val);
        free(val); // Libera o int* de B
    }
    printf("\n");

    // Libera as estruturas das filas
    free_fila(&fila_A);
    
    // Libera a fila B (que foi alocada dinamicamente)
    free_fila(fila_B); // Libera o vetor interno
    free(fila_B);      // Libera a 'struct Fila'
    
    printf("\nSimulado concluido.\n");

    return 0;
}