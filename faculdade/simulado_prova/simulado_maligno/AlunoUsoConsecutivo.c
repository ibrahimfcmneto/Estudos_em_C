#include <stdio.h>

// Alunos cadastrados
typedef struct {
    unsigned int idAluno;        // identificador único do aluno
    unsigned int codCurso;       // código do curso em que está matriculado
    unsigned int anoIngresso;    // ano de ingresso no curso
} PessoaAluno;

// Registro de empréstimos
typedef struct {
    unsigned int idEmprestimo;   // identificador do empréstimo
    unsigned int idExemplar;     // exemplar emprestado
    unsigned int idPessoa;       // id da pessoa que pegou (aluno ou professor)
    unsigned int tipoPessoa;     // 0 = aluno, 1 = professor
    unsigned int anoEmprestimo;  // ano do empréstimo
    unsigned int anoDevolucao;   // ano da devolução (0 se não devolvido)
} Emprestimo;


int alunosUsoConsecutivo(PessoaAluno lista_alunos[], int qtd_alunos, Emprestimo lista_emprestimos[],
int qtd_emprestimos, int AnoBase)
{
    int lista_pessoas_fizeram_emprestimo[qtd_alunos];
    int cont_pessoas_emprestimo = 0;

    int lista_pessoas_fizeram_emprestimo_ano_seguinte[qtd_alunos];
    int cont_pessoas_emprestimo_ano_seguinte = 0;

    for(int cont_emprestimo=0; cont_emprestimo<qtd_emprestimos; cont_emprestimo++)
        {
            if(lista_emprestimos[cont_emprestimo].anoEmprestimo == AnoBase &&
                lista_emprestimos[cont_emprestimo].tipoPessoa == 0)//achou o ano base e alunos
            {
                int esta_na_lista=0;//0=não 1=sim;
                for(int i=0; i<cont_pessoas_emprestimo; i++)
                {
                    if(lista_emprestimos[cont_emprestimo].idPessoa == lista_pessoas_fizeram_emprestimo[i])
                    {
                        esta_na_lista = 1;
                    }
                }
                if (esta_na_lista == 0)
                {
                    lista_pessoas_fizeram_emprestimo[cont_pessoas_emprestimo] = lista_emprestimos[cont_emprestimo].idPessoa;
                    cont_pessoas_emprestimo++;
                }
            }

        }
    
    //alunos que fizeram emprestimo no ano seguinte
    for(int cont_emprestimo=0; cont_emprestimo<qtd_emprestimos; cont_emprestimo++)
    {
        if(lista_emprestimos[cont_emprestimo].anoEmprestimo == AnoBase+1 &&
            lista_emprestimos[cont_emprestimo].tipoPessoa == 0)//achou o ano base e alunos
        {
            int esta_na_lista=0;//0=não 1=sim;
            for(int i=0; i<cont_pessoas_emprestimo_ano_seguinte; i++)
            {
                if(lista_emprestimos[cont_emprestimo].idPessoa == lista_pessoas_fizeram_emprestimo_ano_seguinte[i])
                {
                    esta_na_lista = 1;
                }
            }
            if (esta_na_lista == 0)
            {
                lista_pessoas_fizeram_emprestimo_ano_seguinte[cont_pessoas_emprestimo_ano_seguinte] = lista_emprestimos[cont_emprestimo].idPessoa;
                cont_pessoas_emprestimo_ano_seguinte++;
            }
        }
    }

    int intersecao_dos_alunos[qtd_alunos];
    int cont_intercecao_alunos = 0;

    //contagem da interceção
    for(int cont_ano_base=0; cont_ano_base<cont_pessoas_emprestimo; cont_ano_base++)
    {
        for(int cont_ano_seguinte = 0; cont_ano_seguinte<cont_pessoas_emprestimo_ano_seguinte; cont_ano_seguinte++)
        {
            if(lista_pessoas_fizeram_emprestimo[cont_ano_base] == lista_pessoas_fizeram_emprestimo_ano_seguinte[cont_ano_seguinte])
            {
                intersecao_dos_alunos[cont_intercecao_alunos] = lista_pessoas_fizeram_emprestimo[cont_ano_base];
                cont_intercecao_alunos++;
            }
        }
    }

    return cont_intercecao_alunos;
    
}


int main()
{
    PessoaAluno alunos[1000];
    int qtd_alunos;
    Emprestimo emprestimos[1000];
    int qtd_emprestimos;
    int AnoBase;

    //quer saber quantos alunos fizeram emprestimo no ano dado e no ano consecutivo;
    alunosUsoConsecutivo(alunos, qtd_alunos, emprestimos, qtd_emprestimos, AnoBase);

    return 0;
}