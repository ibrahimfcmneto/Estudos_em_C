#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int id;
    int idade;
    int pontos;
    int jogos;
    int faltas;
} Atleta;

typedef struct {
    int id;
    int idAtletas[5];
    int idTreinador;
} Time;

typedef struct {
    int idTime1;
    int idTime2;
    int pontos1;
    int pontos2;
    int idEstadio;
} Partida;

typedef struct {
    int id;
    int experiencia;
    int titulos;
} Treinador;

int qtdTimesJovensEficientes(Atleta lista_atletas[], int qtd_atletas,
Time lista_times[], int qtd_times, Partida lista_partidas[], int qtd_partidas,
Treinador lista_treinadores[], int qtd_treinadores)
{
    int id_times_jovens[qtd_times];

    //inicializando contador;
    for(int i=0; i<qtd_times; i++)
    {
        id_times_jovens[i] = 0;
    }
    
    int qtd_times_jovens = 0;

    //verificar se o time é jovem
    for(int i=0; i<qtd_times; i++)
    {   
        bool time_jovem = true;
        for(int j=0; j<5; j++)
        {
            if(lista_times[i].idAtletas[j] == lista_atletas[j].id
            && lista_atletas[j].idade > 20)
            {
                time_jovem = false;
            }

        }
        if(time_jovem == true)
        {
            //adicionando id dos times jovens na lista
            id_times_jovens[i] = lista_times[i].id;
            qtd_times_jovens++;
        }
    }

    int eficiencia;
    int id_time_eficiente[qtd_times];
    //verificar times jovens com eficiência maior que 1 em alguma partida
    for(int i=0; i<qtd_times; i++)
    {
        bool time1_eficiente = false;
        bool time2_eficiente = false;
        for(int j=0; j<qtd_partidas; j++)
        {
            if(lista_times[i].id == lista_partidas[j].idTime1)
            {
                eficiencia = lista_partidas[j].pontos1 / (lista_partidas[j].pontos2 + 1);
                if(eficiencia > 1)
                {
                    time1_eficiente = true;
                    break;
                }
            }

            if(lista_times[i].id == lista_partidas[j].idTime2)
            {
                eficiencia = lista_partidas[j].pontos2 / (lista_partidas[j].pontos1 + 1);
                if(eficiencia > 1)
                {
                    time2_eficiente = true;
                    break;
                }
            }
        }

        for(int c=0; c<qtd_times; c++)
        {
            if(time1_eficiente == true)
            {
                id_time_eficiente[c] = lista_times[i].id;
            }
            if(time2_eficiente == true)
            {
                id_time_eficiente[c] = lista_times[i].id;
            }
        }
    }

    int qtd_times_jovens_e_eficientes = 0;
    //pegando a interseção dos times que são jovens e eficientes
    for(int i=0; i<qtd_times; i++)
    {
        for(int j=0; j<qtd_times; j++)
        {
            if(id_times_jovens[i] == id_time_eficiente[j])
            {
                qtd_times_jovens_e_eficientes++;
            }
        }
    }

    return qtd_times_jovens_e_eficientes;
}

int main()
{
    Atleta atletas[1000];
    int qtd_atletas;
    Time times[1000];
    int qtd_times;
    Partida partidas[1000];
    int qtd_partidas;
    Treinador treinadores[1000];
    int qtd_treinadores;

    qtdTimesJovensEficientes(atletas, qtd_atletas, times, qtd_times, partidas, qtd_partidas, treinadores, qtd_treinadores);


    return 0;
}