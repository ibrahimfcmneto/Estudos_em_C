#include <stdio.h>

typedef struct {
    int idTime1;    // id do primeiro time
    int idTime2;    // id do segundo time
    int pontos1;    // pontos marcados pelo time1
    int pontos2;    // pontos marcados pelo time2
    int estadioId;  // id do estádio onde ocorreu a partida
} Partida;

typedef struct {
    int id;           // identificador único do estádio
    int capacidade;   // capacidade máxima de torcedores
    int jogos;        // número de jogos realizados no estádio
} Estadio;

//retornar o id do estádio onde ocorre mais partidas;

int estadioMaisUsado(Partida lista_partidas[], int qtd_partidas,
Estadio lista_estadios[], int qtd_estadios)
{
    int contagemJogos[qtd_estadios];

    // inicializa os contadores
    for(int i=0; i<qtd_estadios; i++)
    {
        contagemJogos[i] = 0;
    }

    //somar a quantidade de jogos que tiveram nos estádios
    for(int i=0; i<qtd_partidas; i++)
    {
        for(int j=0; j<qtd_estadios; j++)
        {
            //acha o estádio
            if(lista_partidas[i].estadioId == lista_estadios[j].id)
            {
                //pega o estádio na posição j e soma 1;
                contagemJogos[j]++;
                break;
            }
        }
    }

    //achar o estádio que mais teve jogos
    int id_estadio_com_mais_jogos;
    int qtd_jogos = 0;

    for(int i=0; i<qtd_estadios; i++)
    {
        if(i == 0)
        {
            qtd_jogos = contagemJogos[i];
            id_estadio_com_mais_jogos = lista_estadios[i].id;
        }
        else if(contagemJogos[i] > qtd_jogos)
        {
            qtd_jogos = contagemJogos[i];
            id_estadio_com_mais_jogos = lista_estadios[i].id;
        }
    }

    return id_estadio_com_mais_jogos;
}


int main()
{
    Partida partidas[1000];
    int qtd_partidas;
    Estadio estadio[1000];
    int qtd_estadios;


        // --- DADOS DOS ESTÁDIOS ---
    Estadio meus_estadios[] = {
        {101, 66000, 0},  // Morumbi
        {202, 78000, 0},  // Maracanã
        {303, 62000, 0},  // Mineirão
        {404, 50000, 0}   // Beira-Rio (não será usado)
    };
    int total_estadios = 4;

    // --- DADOS DAS PARTIDAS ---
    // Total de 6 partidas distribuídas pelos estádios.
    Partida minhas_partidas[] = {
        {1, 2, 2, 1, 202}, // Jogo no Maracanã (ID 202)
        {3, 4, 1, 1, 101}, // Jogo no Morumbi (ID 101)
        {5, 6, 3, 0, 303}, // Jogo no Mineirão (ID 303)
        {1, 3, 0, 2, 101}, // Jogo no Morumbi (ID 101)
        {2, 4, 2, 2, 202}, // Jogo no Maracanã (ID 202)
        {5, 1, 1, 0, 101}  // Jogo no Morumbi (ID 101)
    };
    int total_partidas = 6;


    
    estadioMaisUsado(partidas, qtd_partidas, estadio, qtd_estadios);
    
    return 0;
}