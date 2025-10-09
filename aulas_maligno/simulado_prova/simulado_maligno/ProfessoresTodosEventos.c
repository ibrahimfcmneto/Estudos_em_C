#include <stdio.h>

typedef struct {
    unsigned int idProfessor;     // Identificador único
    unsigned int codDepartamento; // Departamento
    unsigned int anoContratacao;  // Ano de contratação
} PessoaProfessor;

typedef struct {
    unsigned int idEvento;      // Identificador
    unsigned int codTipoEvento; // Tipo de evento
    unsigned int anoEvento;     // Ano do evento
} Evento;

typedef struct {
    unsigned int idParticipacao;// Identificador
    unsigned int idEvento;      // FK -> Evento
    unsigned int idPessoa;      // Aluno ou Professor
    unsigned int tipoPessoa;    // 0=Aluno, 1=Professor
} ParticipacaoEvento;

void ProfessoresEmTodosEventos(PessoaProfessor lista_professores[], int qtd_professores,
    Evento lista_eventos[], int qtd_eventos, ParticipacaoEvento lista_participacoes[],
    int qtd_participacoes, int ano);
{
    int id_professores[qtd_professores];
    int qtd_professores;
    int eventos_do_ano[qtd_eventos];
    int contador_qtd_eventos = 0;

    //descobrir quantos eventos tem no ano certo;
    for(int i=0; i<qtd_eventos; i++)
    {
        if(lista_eventos[i].anoEvento == ano)
        {
            eventos_do_ano[contador_qtd_eventos] = lista_eventos[i].idEvento;
            contador_qtd_eventos++;
        }
    }

    for(cont_evento=0; cont_evento<qtd_eventos; cont_evento++)
    {
        if(lista_participacoes[cont_evento].tipoPessoa == 0)
        {
            continue;
        }
        
        else
        {
            for(int cont_participacoes=0; cont_participacoes<qtd_participacoes; cont_participacoes++)
            {
                if(lista_participacoes[cont_participacoes].)
            }
        }
    }


    /*for(int cont_evento=0; cont_evento<qtd_eventos; cont_evento++)
    {
        if(lista_evento[cont_evento].anoEvento == ano)//encontrou o ano certo
        {
            for(int cont_participacoes=0; cont_participacoes<qtd_participacoes; cont_participacoes++)
            {

            }
        }
    }
    */
}


int main()
{
    PessoaProfessor professores[1000];
    int qtd_professores;
    Evento eventos[1000];
    int qtd_eventos;
    ParticipacaoEvento participacoes[1000];
    int qtd_participacoes;
    int ano;


    ProfessoresEmTodosEventos(professores, qtd_professores, eventos, qtd_eventos, participacoes, qtd_participacoes, ano);
    
    return 0;
}