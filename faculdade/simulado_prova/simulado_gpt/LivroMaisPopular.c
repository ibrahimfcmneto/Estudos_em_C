#include <stdio.h>

typedef struct {
    int id;               // identificador único do livro
    char titulo[100];     // título completo do livro
    char autor[100];      // nome do autor do livro
} Livro;

typedef struct {
    int idEmprestimo;     // identificador único do empréstimo
    int idLivro;          // id do livro que foi emprestado
    int idUsuario;        // id do usuário que pegou o livro
} Emprestimo;

int LivroMaisPopular(Livro lista_livros[], int qtd_livros,
Emprestimo lista_emprestimo[], int qtd_emprestimos)
{
    int qtd_emprestimo_livro[qtd_livros];

    //incializando o contador;
    for (int i=0; i<qtd_livros; i++)
    {
        qtd_emprestimo_livro[i] = 0;
    }

    //achar quantos emprestimos cada livro fez
    for(int i=0; i<qtd_emprestimos; i++)
    {
        for(int j=0; j<qtd_livros; j++)
        {
            //acha o livro
            if(lista_emprestimo[i].idLivro == lista_livros[j].id)
            {
                //somando cada emprestimo de cada livro;
                qtd_emprestimo_livro[j]++;
                break;
            }
        }
    }

    int id_livro_mais_emprestimos;
    int qtd_livro_mais_emprestado;

    for(int i=0; i<qtd_livros; i++)
    {
        if(i==0)
        {
            id_livro_mais_emprestimos = lista_livros[i].id;
            qtd_livro_mais_emprestado = qtd_emprestimo_livro[i];
        }
        else if(qtd_emprestimo_livro[i] > qtd_livro_mais_emprestado)
        {
            id_livro_mais_emprestimos = lista_livros[i].id;
            qtd_livro_mais_emprestado = qtd_emprestimo_livro[i];
        }
    }

    return id_livro_mais_emprestimos;
}


int main()
{
    return 0;
}