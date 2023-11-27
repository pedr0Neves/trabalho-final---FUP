#pragma once

typedef struct{
    int n1;
    char player[10];
    int pontuacao;
} geral;

geral *score;

void erro_ranking();
void ler_ranking(int *cont);
geral* adiciona_score(geral *score, int *cont, char nome_jogador[], int placar);
geral* remover_score(geral *score, int *cont, int *apagar);
void imprimir_score(geral *score,int *cont);