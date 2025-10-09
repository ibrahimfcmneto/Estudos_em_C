#include <stdio.h>

typedef struct {
    unsigned int idEditora;    // identificador único da editora
    unsigned int codPais;      // código do país de origem
    unsigned int anoFundacao;  // ano de fundação
} Editora;

typedef struct {
    unsigned int idLivro;      // identificador único do livro
    unsigned int idAutor;      // FK -> Autor
    unsigned int idEditora;    // FK -> Editora
    unsigned int idCategoria;  // FK -> Categoria (apenas o código é usado no exercício)
    unsigned int anoPublicacao;// ano de publicação
    unsigned int numPaginas;   // número de páginas
} Livro;

typedef struct {
    unsigned int idCategoria;  // identificador único da categoria
    unsigned int codArea;      // código da área do conhecimento
} Categoria;

int editorasMonocategoria(Editora lista_editoras[],int qtd_editoras,
Livro lista_livros[], int qtd_livros, Categoria lista_categorias[], int qtd_categorias)
{
    int id_categoria_atual;

    for(int c_editora=0; c_editora<qtd_editoras; c_editora++)
    {
        for(int c_livro=0; c_livro<qtd_livros; c_livro++)
        {
            //encontra a editora
            if(lista_livros[c_livro].idEditora == lista_editoras[c_editora].idEditora)
            {
                //encontra a categoria do primeiro livro
                id_categoria_atual = lista_livros[c_livro].idCategoria;
                
                int categoria_certa = 1;//0=não 1=sim;
                if(lista_livros[c_livro].idCategoria != id_categoria_atual)
                {
                    categoria_certa = 0;
                }
            }
        }
    }
}

int main()
{

    Editora editoras[1000];
    int qtd_editoras;
    Livro livros[1000];
    int qtd_livros;
    Categoria categorias[1000];
    int qtd_categorias;

    editorasMonocategoria(editoras, qtd_editoras, livros, qtd_livros, categorias, qtd_categorias);


    return 0;
}