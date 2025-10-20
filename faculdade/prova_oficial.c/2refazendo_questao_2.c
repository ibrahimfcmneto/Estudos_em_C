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
    int contador_times_jovens_eficientes = 0;

    //vai rodar de time em time
    for (int i=0; i<qtd_times; i++)
    {
        bool time_jovem = true;
        //vai pegar os atletas dentro do time
        for(int j=0; j<5; j++)
        {
            int atleta_atual = lista_times[i].idAtletas[j];

            for(int k=0; k<qtd_atletas; k++)
            {
                if(lista_atletas[k].id == atleta_atual)
                {
                    if(lista_atletas[k].idade > 20)
                    {
                        time_jovem = false;
                        
                    }
                    break;//sai do loop de busca
                }

            }
        if(time_jovem == false)
        {
            break;//sai do loop de atletas
        }
        }

        if(time_jovem == false)
        {
            continue;//caso o time não seja jovem vai voltar para o inicio
        }

        //agora vai verificar a eficiencia do time
        bool time_eficiente = false;

        for(int p=0; p<qtd_partidas; p++)
        {
            //verifica se o time jovem que foi filtrado jogou essa partida
            if(lista_times[i].id == lista_partidas[p].idTime1)
            {
                float eficiencia = (float)lista_partidas[p].pontos1 / (lista_partidas[p].pontos2 + 1);
                if(eficiencia > 1)
                {
                    time_eficiente = true;
                    break;
                }
            }

            else if(lista_times[i].id == lista_partidas[p].idTime2)
            {
                float eficiencia = lista_partidas[p].pontos2 / (lista_partidas[p].pontos1 + 1);
                if(eficiencia > 1)
                {
                    time_eficiente = true;
                    break;
                }
            }
        }
        if(time_eficiente)
        {
            contador_times_jovens_eficientes++;
        }
    }
    return contador_times_jovens_eficientes;
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