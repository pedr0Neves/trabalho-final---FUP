#pragma once
// #ifdef
// #define ACESSO_H

typedef struct{
    int n;
    char nome[10];
    char senha[10];
} acesso;

acesso *jogador;

void erro_login();
void ler_login(int *cont2);
acesso jogador_novo();
acesso* criar_save(acesso *jogador, int *cont2, acesso novo);
acesso* deletar_save(acesso *jogador, int *cont2, int *save);
acesso* criar_login(acesso *jogador, int *cont2);
void fazer_login(int *confirmador, int *cont2, char nome_jogador[]);

// #endif