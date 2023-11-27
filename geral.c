#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "geral.h"

#define clear system("cls");

geral *score;

void erro_ranking()
{
    FILE *ranking = fopen("ranking.txt","w");
    fclose(ranking);
}

void ler_ranking(int *cont)
{
    FILE *ranking;

    int n, pontuacao;
    char player[10];

    ranking = fopen("ranking.txt","r");
    if(ranking == 0){
        erro_ranking();
    }

    *cont = 0;
    while(fscanf(ranking, "%d\n%s\n%d\n", &n, player, &pontuacao) == 3){
        (*cont)++;
    }

    fclose(ranking);
}

geral* adiciona_score(geral *score, int *cont, char nome_jogador[], int placar)
{
    ler_ranking(&*cont);
    FILE *ranking;

    ranking = fopen("ranking.txt","a");
    if(ranking == 0){
        printf("ERRO AO ABRIR O ARQUIVO");
        exit(1);
    }

    score = (geral*) realloc(score, (*cont + 1) * sizeof(geral));
    if(score == 0){
        printf("ERRO");
        exit(1);
    }
    
    score[*cont].n1 = *cont + 1;
    strcpy(score[*cont].player,nome_jogador);
    score[*cont].pontuacao = placar;

    fprintf(ranking, "%d\n%s\n%d\n", score[*cont].n1, score[*cont].player, score[*cont].pontuacao);

    (*cont)++;

    fclose(ranking);
    return score;
}

geral* remover_score(geral *score, int *cont, int *apagar)
{
    ler_ranking(&*cont);
    FILE *ranking;

    if(*cont == 0){
        printf("ainda nao existem rankings\n");
        getch();
        return score;
    }

    int pos, sco, apa;
    char nom[10];

    ranking = fopen("ranking.txt","r");
    for(int j = 0; j < *cont; j++){
        fscanf(ranking, "%d\n%s\n%d\n", &pos, nom, &sco);
        printf("%d - [ %s : %d ]\n\n", pos, nom, sco);
    }
    fclose(ranking);

    printf("\n");
    printf("qual pontuacao voce quer apagar: ");
    scanf("%d", &apa);
    *apagar = apa;

    score = (geral*) realloc(score, (*cont) * sizeof(geral));

    ranking = fopen("ranking.txt","r");
    for(int j = 0; j < *cont; j++){
        fscanf(ranking, "%d\n%s\n%d\n", &score[j].n1, score[j].player, &score[j].pontuacao);
    }
    fclose(ranking);

    for(int i = 0; i < *cont; i++){
        if(score[i].n1 == *apagar){

            score[*cont - 1].n1 = score[i].n1;
            score[i] = score[*cont - 1];

            if(*cont - 1 == 0){
                score = (geral*) realloc(score, 1 * sizeof(geral));
            } else {
                score = (geral*) realloc(score, (*cont - 1) * sizeof(geral));
                if(score == 0){
                    printf("ERRO");
                    exit(1);
                }
            }

            (*cont)--;

            ranking = fopen("ranking.txt","w");
            for(int j = 0; j < *cont; j++){
                fprintf(ranking, "%d\n%s\n%d\n", score[j].n1, score[j].player, score[j].pontuacao);
            }
            fclose(ranking);

            break;
        }
    }

    return score;
}

void imprimir_score(geral *score,int *cont)
{
    ler_ranking(&*cont);
    FILE *ranking;
    int auxl_pont; char auxl_nome[10];

    score = (geral*) realloc(score, (*cont) * sizeof(geral));

    ranking = fopen("ranking.txt","r");
    for(int i = 0; i < *cont; i++){
        fscanf(ranking, "%d\n%s\n%d\n", &score[i].n1, score[i].player, &score[i].pontuacao);
    }
    fclose(ranking);

    for(int i = 0; i < *cont; i++){
        for(int j = 0; j < *cont; j++){
            if(score[i].pontuacao > score[j].pontuacao){
                auxl_pont = score[j].pontuacao;
                strcpy(auxl_nome,score[j].player);
                score[j].pontuacao = score[i].pontuacao;
                strcpy(score[j].player,score[i].player);
                score[i].pontuacao = auxl_pont;
                strcpy(score[i].player,auxl_nome);
            }
        }
    }

    for(int i = 0; i < *cont; i++){
        printf("%d lugar - %s com %d pontos.\n", i+1, score[i].player, score[i].pontuacao);
        printf("\n");
    }

    printf("aperte qualquer tecla para voltar ao menu.\n");
    getch();
}