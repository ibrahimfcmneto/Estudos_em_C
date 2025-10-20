#include <stdio.h>

typedef struct {
    unsigned int idLivro;
    unsigned int idAutor;
    unsigned int idEditora;
    unsigned int idCategoria;
    unsigned int anoPublicacao;
    unsigned int numPaginas;
} Livro;

typedef struct {
    unsigned int idExemplar;
    unsigned int idLivro;
    unsigned int codEstado; //1=novo,2=bom,3=regular,4=ruim
} Exemplar;

typedef struct {
    unsigned int idCategoria;
    unsigned int codArea; //código da área do conhecimento (unsigned int)
} Categoria;

int LivroSemExemplarBom(Livro lista_livros[], int qtd_livros, Exemplar lista_exemplares[], int qtd_exemplares,
Categoria lista_categorias[], int qtd_categorias, int id_categoria_filtro)
{
    int livros_sem_bom_estado[qtd_livros];
    int qtd_livros_sem_bom_estado = 0;

   for (int contador_livros=0; contador_livros<qtd_livros; contador_livros++)
   {
        if(lista_livros[contador_livros].idCategoria != id_categoria_filtro)
        {
            continue;
        }

        else //achou a categoria certa
        {
            int livro_bom_estado = 0; //0 = sim; 1 = não
            for(int contador_exemplar = 0; contador_exemplar<qtd_exemplares; contador_exemplar++)
            {
                //Se o exemplar pertence ao livro atual
                if(lista_exemplares[contador_exemplar].idLivro == lista_livros[contador_livros].idLivro)
                {
                    if(lista_exemplares[contador_exemplar].codEstado == 1 || lista_exemplares[contador_exemplar].codEstado == 2)
                    {
                        livro_bom_estado = 1;
                        break;
                    }
                }
            }
            if(livro_bom_estado == 0)
            {
                livros_sem_bom_estado[qtd_livros_sem_bom_estado] = lista_livros[contador_livros].idLivro;
                qtd_livros_sem_bom_estado++;
            }
        }
   }
   return qtd_livros_sem_bom_estado;
}

int main()
{
    Livro livros[1000];
    int qtd_livros;
    Exemplar exemplares[1000];
    int qtd_exemplares;
    Categoria categorias[1000];
    int qtd_categorias;
    int id_categoria_filtro;
    
    int resultado = LivroSemExemplarBom(livros, qtd_livros, exemplares, qtd_exemplares, categorias, qtd_categorias, categoria_fitro);
    printf("A quantidade de livros sem bom estado eh: %d", resultado);
    return 0;
}