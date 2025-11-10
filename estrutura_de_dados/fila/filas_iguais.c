#include <stdio.h>
#include <stdlib.h>
#include "fila.h"   // Seu .h da fila
#include "basics.h" // Seu .h do boolean

boolean filas_iguais(Fila* f1, Fila* f2)
{
    boolean sao_iguais = true; // Comece assumindo que são

    //verificação rápida para ver se elas tem o mesmo tamanho
    if (f1->qtd_atual != f2->qtd_atual) {
        return false;
    }

    // 2. Verificação rápida: Ambas estão vazias?
    if (fila_vazia(*f1))
    { // Se f1 está vazia e o tamanho é igual, f2 tbm está
        return sao_iguais;
    }

    // Criar dus filas auxiliares para comparar os elementos
    Fila aux1, aux2;

    //inicializar as filas
    nova_fila(&aux1, f1->qtd_atual);
    nova_fila(&aux2, f2->qtd_atual);
    
    ElementoDeFila elem1_ptr, elem2_ptr;
    int* val1;
    int* val2;

    // 4. Loop Principal: Esvazie f1 e f2, compare, e guarde em aux1/aux2
    //    (Rode o loop enquanto f1 NÃO estiver vazia)
    while (!fila_vazia(*f1))//enquanto for diferente de pilha vazia...
    {
        //pegar os primeiros elementos das filas e guardar nos ponteiros
        recupere_da_fila(*f1, &elem1_ptr);
        recupere_da_fila(*f2, &elem2_ptr);

        //removendos os primeiros elementos de cada fila
        remova_elemento_da_fila(f1);
        remova_elemento_da_fila(f2);

        //colocar os elementos nas filas auxiliares
        guarde_na_fila(&aux1, elem1_ptr);
        guarde_na_fila(&aux2, elem2_ptr);

        //trasformar os ponteiros em inteiros para poder comparar os numeros
        val1 = (int*)elem1_ptr;
        val2 = (int*)elem2_ptr;
        //comparar os numeros
        if(*val1 != *val2)
        {
            sao_iguais = false;//caso os numeros sejam diferentes, retorna falso
        }

    }
    //voltar os numeros para as filas originais
    while(!fila_vazia(aux1))
    {
        //pegar o primeiro elemento da fila auxiliar e salvar no ponteiro
        recupere_da_fila(aux1, &elem1_ptr);
        recupere_da_fila(aux2, &elem2_ptr);
        //remover os elementos salvos
        remova_elemento_da_fila(&aux1);
        remova_elemento_da_fila(&aux2);
        //guardar os elementos nas filas originais
        guarde_na_fila(&f1, elem1_ptr);
        guarde_na_fila(&f2, elem2_ptr);
    }
    //esvaziar as filas auxiliares
    free_fila(&aux1);
    free_fila(&aux2);

    //retornar se as filas são iguais
    return sao_iguais;
}

// --- Função auxiliar para criar e enfileirar (facilita o teste) ---
void enfileirar_int(Fila* f, int valor) {
    int* i = (int*)malloc(sizeof(int));
    *i = valor;
    guarde_na_fila(f, (ElementoDeFila)i);
}

// --- Função auxiliar para esvaziar e liberar (facilita o teste) ---
void liberar_elementos_fila(Fila* f) {
    while (!fila_vazia(*f)) {
        ElementoDeFila elem;
        recupere_da_fila(*f, &elem);
        remova_elemento_da_fila(f);
        free(elem);
    }
    free_fila(f);
}

// --- Função main() para testar seu exercício ---
int main()
{
    printf("Iniciando teste do EXERCICIO 3 (Filas Iguais)...\n");

    Fila A, B, C, D;
    nova_fila(&A, 5); nova_fila(&B, 5); nova_fila(&C, 5); nova_fila(&D, 3);
    
    // Fila A: [10, 20, 30]
    enfileirar_int(&A, 10); enfileirar_int(&A, 20); enfileirar_int(&A, 30);
    
    // Fila B: [10, 20, 30] (Igual a A)
    enfileirar_int(&B, 10); enfileirar_int(&B, 20); enfileirar_int(&B, 30);
    
    // Fila C: [10, 20, 99] (Diferente de A)
    enfileirar_int(&C, 10); enfileirar_int(&C, 20); enfileirar_int(&C, 99);
    
    // Fila D: [10, 20] (Tamanho diferente de A)
    enfileirar_int(&D, 10); enfileirar_int(&D, 20);

    // --- Testes ---
    
    printf("A == B? (Esperado: true) -> %s\n", filas_iguais(&A, &B) ? "true" : "false");
    printf("A == C? (Esperado: false) -> %s\n", filas_iguais(&A, &C) ? "true" : "false");
    printf("A == D? (Esperado: false) -> %s\n", filas_iguais(&A, &D) ? "true" : "false");

    // Teste de restauração: A ainda deve ser [10, 20, 30]
    printf("Restauracao Fila A: ");
    while (!fila_vazia(A)) {
        int* val;
        recupere_da_fila(A, (ElementoDeFila*)&val);
        remova_elemento_da_fila(&A);
        printf("%d ", *val);
        free(val); // Libera o int*
    }
    printf("\n");

    // Libera a memória alocada
    liberar_elementos_fila(&B);
    liberar_elementos_fila(&C);
    liberar_elementos_fila(&D);
    free_fila(&A); // A já foi esvaziada, só free_fila

    return 0;
}