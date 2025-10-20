#include <stdio.h>

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
    int id_times_jovens;
    int qtd_times_jovens = 0;

    //buscar times jovens(todos os atletas com até 20 anos)
    for(int i=0; i<qtd_times; i++)
    {
        int time_eh_jovem = 1;//0=não 1=sim;
        for(int c=0; c<5; c++)
        {
            int id_atleta_procurado = lista_times[i].idAtletas[c];
            //acha os atletas do time
            
            if(lista_times[i].idAtletas[c] == lista_atletas[c].id)
            {
                if(lista_atletas[c].idade > 20)
                {
                    time_eh_jovem = 0;
                    break;
                }
            }
        }
        if(time_eh_jovem == 1)
        {
            //adiciona os times que só tem atletas jovens
            id_times_jovens = lista_times[i].id;
            qtd_times_jovens++;
        }
    }

    //buscar os times jovens que tiveram eficiência maior que 1 em alguma partida
    //eficiencia = Pontos marcados / (Pontos Sofridos + 1)

    int time_teve_eficiencia_maior_que_1 = 0;//0=não 1=sim;
    int times_jovens_eficientes = 0;

    for(int i=0; i<qtd_times_jovens; i++)
    {
        for(int c=0; c<qtd_partidas; c++)
        {
            int eficiencia = 0;
            if(lista_times[i].id == lista_partidas[c].idTime1)
            {
                eficiencia = lista_partidas[c].pontos1 / (lista_partidas[c].pontos2 + 1);
                if(eficiencia >= 1)
                {
                    time_teve_eficiencia_maior_que_1 = 1;
                    break;
                }
            }
            if(lista_times[i].id == lista_partidas[c].idTime2)
            {
                eficiencia = lista_partidas[c].pontos2 / (lista_partidas[c].pontos1 + 1);
                if(eficiencia >= 1)
                {
                    time_teve_eficiencia_maior_que_1 = 1;
                    break;
                }
            }
        }
        //somando os times que tiveram eficiência maior que 1
        if(time_teve_eficiencia_maior_que_1 == 1)
        {
            times_jovens_eficientes++;
        }
    }

    return times_jovens_eficientes;
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