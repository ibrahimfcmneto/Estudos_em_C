#include <stdio.h>

#include <stdio.h>

typedef struct {
    unsigned int idAluno;
    unsigned int codCurso;
    unsigned int anoIngressso;
} PessoaAluno;

typedef struct {
    unsigned int idEmprestimo;
    unsigned int idExemplar;
    unsigned int idPessoa;
    int tipoPessoa;
    unsigned int anoEmprestimo;
    unsigned int anoDevolucao;
} Emprestimo;

int alunosSemEmprestimosAno(PessoaAluno lista_pessoas[], int qtd_pessoas, Emprestimo lista_emprestimos[], int qtd_emprestimos, int ano)
{
    int id_pessoas_ja_pegaram_livro[qtd_pessoas];

    int qtd_de_pessoas_que_fizeram_emprestimo = 0;

    for (int i=0; i<qtd_emprestimos; i++)
    {
        if(lista_emprestimos[i].anoEmprestimo == ano)//achou o ano certo
        {
            for(int c=0; c<qtd_pessoas; c++)
            {
                if(lista_pessoas[c].idAluno == lista_emprestimos[i].idPessoa) //achou o aluno que fez o emprestimo
                {
                    int esta_na_lista = 0; //0=nao e 1=sim
                    for(int contador=0; contador<qtd_pessoas; contador++)
                    {
                        if(lista_pessoas[c].idAluno == id_pessoas_ja_pegaram_livro[contador])//acha aluno que já estava na lista
                        {
                            esta_na_lista = 1;
                            break;
                        }
                    }
                    if(esta_na_lista == 0)
                    {
                        id_pessoas_ja_pegaram_livro[qtd_de_pessoas_que_fizeram_emprestimo] = lista_pessoas[c].idAluno;
                        qtd_de_pessoas_que_fizeram_emprestimo++;
                    }
                }
            }
        }
    }
    int qtd_de_pessoas_que_nao_fizeram_emprestimo = (qtd_pessoas - qtd_de_pessoas_que_fizeram_emprestimo);
    return qtd_de_pessoas_que_nao_fizeram_emprestimo;

}

int main()
{
//-------------------------------------------------------

    // Temos 6 alunos no total.
    PessoaAluno lista_pessoas[6] = {
        {101, 1, 2022}, // Maria: Múltiplos empréstimos em 2025
        {102, 1, 2022}, // João: Nenhum empréstimo
        {103, 2, 2023}, // Pedro: Empréstimos em 2024 e 2025
        {104, 2, 2023}, // Sofia: Empréstimo apenas em outro ano (2024)
        {105, 3, 2024}, // Lucas: Apenas um empréstimo em 2025
        {106, 3, 2024}  // Laura: Apenas um empréstimo em 2025
    };
    int qtd_pessoas = 6;

    // Temos 7 registros de empréstimos em anos variados.
    Emprestimo lista_emprestimos[7] = {
        {1, 1, 101, 0, 2025, 0},    // Empréstimo da Maria (ID 101) no ano certo
        {2, 2, 103, 0, 2024, 2024}, // Empréstimo do Pedro (ID 103) em ano anterior
        {3, 3, 104, 0, 2025, 2025}, // Empréstimo da Sofia (ID 104) em ano anterior
        {4, 4, 105, 0, 2025, 0},    // Empréstimo do Lucas (ID 105) no ano certo
        {5, 5, 101, 0, 2025, 0},    // Outro empréstimo da Maria (ID 101) no ano certo
        {6, 6, 103, 0, 2025, 0},    // Empréstimo do Pedro (ID 103) no ano certo
        {7, 7, 106, 0, 2025, 0}     // Empréstimo da Laura (ID 106) no ano certo
    };
    int qtd_emprestimos = 7;

    // O ano que queremos analisar.
    int ano = 2025;

//-------------------------------------------------------
    int resultado = alunosSemEmprestimosAno(lista_pessoas, qtd_pessoas, lista_emprestimos, qtd_emprestimos, ano);

    printf("A quantidade de pessoas que não fizerma emprestimos no ano %d eh: %d", ano, resultado);

    return 0;
}