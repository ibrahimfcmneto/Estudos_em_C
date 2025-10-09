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

int estadioMaisUsado(Partida lista_partidas[], int qtd_partidas,
Estadio lista_estadios[], int qtd_estadios)
{
    int contagem_jogos[qtd_estadios];

    for (int i=0; i<qtd_estadios; i++)
    {
        contagem_jogos[i] = 0;
    }

    //fazendo a contagem dos jogos
    for(int c_partida=0; c_partida<qtd_partidas; c_partida++)
    {
        for(int c_estadio=0; c_estadio<qtd_estadios; c_estadio++)
        {
            if(lista_estadios[c_estadio].id == lista_partidas[c_partida].estadioId)
            {
                contagem_jogos[c_estadio]++;
                break;
            }
        }
    }

    //vendo qual estadio tem mais partidas
    int id_estadio_com_mais_partidas;
    int qtd_de_jogos;

    for(int i=0; i<qtd_estadios; i++)
    {
        if(i==0)
        {
            qtd_de_jogos = contagem_jogos[i];
            id_estadio_com_mais_partidas = lista_estadios[i].id;
        }
        else if(contagem_jogos[i] > qtd_de_jogos)
        {
            qtd_de_jogos = contagem_jogos[i];
            id_estadio_com_mais_partidas = lista_estadios[i].id;
        }
    }

    return id_estadio_com_mais_partidas;

}


int main()
{
    Partida partidas[1000];
    int qtd_partidas;
    Estadio estadio[1000];
    int qtd_estadios;
    
    estadioMaisUsado(partidas, qtd_partidas, estadio, qtd_estadios);
    
    return 0;
}